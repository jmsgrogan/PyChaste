#!/usr/bin/env python

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser

def update_builder(builder):

    builder.class_("OutputFileHandler").include()
    builder.class_("OutputFileHandler").member_functions('OpenOutputFile').exclude()
    
    builder.class_("RelativeTo").include()
    builder.class_("FileFinder").include()
    builder.class_("FileFinder").member_functions('FindMatches').exclude()
    
    #todo exlude boost::filesystem::path constructor

    return builder