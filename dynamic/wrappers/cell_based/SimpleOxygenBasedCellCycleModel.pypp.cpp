#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "SimpleOxygenBasedCellCycleModel.pypp.hpp"

namespace py = pybind11;

typedef SimpleOxygenBasedCellCycleModel SimpleOxygenBasedCellCycleModel;
typedef ::AbstractCellCycleModel * _AbstractCellCycleModelPtr;

class SimpleOxygenBasedCellCycleModel_Overloads : public SimpleOxygenBasedCellCycleModel{
    public:
    using SimpleOxygenBasedCellCycleModel::SimpleOxygenBasedCellCycleModel;

        void UpdateCellCyclePhase()override {
        PYBIND11_OVERLOAD(
        void,
        SimpleOxygenBasedCellCycleModel,
        UpdateCellCyclePhase,
        
        );
        }
        ::AbstractCellCycleModel * CreateCellCycleModel()override {
        PYBIND11_OVERLOAD(
        _AbstractCellCycleModelPtr,
        SimpleOxygenBasedCellCycleModel,
        CreateCellCycleModel,
        
        );
        }
        void OutputCellCycleModelParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        SimpleOxygenBasedCellCycleModel,
        OutputCellCycleModelParameters,
        rParamsFile        
        );
        }

};
void register_SimpleOxygenBasedCellCycleModel_class(py::module &m){
    py::class_<SimpleOxygenBasedCellCycleModel, SimpleOxygenBasedCellCycleModel_Overloads, std::shared_ptr<SimpleOxygenBasedCellCycleModel > , AbstractSimplePhaseBasedCellCycleModel  >(m, "SimpleOxygenBasedCellCycleModel")
        .def(py::init< >())
        .def("UpdateCellCyclePhase", (void (SimpleOxygenBasedCellCycleModel::*)()) &SimpleOxygenBasedCellCycleModel::UpdateCellCyclePhase, "" )
        .def("UpdateHypoxicDuration", (void (SimpleOxygenBasedCellCycleModel::*)()) &SimpleOxygenBasedCellCycleModel::UpdateHypoxicDuration, "" )
        .def("GetCurrentHypoxicDuration", (double (SimpleOxygenBasedCellCycleModel::*)() const ) &SimpleOxygenBasedCellCycleModel::GetCurrentHypoxicDuration, "" )
        .def("GetCurrentHypoxiaOnsetTime", (double (SimpleOxygenBasedCellCycleModel::*)() const ) &SimpleOxygenBasedCellCycleModel::GetCurrentHypoxiaOnsetTime, "" )
        .def("CreateCellCycleModel", (::AbstractCellCycleModel * (SimpleOxygenBasedCellCycleModel::*)()) &SimpleOxygenBasedCellCycleModel::CreateCellCycleModel, "" )
        .def("GetHypoxicConcentration", (double (SimpleOxygenBasedCellCycleModel::*)() const ) &SimpleOxygenBasedCellCycleModel::GetHypoxicConcentration, "" )
        .def("SetHypoxicConcentration", (void (SimpleOxygenBasedCellCycleModel::*)(double)) &SimpleOxygenBasedCellCycleModel::SetHypoxicConcentration, "" , py::arg("hypoxicConcentration"))
        .def("GetQuiescentConcentration", (double (SimpleOxygenBasedCellCycleModel::*)() const ) &SimpleOxygenBasedCellCycleModel::GetQuiescentConcentration, "" )
        .def("SetQuiescentConcentration", (void (SimpleOxygenBasedCellCycleModel::*)(double)) &SimpleOxygenBasedCellCycleModel::SetQuiescentConcentration, "" , py::arg("quiescentConcentration"))
        .def("GetCriticalHypoxicDuration", (double (SimpleOxygenBasedCellCycleModel::*)() const ) &SimpleOxygenBasedCellCycleModel::GetCriticalHypoxicDuration, "" )
        .def("SetCriticalHypoxicDuration", (void (SimpleOxygenBasedCellCycleModel::*)(double)) &SimpleOxygenBasedCellCycleModel::SetCriticalHypoxicDuration, "" , py::arg("criticalHypoxicDuration"))
        .def("SetCurrentHypoxiaOnsetTime", (void (SimpleOxygenBasedCellCycleModel::*)(double)) &SimpleOxygenBasedCellCycleModel::SetCurrentHypoxiaOnsetTime, "" , py::arg("currentHypoxiaOnsetTime"))
        .def("OutputCellCycleModelParameters", (void (SimpleOxygenBasedCellCycleModel::*)(::out_stream &)) &SimpleOxygenBasedCellCycleModel::OutputCellCycleModelParameters, "" , py::arg("rParamsFile"))
    ;
}
