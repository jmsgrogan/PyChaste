#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AveragedSourceParabolicPde2.pypp.hpp"

namespace py = pybind11;

typedef AveragedSourceParabolicPde<2 > AveragedSourceParabolicPde2;
typedef ::boost::numeric::ublas::c_matrix<double, 2, 2> _boost_numeric_ublas_c_matrixdouble_2_2;

class AveragedSourceParabolicPde2_Overloads : public AveragedSourceParabolicPde2{
    public:
    using AveragedSourceParabolicPde2::AveragedSourceParabolicPde;

        void SetupSourceTerms(::TetrahedralMesh<2, 2> & rCoarseMesh, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > * pCellPdeElementMap)override {
        PYBIND11_OVERLOAD(
        void,
        AveragedSourceParabolicPde2,
        SetupSourceTerms,
        rCoarseMesh, 
        pCellPdeElementMap        
        );
        }
        double ComputeDuDtCoefficientFunction(::ChastePoint<2> const & rX)override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde2,
        ComputeDuDtCoefficientFunction,
        rX        
        );
        }
        double ComputeSourceTerm(::ChastePoint<2> const & rX, double u, ::Element<2, 2> * pElement)override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde2,
        ComputeSourceTerm,
        rX, 
        u, 
        pElement        
        );
        }
        double ComputeSourceTermAtNode(::Node<2> const & rNode, double u)override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde2,
        ComputeSourceTermAtNode,
        rNode, 
        u        
        );
        }
        ::boost::numeric::ublas::c_matrix<double, 2, 2> ComputeDiffusionTerm(::ChastePoint<2> const & rX, ::Element<2, 2> * pElement)override {
        PYBIND11_OVERLOAD(
        _boost_numeric_ublas_c_matrixdouble_2_2,
        AveragedSourceParabolicPde2,
        ComputeDiffusionTerm,
        rX, 
        pElement        
        );
        }

};
void register_AveragedSourceParabolicPde2_class(py::module &m){
    py::class_<AveragedSourceParabolicPde2, AveragedSourceParabolicPde2_Overloads, std::shared_ptr<AveragedSourceParabolicPde2 >  >(m, "AveragedSourceParabolicPde2")
        .def(py::init<::AbstractCellPopulation<2, 2> &, double, double, double >())
        .def("rGetCellPopulation", (::AbstractCellPopulation<2, 2> const & (AveragedSourceParabolicPde2::*)() const ) &AveragedSourceParabolicPde2::rGetCellPopulation, "" )
        .def("SetupSourceTerms", (void (AveragedSourceParabolicPde2::*)(::TetrahedralMesh<2, 2> &, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > *)) &AveragedSourceParabolicPde2::SetupSourceTerms, "" , py::arg("rCoarseMesh"), py::arg("pCellPdeElementMap") = nullptr)
        .def("ComputeDuDtCoefficientFunction", (double (AveragedSourceParabolicPde2::*)(::ChastePoint<2> const &)) &AveragedSourceParabolicPde2::ComputeDuDtCoefficientFunction, "" , py::arg("rX"))
        .def("ComputeSourceTerm", (double (AveragedSourceParabolicPde2::*)(::ChastePoint<2> const &, double, ::Element<2, 2> *)) &AveragedSourceParabolicPde2::ComputeSourceTerm, "" , py::arg("rX"), py::arg("u"), py::arg("pElement") = __null)
        .def("ComputeSourceTermAtNode", (double (AveragedSourceParabolicPde2::*)(::Node<2> const &, double)) &AveragedSourceParabolicPde2::ComputeSourceTermAtNode, "" , py::arg("rNode"), py::arg("u"))
        .def("ComputeDiffusionTerm", (::boost::numeric::ublas::c_matrix<double, 2, 2> (AveragedSourceParabolicPde2::*)(::ChastePoint<2> const &, ::Element<2, 2> *)) &AveragedSourceParabolicPde2::ComputeDiffusionTerm, "" , py::arg("rX"), py::arg("pElement") = __null)
        .def("GetUptakeRateForElement", (double (AveragedSourceParabolicPde2::*)(unsigned int)) &AveragedSourceParabolicPde2::GetUptakeRateForElement, "" , py::arg("elementIndex"))
    ;
}
