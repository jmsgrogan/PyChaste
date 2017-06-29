#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "WildTypeCellMutationState.pypp.hpp"

namespace py = pybind11;
typedef WildTypeCellMutationState WildTypeCellMutationState;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_WildTypeCellMutationState_class(py::module &m){
py::class_<WildTypeCellMutationState  , boost::shared_ptr<WildTypeCellMutationState >  , AbstractCellMutationState  >(m, "WildTypeCellMutationState")
        .def(py::init< >())
    ;
}
