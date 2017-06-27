#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellProperty.pypp.hpp"

namespace py = pybind11;

typedef AbstractCellProperty AbstractCellProperty;
void register_AbstractCellProperty_class(py::module &m){
    py::class_<AbstractCellProperty, std::shared_ptr<AbstractCellProperty > , Identifiable  >(m, "AbstractCellProperty")
        .def(py::init< >())
        .def("IsSame", (bool (AbstractCellProperty::*)(::AbstractCellProperty const *)) &AbstractCellProperty::IsSame, "" , py::arg("pOther"))
        .def("IsSame", (bool (AbstractCellProperty::*)(::boost::shared_ptr<const AbstractCellProperty>)) &AbstractCellProperty::IsSame, "" , py::arg("pOther"))
        .def("IncrementCellCount", (void (AbstractCellProperty::*)()) &AbstractCellProperty::IncrementCellCount, "" )
        .def("DecrementCellCount", (void (AbstractCellProperty::*)()) &AbstractCellProperty::DecrementCellCount, "" )
        .def("GetCellCount", (unsigned int (AbstractCellProperty::*)()) &AbstractCellProperty::GetCellCount, "" )
    ;
}
