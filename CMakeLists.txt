#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.22.2)

project(05-102 VERSION ${CMAKE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -ggdb)
#add_compile_options(-Wall -Ofast)

set(ENV{CMAKE_BUILD_PARALLEL_LEVEL} 8)

#-------------------------------------------------------------------------------

set(HDR headers)
set(SRC sources)

set(ARCH architecture)
set(LIBS libraries)

#-------------------------------------------------------------------------------

# Add directories with header files:
include_directories(${HDR}/${ARCH})
include_directories(${HDR}/${LIBS})

#-------------------------------------------------------------------------------

# architecture
set(ARCH_DATA ${HDR}/${ARCH}/data.hpp          ${SRC}/${ARCH}/data.cpp)
set(ARCH_INTF ${HDR}/${ARCH}/interface.hpp     ${SRC}/${ARCH}/interface.cpp)
set(ARCH_POST ${HDR}/${ARCH}/postprocessor.hpp ${SRC}/${ARCH}/postprocessor.cpp)
set(ARCH_PREP ${HDR}/${ARCH}/preprocessor.hpp  ${SRC}/${ARCH}/preprocessor.cpp)
set(ARCH_PROC ${HDR}/${ARCH}/processor.hpp     ${SRC}/${ARCH}/processor.cpp)

# libraries
set(LIBS_DABA ${HDR}/${LIBS}/database.hpp  ${SRC}/${LIBS}/database.cpp)
set(LIBS_EXCP ${HDR}/${LIBS}/exception.hpp ${SRC}/${LIBS}/exception.cpp)
set(LIBS_FILE ${HDR}/${LIBS}/file.hpp      ${SRC}/${LIBS}/file.cpp)
set(LIBS_SNTX ${HDR}/${LIBS}/syntax.hpp    ${SRC}/${LIBS}/syntax.cpp)
set(LIBS_TERM ${HDR}/${LIBS}/terminal.hpp  ${SRC}/${LIBS}/terminal.cpp)

#-------------------------------------------------------------------------------

# architecture
add_library(_data STATIC ${ARCH_DATA})
add_library(_intf STATIC ${ARCH_INTF})
add_library(_post STATIC ${ARCH_POST})
add_library(_prep STATIC ${ARCH_PREP})
add_library(_proc STATIC ${ARCH_PROC})

# libraries
add_library(_daba STATIC ${LIBS_DABA})
add_library(_excp STATIC ${LIBS_EXCP})
add_library(_file STATIC ${LIBS_FILE})
add_library(_sntx STATIC ${LIBS_SNTX})
add_library(_term STATIC ${LIBS_TERM})

# main
add_executable(${PROJECT_NAME} main.cpp)

# INTERFACE - .h , PRIVATE - .cpp , PUBLIC - .h & .cpp
#-------------------------------------------------------------------------------

# architecture
#target_link_libraries(_intf INTERFACE _data)

# libraries
#independent

# main
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE _intf)
target_link_libraries(${PROJECT_NAME} PRIVATE _intf)

#-------------------------------------------------------------------------------

#macro(add_prefix prefix list_name)
#  set(${list_name}_tmp)
#  foreach(l ${${list_name}})
#    list(APPEND ${list_name}_tmp ${prefix}${l})
#  endforeach()
#  set(${list_name} ${${list_name}_tmp})
#  unset(${list_name}_tmp)
#endmacro(add_prefix)
