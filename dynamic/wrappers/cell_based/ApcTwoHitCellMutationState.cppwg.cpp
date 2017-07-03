#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "ApcTwoHitCellMutationState.hpp"

#include "ApcTwoHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
typedef ApcTwoHitCellMutationState ApcTwoHitCellMutationState;
;

void register_ApcTwoHitCellMutationState_class(py::module &m){
py::class_<ApcTwoHitCellMutationState   , AbstractCellMutationState  >(m, "ApcTwoHitCellMutationState")
        .def(py::init< >())
    ;
}
