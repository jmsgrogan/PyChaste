#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ChastePoint3.pypp.hpp"

namespace py = pybind11;

typedef ChastePoint<3 > ChastePoint3;
void register_ChastePoint3_class(py::module &m){
    py::class_<ChastePoint3, std::shared_ptr<ChastePoint3 >  >(m, "ChastePoint3")
        .def(py::init<double, double, double >())
        .def(py::init<::std::vector<double, std::allocator<double> > >())
        .def(py::init<::boost::numeric::ublas::c_vector<double, 3> >())
        .def("rGetLocation", (::boost::numeric::ublas::c_vector<double, 3> & (ChastePoint3::*)()) &ChastePoint3::rGetLocation, "" )
        .def("rGetLocation", (::boost::numeric::ublas::c_vector<double, 3> const & (ChastePoint3::*)()) &ChastePoint3::rGetLocation, "" )
        .def("GetWithDefault", (double (ChastePoint3::*)(unsigned int, double)) &ChastePoint3::GetWithDefault, "" , py::arg("i"), py::arg("def") = 0.)
        .def("SetCoordinate", (void (ChastePoint3::*)(unsigned int, double)) &ChastePoint3::SetCoordinate, "" , py::arg("i"), py::arg("value"))
        .def("IsSamePoint", (bool (ChastePoint3::*)(::ChastePoint<3> const &)) &ChastePoint3::IsSamePoint, "" , py::arg("rPoint"))
    ;
}
