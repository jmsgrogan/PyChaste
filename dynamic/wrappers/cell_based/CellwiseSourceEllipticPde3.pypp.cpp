#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellwiseSourceEllipticPde3.pypp.hpp"

namespace py = pybind11;

typedef CellwiseSourceEllipticPde<3 > CellwiseSourceEllipticPde3;
class CellwiseSourceEllipticPde3_Overloads : public CellwiseSourceEllipticPde3{
    public:
    using CellwiseSourceEllipticPde3::CellwiseSourceEllipticPde<3>;

        double ComputeConstantInUSourceTerm(::ChastePoint<3> const & rX, ::Element<3, 3> * pElement) override {
        PYBIND11_OVERLOAD(
        double,
        CellwiseSourceEllipticPde3,
        ComputeConstantInUSourceTerm,
        rX, 
        pElement        
        );
        }
        double ComputeLinearInUCoeffInSourceTerm(::ChastePoint<3> const & rX, ::Element<3, 3> * pElement) override {
        PYBIND11_OVERLOAD(
        double,
        CellwiseSourceEllipticPde3,
        ComputeLinearInUCoeffInSourceTerm,
        rX, 
        pElement        
        );
        }
        double ComputeLinearInUCoeffInSourceTermAtNode(::Node<3> const & rNode) override {
        PYBIND11_OVERLOAD(
        double,
        CellwiseSourceEllipticPde3,
        ComputeLinearInUCoeffInSourceTermAtNode,
        rNode        
        );
        }
        ::boost::numeric::ublas::c_matrix<double, 3, 3> ComputeDiffusionTerm(::ChastePoint<3> const & rX) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_matrix<double, 3, 3>,
        CellwiseSourceEllipticPde3,
        ComputeDiffusionTerm,
        rX        
        );
        }

};
void register_CellwiseSourceEllipticPde3_class(py::module &m){
    py::class_<CellwiseSourceEllipticPde3, CellwiseSourceEllipticPde3_Overloads, std::shared_ptr<CellwiseSourceEllipticPde3 >  >(m, "CellwiseSourceEllipticPde3")
        .def(py::init<::AbstractCellPopulation<3, 3> &, double >())
        .def("rGetCellPopulation", (::AbstractCellPopulation<3, 3> const & (CellwiseSourceEllipticPde3::*)()) &CellwiseSourceEllipticPde3::rGetCellPopulation, "" )
        .def("GetCoefficient", (double (CellwiseSourceEllipticPde3::*)()) &CellwiseSourceEllipticPde3::GetCoefficient, "" )
        .def("ComputeConstantInUSourceTerm", (double (CellwiseSourceEllipticPde3::*)(::ChastePoint<3> const &, ::Element<3, 3> *)) &CellwiseSourceEllipticPde3::ComputeConstantInUSourceTerm, "" , py::arg("rX"), py::arg("pElement"))
        .def("ComputeLinearInUCoeffInSourceTerm", (double (CellwiseSourceEllipticPde3::*)(::ChastePoint<3> const &, ::Element<3, 3> *)) &CellwiseSourceEllipticPde3::ComputeLinearInUCoeffInSourceTerm, "" , py::arg("rX"), py::arg("pElement"))
        .def("ComputeLinearInUCoeffInSourceTermAtNode", (double (CellwiseSourceEllipticPde3::*)(::Node<3> const &)) &CellwiseSourceEllipticPde3::ComputeLinearInUCoeffInSourceTermAtNode, "" , py::arg("rNode"))
        .def("ComputeDiffusionTerm", (::boost::numeric::ublas::c_matrix<double, 3, 3> (CellwiseSourceEllipticPde3::*)(::ChastePoint<3> const &)) &CellwiseSourceEllipticPde3::ComputeDiffusionTerm, "" , py::arg("rX"))
    ;
}
