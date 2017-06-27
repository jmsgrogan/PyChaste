#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ChastePoint2.pypp.hpp"

namespace py = pybind11;

typedef ChastePoint<2 > ChastePoint2;
void register_ChastePoint2_class(py::module &m){
    py::class_<ChastePoint2, std::shared_ptr<ChastePoint2 >  >(m, "ChastePoint2")
        .def(py::init<double, double, double >())
        .def(py::init<::std::vector<double, std::allocator<double> > >())
        .def(py::init<::boost::numeric::ublas::c_vector<double, 2> >())
        .def("rGetLocation", (::boost::numeric::ublas::c_vector<double, 2> & (ChastePoint2::*)()) &ChastePoint2::rGetLocation, "" )
        .def("rGetLocation", (::boost::numeric::ublas::c_vector<double, 2> const & (ChastePoint2::*)()) &ChastePoint2::rGetLocation, "" )
        .def("GetWithDefault", (double (ChastePoint2::*)(unsigned int, double)) &ChastePoint2::GetWithDefault, "" , py::arg("i"), py::arg("def") = 0.)
        .def("SetCoordinate", (void (ChastePoint2::*)(unsigned int, double)) &ChastePoint2::SetCoordinate, "" , py::arg("i"), py::arg("value"))
        .def("IsSamePoint", (bool (ChastePoint2::*)(::ChastePoint<2> const &)) &ChastePoint2::IsSamePoint, "" , py::arg("rPoint"))
    ;
}
