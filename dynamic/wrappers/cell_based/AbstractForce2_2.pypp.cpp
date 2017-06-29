#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractForce2_2.pypp.hpp"

namespace py = pybind11;

typedef AbstractForce<2,2 > AbstractForce2_2;

class AbstractForce2_2_Overloads : public AbstractForce2_2{
    public:
    using AbstractForce2_2::AbstractForce;

        void AddForceContribution(::AbstractCellPopulation<2, 2> & rCellPopulation)override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractForce2_2,
        AddForceContribution,
        rCellPopulation        
        );
        }
        void OutputForceParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractForce2_2,
        OutputForceParameters,
        rParamsFile        
        );
        }
        void WriteDataToVisualizerSetupFile(::out_stream & pVizSetupFile)override {
        PYBIND11_OVERLOAD(
        void,
        AbstractForce2_2,
        WriteDataToVisualizerSetupFile,
        pVizSetupFile        
        );
        }

};
void register_AbstractForce2_2_class(py::module &m){
    py::class_<AbstractForce2_2, AbstractForce2_2_Overloads, std::shared_ptr<AbstractForce2_2 > , Identifiable  >(m, "AbstractForce2_2")
        .def("AddForceContribution", (void (AbstractForce2_2::*)(::AbstractCellPopulation<2, 2> &)) &AbstractForce2_2::AddForceContribution, "" , py::arg("rCellPopulation"))
        .def("OutputForceInfo", (void (AbstractForce2_2::*)(::out_stream &)) &AbstractForce2_2::OutputForceInfo, "" , py::arg("rParamsFile"))
        .def("OutputForceParameters", (void (AbstractForce2_2::*)(::out_stream &)) &AbstractForce2_2::OutputForceParameters, "" , py::arg("rParamsFile"))
        .def("WriteDataToVisualizerSetupFile", (void (AbstractForce2_2::*)(::out_stream &)) &AbstractForce2_2::WriteDataToVisualizerSetupFile, "" , py::arg("pVizSetupFile"))
    ;
}
