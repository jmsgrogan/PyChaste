#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellId.pypp.hpp"

namespace py = pybind11;

typedef CellId CellId;

void register_CellId_class(py::module &m){
    py::class_<CellId, std::shared_ptr<CellId > , AbstractCellProperty  >(m, "CellId")
        .def(py::init< >())
        .def("AssignCellId", (void (CellId::*)()) &CellId::AssignCellId, "" )
        .def("GetMaxCellId", (unsigned int (CellId::*)() const ) &CellId::GetMaxCellId, "" )
        .def("GetCellId", (unsigned int (CellId::*)() const ) &CellId::GetCellId, "" )
        .def_static("ResetMaxCellId", (void (*)()) &CellId::ResetMaxCellId, "" )
    ;
}
