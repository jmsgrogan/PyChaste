#!/usr/bin/env python

"""Copyright (c) 2005-2017, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"""

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
import os
try:
   import cPickle as pickle
except:
   import pickle
import ntpath
from pygccxml import parser, declarations
import pygccxml.declarations.dependencies
import wrapper_utilities.writers

chaste_license = """
/*

Copyright (c) 2005-2017, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
"""


class PyBind11WrapperGenerator():

    def __init__(self, source_root, wrapper_root,
                 header_collection, castxml_binary, module_name, includes,
                 class_info_collection):

        self.license = chaste_license
        self.source_root = source_root
        self.wrapper_root = wrapper_root
        self.header_collection = header_collection
        self.castxml_binary = castxml_binary
        self.module_name = module_name
        self.includes = includes
        self.global_ns = None
        self.source_ns = None
        self.wrapper_header_name = "wrapper_header_collection.hpp"
        self.class_info_collection = class_info_collection
        self.module_prefix = "_chaste_project_PyChaste_"
        self.module_names = ["core", "ode", "pde", "mesh", "cell_based",
                                     "tutorial", "visualization"]
        self.exposed_class_full_names = []
        for eachClassInfo in self.class_info_collection:
            self.exposed_class_full_names.extend(eachClassInfo.get_full_names())

    def parse_source_code(self):

        xml_generator_config = parser.xml_generator_configuration_t(xml_generator_path=self.castxml_binary, 
                                                                    xml_generator="castxml",
                                                                    cflags="-std=c++11",
                                                                    include_paths=self.includes)

        print "INFO: Parsing Code"
        decls = parser.parse([self.wrapper_root + "/" +
                              self.wrapper_header_name], xml_generator_config,
                             compilation_mode=parser.COMPILATION_MODE.ALL_AT_ONCE)

        # Get access to the global namespace
        self.global_ns = declarations.get_global_namespace(decls)

        # Clean decls to only include those for which file locations exist
        print "INFO: Cleaning Decls"
        query = declarations.custom_matcher_t(lambda decl: decl.location is not None)
        decls_loc_not_none = self.global_ns.decls(function=query)

        # Identify decls in our source tree
        source_decls = [decl for decl in decls_loc_not_none if self.source_root in decl.location.file_name]
        self.source_ns = declarations.namespace_t("source", source_decls)

        print "INFO: Optimizing Decls"
        self.source_ns.init_optimizer()

    def generate_wrappers(self):

        self.parse_source_code()

        possible_module_names = [self.module_name]
        if self.module_name == "All":
            possible_module_names = self.module_names

        for idx, eachModule in enumerate(possible_module_names):

            print 'Generating Wrapper Code for: ' + eachModule + ' Module.'

            # Generate the main cpp file
            main_cpp_file = open(self.wrapper_root + "/" + eachModule + "/" +
                                 eachModule + ".main.cpp", "w")
            main_cpp_file.write('#include <pybind11/pybind11.h>\n')
            for eachClass in self.class_info_collection:
                
                decl_found = True
                for fullName in eachClass.get_full_names():
                    if len(self.source_ns.classes(fullName, allow_empty=True)) == 0:
                        decl_found = False
                        break

                if not decl_found:
                    continue
                
                if not eachClass.include_file_only and eachClass.component == eachModule:
                    short_class_names = eachClass.get_short_names()
                    for idx, eachName in enumerate(short_class_names):
                        main_cpp_file.write('#include "' + eachName + '.pypp.hpp"\n')
            main_cpp_file.write('\nnamespace py = pybind11;\n\n')
            main_cpp_file.write('PYBIND11_MODULE(' +
                                self.module_prefix+eachModule +
                                ', m)\n')
            main_cpp_file.write('{\n')

            # Get object that describes unittests namespace
            class_list = self.class_info_collection
            for eachClass in class_list:

                decl_found = True
                for fullName in eachClass.get_full_names():
                    if len(self.source_ns.classes(fullName, allow_empty=True)) == 0:
                        decl_found = False
                        break

                if not decl_found:
                    continue

                if eachClass.include_file_only:
                    continue

                if eachClass.component != eachModule:
                    continue

                class_writer = wrapper_utilities.writers.PyBind11ClassWriter(eachClass)
                class_writer.exposed_class_full_names = self.exposed_class_full_names
                full_class_names = eachClass.get_full_names()
                short_class_names = eachClass.get_short_names()
                for idx, fullName in enumerate(full_class_names):
                    class_decl = self.source_ns.class_(fullName)

#                     print "Class: ", eachClass.name,
#                     print "Deps:"
#                     for eachDep in declarations.dependencies.get_dependencies_from_decl(class_decl):
#                         print eachDep.declaration.name
                    class_decl.location.file_name
                    class_writer.class_decls.append(class_decl)

                    short_name = short_class_names[idx]
                    main_cpp_file.write('register_' + short_name + '_class(m);\n')
                    print "Writing: ", class_decl.name
                class_writer.write(self.wrapper_root + "/" + eachModule + "/")
            main_cpp_file.write('}\n')
            main_cpp_file.close()


if __name__ == "__main__":

    source_root = sys.argv[1]
    wrapper_root = sys.argv[2]
    header_collection = sys.argv[3]
    castxml_binary = sys.argv[4]
    module_name = sys.argv[5]
    includes = sys.argv[6:]

    with open(wrapper_root + "/class_data.p", 'rb') as fp:
            class_info_collection = pickle.load(fp)

    wrapper_generator = PyBind11WrapperGenerator(source_root,
                                                 wrapper_root,
                                                 header_collection,
                                                 castxml_binary, module_name,
                                                 includes,
                                                 class_info_collection)
    wrapper_generator.generate_wrappers()
