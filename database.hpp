#pragma once

#include <stdexcept> // std::out_of_range не уверен, что это должно быть у меня
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
      std::shared_ptr<void> value{nullptr};
      std::type_index index{typeid(void)};
    };
    std::map<line_type, Unit> variables;

    // 1) набор символов, отвечающих за тип
    // 2) набор функций преобразования из строк к конкретный тип

    Database(const char signs[N], function_type<Ts>... functions);
    ~Database();

    bool exists(line_type name) const;          // существование переменной
    void set(line_type name, line_type value);  // создает переменную
    void erase(line_type name);                 // удаляет переменную
    template<typename T>
      void assign(T& t, line_type name);        // что она делает?
    size_type size() const;                     // возвращает кол-во переменных
    lines_type allNames() const;                // возвращает имена всех переменных

  private:

    std::tuple<function_type<Ts>...> functions_;

    template <size_type I = 0, class Function, class Condition>
      void forEachConversionFunction_(const Function &function, const Condition &condition) const;

};

template <typename... Ts>
template <std::size_t I, class Func, class Cond>
void Database<Ts...>::forEachConversionFunction_(const Func &func, const Cond &cond) const
{
  if constexpr (I < N)
  {
    auto convFunc{std::get<I>(this->conversionFunctions_)};
    if (cond(convFunc))
    {
      func(convFunc);
    }
    else
    {
      this->forEachConversionFunction_<I + 1>(func, cond);
    }
  }
}

  template <typename... Ts>
Database<Ts...>::Database(const char signs[N], function_type<Ts>... functions)
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
void Database<Ts...>::set(line_type name, line_type value)
{}

template <typename... Ts>
  template<typename T>
void Database<Ts...>::assign(T& t, line_type name)
{}

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

