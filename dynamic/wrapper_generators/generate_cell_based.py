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

def do_cell_cycle_models(builder, default_pointer_policy = call_policies.return_value_policy(call_policies.manage_new_object)):
    
    abstract_classes = ["AbstractCellCycleModel",
                       "AbstractPhaseBasedCellCycleModel",
                       "AbstractSimpleCellCycleModel",
                       "AbstractSimplePhaseBasedCellCycleModel",
                       "AbstractSimpleGenerationalCellCycleModel",]
    
    concrete_classes = ["UniformCellCycleModel", 
                       "SimpleOxygenBasedCellCycleModel",
                       "UniformG1GenerationalCellCycleModel",
                       "NoCellCycleModel"] 
    
    # Set up generator names
    generator_classes = []
    for eachClass in concrete_classes:
        generator_classes.append("CellsGenerator<" + eachClass + ", 2>") 
        generator_classes.append("CellsGenerator<" + eachClass + ", 3>") 
    
    # Include listed classes
    all_classes = abstract_classes + concrete_classes + generator_classes
    for eachClass in all_classes:
        builder.class_(eachClass).include()  
    
    # Rename template classes
    generate_bindings.template_replace_list(builder, all_classes)  
    
    class_collection = []
    for eachClass in all_classes:
        class_collection.append(eachClass)
    
    # Add call policies for pointer return types
    for eachClass in concrete_classes + ["AbstractCellCycleModel"]:
        builder.class_(eachClass).member_function("CreateCellCycleModel").call_policies = default_pointer_policy
        
    return class_collection
        
def do_cell_populations(builder, default_pointer_policy = call_policies.return_value_policy(call_policies.manage_new_object)):  
          
    abstract_single_template_classes = ["AbstractOnLatticeCellPopulation",]
    
    abstract_two_template_classes = ["AbstractCellPopulation",
                                    "AbstractCentreBasedCellPopulation",
                                    "AbstractOffLatticeCellPopulation",]
    
    concrete_single_template_classes = ["NodeBasedCellPopulation", 
                                        "CaBasedCellPopulation",
                                        "VertexBasedCellPopulation",
                                        "PottsBasedCellPopulation",
                                        "MeshBasedCellPopulationWithGhostNodes"] 
    
    conconrete_two_template_classes = ["MeshBasedCellPopulation",]
    
    templated_abstract_classes = []
    for eachclass in abstract_single_template_classes:
        templated_abstract_classes.append(eachclass+"<2>")
        templated_abstract_classes.append(eachclass+"<3>")
    for eachclass in abstract_two_template_classes:
        templated_abstract_classes.append(eachclass+"<2,2>")
        templated_abstract_classes.append(eachclass+"<3,3>")
        
    templated_concrete_classes = []
    for eachclass in concrete_single_template_classes:
        templated_concrete_classes.append(eachclass+"<2>")
        templated_concrete_classes.append(eachclass+"<3>")
    for eachclass in conconrete_two_template_classes:
        templated_concrete_classes.append(eachclass+"<2,2>")
        templated_concrete_classes.append(eachclass+"<3,3>")
        
    # Include listed classes
    all_classes = templated_abstract_classes + templated_concrete_classes
    for eachClass in all_classes:
        builder.class_(eachClass).include()  
    
    # Rename template classes
    generate_bindings.template_replace_list(builder, all_classes)  
    
    class_collection = []
    for eachClass in all_classes:
        class_collection.append(eachClass)
    
    # Exclude abstract constuctors
    for eachClass in templated_abstract_classes:
        builder.class_(eachClass).constructors().exclude()
        
    voronoi_writer_prefix = 'def("AddPopulationWriterVoronoiDataWriter", &'
    voronoi_writer_suffix = '::AddPopulationWriter<VoronoiDataWriter>)'
    label_writer_prefix = 'def("AddCellWriterCellLabelWriter", &'
    label_writer_suffix = '::AddCellWriter<CellLabelWriter>)'
    
    for eachTemplate in ["<2,2>", "<3,3>"]:
        builder.class_("AbstractCellPopulation"+eachTemplate).member_functions("GetNode").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
        builder.class_("AbstractCellPopulation"+eachTemplate).member_functions("GetTetrahedralMeshForPdeModifier").exclude()
        builder.class_("AbstractCellPopulation"+eachTemplate).member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
        builder.class_("AbstractCellPopulation"+eachTemplate).member_functions(lambda decl: decl.name.startswith( "rGetCells")).exclude()
        builder.class_("AbstractCentreBasedCellPopulation"+eachTemplate).member_functions("GetNodeCorrespondingToCell").exclude()
        builder.class_("MeshBasedCellPopulation"+eachTemplate).member_functions(lambda decl: decl.name.startswith( "rGetMesh")).exclude()
        builder.class_("MeshBasedCellPopulation"+eachTemplate).add_registration_code(voronoi_writer_prefix + 'MeshBasedCellPopulation' + eachTemplate + voronoi_writer_suffix)      
        builder.class_("MeshBasedCellPopulation"+eachTemplate).member_functions(lambda decl: decl.name.startswith( "GetTetrahedralMeshForPdeModifier")).exclude()
        builder.class_("MeshBasedCellPopulation"+eachTemplate).member_functions("GetNode").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
        builder.class_("MeshBasedCellPopulation"+eachTemplate).member_functions("GetVoronoiTessellation").exclude()
        builder.class_("MeshBasedCellPopulation"+eachTemplate).member_functions("rGetNodePairs").exclude()
    
    # Populations
    for eachTemplate in ["<2>", "<3>"]:
        for eachPopulation in ["CaBasedCellPopulation", "NodeBasedCellPopulation", "VertexBasedCellPopulation", "PottsBasedCellPopulation"]:
            builder.class_(eachPopulation+eachTemplate).member_functions("GetNode").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
            builder.class_(eachPopulation+eachTemplate).member_functions(lambda decl: decl.name.startswith("rGetMesh")).exclude()
            builder.class_(eachPopulation+eachTemplate).member_functions(lambda decl: decl.name.startswith("GetTetrahedralMeshForPdeModifier")).exclude()
        builder.class_("CaBasedCellPopulation"+eachTemplate).member_functions("GetNodeCorrespondingToCell").exclude()
        builder.class_("CaBasedCellPopulation"+eachTemplate).member_functions("rGetAvailableSpaces").exclude()
        builder.class_("NodeBasedCellPopulation"+eachTemplate).member_functions("rGetNodePairs").exclude()
        builder.class_("VertexBasedCellPopulation"+eachTemplate).member_functions("GetElement").exclude()   
        builder.class_("VertexBasedCellPopulation"+eachTemplate).member_functions("GetElementCorrespondingToCell").exclude()        
        builder.class_("PottsBasedCellPopulation"+eachTemplate).member_functions("GetElement").exclude()  
        builder.class_("PottsBasedCellPopulation"+eachTemplate).member_functions("GetElementCorrespondingToCell").exclude()    
        builder.class_("PottsBasedCellPopulation"+eachTemplate).member_functions("GetElementTessellation").exclude()
        builder.class_("PottsBasedCellPopulation"+eachTemplate).member_functions("GetMutableMesh").exclude()    
        builder.class_("PottsBasedCellPopulation"+eachTemplate).add_registration_code(label_writer_prefix + 'PottsBasedCellPopulation' + eachTemplate + label_writer_suffix) 
        builder.class_("MeshBasedCellPopulationWithGhostNodes"+eachTemplate).add_registration_code(voronoi_writer_prefix + 'MeshBasedCellPopulationWithGhostNodes' + eachTemplate + voronoi_writer_suffix) 

    return class_collection

def do_cell_properties(builder):
    
    include_classes = ["AbstractCellProperty",                   
                       "AbstractCellProliferativeType", 
                       "StemCellProliferativeType", 
                       "DefaultCellProliferativeType",
                       "TransitCellProliferativeType",
                       "DifferentiatedCellProliferativeType",
                       "AbstractCellMutationState",
                       "ApcOneHitCellMutationState",
                       "ApcTwoHitCellMutationState",
                       "BetaCateninOneHitCellMutationState",
                       "WildTypeCellMutationState",]
    
    for eachClass in include_classes:
        builder.class_(eachClass).include()  
        
    builder.class_("AbstractCellProperty").member_functions("IsType").exclude()
    
    class_collection = []
    for eachClass in include_classes:
        class_collection.append(eachClass)
        
    return class_collection

def update_builder(builder):

    non_template_classes = ["Identifiable",
                           "Cell",
                           "CellPropertyCollection",
                           "CellId",
                           "CellLabel",
                           "CellData",
                           "CellAncestor",
                           "CellPropertyRegistry",
                           "SimulationTime", ]
    
    single_template_classes = ["OnLatticeSimulation",
                               "DiffusionCaUpdateRule",
                               "AbstractCaUpdateRule",
                               "AbstractUpdateRule",
                               "VtkSceneModifier",
                               "AbstractTargetAreaModifier",
                               "SimpleTargetAreaModifier",
                               "NagaiHondaForce",
                               "AbstractPottsUpdateRule",
                               "VolumeConstraintPottsUpdateRule",
                               "SurfaceAreaConstraintPottsUpdateRule",
                               "DifferentialAdhesionPottsUpdateRule",
                               "AdhesionPottsUpdateRule",
                               "SphereGeometryBoundaryCondition",
                               "AbstractCellKiller",
                               "PlaneBasedCellKiller",
                               "ApoptoticCellKiller",
                               "RandomCellKiller",
                               "CellwiseSourceEllipticPde",
                               "AbstractPdeModifier",
                               "AbstractGrowingDomainPdeModifier",
                               "EllipticGrowingDomainPdeModifier"]

    two_template_classes = ["AbstractCellBasedSimulation",
                           "OffLatticeSimulation",
                           "AbstractCellBasedSimulationModifier",
                           "AbstractTwoBodyInteractionForce",
                           "AbstractForce",
                           "GeneralisedLinearSpringForce",
                           "AbstractCellPopulationBoundaryCondition",
                           "PlaneBoundaryCondition",
                           "AttractingPlaneBoundaryCondition",
                           "AbstractLinearEllipticPde",
                           "AbstractLinearPde"]

    builder.free_function("GetPetscMatForWrapper").call_policies = call_policies.return_value_policy( call_policies.return_opaque_pointer )
    builder.free_function("GetPetscVecForWrapper").call_policies = call_policies.return_value_policy( call_policies.return_opaque_pointer )

    class_collection = []
    for eachClass in non_template_classes:
        builder.class_(eachClass).include()  
        class_collection.append(eachClass)

    expanded_template_classes = []
    for eachClass in single_template_classes:
        builder.class_(eachClass+"<2>").include()  
        expanded_template_classes.append(eachClass+"<2>")
        class_collection.append(eachClass+"2")
        builder.class_(eachClass+"<3>").include()  
        expanded_template_classes.append(eachClass+"<3>")
        class_collection.append(eachClass+"3")
        
    for eachClass in two_template_classes:
        builder.class_(eachClass+"<2,2>").include() 
        expanded_template_classes.append(eachClass+"<2,2>")
        class_collection.append(eachClass+"2_2")
        builder.class_(eachClass+"<3,3>").include()  
        expanded_template_classes.append(eachClass+"<3,3>")
        class_collection.append(eachClass+"3_3")
    
    generate_bindings.template_replace_list(builder, expanded_template_classes)  

    # Set pointer policy
    default_pointer_policy = call_policies.return_value_policy(call_policies.manage_new_object)
                                                               
    # Exclude all iterators
    builder.classes( lambda x: x.name in ("Iterator",)).exclude()
    
    # Cells and cell properties
    builder.class_("Cell").member_functions("rGetCellPropertyCollection").exclude()
    builder.class_("Cell").member_functions("GetCellCycleModel").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_("Cell").member_functions("GetSrnModel").exclude()
    builder.class_("CellPropertyRegistry").member_function("Instance").call_policies = default_pointer_policy
    builder.class_("CellPropertyRegistry").member_functions("rGetAllCellProperties").exclude()
    builder.class_("CellPropertyRegistry").member_functions("TakeOwnership").exclude()  
    builder.class_("CellPropertyRegistry").member_functions("Get").exclude()  
    builder.class_("CellPropertyCollection").member_functions("GetCellPropertyRegistry").exclude()
    
    local_classes = do_cell_properties(builder)
    class_collection.extend(local_classes)
    local_classes = do_cell_cycle_models(builder, default_pointer_policy)
    class_collection.extend(local_classes)
    local_classes = do_cell_populations(builder, default_pointer_policy)
    class_collection.extend(local_classes)
      
    # Simulations
    builder.class_("SimulationTime").member_function("Instance").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)
    for eachTemplate in ["<2,2>", "<3,3>"]:
        builder.class_("AbstractCellBasedSimulation"+eachTemplate).constructors().exclude()
        builder.class_("AbstractCellBasedSimulation"+eachTemplate).member_functions('GetSimulationModifiers').exclude()
        builder.class_("AbstractCellPopulationBoundaryCondition"+eachTemplate).member_functions('GetCellPopulation').call_policies = default_pointer_policy   

    for eachTemplate in ["<2>", "<3>"]: 
        builder.class_("AbstractCellKiller"+eachTemplate).member_functions('GetCellPopulation').call_policies = default_pointer_policy  
        builder.class_("AbstractPdeModifier"+eachTemplate).member_functions('GetSolution').exclude()  
        builder.class_("AbstractPdeModifier"+eachTemplate).member_functions('GetFeMesh').exclude() 
        builder.class_("AbstractPdeModifier"+eachTemplate).constructors().exclude()  
        builder.class_('AbstractPdeModifier'+eachTemplate).calldefs().use_default_arguments=False 
        builder.class_('CellwiseSourceEllipticPde'+eachTemplate).calldefs().use_default_arguments=False   
        builder.class_('AbstractGrowingDomainPdeModifier'+eachTemplate).calldefs().use_default_arguments=False 
        builder.class_("AbstractGrowingDomainPdeModifier"+eachTemplate).constructors().exclude()      
        #builder.class_('EllipticGrowingDomainPdeModifier'+eachTemplate).calldefs().use_default_arguments=False    
        builder.class_("EllipticGrowingDomainPdeModifier"+eachTemplate).member_functions('ConstructBoundaryConditionsContainer').exclude()  
        builder.class_("EllipticGrowingDomainPdeModifier"+eachTemplate).add_declaration_code("BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Vec )")
        builder.class_("EllipticGrowingDomainPdeModifier"+eachTemplate).add_declaration_code("BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Mat )")

    return builder, class_collection