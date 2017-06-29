#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractNonlinearEllipticPde2.pypp.hpp"

namespace py = pybind11;

typedef AbstractNonlinearEllipticPde<2 > AbstractNonlinearEllipticPde2;
typedef ::boost::numeric::ublas::c_matrix<double, 2, 2> _boost_numeric_ublas_c_matrixdouble_2_2;
typedef ::boost::numeric::ublas::c_matrix<double, 2, 2> _boost_numeric_ublas_c_matrixdouble_2_2;

class AbstractNonlinearEllipticPde2_Overloads : public AbstractNonlinearEllipticPde2{
    public:
    using AbstractNonlinearEllipticPde2::AbstractNonlinearEllipticPde;

        double ComputeLinearSourceTerm(::ChastePoint<2> const & rX)override {
        PYBIND11_OVERLOAD_PURE(
        double,
        AbstractNonlinearEllipticPde2,
        ComputeLinearSourceTerm,
        rX        
        );
        }
        double ComputeNonlinearSourceTerm(::ChastePoint<2> const & rX, double u)override {
        PYBIND11_OVERLOAD_PURE(
        double,
        AbstractNonlinearEllipticPde2,
        ComputeNonlinearSourceTerm,
        rX, 
        u        
        );
        }
        ::boost::numeric::ublas::c_matrix<double, 2, 2> ComputeDiffusionTerm(::ChastePoint<2> const & rX, double u)override {
        PYBIND11_OVERLOAD_PURE(
        _boost_numeric_ublas_c_matrixdouble_2_2,
        AbstractNonlinearEllipticPde2,
        ComputeDiffusionTerm,
        rX, 
        u        
        );
        }
        ::boost::numeric::ublas::c_matrix<double, 2, 2> ComputeDiffusionTermPrime(::ChastePoint<2> const & rX, double u)override {
        PYBIND11_OVERLOAD_PURE(
        _boost_numeric_ublas_c_matrixdouble_2_2,
        AbstractNonlinearEllipticPde2,
        ComputeDiffusionTermPrime,
        rX, 
        u        
        );
        }
        double ComputeNonlinearSourceTermPrime(::ChastePoint<2> const & rX, double u)override {
        PYBIND11_OVERLOAD_PURE(
        double,
        AbstractNonlinearEllipticPde2,
        ComputeNonlinearSourceTermPrime,
        rX, 
        u        
        );
        }

};
void register_AbstractNonlinearEllipticPde2_class(py::module &m){
    py::class_<AbstractNonlinearEllipticPde2, AbstractNonlinearEllipticPde2_Overloads, std::shared_ptr<AbstractNonlinearEllipticPde2 >  >(m, "AbstractNonlinearEllipticPde2")
        .def("ComputeLinearSourceTerm", (double (AbstractNonlinearEllipticPde2::*)(::ChastePoint<2> const &)) &AbstractNonlinearEllipticPde2::ComputeLinearSourceTerm, "" , py::arg("rX"))
        .def("ComputeNonlinearSourceTerm", (double (AbstractNonlinearEllipticPde2::*)(::ChastePoint<2> const &, double)) &AbstractNonlinearEllipticPde2::ComputeNonlinearSourceTerm, "" , py::arg("rX"), py::arg("u"))
        .def("ComputeDiffusionTerm", (::boost::numeric::ublas::c_matrix<double, 2, 2> (AbstractNonlinearEllipticPde2::*)(::ChastePoint<2> const &, double)) &AbstractNonlinearEllipticPde2::ComputeDiffusionTerm, "" , py::arg("rX"), py::arg("u"))
        .def("ComputeDiffusionTermPrime", (::boost::numeric::ublas::c_matrix<double, 2, 2> (AbstractNonlinearEllipticPde2::*)(::ChastePoint<2> const &, double)) &AbstractNonlinearEllipticPde2::ComputeDiffusionTermPrime, "" , py::arg("rX"), py::arg("u"))
        .def("ComputeNonlinearSourceTermPrime", (double (AbstractNonlinearEllipticPde2::*)(::ChastePoint<2> const &, double)) &AbstractNonlinearEllipticPde2::ComputeNonlinearSourceTermPrime, "" , py::arg("rX"), py::arg("u"))
    ;
}
