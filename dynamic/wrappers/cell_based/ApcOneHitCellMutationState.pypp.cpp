#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ApcOneHitCellMutationState.pypp.hpp"

namespace py = pybind11;

typedef ApcOneHitCellMutationState ApcOneHitCellMutationState;

void register_ApcOneHitCellMutationState_class(py::module &m){
    py::class_<ApcOneHitCellMutationState, std::shared_ptr<ApcOneHitCellMutationState > , AbstractCellMutationState  >(m, "ApcOneHitCellMutationState")
        .def(py::init< >())
    ;
}
