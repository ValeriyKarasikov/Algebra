#pragma once

#include <stdexcept> // std::out_of_range
#include <tuple>     // std::tuple
#include <memory>    // std::size_t
#include <string>    // std::string
#include <typeindex> // std::type_index
#include <map>       // std::map
#include <list>      // std::list

template <typename... Ts>
class Database
{
  public:

    template <typename T>
      using function_type = T (*)(const std::string &);
    using line_type = std::string;
    using lines_type = std::list<line_type>;
    using size_type = std::size_t;

    static constexpr size_type N = sizeof...(Ts);
    struct Unit
    {
      std::shared_ptr<void> value{nullptr}; // ссылка на переменную
      std::type_index index{typeid(void)};  // тип переменной
    };
    std::map<line_type, Unit> variables;    // содержит все переменные

    // 1) набор символов, отвечающих за тип
    // 2) набор функций преобразования из строк к конкретный тип

    Database(const char (&signs)[N], function_type<Ts>... functions);
    ~Database();

    bool exists(line_type name) const;               // существование
                                                     // переменной

    void set(const line_type& name, const line_type& value);

    template <typename T>
      void set(const line_type name, const T value); // создает переменную
    void erase(line_type name);                      // удаляет переменную

    void assign(line_type& value, line_type& name);
    template<typename T>
      void assign(T& t, line_type& name);            // изменяет значение
                                                     // переменной
    size_type size() const;                          // возвращает кол-во
                                                     // переменных
    lines_type allNames() const;                     // возвращает имена всех
                                                     // переменных
    template<typename T>
      T get(const line_type &name); // возвращает значение переменной
    std::type_index getTypeId(line_type &name);

  private:

    line_type signs_;
    std::tuple<function_type<Ts>...> functions_;

    template <size_type I = 0, class Function, class Condition>
      void forEachConversionFunction_(const Function &function,
          const Condition &condition) const;

    bool find_(const char &a);
};

template <typename... Ts>
template <std::size_t I, class Func, class Cond>
void Database<Ts...>::forEachConversionFunction_(const Func &func,
    const Cond &cond) const
{
  if constexpr (I < N)
  {
    auto convFunc{std::get<I>(this->functions_)};
    if (cond) { func(convFunc); }
    else { this->forEachConversionFunction_<I + 1>(func, cond); }
  }
}

template <typename... Ts>
Database<Ts...>::Database(const char (&signs)[N], function_type<Ts>... functions) :
  signs_{signs}, functions_{functions...}
{
}

  template <typename... Ts>
Database<Ts...>::~Database()
{}

template <typename... Ts>
bool Database<Ts...>::exists(line_type name) const
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  return it != this->variables.end()? 1 : 0;
}

  template <typename... Ts>
void Database<Ts...>::set(const line_type& name, const line_type& value)
{
  if (this->find_(value.back()))
  {
    const auto sign{value.back()};
    auto signs_ci{this->signs_.cbegin()};

    auto cond = [&] {
      return ( sign == *(signs_ci++) );
    };

    //auto func = [&]<typename CF>(CF convFunc) {
    auto func = [&](auto convFunc) {
      this->set(name, (*convFunc)(value));
    };

    this->forEachConversionFunction_(func, cond);
  }
}

template <typename... Ts>
template <typename T>
void Database<Ts...>::set(line_type name, T value)
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  if (it == this->variables.end()){
    this->variables.insert({name, Unit{std::make_shared<T>(value),
                                                   typeid(decltype(value))}});
  }
  else
    this->assign<T>(value, name);
}

template <typename... Ts>
void Database<Ts...>::assign(line_type& value, line_type& name)
{
  if (this->find_(value.back()))
  {
    const auto sign{value.back()};
    auto signs_ci{this->signs_.cbegin()};

    auto cond = [&] {
      return ( sign == *(signs_ci++) );
    };

    auto func = [&](auto convFunc) {
      this->assign((*convFunc)(value), name);
    };

    this->forEachConversionFunction_(func, cond);
  }
}

template <typename... Ts>
template<typename T>
void Database<Ts...>::assign(T& value, line_type &name)
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  if (it == this->variables.end())
    *it = {name, Unit{std::make_shared<T>(value), typeid(decltype(value))}};
  else
    throw std::out_of_range("variable don't exist");
}

template <typename... Ts>
std::size_t Database<Ts...>::size() const
{
  return this->variables.size();
}

template <typename... Ts>
typename Database<Ts...>::lines_type Database<Ts...>::allNames() const
{
  lines_type names;
  size_type size = this->variables.size();
  for (size_type i = 0; i < size; ++i)
  {
    names.push_back(this->variables[i]->first);
  }
  return names;
}

template <typename... Ts>
void Database<Ts...>::erase(line_type name)
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  if (it != this->variables.end())
    this->variables.erase(it);
  else
    throw std::out_of_range("variable don't exist");
}

template <typename... Ts>
template <typename T>
T Database<Ts...>::get(const line_type &name)
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  if (it != this->variables.end())
  {
    if (it->second.index == typeid(T))
      // std::shared_ptr: get(), operator*()
      return *(T*)it->second.value.get();
    else
      throw std::invalid_argument ("Variable type specified incorrectly");
  }
  else
    throw std::out_of_range ("variable don't exist");
}

template <typename... Ts>
bool Database<Ts...>::find_(const char& a)
{
  for (auto i : this->signs_)
  {
    if (a == this->signs_[i])
      return true;
  }
  throw std::invalid_argument("Variable type specified incorrectly");
}

template <typename... Ts>
std::type_index Database<Ts...>::getTypeId(line_type &name)
{
  typename std::map<line_type, Unit>::iterator it = this->variables.find(name);
  if (it != this->variables.end())
    return it->second.index;
  else
    throw std::out_of_range("Variable don't exist");
}
