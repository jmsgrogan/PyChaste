#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractNonlinearEllipticPde3.pypp.hpp"

namespace py = pybind11;
typedef AbstractNonlinearEllipticPde<3 > AbstractNonlinearEllipticPde3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::numeric::ublas::c_matrix<double, 3, 3> _boost_numeric_ublas_c_matrixdouble_3_3;
typedef ::boost::numeric::ublas::c_matrix<double, 3, 3> _boost_numeric_ublas_c_matrixdouble_3_3;

class AbstractNonlinearEllipticPde3_Overloads : public AbstractNonlinearEllipticPde3{
    public:
    using AbstractNonlinearEllipticPde3::AbstractNonlinearEllipticPde;
    double ComputeLinearSourceTerm(::ChastePoint<3> const & rX) override {
        PYBIND11_OVERLOAD_PURE(
            double,
            AbstractNonlinearEllipticPde3,
            ComputeLinearSourceTerm,
            rX);
    }
    double ComputeNonlinearSourceTerm(::ChastePoint<3> const & rX, double u) override {
        PYBIND11_OVERLOAD_PURE(
            double,
            AbstractNonlinearEllipticPde3,
            ComputeNonlinearSourceTerm,
            rX, 
u);
    }
    ::boost::numeric::ublas::c_matrix<double, 3, 3> ComputeDiffusionTerm(::ChastePoint<3> const & rX, double u) override {
        PYBIND11_OVERLOAD_PURE(
            _boost_numeric_ublas_c_matrixdouble_3_3,
            AbstractNonlinearEllipticPde3,
            ComputeDiffusionTerm,
            rX, 
u);
    }
    ::boost::numeric::ublas::c_matrix<double, 3, 3> ComputeDiffusionTermPrime(::ChastePoint<3> const & rX, double u) override {
        PYBIND11_OVERLOAD_PURE(
            _boost_numeric_ublas_c_matrixdouble_3_3,
            AbstractNonlinearEllipticPde3,
            ComputeDiffusionTermPrime,
            rX, 
u);
    }
    double ComputeNonlinearSourceTermPrime(::ChastePoint<3> const & rX, double u) override {
        PYBIND11_OVERLOAD_PURE(
            double,
            AbstractNonlinearEllipticPde3,
            ComputeNonlinearSourceTermPrime,
            rX, 
u);
    }

};
void register_AbstractNonlinearEllipticPde3_class(py::module &m){
py::class_<AbstractNonlinearEllipticPde3 , AbstractNonlinearEllipticPde3_Overloads , boost::shared_ptr<AbstractNonlinearEllipticPde3 >   >(m, "AbstractNonlinearEllipticPde3")
        .def(
            "ComputeLinearSourceTerm", 
            (double(AbstractNonlinearEllipticPde3::*)(::ChastePoint<3> const &)) &AbstractNonlinearEllipticPde3::ComputeLinearSourceTerm, 
            " " , py::arg("rX"))
        .def(
            "ComputeNonlinearSourceTerm", 
            (double(AbstractNonlinearEllipticPde3::*)(::ChastePoint<3> const &, double)) &AbstractNonlinearEllipticPde3::ComputeNonlinearSourceTerm, 
            " " , py::arg("rX"), py::arg("u"))
        .def(
            "ComputeDiffusionTerm", 
            (::boost::numeric::ublas::c_matrix<double, 3, 3>(AbstractNonlinearEllipticPde3::*)(::ChastePoint<3> const &, double)) &AbstractNonlinearEllipticPde3::ComputeDiffusionTerm, 
            " " , py::arg("rX"), py::arg("u"))
        .def(
            "ComputeDiffusionTermPrime", 
            (::boost::numeric::ublas::c_matrix<double, 3, 3>(AbstractNonlinearEllipticPde3::*)(::ChastePoint<3> const &, double)) &AbstractNonlinearEllipticPde3::ComputeDiffusionTermPrime, 
            " " , py::arg("rX"), py::arg("u"))
        .def(
            "ComputeNonlinearSourceTermPrime", 
            (double(AbstractNonlinearEllipticPde3::*)(::ChastePoint<3> const &, double)) &AbstractNonlinearEllipticPde3::ComputeNonlinearSourceTermPrime, 
            " " , py::arg("rX"), py::arg("u"))
    ;
}
