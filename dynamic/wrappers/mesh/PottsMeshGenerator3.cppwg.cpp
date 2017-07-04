#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "SharedPottsMeshGenerator.hpp"

#include "PottsMeshGenerator3.cppwg.hpp"

namespace py = pybind11;
typedef SharedPottsMeshGenerator<3 > PottsMeshGenerator3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::shared_ptr<PottsMesh<3> > _boost_shared_ptrPottsMesh3;

class PottsMeshGenerator3_Overloads : public PottsMeshGenerator3{
    public:
    using PottsMeshGenerator3::SharedPottsMeshGenerator;
    ::boost::shared_ptr<PottsMesh<3> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptrPottsMesh3,
            PottsMeshGenerator3,
            GetMesh,
            );
    }

};
void register_PottsMeshGenerator3_class(py::module &m){
py::class_<PottsMeshGenerator3 , PottsMeshGenerator3_Overloads , boost::shared_ptr<PottsMeshGenerator3 >   >(m, "PottsMeshGenerator3")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool, bool, bool >(), py::arg("numNodesAcross"), py::arg("numElementsAcross"), py::arg("elementWidth"), py::arg("numNodesUp") = 1U, py::arg("numElementsUp") = 1U, py::arg("elementHeight") = 1U, py::arg("numNodesDeep") = 1U, py::arg("numElementsDeep") = 1U, py::arg("elementDepth") = 1U, py::arg("startAtBottomLeft") = false, py::arg("isPeriodicInX") = false, py::arg("isPeriodicInY") = false, py::arg("isPeriodicInZ") = false)
        .def(py::init< >())
        .def(
            "GetMesh", 
            (::boost::shared_ptr<PottsMesh<3> >(PottsMeshGenerator3::*)()) &PottsMeshGenerator3::GetMesh, 
            " "  )
    ;
}
