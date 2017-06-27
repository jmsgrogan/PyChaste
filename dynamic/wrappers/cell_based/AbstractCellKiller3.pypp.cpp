#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellKiller3.pypp.hpp"

namespace py = pybind11;

typedef AbstractCellKiller<3 > AbstractCellKiller3;
class AbstractCellKiller3_Overloads : public AbstractCellKiller3{
    public:
    using AbstractCellKiller3::AbstractCellKiller<3>;

        void CheckAndLabelCellsForApoptosisOrDeath() override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractCellKiller3,
        CheckAndLabelCellsForApoptosisOrDeath,
        
        );
        }
        void OutputCellKillerParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractCellKiller3,
        OutputCellKillerParameters,
        rParamsFile        
        );
        }

};
void register_AbstractCellKiller3_class(py::module &m){
    py::class_<AbstractCellKiller3, AbstractCellKiller3_Overloads, std::shared_ptr<AbstractCellKiller3 > , Identifiable  >(m, "AbstractCellKiller3")
        .def("CheckAndLabelCellsForApoptosisOrDeath", (void (AbstractCellKiller3::*)()) &AbstractCellKiller3::CheckAndLabelCellsForApoptosisOrDeath, "" )
        .def("GetCellPopulation", (::AbstractCellPopulation<3, 3> const * (AbstractCellKiller3::*)()) &AbstractCellKiller3::GetCellPopulation, "" )
        .def("OutputCellKillerInfo", (void (AbstractCellKiller3::*)(::out_stream &)) &AbstractCellKiller3::OutputCellKillerInfo, "" , py::arg("rParamsFile"))
        .def("OutputCellKillerParameters", (void (AbstractCellKiller3::*)(::out_stream &)) &AbstractCellKiller3::OutputCellKillerParameters, "" , py::arg("rParamsFile"))
    ;
}
