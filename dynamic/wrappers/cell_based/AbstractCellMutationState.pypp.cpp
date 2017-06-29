#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellMutationState.pypp.hpp"

namespace py = pybind11;

typedef AbstractCellMutationState AbstractCellMutationState;

void register_AbstractCellMutationState_class(py::module &m){
    py::class_<AbstractCellMutationState, std::shared_ptr<AbstractCellMutationState > , AbstractCellProperty  >(m, "AbstractCellMutationState")
        .def(py::init<unsigned int >())
        .def("GetColour", (unsigned int (AbstractCellMutationState::*)() const ) &AbstractCellMutationState::GetColour, "" )
    ;
}
