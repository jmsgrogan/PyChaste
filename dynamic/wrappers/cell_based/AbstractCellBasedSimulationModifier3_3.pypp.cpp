#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellBasedSimulationModifier3_3.pypp.hpp"

namespace py = pybind11;
typedef AbstractCellBasedSimulationModifier<3,3 > AbstractCellBasedSimulationModifier3_3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractCellBasedSimulationModifier3_3_Overloads : public AbstractCellBasedSimulationModifier3_3{
    public:
    using AbstractCellBasedSimulationModifier3_3::AbstractCellBasedSimulationModifier;
    void UpdateAtEndOfTimeStep(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulationModifier3_3,
            UpdateAtEndOfTimeStep,
            rCellPopulation);
    }
    void UpdateAtEndOfOutputTimeStep(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            AbstractCellBasedSimulationModifier3_3,
            UpdateAtEndOfOutputTimeStep,
            rCellPopulation);
    }
    void SetupSolve(::AbstractCellPopulation<3, 3> & rCellPopulation, ::std::string outputDirectory) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulationModifier3_3,
            SetupSolve,
            rCellPopulation, 
outputDirectory);
    }
    void UpdateAtEndOfSolve(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            AbstractCellBasedSimulationModifier3_3,
            UpdateAtEndOfSolve,
            rCellPopulation);
    }
    void OutputSimulationModifierParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulationModifier3_3,
            OutputSimulationModifierParameters,
            rParamsFile);
    }

};
void register_AbstractCellBasedSimulationModifier3_3_class(py::module &m){
py::class_<AbstractCellBasedSimulationModifier3_3 , AbstractCellBasedSimulationModifier3_3_Overloads , boost::shared_ptr<AbstractCellBasedSimulationModifier3_3 >  , Identifiable  >(m, "AbstractCellBasedSimulationModifier3_3")
        .def(
            "UpdateAtEndOfTimeStep", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::AbstractCellPopulation<3, 3> &)) &AbstractCellBasedSimulationModifier3_3::UpdateAtEndOfTimeStep, 
            " " , py::arg("rCellPopulation"))
        .def(
            "UpdateAtEndOfOutputTimeStep", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::AbstractCellPopulation<3, 3> &)) &AbstractCellBasedSimulationModifier3_3::UpdateAtEndOfOutputTimeStep, 
            " " , py::arg("rCellPopulation"))
        .def(
            "SetupSolve", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::AbstractCellPopulation<3, 3> &, ::std::string)) &AbstractCellBasedSimulationModifier3_3::SetupSolve, 
            " " , py::arg("rCellPopulation"), py::arg("outputDirectory"))
        .def(
            "UpdateAtEndOfSolve", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::AbstractCellPopulation<3, 3> &)) &AbstractCellBasedSimulationModifier3_3::UpdateAtEndOfSolve, 
            " " , py::arg("rCellPopulation"))
        .def(
            "OutputSimulationModifierInfo", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::out_stream &)) &AbstractCellBasedSimulationModifier3_3::OutputSimulationModifierInfo, 
            " " , py::arg("rParamsFile"))
        .def(
            "OutputSimulationModifierParameters", 
            (void(AbstractCellBasedSimulationModifier3_3::*)(::out_stream &)) &AbstractCellBasedSimulationModifier3_3::OutputSimulationModifierParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
