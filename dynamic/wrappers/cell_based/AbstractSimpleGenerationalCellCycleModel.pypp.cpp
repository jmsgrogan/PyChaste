#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractSimpleGenerationalCellCycleModel.pypp.hpp"

namespace py = pybind11;

typedef AbstractSimpleGenerationalCellCycleModel AbstractSimpleGenerationalCellCycleModel;
class AbstractSimpleGenerationalCellCycleModel_Overloads : public AbstractSimpleGenerationalCellCycleModel{
    public:
    using AbstractSimpleGenerationalCellCycleModel::AbstractSimpleGenerationalCellCycleModel;

        void ResetForDivision() override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSimpleGenerationalCellCycleModel,
        ResetForDivision,
        
        );
        }
        void InitialiseDaughterCell() override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSimpleGenerationalCellCycleModel,
        InitialiseDaughterCell,
        
        );
        }
        void OutputCellCycleModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        AbstractSimpleGenerationalCellCycleModel,
        OutputCellCycleModelParameters,
        rParamsFile        
        );
        }

};
void register_AbstractSimpleGenerationalCellCycleModel_class(py::module &m){
    py::class_<AbstractSimpleGenerationalCellCycleModel, AbstractSimpleGenerationalCellCycleModel_Overloads, std::shared_ptr<AbstractSimpleGenerationalCellCycleModel > , AbstractSimplePhaseBasedCellCycleModel  >(m, "AbstractSimpleGenerationalCellCycleModel")
        .def(py::init< >())
        .def("ResetForDivision", (void (AbstractSimpleGenerationalCellCycleModel::*)()) &AbstractSimpleGenerationalCellCycleModel::ResetForDivision, "" )
        .def("InitialiseDaughterCell", (void (AbstractSimpleGenerationalCellCycleModel::*)()) &AbstractSimpleGenerationalCellCycleModel::InitialiseDaughterCell, "" )
        .def("SetGeneration", (void (AbstractSimpleGenerationalCellCycleModel::*)(unsigned int)) &AbstractSimpleGenerationalCellCycleModel::SetGeneration, "" , py::arg("generation"))
        .def("GetGeneration", (unsigned int (AbstractSimpleGenerationalCellCycleModel::*)()) &AbstractSimpleGenerationalCellCycleModel::GetGeneration, "" )
        .def("SetMaxTransitGenerations", (void (AbstractSimpleGenerationalCellCycleModel::*)(unsigned int)) &AbstractSimpleGenerationalCellCycleModel::SetMaxTransitGenerations, "" , py::arg("maxTransitGenerations"))
        .def("GetMaxTransitGenerations", (unsigned int (AbstractSimpleGenerationalCellCycleModel::*)()) &AbstractSimpleGenerationalCellCycleModel::GetMaxTransitGenerations, "" )
        .def("OutputCellCycleModelParameters", (void (AbstractSimpleGenerationalCellCycleModel::*)(::out_stream &)) &AbstractSimpleGenerationalCellCycleModel::OutputCellCycleModelParameters, "" , py::arg("rParamsFile"))
    ;
}
