#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "DiffusionCaUpdateRule.hpp"

#include "PythonObjectConverters.hpp"
#include "DiffusionCaUpdateRule3.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef DiffusionCaUpdateRule<3 > DiffusionCaUpdateRule3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class DiffusionCaUpdateRule3_Overloads : public DiffusionCaUpdateRule3{
    public:
    using DiffusionCaUpdateRule3::DiffusionCaUpdateRule;
    double EvaluateProbability(unsigned int currentNodeIndex, unsigned int targetNodeIndex, ::CaBasedCellPopulation<3> & rCellPopulation, double dt, double deltaX, ::CellPtr cell) override {
        PYBIND11_OVERLOAD(
            double,
            DiffusionCaUpdateRule3,
            EvaluateProbability,
            currentNodeIndex, 
targetNodeIndex, 
rCellPopulation, 
dt, 
deltaX, 
cell);
    }
    void OutputUpdateRuleParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            DiffusionCaUpdateRule3,
            OutputUpdateRuleParameters,
            rParamsFile);
    }

};
void register_DiffusionCaUpdateRule3_class(py::module &m){
py::class_<DiffusionCaUpdateRule3 , DiffusionCaUpdateRule3_Overloads , boost::shared_ptr<DiffusionCaUpdateRule3 >  , AbstractCaUpdateRule<3>  >(m, "DiffusionCaUpdateRule3")
        .def(py::init< >())
        .def(
            "EvaluateProbability", 
            (double(DiffusionCaUpdateRule3::*)(unsigned int, unsigned int, ::CaBasedCellPopulation<3> &, double, double, ::CellPtr)) &DiffusionCaUpdateRule3::EvaluateProbability, 
            " " , py::arg("currentNodeIndex"), py::arg("targetNodeIndex"), py::arg("rCellPopulation"), py::arg("dt"), py::arg("deltaX"), py::arg("cell") )
        .def(
            "GetDiffusionParameter", 
            (double(DiffusionCaUpdateRule3::*)()) &DiffusionCaUpdateRule3::GetDiffusionParameter, 
            " "  )
        .def(
            "SetDiffusionParameter", 
            (void(DiffusionCaUpdateRule3::*)(double)) &DiffusionCaUpdateRule3::SetDiffusionParameter, 
            " " , py::arg("diffusionParameter") )
        .def(
            "OutputUpdateRuleParameters", 
            (void(DiffusionCaUpdateRule3::*)(::out_stream &)) &DiffusionCaUpdateRule3::OutputUpdateRuleParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
