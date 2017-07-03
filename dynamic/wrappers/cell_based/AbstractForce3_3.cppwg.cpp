#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractForce.hpp"

#include "AbstractForce3_3.cppwg.hpp"

namespace py = pybind11;
typedef AbstractForce<3,3 > AbstractForce3_3;
;

class AbstractForce3_3_Overloads : public AbstractForce3_3{
    public:
    using AbstractForce3_3::AbstractForce;
    void AddForceContribution(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractForce3_3,
            AddForceContribution,
            rCellPopulation);
    }
    void OutputForceParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractForce3_3,
            OutputForceParameters,
            rParamsFile);
    }
    void WriteDataToVisualizerSetupFile(::out_stream & pVizSetupFile) override {
        PYBIND11_OVERLOAD(
            void,
            AbstractForce3_3,
            WriteDataToVisualizerSetupFile,
            pVizSetupFile);
    }

};
void register_AbstractForce3_3_class(py::module &m){
py::class_<AbstractForce3_3 , AbstractForce3_3_Overloads   >(m, "AbstractForce3_3")
        .def(
            "AddForceContribution", 
            (void(AbstractForce3_3::*)(::AbstractCellPopulation<3, 3> &)) &AbstractForce3_3::AddForceContribution, 
            " " , py::arg("rCellPopulation"))
        .def(
            "OutputForceInfo", 
            (void(AbstractForce3_3::*)(::out_stream &)) &AbstractForce3_3::OutputForceInfo, 
            " " , py::arg("rParamsFile"))
        .def(
            "OutputForceParameters", 
            (void(AbstractForce3_3::*)(::out_stream &)) &AbstractForce3_3::OutputForceParameters, 
            " " , py::arg("rParamsFile"))
        .def(
            "WriteDataToVisualizerSetupFile", 
            (void(AbstractForce3_3::*)(::out_stream &)) &AbstractForce3_3::WriteDataToVisualizerSetupFile, 
            " " , py::arg("pVizSetupFile"))
    ;
}
