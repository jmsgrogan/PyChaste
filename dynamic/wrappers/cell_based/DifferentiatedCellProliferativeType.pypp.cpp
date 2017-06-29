#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "DifferentiatedCellProliferativeType.pypp.hpp"

namespace py = pybind11;

typedef DifferentiatedCellProliferativeType DifferentiatedCellProliferativeType;

void register_DifferentiatedCellProliferativeType_class(py::module &m){
    py::class_<DifferentiatedCellProliferativeType, std::shared_ptr<DifferentiatedCellProliferativeType > , AbstractCellProliferativeType  >(m, "DifferentiatedCellProliferativeType")
        .def(py::init< >())
    ;
}
