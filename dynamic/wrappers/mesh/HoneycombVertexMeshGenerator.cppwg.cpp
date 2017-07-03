#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "SharedHoneycombVertexMeshGenerator.hpp"

#include "HoneycombVertexMeshGenerator.cppwg.hpp"

namespace py = pybind11;
typedef SharedHoneycombVertexMeshGenerator HoneycombVertexMeshGenerator;
;
typedef ::boost::shared_ptr<MutableVertexMesh<2, 2> > _boost_shared_ptrMutableVertexMesh2_2;

class HoneycombVertexMeshGenerator_Overloads : public HoneycombVertexMeshGenerator{
    public:
    using HoneycombVertexMeshGenerator::SharedHoneycombVertexMeshGenerator;
    ::boost::shared_ptr<MutableVertexMesh<2, 2> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptrMutableVertexMesh2_2,
            HoneycombVertexMeshGenerator,
            GetMesh,
            );
    }

};
void register_HoneycombVertexMeshGenerator_class(py::module &m){
py::class_<HoneycombVertexMeshGenerator , HoneycombVertexMeshGenerator_Overloads   >(m, "HoneycombVertexMeshGenerator")
        .def(py::init<unsigned int, unsigned int, bool, double, double, double >(), py::arg("numElementsAcross"), py::arg("numElementsUp"), py::arg("isFlatBottom") = false, py::arg("cellRearrangementThreshold") = 0.01, py::arg("t2Threshold") = 0.001, py::arg("elementArea") = 0.5 * sqrt(3.))
        .def(py::init< >())
        .def(
            "GetMesh", 
            (::boost::shared_ptr<MutableVertexMesh<2, 2> >(HoneycombVertexMeshGenerator::*)()) &HoneycombVertexMeshGenerator::GetMesh, 
            " " )
    ;
}
