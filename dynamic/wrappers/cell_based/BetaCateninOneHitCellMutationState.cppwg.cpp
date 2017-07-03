#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "BetaCateninOneHitCellMutationState.hpp"

#include "BetaCateninOneHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
typedef BetaCateninOneHitCellMutationState BetaCateninOneHitCellMutationState;
;

void register_BetaCateninOneHitCellMutationState_class(py::module &m){
py::class_<BetaCateninOneHitCellMutationState   , AbstractCellMutationState  >(m, "BetaCateninOneHitCellMutationState")
        .def(py::init< >())
    ;
}
