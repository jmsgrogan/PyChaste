#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "NoCellCycleModel.pypp.hpp"

namespace py = pybind11;

typedef NoCellCycleModel NoCellCycleModel;
typedef ::AbstractCellCycleModel * _AbstractCellCycleModelPtr;

class NoCellCycleModel_Overloads : public NoCellCycleModel{
    public:
    using NoCellCycleModel::NoCellCycleModel;

        bool ReadyToDivide()override {
        PYBIND11_OVERLOAD(
        bool,
        NoCellCycleModel,
        ReadyToDivide,
        
        );
        }
        ::AbstractCellCycleModel * CreateCellCycleModel()override {
        PYBIND11_OVERLOAD(
        _AbstractCellCycleModelPtr,
        NoCellCycleModel,
        CreateCellCycleModel,
        
        );
        }
        double GetAverageTransitCellCycleTime()override {
        PYBIND11_OVERLOAD(
        double,
        NoCellCycleModel,
        GetAverageTransitCellCycleTime,
        
        );
        }
        double GetAverageStemCellCycleTime()override {
        PYBIND11_OVERLOAD(
        double,
        NoCellCycleModel,
        GetAverageStemCellCycleTime,
        
        );
        }
        void OutputCellCycleModelParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        NoCellCycleModel,
        OutputCellCycleModelParameters,
        rParamsFile        
        );
        }

};
void register_NoCellCycleModel_class(py::module &m){
    py::class_<NoCellCycleModel, NoCellCycleModel_Overloads, std::shared_ptr<NoCellCycleModel > , AbstractCellCycleModel  >(m, "NoCellCycleModel")
        .def(py::init< >())
        .def("ReadyToDivide", (bool (NoCellCycleModel::*)()) &NoCellCycleModel::ReadyToDivide, "" )
        .def("CreateCellCycleModel", (::AbstractCellCycleModel * (NoCellCycleModel::*)()) &NoCellCycleModel::CreateCellCycleModel, "" )
        .def("GetAverageTransitCellCycleTime", (double (NoCellCycleModel::*)()) &NoCellCycleModel::GetAverageTransitCellCycleTime, "" )
        .def("GetAverageStemCellCycleTime", (double (NoCellCycleModel::*)()) &NoCellCycleModel::GetAverageStemCellCycleTime, "" )
        .def("OutputCellCycleModelParameters", (void (NoCellCycleModel::*)(::out_stream &)) &NoCellCycleModel::OutputCellCycleModelParameters, "" , py::arg("rParamsFile"))
    ;
}
