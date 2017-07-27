#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractCellBasedSimulation.hpp"

#include "PythonObjectConverters.hpp"
#include "AbstractCellBasedSimulation2_2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
typedef AbstractCellBasedSimulation<2,2 > AbstractCellBasedSimulation2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef unsigned int unsignedint;

class AbstractCellBasedSimulation2_2_Overloads : public AbstractCellBasedSimulation2_2{
    public:
    using AbstractCellBasedSimulation2_2::AbstractCellBasedSimulation;
    void OutputSimulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulation2_2,
            OutputSimulationParameters,
            rParamsFile);
    }
    void WriteVisualizerSetupFile() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractCellBasedSimulation2_2,
            WriteVisualizerSetupFile,
            );
    }
    unsigned int DoCellBirth() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            AbstractCellBasedSimulation2_2,
            DoCellBirth,
            );
    }
    void SetupSolve() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractCellBasedSimulation2_2,
            SetupSolve,
            );
    }
    bool StoppingEventHasOccurred() override {
        PYBIND11_OVERLOAD(
            bool,
            AbstractCellBasedSimulation2_2,
            StoppingEventHasOccurred,
            );
    }
    void UpdateCellPopulation() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractCellBasedSimulation2_2,
            UpdateCellPopulation,
            );
    }
    void UpdateCellLocationsAndTopology() override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulation2_2,
            UpdateCellLocationsAndTopology,
            );
    }
    void OutputAdditionalSimulationSetup(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellBasedSimulation2_2,
            OutputAdditionalSimulationSetup,
            rParamsFile);
    }

};
void register_AbstractCellBasedSimulation2_2_class(py::module &m){
py::class_<AbstractCellBasedSimulation2_2 , AbstractCellBasedSimulation2_2_Overloads , boost::shared_ptr<AbstractCellBasedSimulation2_2 >   >(m, "AbstractCellBasedSimulation2_2")
        .def(py::init<::AbstractCellPopulation<2, 2> &, bool, bool >(), py::arg("rCellPopulation"), py::arg("deleteCellPopulationInDestructor") = false, py::arg("initialiseCells") = true)
        .def(
            "GetNodeLocation", 
            (::std::vector<double, std::allocator<double> >(AbstractCellBasedSimulation2_2::*)(unsigned int const &)) &AbstractCellBasedSimulation2_2::GetNodeLocation, 
            " " , py::arg("rNodeIndex") )
        .def(
            "GetDt", 
            (double(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetDt, 
            " "  )
        .def(
            "GetNumBirths", 
            (unsigned int(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetNumBirths, 
            " "  )
        .def(
            "GetNumDeaths", 
            (unsigned int(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetNumDeaths, 
            " "  )
        .def(
            "GetOutputDirectory", 
            (::std::string(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetOutputDirectory, 
            " "  )
        .def(
            "SetDt", 
            (void(AbstractCellBasedSimulation2_2::*)(double)) &AbstractCellBasedSimulation2_2::SetDt, 
            " " , py::arg("dt") )
        .def(
            "SetEndTime", 
            (void(AbstractCellBasedSimulation2_2::*)(double)) &AbstractCellBasedSimulation2_2::SetEndTime, 
            " " , py::arg("endTime") )
        .def(
            "SetOutputDirectory", 
            (void(AbstractCellBasedSimulation2_2::*)(::std::string)) &AbstractCellBasedSimulation2_2::SetOutputDirectory, 
            " " , py::arg("outputDirectory") )
        .def(
            "SetSamplingTimestepMultiple", 
            (void(AbstractCellBasedSimulation2_2::*)(unsigned int)) &AbstractCellBasedSimulation2_2::SetSamplingTimestepMultiple, 
            " " , py::arg("samplingTimestepMultiple") )
        .def(
            "SetNoBirth", 
            (void(AbstractCellBasedSimulation2_2::*)(bool)) &AbstractCellBasedSimulation2_2::SetNoBirth, 
            " " , py::arg("noBirth") )
        .def(
            "SetUpdateCellPopulationRule", 
            (void(AbstractCellBasedSimulation2_2::*)(bool)) &AbstractCellBasedSimulation2_2::SetUpdateCellPopulationRule, 
            " " , py::arg("updateCellPopulation") )
        .def(
            "GetUpdateCellPopulationRule", 
            (bool(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetUpdateCellPopulationRule, 
            " "  )
        .def(
            "AddCellKiller", 
            (void(AbstractCellBasedSimulation2_2::*)(::boost::shared_ptr<AbstractCellKiller<2> >)) &AbstractCellBasedSimulation2_2::AddCellKiller, 
            " " , py::arg("pCellKiller") )
        .def(
            "RemoveAllCellKillers", 
            (void(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::RemoveAllCellKillers, 
            " "  )
        .def(
            "AddSimulationModifier", 
            (void(AbstractCellBasedSimulation2_2::*)(::boost::shared_ptr<AbstractCellBasedSimulationModifier<2, 2> >)) &AbstractCellBasedSimulation2_2::AddSimulationModifier, 
            " " , py::arg("pSimulationModifier") )
        .def(
            "Solve", 
            (void(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::Solve, 
            " "  )
        .def(
            "rGetCellPopulation", 
            (::AbstractCellPopulation<2, 2> &(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::rGetCellPopulation, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "rGetCellPopulation", 
            (::AbstractCellPopulation<2, 2> const &(AbstractCellBasedSimulation2_2::*)() const ) &AbstractCellBasedSimulation2_2::rGetCellPopulation, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "GetOutputDivisionLocations", 
            (bool(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetOutputDivisionLocations, 
            " "  )
        .def(
            "SetOutputDivisionLocations", 
            (void(AbstractCellBasedSimulation2_2::*)(bool)) &AbstractCellBasedSimulation2_2::SetOutputDivisionLocations, 
            " " , py::arg("outputDivisionLocations") )
        .def(
            "GetOutputCellVelocities", 
            (bool(AbstractCellBasedSimulation2_2::*)()) &AbstractCellBasedSimulation2_2::GetOutputCellVelocities, 
            " "  )
        .def(
            "SetOutputCellVelocities", 
            (void(AbstractCellBasedSimulation2_2::*)(bool)) &AbstractCellBasedSimulation2_2::SetOutputCellVelocities, 
            " " , py::arg("outputCellVelocities") )
        .def(
            "OutputSimulationParameters", 
            (void(AbstractCellBasedSimulation2_2::*)(::out_stream &)) &AbstractCellBasedSimulation2_2::OutputSimulationParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
