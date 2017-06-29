#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellProliferativeType.pypp.hpp"

namespace py = pybind11;

typedef AbstractCellProliferativeType AbstractCellProliferativeType;

void register_AbstractCellProliferativeType_class(py::module &m){
    py::class_<AbstractCellProliferativeType, std::shared_ptr<AbstractCellProliferativeType > , AbstractCellProperty  >(m, "AbstractCellProliferativeType")
        .def(py::init<unsigned int >())
        .def("GetColour", (unsigned int (AbstractCellProliferativeType::*)() const ) &AbstractCellProliferativeType::GetColour, "" )
    ;
}
