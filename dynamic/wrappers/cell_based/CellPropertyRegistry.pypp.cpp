#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellPropertyRegistry.pypp.hpp"

namespace py = pybind11;

typedef CellPropertyRegistry CellPropertyRegistry;
void register_CellPropertyRegistry_class(py::module &m){
    py::class_<CellPropertyRegistry, std::shared_ptr<CellPropertyRegistry >  >(m, "CellPropertyRegistry")
        .def_static("Instance", (::CellPropertyRegistry * (*)()) &CellPropertyRegistry::Instance, "" )
        .def("Clear", (void (CellPropertyRegistry::*)()) &CellPropertyRegistry::Clear, "" )
        .def("SpecifyOrdering", (void (CellPropertyRegistry::*)(::std::vector<boost::shared_ptr<AbstractCellProperty>, std::allocator<boost::shared_ptr<AbstractCellProperty> > > const &)) &CellPropertyRegistry::SpecifyOrdering, "" , py::arg("rOrdering"))
        .def("HasOrderingBeenSpecified", (bool (CellPropertyRegistry::*)()) &CellPropertyRegistry::HasOrderingBeenSpecified, "" )
    ;
}
