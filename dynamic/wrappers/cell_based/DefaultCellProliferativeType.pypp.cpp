#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "DefaultCellProliferativeType.pypp.hpp"

namespace py = pybind11;

typedef DefaultCellProliferativeType DefaultCellProliferativeType;

void register_DefaultCellProliferativeType_class(py::module &m){
    py::class_<DefaultCellProliferativeType, std::shared_ptr<DefaultCellProliferativeType > , AbstractCellProliferativeType  >(m, "DefaultCellProliferativeType")
        .def(py::init< >())
    ;
}
