#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ApoptoticCellKiller3.pypp.hpp"

namespace py = pybind11;

typedef ApoptoticCellKiller<3 > ApoptoticCellKiller3;
class ApoptoticCellKiller3_Overloads : public ApoptoticCellKiller3{
    public:
    using ApoptoticCellKiller3::ApoptoticCellKiller<3>;

        void CheckAndLabelCellsForApoptosisOrDeath() override {
        PYBIND11_OVERLOAD(
        void,
        ApoptoticCellKiller3,
        CheckAndLabelCellsForApoptosisOrDeath,
        
        );
        }
        void OutputCellKillerParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        ApoptoticCellKiller3,
        OutputCellKillerParameters,
        rParamsFile        
        );
        }

};
void register_ApoptoticCellKiller3_class(py::module &m){
    py::class_<ApoptoticCellKiller3, ApoptoticCellKiller3_Overloads, std::shared_ptr<ApoptoticCellKiller3 >  >(m, "ApoptoticCellKiller3")
        .def(py::init<::AbstractCellPopulation<3, 3> * >())
        .def("CheckAndLabelSingleCellForApoptosis", (void (ApoptoticCellKiller3::*)(::CellPtr)) &ApoptoticCellKiller3::CheckAndLabelSingleCellForApoptosis, "" , py::arg("pCell"))
        .def("CheckAndLabelCellsForApoptosisOrDeath", (void (ApoptoticCellKiller3::*)()) &ApoptoticCellKiller3::CheckAndLabelCellsForApoptosisOrDeath, "" )
        .def("OutputCellKillerParameters", (void (ApoptoticCellKiller3::*)(::out_stream &)) &ApoptoticCellKiller3::OutputCellKillerParameters, "" , py::arg("rParamsFile"))
    ;
}
