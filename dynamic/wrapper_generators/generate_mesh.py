#!/usr/bin/env python

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser

def update_builder(builder):

    builder.class_("ChastePoint<3>").include()
    chaste_point = builder.class_("ChastePoint<3>")
    builder.class_("ChastePoint<3>").rename("ChastePoint3")

    # Do not return the non-const reference to the location
    returns_non_const_ref = chaste_point.member_functions(return_type = "::boost::numeric::ublas::c_vector<double, 3> &")
    returns_non_const_ref.exclude()
    
    # Debug output
    # builder.print_declarations(chaste_point)
        
    return builder