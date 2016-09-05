#!/usr/bin/env python

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser
import generate_bindings

def update_builder(builder):
    
    include_classes = ["OutputFileHandler",
               "RelativeTo",
               "FileFinder", 
               "SimulationTime"]
    
    for eachClass in include_classes:
        builder.class_(eachClass).include()  
        new_name = generate_bindings.template_replace(eachClass)
        if(new_name != eachClass):
            builder.class_(eachClass).rename(new_name) 
    
    builder.class_("OutputFileHandler").member_functions('OpenOutputFile').exclude()
    builder.class_("FileFinder").member_functions('FindMatches').exclude()
    builder.class_("SimulationTime").member_function("Instance").exclude()

    return builder