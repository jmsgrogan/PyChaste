#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "TransitCellProliferativeType.pypp.hpp"

namespace py = pybind11;

typedef TransitCellProliferativeType TransitCellProliferativeType;

void register_TransitCellProliferativeType_class(py::module &m){
    py::class_<TransitCellProliferativeType, std::shared_ptr<TransitCellProliferativeType > , AbstractCellProliferativeType  >(m, "TransitCellProliferativeType")
        .def(py::init< >())
    ;
}
