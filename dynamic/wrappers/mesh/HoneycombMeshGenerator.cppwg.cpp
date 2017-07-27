#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "SharedHoneycombMeshGenerator.hpp"

#include "PythonObjectConverters.hpp"
#include "HoneycombMeshGenerator.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
typedef SharedHoneycombMeshGenerator HoneycombMeshGenerator;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::shared_ptr<MutableMesh<2, 2> > _boost_shared_ptr_lt_MutableMesh_lt_2_2_gt__gt_;

class HoneycombMeshGenerator_Overloads : public HoneycombMeshGenerator{
    public:
    using HoneycombMeshGenerator::SharedHoneycombMeshGenerator;
    ::boost::shared_ptr<MutableMesh<2, 2> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptr_lt_MutableMesh_lt_2_2_gt__gt_,
            HoneycombMeshGenerator,
            GetMesh,
            );
    }

};
void register_HoneycombMeshGenerator_class(py::module &m){
py::class_<HoneycombMeshGenerator , HoneycombMeshGenerator_Overloads , boost::shared_ptr<HoneycombMeshGenerator >   >(m, "HoneycombMeshGenerator")
        .def(py::init<unsigned int, unsigned int, unsigned int, double >(), py::arg("numNodesAlongWidth"), py::arg("numNodesAlongLength"), py::arg("ghosts") = 0, py::arg("scaleFactor") = 1.)
        .def(py::init< >())
        .def(
            "GetMesh", 
            (::boost::shared_ptr<MutableMesh<2, 2> >(HoneycombMeshGenerator::*)()) &HoneycombMeshGenerator::GetMesh, 
            " "  )
        .def(
            "GetCellLocationIndices", 
            (::std::vector<unsigned int, std::allocator<unsigned int> >(HoneycombMeshGenerator::*)()) &HoneycombMeshGenerator::GetCellLocationIndices, 
            " "  )
        .def(
            "GetCircularMesh", 
            (::boost::shared_ptr<MutableMesh<2, 2> >(HoneycombMeshGenerator::*)(double)) &HoneycombMeshGenerator::GetCircularMesh, 
            " " , py::arg("radius") )
        .def(
            "GetDomainDepth", 
            (double(HoneycombMeshGenerator::*)()) &HoneycombMeshGenerator::GetDomainDepth, 
            " "  )
        .def(
            "GetDomainWidth", 
            (double(HoneycombMeshGenerator::*)()) &HoneycombMeshGenerator::GetDomainWidth, 
            " "  )
    ;
}
