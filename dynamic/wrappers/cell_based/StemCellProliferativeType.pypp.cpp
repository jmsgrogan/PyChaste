#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "StemCellProliferativeType.pypp.hpp"

namespace py = pybind11;

typedef StemCellProliferativeType StemCellProliferativeType;
void register_StemCellProliferativeType_class(py::module &m){
    py::class_<StemCellProliferativeType, std::shared_ptr<StemCellProliferativeType > , AbstractCellProliferativeType  >(m, "StemCellProliferativeType")
        .def(py::init< >())
    ;
}
