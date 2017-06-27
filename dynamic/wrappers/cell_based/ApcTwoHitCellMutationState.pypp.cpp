#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ApcTwoHitCellMutationState.pypp.hpp"

namespace py = pybind11;

typedef ApcTwoHitCellMutationState ApcTwoHitCellMutationState;
void register_ApcTwoHitCellMutationState_class(py::module &m){
    py::class_<ApcTwoHitCellMutationState, std::shared_ptr<ApcTwoHitCellMutationState > , AbstractCellMutationState  >(m, "ApcTwoHitCellMutationState")
        .def(py::init< >())
    ;
}
