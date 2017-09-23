#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractSimpleCellCycleModel.hpp"

#include "PythonObjectConverters.hpp"
#include "AbstractSimpleCellCycleModel.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef AbstractSimpleCellCycleModel AbstractSimpleCellCycleModel;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractSimpleCellCycleModel_Overloads : public AbstractSimpleCellCycleModel{
    public:
    using AbstractSimpleCellCycleModel::AbstractSimpleCellCycleModel;
    bool ReadyToDivide() override {
        PYBIND11_OVERLOAD(
            bool,
            AbstractSimpleCellCycleModel,
            ReadyToDivide,
            );
    }
    void ResetForDivision() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractSimpleCellCycleModel,
            ResetForDivision,
            );
    }
    void InitialiseDaughterCell() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractSimpleCellCycleModel,
            InitialiseDaughterCell,
            );
    }
    void Initialise() override {
        PYBIND11_OVERLOAD(
            void,
            AbstractSimpleCellCycleModel,
            Initialise,
            );
    }
    void SetCellCycleDuration() override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractSimpleCellCycleModel,
            SetCellCycleDuration,
            );
    }
    void OutputCellCycleModelParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractSimpleCellCycleModel,
            OutputCellCycleModelParameters,
            rParamsFile);
    }

};
void register_AbstractSimpleCellCycleModel_class(py::module &m){
py::class_<AbstractSimpleCellCycleModel , AbstractSimpleCellCycleModel_Overloads , boost::shared_ptr<AbstractSimpleCellCycleModel >  , AbstractCellCycleModel  >(m, "AbstractSimpleCellCycleModel")
        .def(
            "ReadyToDivide", 
            (bool(AbstractSimpleCellCycleModel::*)()) &AbstractSimpleCellCycleModel::ReadyToDivide, 
            " "  )
        .def(
            "ResetForDivision", 
            (void(AbstractSimpleCellCycleModel::*)()) &AbstractSimpleCellCycleModel::ResetForDivision, 
            " "  )
        .def(
            "InitialiseDaughterCell", 
            (void(AbstractSimpleCellCycleModel::*)()) &AbstractSimpleCellCycleModel::InitialiseDaughterCell, 
            " "  )
        .def(
            "Initialise", 
            (void(AbstractSimpleCellCycleModel::*)()) &AbstractSimpleCellCycleModel::Initialise, 
            " "  )
        .def(
            "SetCellCycleDuration", 
            (void(AbstractSimpleCellCycleModel::*)()) &AbstractSimpleCellCycleModel::SetCellCycleDuration, 
            " "  )
        .def(
            "GetCellCycleDuration", 
            (double(AbstractSimpleCellCycleModel::*)() const ) &AbstractSimpleCellCycleModel::GetCellCycleDuration, 
            " "  )
        .def(
            "OutputCellCycleModelParameters", 
            (void(AbstractSimpleCellCycleModel::*)(::out_stream &)) &AbstractSimpleCellCycleModel::OutputCellCycleModelParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
