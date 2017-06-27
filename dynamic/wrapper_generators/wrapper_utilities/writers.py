import os
from pygccxml import declarations

class PyBind11Writer():

    """
    This class has methods for generating PyBind11 wrapper code
    """

    def __init__(self):
        pass


class PyBind11ClassWriter():

    """
    This class generates PyBind11 output for individual classes
    """

    def __init__(self, class_info):

        self.hpp_string = ""
        self.cpp_string = ""
        self.class_info = class_info
        self.class_decls = []
        self.exposed_class_full_names = []
        self.class_full_names = self.class_info.get_full_names()
        self.class_short_names = self.class_info.get_short_names()
        self.has_shared_ptr = True
        self.exclusion_args = ["::Vec", "::Mat"]
        self.is_abstract = False

        if(len(self.class_full_names) != len(self.class_short_names)):
            message = 'Full and short name lists should be the same length'
            raise ValueError(message)

        # Styling
        self.indent_1 = " " * 4
        self.indent_2 = " " * 8

    def do_file_write(self, work_dir, class_short_name):

        path = work_dir + "/" + class_short_name

        hpp_file = open(path + ".pypp.hpp", "w")
        hpp_file.write(self.hpp_string)
        hpp_file.close()

        cpp_file = open(path + ".pypp.cpp", "w")
        cpp_file.write(self.cpp_string)
        cpp_file.close()

    def write_constructor(self, ctor_decl):

        # Check for exclusions
        for eachArg in ctor_decl.argument_types:
            if eachArg.decl_string.replace(" ", "") in self.exclusion_args:
                return

        if ctor_decl.is_artificial:
            return

        self.cpp_string += self.indent_2 + '.def(py::init<'

        num_arg_types = len(ctor_decl.argument_types)
        for idx, eachArg in enumerate(ctor_decl.argument_types):
            self.cpp_string += eachArg.decl_string
            if idx < num_arg_types-1:
                self.cpp_string += ", "
        self.cpp_string += ' >(''))\n'

    def write_hpp(self, class_short_name):

        line_end = "_hpp__pyplusplus_wrapper\n"
        self.hpp_string += 'namespace py = pybind11;\n\n'
        self.hpp_string += "#ifndef " + class_short_name + line_end
        self.hpp_string += "#define " + class_short_name + line_end
        self.hpp_string += 'void register_' + class_short_name
        self.hpp_string += '_class(py::module &m);\n'
        self.hpp_string += "#endif // " + class_short_name + line_end

    def write_method(self, method_decl, class_short_name):

        method_name = method_decl.name
        return_type = method_decl.return_type.decl_string

        # Check for exclusions
        if return_type.replace(" ", "") in self.exclusion_args:
            return

        for eachArg in method_decl.argument_types:
            if eachArg.decl_string.split()[0].replace(" ", "") in self.exclusion_args:
                return

        # Start method string
        def_string = "def"
        if method_decl.has_static:
            def_string += "_static"

        # .def("MyMethod", (rtype (MyClass::*)(
        self.cpp_string += self.indent_2 + '.' + def_string + '("' + method_name + '", '
        self.cpp_string += '(' + return_type + ' ('

        if not method_decl.has_static:
            self.cpp_string += class_short_name + "::*)("
        else:
            self.cpp_string += "*)("

        # Specify arg signature
        # argtype1, argytype2, argtype3 )) &MyClass::MyMethod, ""
        num_arg_types = len(method_decl.argument_types)
        for idx, eachArg in enumerate(method_decl.argument_types):
            self.cpp_string += eachArg.decl_string
            if idx < num_arg_types-1:
                self.cpp_string += ", "
        self.cpp_string += ')) &' + class_short_name + '::'
        self.cpp_string += method_name + ', "" '

        # Add individual arguments, include names and default values
        for eachArg in method_decl.arguments:
            self.cpp_string += ', py::arg("' + eachArg.name + '")'
            if eachArg.default_value is not None:
                self.cpp_string += ' = ' + eachArg.default_value
        self.cpp_string += ')\n'

    def write_cpp_header(self, full_class_name, short_class_name):

        header = "wrapper_header_collection"
#         if self.class_info.full_path is None:
#             header = "wrapper_header_collection"
#         else:
#             header = os.path.basename(self.class_info.full_path).split(".")[0]
        self.cpp_string += '#include <pybind11/pybind11.h>\n'
        self.cpp_string += '#include <pybind11/stl.h>\n'
        self.cpp_string += '#include "' + header + '.hpp"\n'
        self.cpp_string += '#include "' + short_class_name + '.pypp.hpp"\n\n'
        self.cpp_string += 'namespace py = pybind11;\n\n'
        self.cpp_string += 'typedef ' + full_class_name + " "
        self.cpp_string += short_class_name + ";\n"

    def write_cpp_virtual_overides(self, class_decl, short_class_name):

        # Identify any methods needing over-rides, i.e. any that are virtual
        #  here or in a parent.
        methods_needing_override = []
        for eachMemberFunction in class_decl.member_functions(allow_empty=True):
            is_pure_virtual = eachMemberFunction.virtuality == "pure virtual"
            is_virtual = eachMemberFunction.virtuality == "virtual"
            if is_pure_virtual or is_virtual:
                methods_needing_override.append(eachMemberFunction)
            if is_pure_virtual:
                self.is_abstract = True

        if(len(methods_needing_override) > 0):
            self.cpp_string += "class " + short_class_name + "_Overloads : public "
            self.cpp_string += short_class_name + "{\n"
            self.cpp_string += self.indent_1 + "public:\n" + self.indent_1 + "using "
            self.cpp_string += short_class_name + "::" + class_decl.name +";\n\n"

            for eachMethod in methods_needing_override:

                overload_string = "PYBIND11_OVERLOAD"
                if eachMethod.virtuality == "pure virtual":
                    overload_string += "_PURE"

                self.cpp_string += self.indent_2 + eachMethod.return_type.decl_string + " " + eachMethod.name
                self.cpp_string += "("
                num_arg_types = len(eachMethod.argument_types)
                args = eachMethod.arguments

                for idx, eachArg in enumerate(eachMethod.argument_types):
                    self.cpp_string += eachArg.decl_string + " " + args[idx].name
                    if idx < num_arg_types-1:
                        self.cpp_string += ", "
                self.cpp_string += ") override {\n"
                self.cpp_string += self.indent_2 + overload_string + "(\n"
                self.cpp_string += self.indent_2 + eachMethod.return_type.decl_string + ",\n"
                self.cpp_string += self.indent_2 + short_class_name + ",\n"
                self.cpp_string += self.indent_2 + eachMethod.name + ",\n"
                for idx, eachArg in enumerate(eachMethod.argument_types):
                    self.cpp_string += self.indent_2 + args[idx].name
                    if idx < num_arg_types-1:
                        self.cpp_string += ", \n"
                self.cpp_string += self.indent_2 + "\n" + self.indent_2 + ");\n"
                self.cpp_string += self.indent_2 + "}\n"
            self.cpp_string += "\n};\n"
        return len(methods_needing_override) > 0

    def write(self, work_dir):

        if(len(self.class_decls) != len(self.class_full_names)):
            message = 'Not enough class decls added to do write.'
            raise ValueError(message)

        for idx, full_name in enumerate(self.class_full_names):
            short_name = self.class_short_names[idx]
            class_decl = self.class_decls[idx]
            self.hpp_string = ""
            self.cpp_string = ""

            # Add the cpp file header
            self.write_cpp_header(full_name, short_name)

            # Define any virtual function overloads
            needs_overrides = self.write_cpp_virtual_overides(class_decl, short_name)

            # Open the class definition
            self.cpp_string += 'void register_' + short_name + '_class(py::module &m){\n'
            self.cpp_string += self.indent_1 + 'py::class_<' + short_name

            # Add overrides if needed
            if needs_overrides:
                self.cpp_string += ', ' + short_name + '_Overloads'

            # Add shared_ptr support if needed
            if self.has_shared_ptr:
                self.cpp_string += ', std::shared_ptr<' + short_name + ' > '

            # Add base classes if needed
            for eachBase in class_decl.bases:
                if eachBase.related_class.name in self.exposed_class_full_names:
                    self.cpp_string += ', ' + eachBase.related_class.name + " "

            self.cpp_string += ' >(m, "' + short_name + '")\n'

            # Add constructors
            if not self.is_abstract:
                query = declarations.access_type_matcher_t('public')
                for eachConstructor in class_decl.constructors(function=query,
                                                               allow_empty=True):
                    self.write_constructor(eachConstructor)

            # Add public member functions
            query = declarations.access_type_matcher_t('public')
            for eachMemberFunction in class_decl.member_functions(function=query,
                                                                  allow_empty=True):
                exlcuded = False
                if self.class_info.excluded_methods is not None:
                    exlcuded = (eachMemberFunction.name in
                                self.class_info.excluded_methods)
                if not exlcuded:
                    self.write_method(eachMemberFunction, short_name)

            # Close the class definition
            self.cpp_string += self.indent_1 + ';\n'
            self.cpp_string += '}\n'

            # Set up the hpp
            self.write_hpp(short_name)

            # Do the write
            self.do_file_write(work_dir, short_name)
