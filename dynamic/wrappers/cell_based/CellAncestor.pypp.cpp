#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellAncestor.pypp.hpp"

namespace py = pybind11;

typedef CellAncestor CellAncestor;
void register_CellAncestor_class(py::module &m){
    py::class_<CellAncestor, std::shared_ptr<CellAncestor > , AbstractCellProperty  >(m, "CellAncestor")
        .def(py::init<unsigned int >())
        .def("GetAncestor", (unsigned int (CellAncestor::*)()) &CellAncestor::GetAncestor, "" )
    ;
}
