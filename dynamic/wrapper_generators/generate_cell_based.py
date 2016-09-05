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

    include_classes = ["Cell",
                       "CaBasedCellPopulation<3>",
                       "CaBasedCellPopulation<2>",
                       "StemCellProliferativeType"]

    for eachClass in include_classes:
        builder.class_(eachClass).include()  
        new_name = generate_bindings.template_replace(eachClass)
        if(new_name != eachClass):
            builder.class_(eachClass).rename(new_name) 

    builder.class_("CaBasedCellPopulation<3>").member_functions("GetNode").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("rGetAvailableSpaces").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetNode").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("rGetAvailableSpaces").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()

    return builder