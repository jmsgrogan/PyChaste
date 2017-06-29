#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "OnLatticeSimulation3.pypp.hpp"

namespace py = pybind11;
typedef OnLatticeSimulation<3 > OnLatticeSimulation3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class OnLatticeSimulation3_Overloads : public OnLatticeSimulation3{
    public:
    using OnLatticeSimulation3::OnLatticeSimulation;
    void OutputAdditionalSimulationSetup(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            OnLatticeSimulation3,
            OutputAdditionalSimulationSetup,
            rParamsFile);
    }
    void OutputSimulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            OnLatticeSimulation3,
            OutputSimulationParameters,
            rParamsFile);
    }
    void UpdateCellPopulation() override {
        PYBIND11_OVERLOAD(
            void,
            OnLatticeSimulation3,
            UpdateCellPopulation,
            );
    }
    void UpdateCellLocationsAndTopology() override {
        PYBIND11_OVERLOAD(
            void,
            OnLatticeSimulation3,
            UpdateCellLocationsAndTopology,
            );
    }

};
void register_OnLatticeSimulation3_class(py::module &m){
py::class_<OnLatticeSimulation3 , OnLatticeSimulation3_Overloads , boost::shared_ptr<OnLatticeSimulation3 >   >(m, "OnLatticeSimulation3")
        .def(py::init<::AbstractCellPopulation<3, 3> &, bool, bool >())
        .def(
            "AddUpdateRule", 
            (void(OnLatticeSimulation3::*)(::boost::shared_ptr<AbstractUpdateRule<3> >)) &OnLatticeSimulation3::AddUpdateRule, 
            " " , py::arg("pUpdateRule"))
        .def(
            "RemoveAllUpdateRules", 
            (void(OnLatticeSimulation3::*)()) &OnLatticeSimulation3::RemoveAllUpdateRules, 
            " " )
        .def(
            "OutputAdditionalSimulationSetup", 
            (void(OnLatticeSimulation3::*)(::out_stream &)) &OnLatticeSimulation3::OutputAdditionalSimulationSetup, 
            " " , py::arg("rParamsFile"))
        .def(
            "OutputSimulationParameters", 
            (void(OnLatticeSimulation3::*)(::out_stream &)) &OnLatticeSimulation3::OutputSimulationParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
