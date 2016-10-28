#!/usr/bin/env python

"""Copyright (c) 2005-2016, University of Oxford.
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
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser
import generate_bindings

def update_builder(builder):

    include_classes = ["Cell",
                       "AbstractOnLatticeCellPopulation<3>",
                       "AbstractOnLatticeCellPopulation<2>",
                       "CaBasedCellPopulation<3>",
                       "CaBasedCellPopulation<2>",
                       "StemCellProliferativeType",
                       "DefaultCellProliferativeType",
                       "UniformCellCycleModel",
                       "CellPropertyCollection",
                       "SimulationTime",
                       "GenericCellsGenerator<2>",
                       "GenericCellsGenerator<3>",
                       "AbstractCellProperty",
                       "AbstractCellCycleModel",
                       "OnLatticeSimulation<2>",
                       "OnLatticeSimulation<3>",
                       "AbstractCellPopulation<2,2>",
                       "AbstractCellPopulation<3,3>",
                       "AbstractCellBasedSimulation<2,2>",
                       "AbstractCellBasedSimulation<3,3>",
                       "Identifiable",
                       "DiffusionCaUpdateRule<2>",
                       "AbstractCaUpdateRule<2>",
                       "AbstractUpdateRule<2>",
                       "VtkSceneModifier<2>",
                       "VtkSceneModifier<3>",
                       "AbstractCellBasedSimulationModifier<2,2>",
                       "AbstractCellBasedSimulationModifier<3,3>",
                       "NodeBasedCellPopulation<2>",
                       "NodeBasedCellPopulation<3>",
                       "AbstractCentreBasedCellPopulation<2,2>",
                       "AbstractCentreBasedCellPopulation<3,3>",
                       "AbstractOffLatticeCellPopulation<2,2>",
                       "AbstractOffLatticeCellPopulation<3,3>",
                       "OffLatticeSimulation<2,2>",
                       "OffLatticeSimulation<3,3>",
                       "MeshBasedCellPopulation<2,2>",
                       "MeshBasedCellPopulation<3,3>",
                       "VertexBasedCellPopulation<2>",
                       "VertexBasedCellPopulation<3>",
                       "PottsBasedCellPopulation<2>",
                       "PottsBasedCellPopulation<3>",
                       "AbstractTwoBodyInteractionForce<2,2>",
                       "AbstractTwoBodyInteractionForce<3,3>",
                       "GeneralisedLinearSpringForce<2,2>",
                       "GeneralisedLinearSpringForce<3,3>",
                       "NagaiHondaForce<2>",
                       "NagaiHondaForce<3>",
                       "AbstractTargetAreaModifier<2>",
                       "AbstractTargetAreaModifier<3>",
                       "SimpleTargetAreaModifier<2>",
                       "SimpleTargetAreaModifier<3>",
                       ]
    
    for eachClass in include_classes:
        builder.class_(eachClass).include()  
        new_name = generate_bindings.template_replace(eachClass)
        if(new_name != eachClass):
            builder.class_(eachClass).rename(new_name) 

    builder.classes( lambda x: x.name in ("Iterator",)).exclude()
    builder.class_("CellsGenerator<UniformCellCycleModel, 2>").include()  
    builder.class_("CellPropertyCollection").member_functions("GetCellPropertyRegistry").exclude()
    
    builder.class_("AbstractCellBasedSimulation<2,2>").constructors().exclude()
    builder.class_("AbstractCellBasedSimulation<2,2>").member_functions('GetSimulationModifiers').exclude()
    builder.class_("AbstractCellBasedSimulation<3,3>").constructors().exclude()
    builder.class_("AbstractCellBasedSimulation<3,3>").member_functions('GetSimulationModifiers').exclude()
    
    builder.class_("AbstractCellPopulation<2,2>").member_functions("GetNode").exclude()
    builder.class_("AbstractCellPopulation<2,2>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("AbstractCellPopulation<2,2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("AbstractCellPopulation<2,2>").member_functions(lambda decl: decl.name.startswith( "rGetCells")).exclude()
    builder.class_("AbstractCellPopulation<2,2>").constructors().exclude()
    builder.class_("AbstractCellPopulation<3,3>").member_functions("GetNode").exclude()
    builder.class_("AbstractCellPopulation<3,3>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("AbstractCellPopulation<3,3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("AbstractCellPopulation<3,3>").member_functions(lambda decl: decl.name.startswith( "rGetCells")).exclude()
    builder.class_("AbstractCellPopulation<3,3>").constructors().exclude()
    builder.class_("AbstractOnLatticeCellPopulation<2>").constructors().exclude()
    builder.class_("AbstractOnLatticeCellPopulation<2>").member_functions(function=lambda decl:decl.virtuality == "virtual").exclude()
    builder.class_("AbstractOnLatticeCellPopulation<3>").constructors().exclude()
    
    builder.class_("AbstractCentreBasedCellPopulation<2,2>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("AbstractCentreBasedCellPopulation<3,3>").member_functions("GetNodeCorrespondingToCell").exclude()
    
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetNode").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("rGetAvailableSpaces").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("CaBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetNode").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetNodeCorrespondingToCell").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("rGetAvailableSpaces").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions("GetTetrahedralMeshForPdeModifier").exclude()
    builder.class_("CaBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    
    builder.class_("NodeBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("NodeBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("NodeBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("NodeBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("NodeBasedCellPopulation<2>").member_functions("GetNode").exclude()
    builder.class_("NodeBasedCellPopulation<3>").member_functions("GetNode").exclude()
    builder.class_("NodeBasedCellPopulation<2>").member_functions("rGetNodePairs").exclude()
    builder.class_("NodeBasedCellPopulation<3>").member_functions("rGetNodePairs").exclude()
    
    builder.class_("MeshBasedCellPopulation<2,2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("MeshBasedCellPopulation<3,3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("MeshBasedCellPopulation<2,2>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("MeshBasedCellPopulation<3,3>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("MeshBasedCellPopulation<2,2>").member_functions("GetNode").exclude()
    builder.class_("MeshBasedCellPopulation<3,3>").member_functions("GetNode").exclude()
    builder.class_("MeshBasedCellPopulation<2,2>").member_functions("GetVoronoiTessellation").exclude()
    builder.class_("MeshBasedCellPopulation<3,3>").member_functions("GetVoronoiTessellation").exclude()
    builder.class_("MeshBasedCellPopulation<2,2>").member_functions("rGetNodePairs").exclude()
    builder.class_("MeshBasedCellPopulation<3,3>").member_functions("rGetNodePairs").exclude()
    
    builder.class_("VertexBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("VertexBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
    builder.class_("VertexBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("VertexBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("VertexBasedCellPopulation<2>").member_functions("GetNode").exclude()
    builder.class_("VertexBasedCellPopulation<3>").member_functions("GetNode").exclude()
    builder.class_("VertexBasedCellPopulation<2>").member_functions("GetElement").exclude()
    builder.class_("VertexBasedCellPopulation<3>").member_functions("GetElement").exclude() 
    builder.class_("VertexBasedCellPopulation<2>").member_functions("GetElementCorrespondingToCell").exclude()
    builder.class_("VertexBasedCellPopulation<3>").member_functions("GetElementCorrespondingToCell").exclude()         

    builder.class_("PottsBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith("rGetMesh")).exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith("rGetMesh")).exclude()
    builder.class_("PottsBasedCellPopulation<2>").member_functions(lambda decl: decl.name.startswith("GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions(lambda decl: decl.name.startswith("GetTetrahedralMeshForPdeModifier")).exclude()
    builder.class_("PottsBasedCellPopulation<2>").member_functions("GetNode").exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions("GetNode").exclude()
    builder.class_("PottsBasedCellPopulation<2>").member_functions("GetElement").exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions("GetElement").exclude() 
    builder.class_("PottsBasedCellPopulation<2>").member_functions("GetElementTessellation").exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions("GetElementTessellation").exclude() 
    builder.class_("PottsBasedCellPopulation<2>").member_functions("GetMutableMesh").exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions("GetMutableMesh").exclude()     
    builder.class_("PottsBasedCellPopulation<2>").member_functions("GetElementCorrespondingToCell").exclude()
    builder.class_("PottsBasedCellPopulation<3>").member_functions("GetElementCorrespondingToCell").exclude()     

    builder.class_("Cell").member_functions("rGetCellPropertyCollection").exclude()
    builder.class_("Cell").member_functions("GetCellCycleModel").exclude()
    builder.class_("Cell").member_functions("GetSrnModel").exclude()
    
    builder.class_("AbstractCellCycleModel").member_function("CreateCellCycleModel").call_policies = call_policies.return_value_policy(call_policies.manage_new_object)
    builder.class_("UniformCellCycleModel").member_function("CreateCellCycleModel").call_policies = call_policies.return_value_policy(call_policies.manage_new_object)
    builder.class_("SimulationTime").member_function("Instance").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)
    
    builder.class_("AbstractCellProperty").member_functions("IsType").exclude()

    return builder