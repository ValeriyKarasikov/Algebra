#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.22.2)

project(Algebra VERSION ${CMAKE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -ggdb)
#add_compile_options(-Wall -Ofast)

#set(ENV{CMAKE_BUILD_PARALLEL_LEVEL} 8)

#-------------------------------------------------------------------------------

set(HDR headers)
set(SRC sources)

set(ARCH architecture)
set(LIBR libraries)
set(VRBL variables)

#-------------------------------------------------------------------------------

# Add directories with header files:
include_directories(${HDR}/${ARCH})
include_directories(${HDR}/${LIBR})
include_directories(${HDR}/${VRBL})

#-------------------------------------------------------------------------------

# architecture
set(ARCH_INTR ${HDR}/${ARCH}/interpreter.hpp   ${SRC}/${ARCH}/interpreter.cpp)
set(ARCH_POST ${HDR}/${ARCH}/postprocessor.hpp ${SRC}/${ARCH}/postprocessor.cpp)
set(ARCH_PREP ${HDR}/${ARCH}/preprocessor.hpp  ${SRC}/${ARCH}/preprocessor.cpp)
set(ARCH_PROC ${HDR}/${ARCH}/processor.hpp     ${SRC}/${ARCH}/processor.cpp)

# libraries
set(LIBR_ALGB ${HDR}/${LIBR}/algebra.hpp   ${SRC}/${LIBR}/algebra.cpp)
set(LIBR_EXCP ${HDR}/${LIBR}/exception.hpp ${SRC}/${LIBR}/exception.cpp)
set(LIBR_FILE ${HDR}/${LIBR}/file.hpp      ${SRC}/${LIBR}/file.cpp)
set(LIBR_SNTX ${HDR}/${LIBR}/syntax.hpp    ${SRC}/${LIBR}/syntax.cpp)
set(LIBR_TERM ${HDR}/${LIBR}/terminal.hpp  ${SRC}/${LIBR}/terminal.cpp)

# variables
set(VRBL_DABA ${HDR}/${VRBL}/database.hpp ${SRC}/${VRBL}/database.cpp)
set(VRBL_LIBR ${HDR}/${VRBL}/library.hpp  ${SRC}/${VRBL}/library.cpp)

#-------------------------------------------------------------------------------

# architecture
add_library(_intr STATIC ${ARCH_INTR})
add_library(_post STATIC ${ARCH_POST})
add_library(_prep STATIC ${ARCH_PREP})
add_library(_proc STATIC ${ARCH_PROC})

# libraries
add_library(_algb STATIC ${LIBR_ALGB})
add_library(_excp STATIC ${LIBR_EXCP})
add_library(_file STATIC ${LIBR_FILE})
add_library(_sntx STATIC ${LIBR_SNTX})
add_library(_term STATIC ${LIBR_TERM})

# variables
add_library(_daba STATIC ${VRBL_DABA})
add_library(_libr STATIC ${VRBL_LIBR})

# main
add_executable(${PROJECT_NAME} main.cpp)

# INTERFACE - .h , PRIVATE - .cpp , PUBLIC - .h & .cpp
#-------------------------------------------------------------------------------

# architecture
#target_link_libraries(_intf INTERFACE _data)

# libraries
#independent

# variables
#target_link_libraries(_intf INTERFACE _data)

# main
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE _intf)
target_link_libraries(${PROJECT_NAME} PRIVATE _intr)

#-------------------------------------------------------------------------------

#macro(add_prefix prefix list_name)
#  set(${list_name}_tmp)
#  foreach(l ${${list_name}})
#    list(APPEND ${list_name}_tmp ${prefix}${l})
#  endforeach()
#  set(${list_name} ${${list_name}_tmp})
#  unset(${list_name}_tmp)
#endmacro(add_prefix)
