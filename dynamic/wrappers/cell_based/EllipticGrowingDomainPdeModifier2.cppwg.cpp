#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <petsc/private/vecimpl.h>
#include <petsc/private/matimpl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "EllipticGrowingDomainPdeModifier.hpp"

#include "PythonObjectConverters.hpp"
#include "EllipticGrowingDomainPdeModifier2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef EllipticGrowingDomainPdeModifier<2 > EllipticGrowingDomainPdeModifier2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
PYBIND11_MAKE_OPAQUE(Vec);
PYBIND11_MAKE_OPAQUE(Mat);
typedef ::std::shared_ptr<BoundaryConditionsContainer<2, 2, 1> > _std_shared_ptr_lt_BoundaryConditionsContainer_lt_2_2_1_gt__gt_;

class EllipticGrowingDomainPdeModifier2_Overloads : public EllipticGrowingDomainPdeModifier2{
    public:
    using EllipticGrowingDomainPdeModifier2::EllipticGrowingDomainPdeModifier;
    void UpdateAtEndOfTimeStep(::AbstractCellPopulation<2, 2> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier2,
            UpdateAtEndOfTimeStep,
            rCellPopulation);
    }
    void SetupSolve(::AbstractCellPopulation<2, 2> & rCellPopulation, ::std::string outputDirectory) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier2,
            SetupSolve,
            rCellPopulation, 
outputDirectory);
    }
    ::std::shared_ptr<BoundaryConditionsContainer<2, 2, 1> > ConstructBoundaryConditionsContainer() override {
        PYBIND11_OVERLOAD(
            _std_shared_ptr_lt_BoundaryConditionsContainer_lt_2_2_1_gt__gt_,
            EllipticGrowingDomainPdeModifier2,
            ConstructBoundaryConditionsContainer,
            );
    }
    void OutputSimulationModifierParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier2,
            OutputSimulationModifierParameters,
            rParamsFile);
    }

};
void register_EllipticGrowingDomainPdeModifier2_class(py::module &m){
py::class_<EllipticGrowingDomainPdeModifier2 , EllipticGrowingDomainPdeModifier2_Overloads , boost::shared_ptr<EllipticGrowingDomainPdeModifier2 >  , AbstractGrowingDomainPdeModifier<2>  >(m, "EllipticGrowingDomainPdeModifier2")
        .def(py::init<::boost::shared_ptr<AbstractLinearPde<2, 2> >, ::boost::shared_ptr<AbstractBoundaryCondition<2> >, bool, ::Vec >(), py::arg("pPde") = boost::shared_ptr<AbstractLinearPde<DIM, DIM> >(), py::arg("pBoundaryCondition") = boost::shared_ptr<AbstractBoundaryCondition<DIM> >(), py::arg("isNeumannBoundaryCondition") = true, py::arg("solution") = nullptr)
        .def(
            "UpdateAtEndOfTimeStep", 
            (void(EllipticGrowingDomainPdeModifier2::*)(::AbstractCellPopulation<2, 2> &)) &EllipticGrowingDomainPdeModifier2::UpdateAtEndOfTimeStep, 
            " " , py::arg("rCellPopulation") )
        .def(
            "SetupSolve", 
            (void(EllipticGrowingDomainPdeModifier2::*)(::AbstractCellPopulation<2, 2> &, ::std::string)) &EllipticGrowingDomainPdeModifier2::SetupSolve, 
            " " , py::arg("rCellPopulation"), py::arg("outputDirectory") )
        .def(
            "OutputSimulationModifierParameters", 
            (void(EllipticGrowingDomainPdeModifier2::*)(::out_stream &)) &EllipticGrowingDomainPdeModifier2::OutputSimulationModifierParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
