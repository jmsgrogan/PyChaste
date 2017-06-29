#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ApoptoticCellKiller2.pypp.hpp"

namespace py = pybind11;

typedef ApoptoticCellKiller<2 > ApoptoticCellKiller2;

class ApoptoticCellKiller2_Overloads : public ApoptoticCellKiller2{
    public:
    using ApoptoticCellKiller2::ApoptoticCellKiller;

        void CheckAndLabelCellsForApoptosisOrDeath()override {
        PYBIND11_OVERLOAD(
        void,
        ApoptoticCellKiller2,
        CheckAndLabelCellsForApoptosisOrDeath,
        
        );
        }
        void OutputCellKillerParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        ApoptoticCellKiller2,
        OutputCellKillerParameters,
        rParamsFile        
        );
        }

};
void register_ApoptoticCellKiller2_class(py::module &m){
    py::class_<ApoptoticCellKiller2, ApoptoticCellKiller2_Overloads, std::shared_ptr<ApoptoticCellKiller2 >  >(m, "ApoptoticCellKiller2")
        .def(py::init<::AbstractCellPopulation<2, 2> * >())
        .def("CheckAndLabelSingleCellForApoptosis", (void (ApoptoticCellKiller2::*)(::CellPtr)) &ApoptoticCellKiller2::CheckAndLabelSingleCellForApoptosis, "" , py::arg("pCell"))
        .def("CheckAndLabelCellsForApoptosisOrDeath", (void (ApoptoticCellKiller2::*)()) &ApoptoticCellKiller2::CheckAndLabelCellsForApoptosisOrDeath, "" )
        .def("OutputCellKillerParameters", (void (ApoptoticCellKiller2::*)(::out_stream &)) &ApoptoticCellKiller2::OutputCellKillerParameters, "" , py::arg("rParamsFile"))
    ;
}
