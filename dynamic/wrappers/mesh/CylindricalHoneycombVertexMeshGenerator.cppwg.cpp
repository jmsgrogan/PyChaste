#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "SharedCylindricalHoneycombVertexMeshGenerator.hpp"

#include "CylindricalHoneycombVertexMeshGenerator.cppwg.hpp"

namespace py = pybind11;
typedef SharedCylindricalHoneycombVertexMeshGenerator CylindricalHoneycombVertexMeshGenerator;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::shared_ptr<MutableVertexMesh<2, 2> > _boost_shared_ptrMutableVertexMesh2_2;

class CylindricalHoneycombVertexMeshGenerator_Overloads : public CylindricalHoneycombVertexMeshGenerator{
    public:
    using CylindricalHoneycombVertexMeshGenerator::SharedCylindricalHoneycombVertexMeshGenerator;
    ::boost::shared_ptr<MutableVertexMesh<2, 2> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptrMutableVertexMesh2_2,
            CylindricalHoneycombVertexMeshGenerator,
            GetMesh,
            );
    }

};
void register_CylindricalHoneycombVertexMeshGenerator_class(py::module &m){
py::class_<CylindricalHoneycombVertexMeshGenerator , CylindricalHoneycombVertexMeshGenerator_Overloads , boost::shared_ptr<CylindricalHoneycombVertexMeshGenerator >   >(m, "CylindricalHoneycombVertexMeshGenerator")
        .def(py::init<unsigned int, unsigned int, bool, double, double >(), py::arg("numElementsAcross"), py::arg("numElementsUp"), py::arg("isFlatBottom") = false, py::arg("cellRearrangementThreshold") = 0.01, py::arg("t2Threshold") = 0.001)
        .def(
            "GetMesh", 
            (::boost::shared_ptr<MutableVertexMesh<2, 2> >(CylindricalHoneycombVertexMeshGenerator::*)()) &CylindricalHoneycombVertexMeshGenerator::GetMesh, 
            " "  )
        .def(
            "GetCylindricalMesh", 
            (::boost::shared_ptr<Cylindrical2dVertexMesh>(CylindricalHoneycombVertexMeshGenerator::*)()) &CylindricalHoneycombVertexMeshGenerator::GetCylindricalMesh, 
            " "  )
    ;
}
