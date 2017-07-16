#include <pybind11/pybind11.h>
#include "ChastePoint2.cppwg.hpp"
#include "ChastePoint3.cppwg.hpp"
#include "NodeAttributes2.cppwg.hpp"
#include "NodeAttributes3.cppwg.hpp"
#include "Node2.cppwg.hpp"
#include "Node3.cppwg.hpp"
#include "Element2_2.cppwg.hpp"
#include "Element3_3.cppwg.hpp"
#include "AbstractMesh2_2.cppwg.hpp"
#include "AbstractMesh3_3.cppwg.hpp"
#include "AbstractTetrahedralMesh2_2.cppwg.hpp"
#include "AbstractTetrahedralMesh3_3.cppwg.hpp"
#include "TetrahedralMesh2_2.cppwg.hpp"
#include "TetrahedralMesh3_3.cppwg.hpp"
#include "MutableMesh2_2.cppwg.hpp"
#include "MutableMesh3_3.cppwg.hpp"
#include "NodesOnlyMesh2.cppwg.hpp"
#include "NodesOnlyMesh3.cppwg.hpp"
#include "PottsElement2.cppwg.hpp"
#include "PottsElement3.cppwg.hpp"
#include "PottsMesh2.cppwg.hpp"
#include "PottsMesh3.cppwg.hpp"
#include "PottsMeshGenerator2.cppwg.hpp"
#include "PottsMeshGenerator3.cppwg.hpp"
#include "VertexMesh2_2.cppwg.hpp"
#include "VertexMesh3_3.cppwg.hpp"
#include "MutableVertexMesh2_2.cppwg.hpp"
#include "MutableVertexMesh3_3.cppwg.hpp"
#include "Cylindrical2dVertexMesh.cppwg.hpp"
#include "HoneycombMeshGenerator.cppwg.hpp"
#include "HoneycombVertexMeshGenerator.cppwg.hpp"
#include "CylindricalHoneycombVertexMeshGenerator.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_mesh, m)
{
    register_ChastePoint2_class(m);
    register_ChastePoint3_class(m);
    register_NodeAttributes2_class(m);
    register_NodeAttributes3_class(m);
    register_Node2_class(m);
    register_Node3_class(m);
    register_Element2_2_class(m);
    register_Element3_3_class(m);
    register_AbstractMesh2_2_class(m);
    register_AbstractMesh3_3_class(m);
    register_AbstractTetrahedralMesh2_2_class(m);
    register_AbstractTetrahedralMesh3_3_class(m);
    register_TetrahedralMesh2_2_class(m);
    register_TetrahedralMesh3_3_class(m);
    register_MutableMesh2_2_class(m);
    register_MutableMesh3_3_class(m);
    register_NodesOnlyMesh2_class(m);
    register_NodesOnlyMesh3_class(m);
    register_PottsElement2_class(m);
    register_PottsElement3_class(m);
    register_PottsMesh2_class(m);
    register_PottsMesh3_class(m);
    register_PottsMeshGenerator2_class(m);
    register_PottsMeshGenerator3_class(m);
    register_VertexMesh2_2_class(m);
    register_VertexMesh3_3_class(m);
    register_MutableVertexMesh2_2_class(m);
    register_MutableVertexMesh3_3_class(m);
    register_Cylindrical2dVertexMesh_class(m);
    register_HoneycombMeshGenerator_class(m);
    register_HoneycombVertexMeshGenerator_class(m);
    register_CylindricalHoneycombVertexMeshGenerator_class(m);
}
