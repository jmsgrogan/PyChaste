# Copyright (c) 2005-2019, University of Oxford.
# All rights reserved.
# 
# University of Oxford means the Chancellor, Masters and Scholars of the
# University of Oxford, having an administrative office at Wellington
# Square, Oxford OX1 2JD, UK.
# 
# This file is part of Chaste.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#  * Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#  * Neither the name of the University of Oxford nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
add_compile_options(-Wno-unused-local-typedefs)

######### Find the dependencies for wrapper building ###################### 
# Add any cmake modules defined in this project
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

# Python headers and shared library are also needed. The version needs to be the same
# as that of the Python interpreter used to run package. e.g. Python 2.7.x.
#find_package(PythonLibs REQUIRED)
#(${PYTHON_INCLUDE_DIRS})

# Used for binding generation
set(CASTXML_EXE_LOC "/usr/bin/castxml" CACHE FILEPATH "Path to the castxml executable.")

# Find the Chaste and third party dependency header files.
include_directories(${Chaste_INCLUDE_DIRS} ${Chaste_THIRD_PARTY_INCLUDE_DIRS})

# Any non-wrapper code (code in the src folder) in this project needs to be put in its own shared library. 
if(APPLE)
    set(PYCHASTE_SHARED_LIB ${CMAKE_CURRENT_BINARY_DIR}/libchaste_project_PyChaste.dylib)
elseif(WIN32)
    set(PYCHASTE_SHARED_LIB ${CMAKE_CURRENT_BINARY_DIR}/libchaste_project_PyChaste.dll)  
else()
    set(PYCHASTE_SHARED_LIB ${CMAKE_CURRENT_BINARY_DIR}/libchaste_project_PyChaste.so)  
endif()

# Collect the header directories for this project
include(${CMAKE_CURRENT_SOURCE_DIR}/ProjectIncludes.cmake)
include_directories(${PYCHASTE_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/wrappers)

set (CMAKE_CXX_STANDARD 14)
if(CMAKE_COMPILER_IS_GNUCXX)
        # https://svn.boost.org/trac/boost/ticket/9240
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fext-numeric-literals")
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/pybind11/include)

# For now Chaste needs Python 2.7 for infra stuff, need to temporarily switch to
# Python 3 for PyChaste building and switch back later.
unset(PYTHONINTERP_FOUND CACHE)
unset(PYTHON_EXECUTABLE CACHE)
unset(PYTHON_VERSION_STRING CACHE)
unset(PYTHON_VERSION_MAJOR CACHE)
unset(PYTHON_VERSION_MINOR CACHE)
unset(PYTHON_VERSION_PATCH CACHE)
unset(PYTHON_LIBRARIES CACHE)
unset(PYTHON_LIBRARY CACHE)
find_package(PythonInterp 3.6)

set(PYBIND11_PYTHON_VERSION 3.6)
set(PYBIND11_CPP_STANDARD -std=c++14)
add_subdirectory(dynamic/pybind11)
include_directories(${PYTHON_INCLUDE_DIRS})

######### Build the Python modules ###################### 
set (PYCHASTE_PYTHON_AUTO_MODULES "")
set (PYCHASTE_PYTHON_MODULES "")
# The shared library corresponding to this module needs to be put in the correct place in the package tree after it is built, put the location here.
set (PYCHASTE_PYTHON_MODULE_LOCATIONS "")

# Add each module to be built to this list. 
# Modules with auto wrapping
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES core)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/core)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES ode)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/ode)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES pde)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/pde)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES mesh)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/mesh)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES cell_based)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/cell_based)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES visualization)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/visualization)
list (APPEND PYCHASTE_PYTHON_AUTO_MODULES tutorial)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/tutorial)
list (APPEND PYCHASTE_PYTHON_MODULES ${PYCHASTE_PYTHON_AUTO_MODULES})

# Modules with manual wrapping
list (APPEND PYCHASTE_PYTHON_MODULES preload)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/)
list (APPEND PYCHASTE_PYTHON_MODULES tutorial_manual)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/tutorial/)

# Copy the Python package (i.e. all source files etc) to the build folder, ignore any shared libraries that might be in there.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/python/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/python/ PATTERN "*.so" EXCLUDE)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/python/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/python/test/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/doc/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/python/doc/)

# Target to generate bindings
add_custom_target(project_PyChaste_Python_Bindings)
SET(arguments ${CMAKE_SOURCE_DIR}/)
LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/wrappers/)
LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/wrapper_generators/package_info.yaml)
LIST(APPEND arguments ${CASTXML_EXE_LOC})
LIST(APPEND arguments ${PYCHASTE_INCLUDE_DIRS})
LIST(APPEND arguments ${Chaste_INCLUDE_DIRS})
LIST(APPEND arguments ${Chaste_THIRD_PARTY_INCLUDE_DIRS})
add_custom_command(TARGET project_PyChaste_Python_Bindings COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/wrapper_generators/generate.py ${arguments})

# Loop through each module and create the shared library targets
list(LENGTH PYCHASTE_PYTHON_MODULES len1)
math(EXPR len2 "${len1} - 1")
foreach(val RANGE ${len2})
    list(GET PYCHASTE_PYTHON_MODULES ${val} python_module)
    list(GET PYCHASTE_PYTHON_MODULE_LOCATIONS ${val} python_module_location)
    
    file(GLOB MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/wrappers/${python_module}/*.cpp)
    
    # each module is in the 'dynamic' directory. The library name must be the same as that defined in the cpp file. It is customary
    # to start the name with an underscore. The usual 'lib' prefix is disabled.
    add_library(_chaste_project_PyChaste_${python_module} SHARED ${MODULE_SOURCES})
    set_target_properties(_chaste_project_PyChaste_${python_module} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${python_module_location} 
        PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX ".so")
    target_compile_features(_chaste_project_PyChaste_${python_module} PRIVATE cxx_range_for)
    # order is important, pybind and python come first
    target_link_libraries(_chaste_project_PyChaste_${python_module} pybind11::module ${PYTHON_LIBRARIES} ${Chaste_THIRD_PARTY_LIBRARIES} ${Chaste_LIBRARIES} ${PYCHASTE_SHARED_LIB})
    add_dependencies(_chaste_project_PyChaste_${python_module} chaste_project_PyChaste)
endforeach()

# Add a target so all the libraries are built with a single command
add_custom_target(project_PyChaste_Python)
foreach(val RANGE ${len2})
    list(GET PYCHASTE_PYTHON_MODULES ${val} python_module)
    add_dependencies(project_PyChaste_Python _chaste_project_PyChaste_${python_module})
endforeach()

# Switch back to Python 2 for the rest of Chaste
unset(PYTHONINTERP_FOUND CACHE)
unset(PYTHON_EXECUTABLE CACHE)
unset(PYTHON_VERSION_STRING CACHE)
unset(PYTHON_VERSION_MAJOR CACHE)
unset(PYTHON_VERSION_MINOR CACHE)
unset(PYTHON_VERSION_PATCH CACHE)
unset(PYTHON_LIBRARIES CACHE)
unset(PYTHON_LIBRARY CACHE)
find_package(PythonInterp 2)
