#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "VtkSceneModifier2.pypp.hpp"

namespace py = pybind11;

typedef VtkSceneModifier<2 > VtkSceneModifier2;
class VtkSceneModifier2_Overloads : public VtkSceneModifier2{
    public:
    using VtkSceneModifier2::VtkSceneModifier<2>;

        void UpdateAtEndOfTimeStep(::AbstractCellPopulation<2, 2> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VtkSceneModifier2,
        UpdateAtEndOfTimeStep,
        rCellPopulation        
        );
        }
        void SetupSolve(::AbstractCellPopulation<2, 2> & rCellPopulation, ::std::string outputDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        VtkSceneModifier2,
        SetupSolve,
        rCellPopulation, 
        outputDirectory        
        );
        }
        void OutputSimulationModifierParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        VtkSceneModifier2,
        OutputSimulationModifierParameters,
        rParamsFile        
        );
        }

};
void register_VtkSceneModifier2_class(py::module &m){
    py::class_<VtkSceneModifier2, VtkSceneModifier2_Overloads, std::shared_ptr<VtkSceneModifier2 >  >(m, "VtkSceneModifier2")
        .def(py::init< >())
        .def("GetVtkScene", (::boost::shared_ptr<VtkScene<2> > (VtkSceneModifier2::*)()) &VtkSceneModifier2::GetVtkScene, "" )
        .def("UpdateAtEndOfTimeStep", (void (VtkSceneModifier2::*)(::AbstractCellPopulation<2, 2> &)) &VtkSceneModifier2::UpdateAtEndOfTimeStep, "" , py::arg("rCellPopulation"))
        .def("SetupSolve", (void (VtkSceneModifier2::*)(::AbstractCellPopulation<2, 2> &, ::std::string)) &VtkSceneModifier2::SetupSolve, "" , py::arg("rCellPopulation"), py::arg("outputDirectory"))
        .def("SetVtkScene", (void (VtkSceneModifier2::*)(::boost::shared_ptr<VtkScene<2> >)) &VtkSceneModifier2::SetVtkScene, "" , py::arg("pScene"))
        .def("UpdateCellData", (void (VtkSceneModifier2::*)(::AbstractCellPopulation<2, 2> &)) &VtkSceneModifier2::UpdateCellData, "" , py::arg("rCellPopulation"))
        .def("OutputSimulationModifierParameters", (void (VtkSceneModifier2::*)(::out_stream &)) &VtkSceneModifier2::OutputSimulationModifierParameters, "" , py::arg("rParamsFile"))
        .def("SetUpdateFrequency", (void (VtkSceneModifier2::*)(unsigned int)) &VtkSceneModifier2::SetUpdateFrequency, "" , py::arg("frequency"))
    ;
}
