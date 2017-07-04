#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AveragedSourceEllipticPde.hpp"

#include "AveragedSourceEllipticPde2.cppwg.hpp"

namespace py = pybind11;
typedef AveragedSourceEllipticPde<2 > AveragedSourceEllipticPde2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::numeric::ublas::c_matrix<double, 2, 2> _boost_numeric_ublas_c_matrixdouble_2_2;

class AveragedSourceEllipticPde2_Overloads : public AveragedSourceEllipticPde2{
    public:
    using AveragedSourceEllipticPde2::AveragedSourceEllipticPde;
    void SetupSourceTerms(::TetrahedralMesh<2, 2> & rCoarseMesh, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > * pCellPdeElementMap) override {
        PYBIND11_OVERLOAD(
            void,
            AveragedSourceEllipticPde2,
            SetupSourceTerms,
            rCoarseMesh, 
pCellPdeElementMap);
    }
    double ComputeConstantInUSourceTerm(::ChastePoint<2> const & rX, ::Element<2, 2> * pElement) override {
        PYBIND11_OVERLOAD(
            double,
            AveragedSourceEllipticPde2,
            ComputeConstantInUSourceTerm,
            rX, 
pElement);
    }
    double ComputeLinearInUCoeffInSourceTerm(::ChastePoint<2> const & rX, ::Element<2, 2> * pElement) override {
        PYBIND11_OVERLOAD(
            double,
            AveragedSourceEllipticPde2,
            ComputeLinearInUCoeffInSourceTerm,
            rX, 
pElement);
    }
    ::boost::numeric::ublas::c_matrix<double, 2, 2> ComputeDiffusionTerm(::ChastePoint<2> const & rX) override {
        PYBIND11_OVERLOAD(
            _boost_numeric_ublas_c_matrixdouble_2_2,
            AveragedSourceEllipticPde2,
            ComputeDiffusionTerm,
            rX);
    }

};
void register_AveragedSourceEllipticPde2_class(py::module &m){
py::class_<AveragedSourceEllipticPde2 , AveragedSourceEllipticPde2_Overloads , boost::shared_ptr<AveragedSourceEllipticPde2 >   >(m, "AveragedSourceEllipticPde2")
        .def(py::init<::AbstractCellPopulation<2, 2> &, double, double >(), py::arg("rCellPopulation"), py::arg("sourceCoefficient") = 0., py::arg("diffusionCoefficient") = 1.)
        .def(
            "rGetCellPopulation", 
            (::AbstractCellPopulation<2, 2> const &(AveragedSourceEllipticPde2::*)() const ) &AveragedSourceEllipticPde2::rGetCellPopulation, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "GetCoefficient", 
            (double(AveragedSourceEllipticPde2::*)() const ) &AveragedSourceEllipticPde2::GetCoefficient, 
            " "  )
        .def(
            "SetupSourceTerms", 
            (void(AveragedSourceEllipticPde2::*)(::TetrahedralMesh<2, 2> &, ::std::map<boost::shared_ptr<Cell>, unsigned int, std::less<boost::shared_ptr<Cell> >, std::allocator<std::pair<const boost::shared_ptr<Cell>, unsigned int> > > *)) &AveragedSourceEllipticPde2::SetupSourceTerms, 
            " " , py::arg("rCoarseMesh"), py::arg("pCellPdeElementMap") = nullptr )
        .def(
            "ComputeConstantInUSourceTerm", 
            (double(AveragedSourceEllipticPde2::*)(::ChastePoint<2> const &, ::Element<2, 2> *)) &AveragedSourceEllipticPde2::ComputeConstantInUSourceTerm, 
            " " , py::arg("rX"), py::arg("pElement") )
        .def(
            "ComputeLinearInUCoeffInSourceTerm", 
            (double(AveragedSourceEllipticPde2::*)(::ChastePoint<2> const &, ::Element<2, 2> *)) &AveragedSourceEllipticPde2::ComputeLinearInUCoeffInSourceTerm, 
            " " , py::arg("rX"), py::arg("pElement") )
        .def(
            "ComputeDiffusionTerm", 
            (::boost::numeric::ublas::c_matrix<double, 2, 2>(AveragedSourceEllipticPde2::*)(::ChastePoint<2> const &)) &AveragedSourceEllipticPde2::ComputeDiffusionTerm, 
            " " , py::arg("rX") )
        .def(
            "GetUptakeRateForElement", 
            (double(AveragedSourceEllipticPde2::*)(unsigned int)) &AveragedSourceEllipticPde2::GetUptakeRateForElement, 
            " " , py::arg("elementIndex") )
    ;
}
