#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AveragedSourceParabolicPde3.pypp.hpp"

namespace py = pybind11;

typedef AveragedSourceParabolicPde<3 > AveragedSourceParabolicPde3;
class AveragedSourceParabolicPde3_Overloads : public AveragedSourceParabolicPde3{
    public:
    using AveragedSourceParabolicPde3::AveragedSourceParabolicPde<3>;

        void SetupSourceTerms(::TetrahedralMesh<3, 3> & rCoarseMesh, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > * pCellPdeElementMap) override {
        PYBIND11_OVERLOAD(
        void,
        AveragedSourceParabolicPde3,
        SetupSourceTerms,
        rCoarseMesh, 
        pCellPdeElementMap        
        );
        }
        double ComputeDuDtCoefficientFunction(::ChastePoint<3> const & rX) override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde3,
        ComputeDuDtCoefficientFunction,
        rX        
        );
        }
        double ComputeSourceTerm(::ChastePoint<3> const & rX, double u, ::Element<3, 3> * pElement) override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde3,
        ComputeSourceTerm,
        rX, 
        u, 
        pElement        
        );
        }
        double ComputeSourceTermAtNode(::Node<3> const & rNode, double u) override {
        PYBIND11_OVERLOAD(
        double,
        AveragedSourceParabolicPde3,
        ComputeSourceTermAtNode,
        rNode, 
        u        
        );
        }
        ::boost::numeric::ublas::c_matrix<double, 3, 3> ComputeDiffusionTerm(::ChastePoint<3> const & rX, ::Element<3, 3> * pElement) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_matrix<double, 3, 3>,
        AveragedSourceParabolicPde3,
        ComputeDiffusionTerm,
        rX, 
        pElement        
        );
        }

};
void register_AveragedSourceParabolicPde3_class(py::module &m){
    py::class_<AveragedSourceParabolicPde3, AveragedSourceParabolicPde3_Overloads, std::shared_ptr<AveragedSourceParabolicPde3 >  >(m, "AveragedSourceParabolicPde3")
        .def(py::init<::AbstractCellPopulation<3, 3> &, double, double, double >())
        .def("rGetCellPopulation", (::AbstractCellPopulation<3, 3> const & (AveragedSourceParabolicPde3::*)()) &AveragedSourceParabolicPde3::rGetCellPopulation, "" )
        .def("SetupSourceTerms", (void (AveragedSourceParabolicPde3::*)(::TetrahedralMesh<3, 3> &, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > *)) &AveragedSourceParabolicPde3::SetupSourceTerms, "" , py::arg("rCoarseMesh"), py::arg("pCellPdeElementMap") = nullptr)
        .def("ComputeDuDtCoefficientFunction", (double (AveragedSourceParabolicPde3::*)(::ChastePoint<3> const &)) &AveragedSourceParabolicPde3::ComputeDuDtCoefficientFunction, "" , py::arg("rX"))
        .def("ComputeSourceTerm", (double (AveragedSourceParabolicPde3::*)(::ChastePoint<3> const &, double, ::Element<3, 3> *)) &AveragedSourceParabolicPde3::ComputeSourceTerm, "" , py::arg("rX"), py::arg("u"), py::arg("pElement") = __null)
        .def("ComputeSourceTermAtNode", (double (AveragedSourceParabolicPde3::*)(::Node<3> const &, double)) &AveragedSourceParabolicPde3::ComputeSourceTermAtNode, "" , py::arg("rNode"), py::arg("u"))
        .def("ComputeDiffusionTerm", (::boost::numeric::ublas::c_matrix<double, 3, 3> (AveragedSourceParabolicPde3::*)(::ChastePoint<3> const &, ::Element<3, 3> *)) &AveragedSourceParabolicPde3::ComputeDiffusionTerm, "" , py::arg("rX"), py::arg("pElement") = __null)
        .def("GetUptakeRateForElement", (double (AveragedSourceParabolicPde3::*)(unsigned int)) &AveragedSourceParabolicPde3::GetUptakeRateForElement, "" , py::arg("elementIndex"))
    ;
}
