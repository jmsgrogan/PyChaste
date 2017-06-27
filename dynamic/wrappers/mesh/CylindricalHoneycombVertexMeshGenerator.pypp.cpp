#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CylindricalHoneycombVertexMeshGenerator.pypp.hpp"

namespace py = pybind11;

typedef SharedCylindricalHoneycombVertexMeshGenerator CylindricalHoneycombVertexMeshGenerator;
class CylindricalHoneycombVertexMeshGenerator_Overloads : public CylindricalHoneycombVertexMeshGenerator{
    public:
    using CylindricalHoneycombVertexMeshGenerator::SharedCylindricalHoneycombVertexMeshGenerator;

        ::boost::shared_ptr<MutableVertexMesh<2, 2> > GetMesh() override {
        PYBIND11_OVERLOAD(
        ::boost::shared_ptr<MutableVertexMesh<2, 2> >,
        CylindricalHoneycombVertexMeshGenerator,
        GetMesh,
        
        );
        }

};
void register_CylindricalHoneycombVertexMeshGenerator_class(py::module &m){
    py::class_<CylindricalHoneycombVertexMeshGenerator, CylindricalHoneycombVertexMeshGenerator_Overloads, std::shared_ptr<CylindricalHoneycombVertexMeshGenerator > , SharedHoneycombVertexMeshGenerator  >(m, "CylindricalHoneycombVertexMeshGenerator")
        .def(py::init<unsigned int, unsigned int, bool, double, double >())
        .def("GetMesh", (::boost::shared_ptr<MutableVertexMesh<2, 2> > (CylindricalHoneycombVertexMeshGenerator::*)()) &CylindricalHoneycombVertexMeshGenerator::GetMesh, "" )
        .def("GetCylindricalMesh", (::boost::shared_ptr<Cylindrical2dVertexMesh> (CylindricalHoneycombVertexMeshGenerator::*)()) &CylindricalHoneycombVertexMeshGenerator::GetCylindricalMesh, "" )
    ;
}
