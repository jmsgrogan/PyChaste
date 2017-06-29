#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "HoneycombVertexMeshGenerator.pypp.hpp"

namespace py = pybind11;

typedef SharedHoneycombVertexMeshGenerator HoneycombVertexMeshGenerator;
typedef ::boost::shared_ptr<MutableVertexMesh<2, 2> > _boost_shared_ptrMutableVertexMesh2_2;

class HoneycombVertexMeshGenerator_Overloads : public HoneycombVertexMeshGenerator{
    public:
    using HoneycombVertexMeshGenerator::SharedHoneycombVertexMeshGenerator;

        ::boost::shared_ptr<MutableVertexMesh<2, 2> > GetMesh()override {
        PYBIND11_OVERLOAD(
        _boost_shared_ptrMutableVertexMesh2_2,
        HoneycombVertexMeshGenerator,
        GetMesh,
        
        );
        }

};
void register_HoneycombVertexMeshGenerator_class(py::module &m){
    py::class_<HoneycombVertexMeshGenerator, HoneycombVertexMeshGenerator_Overloads, std::shared_ptr<HoneycombVertexMeshGenerator >  >(m, "HoneycombVertexMeshGenerator")
        .def(py::init<unsigned int, unsigned int, bool, double, double, double >())
        .def(py::init< >())
        .def("GetMesh", (::boost::shared_ptr<MutableVertexMesh<2, 2> > (HoneycombVertexMeshGenerator::*)()) &HoneycombVertexMeshGenerator::GetMesh, "" )
    ;
}
