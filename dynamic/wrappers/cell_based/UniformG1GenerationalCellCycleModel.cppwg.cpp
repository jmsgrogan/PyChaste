#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "UniformG1GenerationalCellCycleModel.hpp"

#include "PythonObjectConverters.hpp"
#include "UniformG1GenerationalCellCycleModel.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
typedef UniformG1GenerationalCellCycleModel UniformG1GenerationalCellCycleModel;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::AbstractCellCycleModel * _AbstractCellCycleModelPtr;

class UniformG1GenerationalCellCycleModel_Overloads : public UniformG1GenerationalCellCycleModel{
    public:
    using UniformG1GenerationalCellCycleModel::UniformG1GenerationalCellCycleModel;
    ::AbstractCellCycleModel * CreateCellCycleModel() override {
        PYBIND11_OVERLOAD(
            _AbstractCellCycleModelPtr,
            UniformG1GenerationalCellCycleModel,
            CreateCellCycleModel,
            );
    }
    void OutputCellCycleModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            UniformG1GenerationalCellCycleModel,
            OutputCellCycleModelParameters,
            rParamsFile);
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
py::class_<UniformG1GenerationalCellCycleModel , UniformG1GenerationalCellCycleModel_Overloads , boost::shared_ptr<UniformG1GenerationalCellCycleModel >  , AbstractSimpleGenerationalCellCycleModel  >(m, "UniformG1GenerationalCellCycleModel")
        .def(py::init< >())
        .def(
            "CreateCellCycleModel", 
            (::AbstractCellCycleModel *(UniformG1GenerationalCellCycleModel::*)()) &UniformG1GenerationalCellCycleModel::CreateCellCycleModel, 
            " "  , py::return_value_policy::reference)
        .def(
            "OutputCellCycleModelParameters", 
            (void(UniformG1GenerationalCellCycleModel::*)(::out_stream &)) &UniformG1GenerationalCellCycleModel::OutputCellCycleModelParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
