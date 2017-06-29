#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellProperty.pypp.hpp"

namespace py = pybind11;
typedef AbstractCellProperty AbstractCellProperty;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_AbstractCellProperty_class(py::module &m){
py::class_<AbstractCellProperty  , boost::shared_ptr<AbstractCellProperty >  , Identifiable  >(m, "AbstractCellProperty")
        .def(py::init< >())
        .def(
            "IsSame", 
            (bool(AbstractCellProperty::*)(::AbstractCellProperty const *) const ) &AbstractCellProperty::IsSame, 
            " " , py::arg("pOther"))
        .def(
            "IsSame", 
            (bool(AbstractCellProperty::*)(::boost::shared_ptr<const AbstractCellProperty>) const ) &AbstractCellProperty::IsSame, 
            " " , py::arg("pOther"))
        .def(
            "IncrementCellCount", 
            (void(AbstractCellProperty::*)()) &AbstractCellProperty::IncrementCellCount, 
            " " )
        .def(
            "DecrementCellCount", 
            (void(AbstractCellProperty::*)()) &AbstractCellProperty::DecrementCellCount, 
            " " )
        .def(
            "GetCellCount", 
            (unsigned int(AbstractCellProperty::*)() const ) &AbstractCellProperty::GetCellCount, 
            " " )
    ;
}
