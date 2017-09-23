#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "SharedPottsMeshGenerator.hpp"

#include "PythonObjectConverters.hpp"
#include "PottsMeshGenerator2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef SharedPottsMeshGenerator<2 > PottsMeshGenerator2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::shared_ptr<PottsMesh<2> > _boost_shared_ptr_lt_PottsMesh_lt_2_gt__gt_;

class PottsMeshGenerator2_Overloads : public PottsMeshGenerator2{
    public:
    using PottsMeshGenerator2::SharedPottsMeshGenerator;
    ::boost::shared_ptr<PottsMesh<2> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptr_lt_PottsMesh_lt_2_gt__gt_,
            PottsMeshGenerator2,
            GetMesh,
            );
    }

};
void register_PottsMeshGenerator2_class(py::module &m){
py::class_<PottsMeshGenerator2 , PottsMeshGenerator2_Overloads , boost::shared_ptr<PottsMeshGenerator2 >   >(m, "PottsMeshGenerator2")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool, bool, bool >(), py::arg("numNodesAcross"), py::arg("numElementsAcross"), py::arg("elementWidth"), py::arg("numNodesUp") = 1U, py::arg("numElementsUp") = 1U, py::arg("elementHeight") = 1U, py::arg("numNodesDeep") = 1U, py::arg("numElementsDeep") = 1U, py::arg("elementDepth") = 1U, py::arg("startAtBottomLeft") = false, py::arg("isPeriodicInX") = false, py::arg("isPeriodicInY") = false, py::arg("isPeriodicInZ") = false)
        .def(py::init< >())
        .def(
            "GetMesh", 
            (::boost::shared_ptr<PottsMesh<2> >(PottsMeshGenerator2::*)()) &PottsMeshGenerator2::GetMesh, 
            " "  )
    ;
}
