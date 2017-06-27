#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractSrnModel.pypp.hpp"

namespace py = pybind11;

typedef AbstractSrnModel AbstractSrnModel;
class AbstractSrnModel_Overloads : public AbstractSrnModel{
    public:
    using AbstractSrnModel::AbstractSrnModel;

        void Initialise() override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSrnModel,
        Initialise,
        
        );
        }
        void InitialiseDaughterCell() override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSrnModel,
        InitialiseDaughterCell,
        
        );
        }
        void SimulateToCurrentTime() override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractSrnModel,
        SimulateToCurrentTime,
        
        );
        }
        void ResetForDivision() override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSrnModel,
        ResetForDivision,
        
        );
        }
        ::AbstractSrnModel * CreateSrnModel() override {
        PYBIND11_OVERLOAD_PURE(
        ::AbstractSrnModel *,
        AbstractSrnModel,
        CreateSrnModel,
        
        );
        }
        void OutputSrnModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSrnModel,
        OutputSrnModelParameters,
        rParamsFile        
        );
        }

};
void register_AbstractSrnModel_class(py::module &m){
    py::class_<AbstractSrnModel, AbstractSrnModel_Overloads, std::shared_ptr<AbstractSrnModel > , Identifiable  >(m, "AbstractSrnModel")
        .def("SetCell", (void (AbstractSrnModel::*)(::CellPtr)) &AbstractSrnModel::SetCell, "" , py::arg("pCell"))
        .def("Initialise", (void (AbstractSrnModel::*)()) &AbstractSrnModel::Initialise, "" )
        .def("InitialiseDaughterCell", (void (AbstractSrnModel::*)()) &AbstractSrnModel::InitialiseDaughterCell, "" )
        .def("GetCell", (::CellPtr (AbstractSrnModel::*)()) &AbstractSrnModel::GetCell, "" )
        .def("SetSimulatedToTime", (void (AbstractSrnModel::*)(double)) &AbstractSrnModel::SetSimulatedToTime, "" , py::arg("simulatedToTime"))
        .def("GetSimulatedToTime", (double (AbstractSrnModel::*)()) &AbstractSrnModel::GetSimulatedToTime, "" )
        .def("SimulateToCurrentTime", (void (AbstractSrnModel::*)()) &AbstractSrnModel::SimulateToCurrentTime, "" )
        .def("ResetForDivision", (void (AbstractSrnModel::*)()) &AbstractSrnModel::ResetForDivision, "" )
        .def("CreateSrnModel", (::AbstractSrnModel * (AbstractSrnModel::*)()) &AbstractSrnModel::CreateSrnModel, "" )
        .def("OutputSrnModelInfo", (void (AbstractSrnModel::*)(::out_stream &)) &AbstractSrnModel::OutputSrnModelInfo, "" , py::arg("rParamsFile"))
        .def("OutputSrnModelParameters", (void (AbstractSrnModel::*)(::out_stream &)) &AbstractSrnModel::OutputSrnModelParameters, "" , py::arg("rParamsFile"))
    ;
}
