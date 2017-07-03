#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "WildTypeCellMutationState.hpp"

#include "WildTypeCellMutationState.cppwg.hpp"

namespace py = pybind11;
typedef WildTypeCellMutationState WildTypeCellMutationState;
;

void register_WildTypeCellMutationState_class(py::module &m){
py::class_<WildTypeCellMutationState   , AbstractCellMutationState  >(m, "WildTypeCellMutationState")
        .def(py::init< >())
    ;
}
