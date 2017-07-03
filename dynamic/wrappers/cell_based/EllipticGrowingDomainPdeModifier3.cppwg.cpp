#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "EllipticGrowingDomainPdeModifier.hpp"

#include "EllipticGrowingDomainPdeModifier3.cppwg.hpp"

namespace py = pybind11;
typedef EllipticGrowingDomainPdeModifier<3 > EllipticGrowingDomainPdeModifier3;
;
typedef ::std::shared_ptr<BoundaryConditionsContainer<3, 3, 1> > _std_shared_ptrBoundaryConditionsContainer3_3_1;

class EllipticGrowingDomainPdeModifier3_Overloads : public EllipticGrowingDomainPdeModifier3{
    public:
    using EllipticGrowingDomainPdeModifier3::EllipticGrowingDomainPdeModifier;
    void UpdateAtEndOfTimeStep(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier3,
            UpdateAtEndOfTimeStep,
            rCellPopulation);
    }
    void SetupSolve(::AbstractCellPopulation<3, 3> & rCellPopulation, ::std::string outputDirectory) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier3,
            SetupSolve,
            rCellPopulation, 
outputDirectory);
    }
    ::std::shared_ptr<BoundaryConditionsContainer<3, 3, 1> > ConstructBoundaryConditionsContainer() override {
        PYBIND11_OVERLOAD(
            _std_shared_ptrBoundaryConditionsContainer3_3_1,
            EllipticGrowingDomainPdeModifier3,
            ConstructBoundaryConditionsContainer,
            );
    }
    void OutputSimulationModifierParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            EllipticGrowingDomainPdeModifier3,
            OutputSimulationModifierParameters,
            rParamsFile);
    }

};
void register_EllipticGrowingDomainPdeModifier3_class(py::module &m){
py::class_<EllipticGrowingDomainPdeModifier3 , EllipticGrowingDomainPdeModifier3_Overloads   >(m, "EllipticGrowingDomainPdeModifier3")
        .def(
            "UpdateAtEndOfTimeStep", 
            (void(EllipticGrowingDomainPdeModifier3::*)(::AbstractCellPopulation<3, 3> &)) &EllipticGrowingDomainPdeModifier3::UpdateAtEndOfTimeStep, 
            " " , py::arg("rCellPopulation"))
        .def(
            "SetupSolve", 
            (void(EllipticGrowingDomainPdeModifier3::*)(::AbstractCellPopulation<3, 3> &, ::std::string)) &EllipticGrowingDomainPdeModifier3::SetupSolve, 
            " " , py::arg("rCellPopulation"), py::arg("outputDirectory"))
        .def(
            "OutputSimulationModifierParameters", 
            (void(EllipticGrowingDomainPdeModifier3::*)(::out_stream &)) &EllipticGrowingDomainPdeModifier3::OutputSimulationModifierParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
