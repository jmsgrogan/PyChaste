#include <pybind11/pybind11.h>
#include "ChastePoint2.pypp.hpp"
#include "ChastePoint3.pypp.hpp"
#include "NodeAttributes2.pypp.hpp"
#include "NodeAttributes3.pypp.hpp"
#include "Node2.pypp.hpp"
#include "Node3.pypp.hpp"
#include "Element2_2.pypp.hpp"
#include "Element3_3.pypp.hpp"
#include "NodesOnlyMesh2.pypp.hpp"
#include "NodesOnlyMesh3.pypp.hpp"
#include "MutableMesh2_2.pypp.hpp"
#include "MutableMesh3_3.pypp.hpp"
#include "PottsMeshGenerator2.pypp.hpp"
#include "PottsMeshGenerator3.pypp.hpp"
#include "TetrahedralMesh2_2.pypp.hpp"
#include "TetrahedralMesh3_3.pypp.hpp"
#include "AbstractTetrahedralMesh2_2.pypp.hpp"
#include "AbstractTetrahedralMesh3_3.pypp.hpp"
#include "AbstractMesh2_2.pypp.hpp"
#include "AbstractMesh3_3.pypp.hpp"
#include "VertexMesh2_2.pypp.hpp"
#include "VertexMesh3_3.pypp.hpp"
#include "MutableVertexMesh2_2.pypp.hpp"
#include "MutableVertexMesh3_3.pypp.hpp"
#include "Cylindrical2dVertexMesh.pypp.hpp"
#include "HoneycombMeshGenerator.pypp.hpp"
#include "HoneycombVertexMeshGenerator.pypp.hpp"
#include "CylindricalHoneycombVertexMeshGenerator.pypp.hpp"

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
register_NodesOnlyMesh2_class(m);
register_NodesOnlyMesh3_class(m);
register_MutableMesh2_2_class(m);
register_MutableMesh3_3_class(m);
register_PottsMeshGenerator2_class(m);
register_PottsMeshGenerator3_class(m);
register_TetrahedralMesh2_2_class(m);
register_TetrahedralMesh3_3_class(m);
register_AbstractTetrahedralMesh2_2_class(m);
register_AbstractTetrahedralMesh3_3_class(m);
register_AbstractMesh2_2_class(m);
register_AbstractMesh3_3_class(m);
register_VertexMesh2_2_class(m);
register_VertexMesh3_3_class(m);
register_MutableVertexMesh2_2_class(m);
register_MutableVertexMesh3_3_class(m);
register_Cylindrical2dVertexMesh_class(m);
register_HoneycombMeshGenerator_class(m);
register_HoneycombVertexMeshGenerator_class(m);
register_CylindricalHoneycombVertexMeshGenerator_class(m);
}
