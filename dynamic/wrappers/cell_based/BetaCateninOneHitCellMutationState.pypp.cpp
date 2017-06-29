#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "BetaCateninOneHitCellMutationState.pypp.hpp"

namespace py = pybind11;
typedef BetaCateninOneHitCellMutationState BetaCateninOneHitCellMutationState;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_BetaCateninOneHitCellMutationState_class(py::module &m){
py::class_<BetaCateninOneHitCellMutationState  , boost::shared_ptr<BetaCateninOneHitCellMutationState >  , AbstractCellMutationState  >(m, "BetaCateninOneHitCellMutationState")
        .def(py::init< >())
    ;
}
