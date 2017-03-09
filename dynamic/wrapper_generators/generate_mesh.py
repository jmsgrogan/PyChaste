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
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser
import generate_bindings

def update_builder(builder):

    include_classes = ["ChastePoint<3>", 
                       "Node<3>",
                       "NodeAttributes<3>",
                       "PottsMesh<3>",
                       "SharedPottsMeshGenerator<3>",
                       "ChastePoint<2>",
                       "Node<2>",
                       "NodeAttributes<2>",
                       "PottsMesh<2>",
                       "SharedPottsMeshGenerator<2>",
                       "NodesOnlyMesh<2>",
                       "NodesOnlyMesh<3>",
                       "MutableMesh<2,2>",
                       "MutableMesh<3,3>",
                       "TetrahedralMesh<2,2>",
                       "TetrahedralMesh<3,3>",
                       "AbstractTetrahedralMesh<2,2>",
                       "AbstractTetrahedralMesh<3,3>",
                       "AbstractMesh<2,2>",
                       "AbstractMesh<3,3>",
                       "VertexMesh<2,2>",
                       "VertexMesh<3,3>",
                       "MutableVertexMesh<2,2>",
                       "MutableVertexMesh<3,3>",
                       "Cylindrical2dVertexMesh",
                       "SharedCylindricalHoneycombVertexMeshGenerator"
                       ]

    class_collection = []
    for eachClass in include_classes:
        builder.class_(eachClass).include()  
        new_name = generate_bindings.template_replace(eachClass)
        class_collection.append(new_name)
        if(new_name != eachClass):
            builder.class_(eachClass).rename(new_name) 
    
    builder.class_('SharedPottsMeshGenerator<3>').include()  
    builder.class_('SharedPottsMeshGenerator<3>').rename("PottsMeshGenerator3")
    builder.class_('SharedPottsMeshGenerator<2>').include()  
    builder.class_('SharedPottsMeshGenerator<2>').rename("PottsMeshGenerator2")
    builder.class_('SharedHoneycombMeshGenerator').include()  
    builder.class_('SharedHoneycombMeshGenerator').rename("HoneycombMeshGenerator")
    builder.class_('SharedHoneycombVertexMeshGenerator').include()  
    builder.class_('SharedHoneycombVertexMeshGenerator').rename("HoneycombVertexMeshGenerator")
    builder.class_('SharedCylindricalHoneycombVertexMeshGenerator').include()  
    builder.class_('SharedCylindricalHoneycombVertexMeshGenerator').rename("CylindricalHoneycombVertexMeshGenerator")

    # Do not return the non-const reference to the location
    returns_non_const_ref = builder.class_('ChastePoint<3>').member_functions(return_type = "::boost::numeric::ublas::c_vector<double, 3> &")
    returns_non_const_ref.exclude()
    returns_non_const_ref = builder.class_('ChastePoint<2>').member_functions(return_type = "::boost::numeric::ublas::c_vector<double, 2> &")
    returns_non_const_ref.exclude()
    
    builder.class_('AbstractMesh<3,3>').member_functions("GetNode").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('AbstractMesh<2,2>').member_functions("GetNode").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('AbstractMesh<3,3>').member_functions("GetNodeOrHaloNode").exclude()
    builder.class_('AbstractMesh<2,2>').member_functions("GetNodeOrHaloNode").exclude()
    builder.class_('AbstractMesh<3,3>').member_functions("GetNodeFromPrePermutationIndex").exclude()
    builder.class_('AbstractMesh<2,2>').member_functions("GetNodeFromPrePermutationIndex").exclude()
    builder.class_('AbstractMesh<3,3>').member_functions("GetDistributedVectorFactory").exclude()
    builder.class_('AbstractMesh<2,2>').member_functions("GetDistributedVectorFactory").exclude()
    builder.class_('AbstractMesh<3,3>').member_functions("rGetNodePermutation").exclude()
    builder.class_('AbstractMesh<2,2>').member_functions("rGetNodePermutation").exclude()
    builder.class_('AbstractTetrahedralMesh<3,3>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('AbstractTetrahedralMesh<2,2>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('AbstractTetrahedralMesh<3,3>').member_functions("GetBoundaryElement").exclude()
    builder.class_('AbstractTetrahedralMesh<2,2>').member_functions("GetBoundaryElement").exclude()
    builder.class_('TetrahedralMesh<3,3>').member_functions("FreeTriangulateIo").exclude()
    builder.class_('TetrahedralMesh<2,2>').member_functions("FreeTriangulateIo").exclude()
    builder.class_('TetrahedralMesh<3,3>').member_functions("InitialiseTriangulateIo").exclude()
    builder.class_('TetrahedralMesh<2,2>').member_functions("InitialiseTriangulateIo").exclude()
    
    builder.class_('PottsMesh<3>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('PottsMesh<2>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('VertexMesh<3,3>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('VertexMesh<2,2>').member_functions("GetElement").call_policies = call_policies.return_value_policy(call_policies.reference_existing_object)  
    builder.class_('VertexMesh<3,3>').member_functions("GetFace").exclude()
    builder.class_('VertexMesh<2,2>').member_functions("GetFace").exclude()
    builder.class_('VertexMesh<3,3>').constructors(arg_types=[None]).exclude()
    builder.class_('VertexMesh<2,2>').constructors(arg_types=[None]).exclude()
    
    builder.class_('MutableMesh<3,3>').member_functions("RescaleMeshFromBoundaryNode").exclude()
    builder.class_('MutableMesh<2,2>').member_functions("RescaleMeshFromBoundaryNode").exclude()
    builder.class_('MutableMesh<3,3>').member_functions("SplitLongEdges").exclude() # cant deal with vec_cvec for some reason
    builder.class_('MutableMesh<2,2>').member_functions("SplitLongEdges").exclude()
    builder.class_('NodesOnlyMesh<3>').member_functions("GetBoxCollection").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("GetBoxCollection").exclude()
    builder.class_('NodesOnlyMesh<3>').member_functions("GetNodeOrHaloNode").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("GetNodeOrHaloNode").exclude()
    builder.class_('NodesOnlyMesh<3>').member_functions("rGetHaloNodesToSendLeft").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("rGetHaloNodesToSendLeft").exclude()
    builder.class_('NodesOnlyMesh<3>').member_functions("rGetHaloNodesToSendRight").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("rGetHaloNodesToSendRight").exclude() 
    builder.class_('NodesOnlyMesh<3>').member_functions("rGetInitiallyOwnedNodes").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("rGetInitiallyOwnedNodes").exclude()  
    builder.class_('NodesOnlyMesh<3>').member_functions("rGetNodesToSendLeft").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("rGetNodesToSendLeft").exclude()  
    builder.class_('NodesOnlyMesh<3>').member_functions("rGetNodesToSendRight").exclude()
    builder.class_('NodesOnlyMesh<2>').member_functions("rGetNodesToSendRight").exclude()         
    
    builder.class_('Node<3>').member_functions("rGetModifiableLocation").exclude()
    builder.class_('Node<2>').member_functions("rGetModifiableLocation").exclude()
    builder.class_('Node<3>').member_functions("rGetNeighbours").exclude()
    builder.class_('Node<2>').member_functions("rGetNeighbours").exclude()
    builder.class_('Node<3>').member_functions("rGetContainingElementIndices").exclude()
    builder.class_('Node<2>').member_functions("rGetContainingElementIndices").exclude()
    builder.class_('Node<3>').member_functions("rGetNodeAttributes").exclude()
    builder.class_('Node<2>').member_functions("rGetNodeAttributes").exclude()
    builder.class_('Node<3>').member_functions("rGetAppliedForce").call_policies = call_policies.return_internal_reference()  
    builder.class_('Node<2>').member_functions("rGetAppliedForce").call_policies = call_policies.return_internal_reference() 
    builder.class_('Node<3>').member_functions("rGetContainingBoundaryElementIndices").exclude()
    builder.class_('Node<2>').member_functions("rGetContainingBoundaryElementIndices").exclude()
    
    builder.class_('NodeAttributes<3>').member_functions("rGetAttributes").exclude()
    builder.class_('NodeAttributes<2>').member_functions("rGetAttributes").exclude()
    builder.class_('NodeAttributes<3>').member_functions("rGetNeighbours").exclude()
    builder.class_('NodeAttributes<2>').member_functions("rGetNeighbours").exclude()
    builder.class_('NodeAttributes<3>').member_functions("rGetAppliedForce").call_policies = call_policies.return_internal_reference()  
    builder.class_('NodeAttributes<2>').member_functions("rGetAppliedForce").call_policies = call_policies.return_internal_reference()    
    
    builder.class_('Cylindrical2dVertexMesh').member_functions("GetMeshForVtk").exclude()    
        
    return builder, class_collection