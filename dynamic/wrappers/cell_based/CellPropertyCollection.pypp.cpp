#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellPropertyCollection.pypp.hpp"

namespace py = pybind11;

typedef CellPropertyCollection CellPropertyCollection;
void register_CellPropertyCollection_class(py::module &m){
    py::class_<CellPropertyCollection, std::shared_ptr<CellPropertyCollection >  >(m, "CellPropertyCollection")
        .def(py::init< >())
        .def("AddProperty", (void (CellPropertyCollection::*)(::boost::shared_ptr<AbstractCellProperty> const &)) &CellPropertyCollection::AddProperty, "" , py::arg("rProp"))
        .def("SetCellPropertyRegistry", (void (CellPropertyCollection::*)(::CellPropertyRegistry *)) &CellPropertyCollection::SetCellPropertyRegistry, "" , py::arg("pRegistry"))
        .def("HasProperty", (bool (CellPropertyCollection::*)(::boost::shared_ptr<AbstractCellProperty> const &)) &CellPropertyCollection::HasProperty, "" , py::arg("rProp"))
        .def("RemoveProperty", (void (CellPropertyCollection::*)(::boost::shared_ptr<AbstractCellProperty> const &)) &CellPropertyCollection::RemoveProperty, "" , py::arg("rProp"))
        .def("GetSize", (unsigned int (CellPropertyCollection::*)()) &CellPropertyCollection::GetSize, "" )
        .def("Begin", (::CellPropertyCollection::Iterator (CellPropertyCollection::*)()) &CellPropertyCollection::Begin, "" )
        .def("End", (::CellPropertyCollection::Iterator (CellPropertyCollection::*)()) &CellPropertyCollection::End, "" )
        .def("GetProperty", (::boost::shared_ptr<AbstractCellProperty> (CellPropertyCollection::*)()) &CellPropertyCollection::GetProperty, "" )
    ;
}
