#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellProliferativeType.pypp.hpp"

namespace py = pybind11;
typedef AbstractCellProliferativeType AbstractCellProliferativeType;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_AbstractCellProliferativeType_class(py::module &m){
py::class_<AbstractCellProliferativeType  , boost::shared_ptr<AbstractCellProliferativeType >  , AbstractCellProperty  >(m, "AbstractCellProliferativeType")
        .def(py::init<unsigned int >())
        .def(
            "GetColour", 
            (unsigned int(AbstractCellProliferativeType::*)() const ) &AbstractCellProliferativeType::GetColour, 
            " " )
    ;
}
