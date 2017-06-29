#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "WildTypeCellMutationState.pypp.hpp"

namespace py = pybind11;

typedef WildTypeCellMutationState WildTypeCellMutationState;

void register_WildTypeCellMutationState_class(py::module &m){
    py::class_<WildTypeCellMutationState, std::shared_ptr<WildTypeCellMutationState > , AbstractCellMutationState  >(m, "WildTypeCellMutationState")
        .def(py::init< >())
    ;
}
