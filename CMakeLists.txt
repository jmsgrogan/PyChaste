cmake_minimum_required (VERSION 2.6)
project (pychaste)

find_package(PythonLibs)
find_package(Boost COMPONENTS python)
find_package(Chaste)

include_directories(${Chaste_INCLUDE_DIRS} ${Chaste_THIRD_PARTY_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(mylib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/Hello.cpp)
target_link_libraries(mylib ${Chaste_LIBRARIES})

add_library(_pychaste SHARED ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/HelloWrapper.cpp)
target_link_libraries(_pychaste boost_python ${PYTHON_LIBRARY} ${CMAKE_BINARY_DIR}/libmylib.so ${Chaste_THIRD_PARTY_LIBRARIES} ${Chaste_LIBRARIES})
add_dependencies(_pychaste mylib)
set_target_properties(_pychaste PROPERTIES PREFIX "" )
