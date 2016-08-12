#!/usr/bin/env python

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser

def update_builder(builder):

    include_classes = ["AbstractOdeSystem",
                       "AbstractOdeSystemInformation",
                       "AbstractPythonOdeSystemInformation"]
    
    for eachClass in include_classes:
        builder.class_(eachClass).include()
        
    return builder