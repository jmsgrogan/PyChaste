"""
This file contains a list of classes that are to be wrapped.

Each class includes metadata such as template arguments, excluded methods,
methods with special pointer management requirements, and any special
declaration code needed for wrapping. A minimal case is just to
specify the class name and component it will belong to.
"""

import os
import fnmatch
try:
    import cPickle as pickle
except:
    import pickle


class CppClassInfo():

    """
    A container for each class to be wrapped. Include the class name,
    template arguments and specify if any custom code is needed to
    complete the wrapping.

    Template arguments are specified in a list of lists. For example if a
    class is templated over a single dimension <DIM> then the template
    list might look like [[2], [3]]. If templated over two dimensions <ELEMENT, DIM>
    <SPACE, DIM> it might look like [[2,2], [3,3]]. If templated over type it might look
    like [[UniformCellCycleModel, 2], [SimpleOxygenBasedCellCycleModel, 2]]

    :param: name - the class name, for example AbstractCellPopulation
    :param: component - which module the class will be in, e.g. ode, pde, core, cell_based
    :param: template_args - a list of lists containing the template arguments
    :param: skip_wrapping - do not wrap the class if True. The class can still go in include files
    :param: excluded_methods - a list of methods not to be wrapped
    :param: excluded_variables - a list of public member variables not to be wrapped
    :param: pointer_return_methods - a list of lists of methods with special pointer
    or reference return requirements and the name of the Py++ method for managing them.
    :param: needs_include_file - should the class be added to the include file, mostly yes
    :param: include_file_only - should the class only be added to the include file and nothing else
    :param: declaration_code - a list of extra Boost Python wrapper codes to be added to the autowrapper
    :param: needs_instantiation - does the class need instantiation in the header, mostly True for templated
    classes
    """

    def __init__(self, name, component=None, template_args=None,
                 skip_wrapping=False,
                 excluded_methods=None, excluded_variables=None,
                 pointer_return_methods=None,
                 needs_include_file=True, include_file_only=False,
                 declaration_code=None,
                 needs_instantiation=True, name_override=None,
                 include_vec_ptr_self=False,
                 include_ptr_self=False, include_raw_ptr_self=False):

        self.name = name
        self.component = component
        self.template_args = template_args
        self.skip_wrapping = skip_wrapping
        self.excluded_methods = excluded_methods
        self.excluded_variables = excluded_variables
        self.needs_include_file = needs_include_file
        self.pointer_return_methods = pointer_return_methods
        self.include_file_only = include_file_only
        self.declaration_code = declaration_code
        self.needs_instantiation = needs_instantiation
        self.full_path = None
        self.name_override = name_override
        self.include_vec_ptr_self = include_vec_ptr_self
        self.include_ptr_self = include_ptr_self
        self.include_raw_ptr_self = include_raw_ptr_self
        self.name_replacements = {"double": "Double",
                                  "unsigned int": "Unsigned",
                                  "Unsigned int": "Unsigned",
                                  "unsigned": "Unsigned",
                                  "double": "Double",
                                  "std::vector": "Vector",
                                  "std::pair": "Pair",
                                  "std::map": "Map",
                                  "std::string": "String",
                                  "boost::shared_ptr": "SharedPtr",
                                  "*": "Ptr",
                                  "c_vector": "CVector",
                                  "std::set": "Set"}

    def get_short_names(self):

        """
        Return the name of the class as it will appear on the Python side. This
        collapses template arguements, separating them by underscores and removes
        special characters. The return type is a list, as a class can have multiple
        names if it is templated.
        """

        if self.template_args is None:
            if self.name_override is None:
                return [self.name]
            else:
                return [self.name_override]

        names = []
        for eachTemplateArg in self.template_args:
            template_string = ""
            for idx, eachTemplateEntry in enumerate(eachTemplateArg):

                # Do standard translations
                current_name = str(eachTemplateEntry)
                for eachReplacementString in self.name_replacements.keys():
                    replacement = self.name_replacements[eachReplacementString]
                    current_name = current_name.replace(eachReplacementString,
                                                        replacement)

                cleaned_entry = current_name.translate(None, "<>:,")
                cleaned_entry = cleaned_entry.replace(" ", "")
                if len(cleaned_entry) > 1:
                    first_letter = cleaned_entry[0].capitalize()
                    cleaned_entry = first_letter + cleaned_entry[1:]
                template_string += str(cleaned_entry)
                if(idx != len(eachTemplateArg)-1):
                    template_string += "_"

            current_name = self.name
            if self.name_override is not None:
                current_name = self.name_override

            # Do standard translations
            for eachReplacementString in self.name_replacements.keys():
                replacement = self.name_replacements[eachReplacementString]
                current_name = current_name.replace(eachReplacementString,
                                                    replacement)

            # Strip templates and scopes
            cleaned_name = current_name.translate(None, "<>:,")
            cleaned_name = cleaned_name.replace(" ", "")
            if len(cleaned_name) > 1:
                cleaned_name = cleaned_name[0].capitalize()+cleaned_name[1:]
            names.append(cleaned_name+template_string)
        return names

    def get_full_names(self):

        """
        Return the name (declaration) of the class as it appears on the C++ side.
        The return type is a list, as a class can have multiple
        names (declarations) if it is templated.
        """

        if self.template_args is None:
            return [self.name]

        names = []
        for eachTemplateArg in self.template_args:
            template_string = "<"
            for idx, eachTemplateEntry in enumerate(eachTemplateArg):
                template_string += str(eachTemplateEntry)
                if(idx == len(eachTemplateArg)-1):
                    template_string += " >"
                else:
                    template_string += ","
            names.append(self.name + template_string)
        return names

    def needs_header_file_instantiation(self):

        """
        Does this class need to be instantiated in the header file
        """

        return ((self.template_args is not None) and
                (not self.include_file_only) and
                (self.needs_instantiation))

    def needs_header_file_typdef(self):

        """
        Does this class need to be typdef'd with a nicer name in the header
        file. All template classes need this.
        """

        cond1 = (self.template_args is not None) and (not
                                                      self.include_file_only)
        cond2 = (self.include_vec_ptr_self or self.include_ptr_self or
                 self.include_raw_ptr_self)

        return cond1 or cond2

    def needs_auto_wrapper_generation(self):

        """
        Does this class need a wrapper to be autogenerated.
        """

        return (not self.include_file_only) and (not self.skip_wrapping)


class ClassInfoHelper():

    """
    This attempts to automatically fill in some class info based on
    simple analysis of the source tree.
    """

    def __init__(self, source_root, wrapper_root, class_info_collection):

        self.source_root = source_root
        self.wrapper_root = wrapper_root
        self.class_info_collection = class_info_collection

        # For covenience collect class info in a dict keyed by name
        self.class_dict = {}
        for eachClass in self.class_info_collection:
            self.class_dict[eachClass.name] = eachClass

        # Try to identify modules automatically
        self.module_keys = {"pde": "pde",
                            "ode": "ode",
                            "cell_based": "cell_based",
                            "mesh": "mesh",
                            "linalg": "core",
                            "global": "core",
                            "tutorial": "tutorial",
                            "visualization": "visualization",
                            "extra": "extra"}
        self.attempt_auto_module_id = True

        # Template auto-replace
        same_dims_1 = [[2], [3]]  # i.e. <DIM>
        same_dims_2 = [[2, 2], [3, 3]]  # i.e. <ELEMENT_DIM, SPACE_DIM>
        self.template_substitutions = {"<unsigned ELEMENT_DIM, unsigned SPACE_DIM>":
                                       same_dims_2,
                                       "<unsigned DIM, unsigned DIM>":
                                       same_dims_2,
                                       "unsigned ELEMENT_DIM, unsigned SPACE_DIM=ELEMENT_DIM":
                                       same_dims_2,
                                       "<unsigned SPACE_DIM>":
                                       same_dims_1,
                                       "<unsigned DIM>":
                                       same_dims_1}

    def assign_include_paths(self):

        for root, _, filenames in os.walk(self.source_root, followlinks=True):
            for filename in fnmatch.filter(filenames, '*.hpp'):
                filename_no_ext = os.path.splitext(filename)[0]
                if filename_no_ext in self.class_dict.keys():
                    full_path = os.path.join(root, filename)
                    self.class_dict[filename_no_ext].full_path = full_path

    def assign_module_by_directory(self):

        # Set the component name
        for eachClass in self.class_info_collection:
            if eachClass.component is None and eachClass.full_path is not None:
                for eachKey in self.module_keys.keys():
                    if "/" + eachKey + "/" in eachClass.full_path:
                        eachClass.component = self.module_keys[eachKey]

    def auto_expand_templates(self):

        for eachClass in self.class_info_collection:

            # Skip any classes with pre-defined template args
            no_template = eachClass.template_args is None
            has_path = eachClass.full_path is not None
            if not (no_template and has_path):
                continue

            if not os.path.exists(eachClass.full_path):
                continue

            f = open(eachClass.full_path)
            lines = (line.rstrip() for line in f)  # Remove blank lines

            lines = list(line for line in lines if line)
            for idx, eachLine in enumerate(lines):
                stripped_line = eachLine.replace(" ", "")
                if idx+1 < len(lines):
                    stripped_next = lines[idx+1].replace(" ", "")
                else:
                    continue

                for eachTemplateString in self.template_substitutions.keys():
                    cleaned_string = eachTemplateString.replace(" ", "")
                    if cleaned_string in stripped_line:
                        class_string = "class" + eachClass.name
                        class_decl_next = class_string + ":" in stripped_next
                        class_decl_whole = class_string == stripped_next
                        if class_decl_next or class_decl_whole:
                            template_args = self.template_substitutions[eachTemplateString]
                            eachClass.template_args = template_args
                            break
            f.close()

    def do_custom_template_substitution(self):

        # Add cell generator templates for each cell cycle model
        concrete_cell_cycle_classes = []
        for eachClass in self.class_info_collection:
            in_cell_cycle_dir = False
            if eachClass.full_path is not None:
                source_path = "/cell_based/src/cell/cycle"
                in_cell_cycle_dir = source_path in eachClass.full_path

            name_slice = eachClass.name[len(eachClass.name)-14:]
            cell_cycle_class = name_slice == "CellCycleModel"
            not_abstract = "Abstract" not in eachClass.name
            if in_cell_cycle_dir and not_abstract and cell_cycle_class:
                    concrete_cell_cycle_classes.append(eachClass.name)

        if "CellsGenerator" in self.class_dict.keys():
            if self.class_dict["CellsGenerator"].template_args is None:
                self.class_dict["CellsGenerator"].template_args = []
                for eachCycleModel in concrete_cell_cycle_classes:
                    ccm2 = [eachCycleModel, 2]
                    ccm3 = [eachCycleModel, 3]
                    self.class_dict["CellsGenerator"].template_args.append(ccm2)
                    self.class_dict["CellsGenerator"].template_args.append(ccm3)

    def generate_class_info(self):

        self.assign_include_paths()

        if self.attempt_auto_module_id:
            self.assign_module_by_directory()

        self.auto_expand_templates()
        self.do_custom_template_substitution()

        with open(self.wrapper_root + "/class_data.p", 'wb') as fp:
            pickle.dump(self.class_info_collection, fp)