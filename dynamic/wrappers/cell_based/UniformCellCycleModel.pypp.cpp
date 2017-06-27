#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "UniformCellCycleModel.pypp.hpp"

namespace py = pybind11;

typedef UniformCellCycleModel UniformCellCycleModel;
class UniformCellCycleModel_Overloads : public UniformCellCycleModel{
    public:
    using UniformCellCycleModel::UniformCellCycleModel;

        void SetCellCycleDuration() override {
        PYBIND11_OVERLOAD(
        void,
        UniformCellCycleModel,
        SetCellCycleDuration,
        
        );
        }
        ::AbstractCellCycleModel * CreateCellCycleModel() override {
        PYBIND11_OVERLOAD(
        ::AbstractCellCycleModel *,
        UniformCellCycleModel,
        CreateCellCycleModel,
        
        );
        }
        double GetAverageTransitCellCycleTime() override {
        PYBIND11_OVERLOAD(
        double,
        UniformCellCycleModel,
        GetAverageTransitCellCycleTime,
        
        );
        }
        double GetAverageStemCellCycleTime() override {
        PYBIND11_OVERLOAD(
        double,
        UniformCellCycleModel,
        GetAverageStemCellCycleTime,
        
        );
        }
        void OutputCellCycleModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        UniformCellCycleModel,
        OutputCellCycleModelParameters,
        rParamsFile        
        );
        }

};
void register_UniformCellCycleModel_class(py::module &m){
    py::class_<UniformCellCycleModel, UniformCellCycleModel_Overloads, std::shared_ptr<UniformCellCycleModel > , AbstractSimpleCellCycleModel  >(m, "UniformCellCycleModel")
        .def(py::init< >())
        .def("SetCellCycleDuration", (void (UniformCellCycleModel::*)()) &UniformCellCycleModel::SetCellCycleDuration, "" )
        .def("CreateCellCycleModel", (::AbstractCellCycleModel * (UniformCellCycleModel::*)()) &UniformCellCycleModel::CreateCellCycleModel, "" )
        .def("GetMinCellCycleDuration", (double (UniformCellCycleModel::*)()) &UniformCellCycleModel::GetMinCellCycleDuration, "" )
        .def("SetMinCellCycleDuration", (void (UniformCellCycleModel::*)(double)) &UniformCellCycleModel::SetMinCellCycleDuration, "" , py::arg("minCellCycleDuration"))
        .def("GetMaxCellCycleDuration", (double (UniformCellCycleModel::*)()) &UniformCellCycleModel::GetMaxCellCycleDuration, "" )
        .def("SetMaxCellCycleDuration", (void (UniformCellCycleModel::*)(double)) &UniformCellCycleModel::SetMaxCellCycleDuration, "" , py::arg("maxCellCycleDuration"))
        .def("GetAverageTransitCellCycleTime", (double (UniformCellCycleModel::*)()) &UniformCellCycleModel::GetAverageTransitCellCycleTime, "" )
        .def("GetAverageStemCellCycleTime", (double (UniformCellCycleModel::*)()) &UniformCellCycleModel::GetAverageStemCellCycleTime, "" )
        .def("OutputCellCycleModelParameters", (void (UniformCellCycleModel::*)(::out_stream &)) &UniformCellCycleModel::OutputCellCycleModelParameters, "" , py::arg("rParamsFile"))
    ;
}
