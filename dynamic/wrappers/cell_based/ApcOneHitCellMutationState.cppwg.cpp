#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "ApcOneHitCellMutationState.hpp"

#include "ApcOneHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
typedef ApcOneHitCellMutationState ApcOneHitCellMutationState;
;

void register_ApcOneHitCellMutationState_class(py::module &m){
py::class_<ApcOneHitCellMutationState   , AbstractCellMutationState  >(m, "ApcOneHitCellMutationState")
        .def(py::init< >())
    ;
}
