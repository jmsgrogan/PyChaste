#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "UniformG1GenerationalCellCycleModel.pypp.hpp"

namespace py = pybind11;

typedef UniformG1GenerationalCellCycleModel UniformG1GenerationalCellCycleModel;
class UniformG1GenerationalCellCycleModel_Overloads : public UniformG1GenerationalCellCycleModel{
    public:
    using UniformG1GenerationalCellCycleModel::UniformG1GenerationalCellCycleModel;

        ::AbstractCellCycleModel * CreateCellCycleModel() override {
        PYBIND11_OVERLOAD(
        ::AbstractCellCycleModel *,
        UniformG1GenerationalCellCycleModel,
        CreateCellCycleModel,
        
        );
        }
        void OutputCellCycleModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        UniformG1GenerationalCellCycleModel,
        OutputCellCycleModelParameters,
        rParamsFile        
        );
        }
        void SetG1Duration() override {
        PYBIND11_OVERLOAD(
        void,
        UniformG1GenerationalCellCycleModel,
        SetG1Duration,
        
        );
        }

};
void register_UniformG1GenerationalCellCycleModel_class(py::module &m){
    py::class_<UniformG1GenerationalCellCycleModel, UniformG1GenerationalCellCycleModel_Overloads, std::shared_ptr<UniformG1GenerationalCellCycleModel > , AbstractSimpleGenerationalCellCycleModel  >(m, "UniformG1GenerationalCellCycleModel")
        .def(py::init< >())
        .def("CreateCellCycleModel", (::AbstractCellCycleModel * (UniformG1GenerationalCellCycleModel::*)()) &UniformG1GenerationalCellCycleModel::CreateCellCycleModel, "" )
        .def("OutputCellCycleModelParameters", (void (UniformG1GenerationalCellCycleModel::*)(::out_stream &)) &UniformG1GenerationalCellCycleModel::OutputCellCycleModelParameters, "" , py::arg("rParamsFile"))
    ;
}
