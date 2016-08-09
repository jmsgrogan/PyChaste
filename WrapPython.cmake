# Copyright (c) 2005-2016, University of Oxford.
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

######### Find the dependencies for wrapper building ###################### 
# The Boost Python headers and shared library are needed, use CMake to find them.
find_package(Boost COMPONENTS python REQUIRED)

# Python headers and shared library are also needed. The version needs to be the same
# as that of the Python interpreter used to run package. e.g. Python 2.7.x.
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# Find the Chaste and third party dependency header files.
include_directories(${Chaste_INCLUDE_DIRS} ${Chaste_THIRD_PARTY_INCLUDE_DIRS})

# Any non-wrapper code (code in the src folder) in this project needs to be put in its own shared library. 
set(PYCHASTE_SHARED_LIB ${CMAKE_CURRENT_BINARY_DIR}/libchaste_project_PyChaste.so)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/)
######### Build the Python modules ###################### 
set (PYCHASTE_PYTHON_MODULES "")
set (PYCHASTE_PYTHON_MODULE_LOCATIONS "")

# Add each module to be built to this list. 
list (APPEND PYCHASTE_PYTHON_MODULES preload)
list (APPEND PYCHASTE_PYTHON_MODULES core)
#list (APPEND PYCHASTE_PYTHON_MODULES hello_manual)
#list (APPEND PYCHASTE_PYTHON_MODULES hello_auto)

# The shared library corresponding to this module needs to be put in the correct place in the package tree after it is built, put the location here.
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/)
list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/core)
#list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/tutorial/)
#list (APPEND PYCHASTE_PYTHON_MODULE_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/python/chaste/tutorial/)

# Copy the Python package (i.e. all source files etc) to the build folder, ignore any shared libraries that might be in there.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/python/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/python/ PATTERN "*.so" EXCLUDE)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/python/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/python/test/)

# If needed regenerate the bindings
#SET(arguments hello)
#LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR} )
#LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial/Hello.hpp)
#LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial/)
#LIST(APPEND arguments ${Chaste_INCLUDE_DIRS})
#LIST(APPEND arguments ${Chaste_THIRD_PARTY_INCLUDE_DIRS})

#add_custom_command(TARGET project_PyChaste_Python_Bindings COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/generate_tutorial_bindings.py ${arguments})

SET(arguments core)
LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR} )
LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/CoreWrapperHeaderCollection.hpp)
LIST(APPEND arguments ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/)
LIST(APPEND arguments ${Chaste_INCLUDE_DIRS})
LIST(APPEND arguments ${Chaste_THIRD_PARTY_INCLUDE_DIRS})
add_custom_target(project_PyChaste_Python_Bindings)
add_custom_command(TARGET project_PyChaste_Python_Bindings COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/generate_core_bindings.py ${arguments})

# Loop through each module and create the shared library targets
list(LENGTH PYCHASTE_PYTHON_MODULES len1)
math(EXPR len2 "${len1} - 1")
foreach(val RANGE ${len2})
    list(GET PYCHASTE_PYTHON_MODULES ${val} python_module)
    list(GET PYCHASTE_PYTHON_MODULE_LOCATIONS ${val} python_module_location)
    
    # each module is in the 'dynamic' directory. The library name must be the same as that defined in the cpp file. It is customary
    # to start the name with an underscore. The usual 'lib' prefix is disabled.
    add_library(_chaste_project_PyChaste_${python_module} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/${python_module}.cpp)
    set_target_properties(_chaste_project_PyChaste_${python_module} PROPERTIES PREFIX "" LIBRARY_OUTPUT_DIRECTORY ${python_module_location})
    
    # order is important, boost python and python come first
    target_link_libraries(_chaste_project_PyChaste_${python_module} boost_python ${PYTHON_LIBRARIES} ${Chaste_THIRD_PARTY_LIBRARIES} ${Chaste_LIBRARIES} ${PYCHASTE_SHARED_LIB})
    add_dependencies(_chaste_project_PyChaste_${python_module} project_PyChaste_Python_Bindings)
endforeach()

# Add a target so all the libraries are built with a single command
add_custom_target(project_PyChaste_Python)
#add_dependencies(project_PyChaste_Python _chaste_project_PyChaste_preload _chaste_project_PyChaste_hello_manual _chaste_project_PyChaste_hello_auto)
add_dependencies(project_PyChaste_Python _chaste_project_PyChaste_preload _chaste_project_PyChaste_core)