// This file has been generated by Py++.

/*

Copyright (c) 2005-2016, University of Oxford.
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

*/


#include "boost/python.hpp"

#include "indexing_suite/value_traits.hpp"

#include "indexing_suite/container_suite.hpp"

#include "indexing_suite/vector.hpp"

#include "indexing_suite/set.hpp"

#include "mesh_headers.hpp"

#include "AbstractMesh2_2.pypp.hpp"

#include "AbstractMesh3_3.pypp.hpp"

#include "AbstractTetrahedralMesh2_2.pypp.hpp"

#include "AbstractTetrahedralMesh3_3.pypp.hpp"

#include "ChastePoint2.pypp.hpp"

#include "ChastePoint3.pypp.hpp"

#include "Cylindrical2dVertexMesh.pypp.hpp"

#include "CylindricalHoneycombVertexMeshGenerator.pypp.hpp"

#include "HoneycombMeshGenerator.pypp.hpp"

#include "HoneycombVertexMeshGenerator.pypp.hpp"

#include "MutableMesh2_2.pypp.hpp"

#include "MutableMesh3_3.pypp.hpp"

#include "MutableVertexMesh2_2.pypp.hpp"

#include "MutableVertexMesh3_3.pypp.hpp"

#include "Node2.pypp.hpp"

#include "Node3.pypp.hpp"

#include "NodeAttributes2.pypp.hpp"

#include "NodeAttributes3.pypp.hpp"

#include "NodesOnlyMesh2.pypp.hpp"

#include "NodesOnlyMesh3.pypp.hpp"

#include "PottsMesh2.pypp.hpp"

#include "PottsMesh3.pypp.hpp"

#include "PottsMeshGenerator2.pypp.hpp"

#include "PottsMeshGenerator3.pypp.hpp"

#include "SetUnsigned.pypp.hpp"

#include "TetrahedralMesh2_2.pypp.hpp"

#include "TetrahedralMesh3_3.pypp.hpp"

#include "VecCVectorDouble_2.pypp.hpp"

#include "VecCVectorDouble_3.pypp.hpp"

#include "VecDouble.pypp.hpp"

#include "VecNodePtr2.pypp.hpp"

#include "VecNodePtr3.pypp.hpp"

#include "VecNodeSharedPtr2.pypp.hpp"

#include "VecNodeSharedPtr3.pypp.hpp"

#include "VecPottsElementPtr2.pypp.hpp"

#include "VecPottsElementPtr3.pypp.hpp"

#include "VecSetInt.pypp.hpp"

#include "VecUnsigned.pypp.hpp"

#include "VecVecInt.pypp.hpp"

#include "VecVertexElementPtr1_2.pypp.hpp"

#include "VecVertexElementPtr2_2.pypp.hpp"

#include "VecVertexElementPtr2_3.pypp.hpp"

#include "VecVertexElementPtr3_3.pypp.hpp"

#include "VertexMesh2_2.pypp.hpp"

#include "VertexMesh3_3.pypp.hpp"

#include "_chaste_project_PyChaste_mesh_free_functions.pypp.hpp"

#include "vector_less__std_scope_pair_less_Node_less_2_greater___ptr__comma__Node_less_2_greater___ptr__greater___greater_.pypp.hpp"

#include "vector_less__std_scope_pair_less_Node_less_3_greater___ptr__comma__Node_less_3_greater___ptr__greater___greater_.pypp.hpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_chaste_project_PyChaste_mesh){
    register_VecUnsigned_class();

    register_VecVecInt_class();

    register_VecSetInt_class();

    register_vector_less__std_scope_pair_less_Node_less_3_greater___ptr__comma__Node_less_3_greater___ptr__greater___greater__class();

    register_vector_less__std_scope_pair_less_Node_less_2_greater___ptr__comma__Node_less_2_greater___ptr__greater___greater__class();

    register_VecDouble_class();

    register_VecNodeSharedPtr3_class();

    register_VecNodeSharedPtr2_class();

    register_VecCVectorDouble_3_class();

    register_VecCVectorDouble_2_class();

    register_VecVertexElementPtr3_3_class();

    register_VecVertexElementPtr2_3_class();

    register_VecVertexElementPtr2_2_class();

    register_VecVertexElementPtr1_2_class();

    register_VecPottsElementPtr3_class();

    register_VecPottsElementPtr2_class();

    register_VecNodePtr3_class();

    register_VecNodePtr2_class();

    register_SetUnsigned_class();

    register_AbstractMesh2_2_class();

    register_AbstractMesh3_3_class();

    register_AbstractTetrahedralMesh2_2_class();

    register_AbstractTetrahedralMesh3_3_class();

    register_ChastePoint2_class();

    register_ChastePoint3_class();

    register_VertexMesh2_2_class();

    register_MutableVertexMesh2_2_class();

    register_Cylindrical2dVertexMesh_class();

    register_TetrahedralMesh2_2_class();

    register_MutableMesh2_2_class();

    register_TetrahedralMesh3_3_class();

    register_MutableMesh3_3_class();

    register_VertexMesh3_3_class();

    register_MutableVertexMesh3_3_class();

    register_Node2_class();

    register_Node3_class();

    register_NodeAttributes2_class();

    register_NodeAttributes3_class();

    register_NodesOnlyMesh2_class();

    register_NodesOnlyMesh3_class();

    register_PottsMesh2_class();

    register_PottsMesh3_class();

    register_HoneycombVertexMeshGenerator_class();

    register_CylindricalHoneycombVertexMeshGenerator_class();

    register_HoneycombMeshGenerator_class();

    register_PottsMeshGenerator2_class();

    register_PottsMeshGenerator3_class();

    register_free_functions();
}
