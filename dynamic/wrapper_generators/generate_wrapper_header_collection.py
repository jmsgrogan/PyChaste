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
Generate the file classes_to_be_wrapped.hpp, which contains includes, instantiation and
naming typedefs for all classes that are to be automatically wrapped.
"""

import sys
from wrapper_utilities.class_info import ClassInfoHelper


class CastXmlHeaderGenerator():

    """
    This class manages generation of the header collection file for
    parsing by CastXML
    """

    def __init__(self, source_root, wrapper_root, class_info_collection):

        self.source_root = source_root
        self.wrapper_root = wrapper_root
        self.class_info_collection = class_info_collection
        self.header_file_name = "wrapper_header_collection.hpp"
        self.header_string = ""
        self.package_name = "PYCHASTE"
        self.add_common_stl = True
        self.use_vec_pointer_typedefs = False

    def add_vec_pointer_typedefs(self, class_info, short_name, full_name):

        # Nice names for vectors of pointers
        if class_info.include_vec_ptr_self:
            raw_prefix = "typedef " + full_name + "* "
            shared_prefix = "typedef std::shared_ptr<"
            vector_prefix = "typedef std::vector<"
            vec_shared_prefix = "typedef std::vector<SharedPtr"
            self.header_string += raw_prefix + short_name + "Ptr;\n"
            self.header_string += shared_prefix + full_name
            self.header_string += " > SharedPtr" + short_name + ";\n"
            self.header_string += vector_prefix + short_name + "Ptr> "
            self.header_string += "Vector" + short_name + "Ptr;\n"
            self.header_string += vec_shared_prefix + short_name + "> "
            self.header_string += "VectorSharedPtr" + short_name + ";\n"

        add_ptr_self = class_info.include_ptr_self
        no_add_vec_ptr_self = not class_info.include_vec_ptr_self
        if add_ptr_self and not no_add_vec_ptr_self:
            self.header_string += "typedef std::shared_ptr<" + full_name
            self.header_string += " > SharedPtr" + short_name + ";\n"

        if class_info.include_raw_ptr_self and no_add_vec_ptr_self:
            self.header_string += "typedef " + full_name + "* "
            self.header_string += short_name + "Ptr;\n"

    def add_custom_header_code(self):

        # Add some special includes for Boost and PETSc
        self.header_string += "\n// Need to specifically instantiate PETSc Vec and Mat \n"
        #self.header_string += "typedef boost::filesystem::path boost_filesystem_path;\n"
        self.header_string += "\n inline int Instantiation()\n{\nreturn sizeof(Mat) + sizeof(Vec);\n}\n"
        self.header_string += "\n inline Mat GetPetscMatForWrapper()\n{\nMat A;\nPetscTools::SetupMat(A, 3, 3, 3);\nreturn A;\n}\n"

    def generate_hpp_file(self):

        class_info_helper = ClassInfoHelper(self.source_root,
                                            self.wrapper_root,
                                            self.class_info_collection)
        class_info_helper.generate_class_info()

        # Add the includes
        self.header_string = ""
        self.header_string += "#ifndef " + self.package_name + "HEADERS_HPP_\n"
        self.header_string += "#define " + self.package_name + "HEADERS_HPP_\n"
        self.header_string += "\n// Includes \n"

        # Start with STL components
        if self.add_common_stl:
            self.header_string += "#include <vector>\n"
            self.header_string += "#include <set>\n"
            self.header_string += "#include <map>\n"

        # Now our own includes
        for eachClass in self.class_info_collection:
            if eachClass.needs_include_file:
                self.header_string += '#include "' + eachClass.name + '.hpp"\n'

        # Add the template instantiations
        self.header_string += "\n// Instantiate Template Classes \n"
        for eachClass in self.class_info_collection:
            if not eachClass.needs_header_file_instantiation():
                continue
            prefix = "template class "
            for eachTemplateName in eachClass.get_full_names():
                self.header_string += prefix + eachTemplateName + ";\n"

        # Add typdefs for nice naming
        self.header_string += "\n// Typedef for nicer naming\n"
        self.header_string += "namespace pyplusplus{ \n"
        self.header_string += "namespace aliases{ \n"
        for eachClass in self.class_info_collection:
            if not eachClass.needs_header_file_typdef():
                continue

            short_names = eachClass.get_short_names()
            full_names = eachClass.get_full_names()
            for idx, eachTemplateName in enumerate(full_names):
                short_name = short_names[idx]
                typdef_prefix = "typedef " + eachTemplateName + " "
                self.header_string += typdef_prefix + short_name + ";\n"

                if self.use_vec_pointer_typedefs:
                    self.add_vec_pointer_typedefs(eachClass, short_name,
                                                  eachTemplateName)

        self.header_string += "    }\n"
        self.header_string += "}\n"

        self.add_custom_header_code()
        self.header_string += "#endif // " + self.package_name + "HEADERS_HPP_\n"

        file_path = self.wrapper_root + "/" + self.header_file_name

        hpp_file = open(file_path, 'w')
        hpp_file.write(self.header_string)
        hpp_file.close()


if __name__ == "__main__":

    # fake_path = ["","/home/grogan/Chaste", "/home/grogan/"]
    import classes_to_be_wrapped
    class_info_collection = classes_to_be_wrapped.classes

    writer = CastXmlHeaderGenerator(sys.argv[1], sys.argv[2],
                                    class_info_collection)
    writer.generate_hpp_file()
