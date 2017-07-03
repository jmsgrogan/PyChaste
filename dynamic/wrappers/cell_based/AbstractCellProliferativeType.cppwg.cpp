#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractCellProliferativeType.hpp"

#include "AbstractCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
typedef AbstractCellProliferativeType AbstractCellProliferativeType;
;

void register_AbstractCellProliferativeType_class(py::module &m){
py::class_<AbstractCellProliferativeType   , AbstractCellProperty  >(m, "AbstractCellProliferativeType")
        .def(py::init<unsigned int >(), py::arg("colour"))
        .def(
            "GetColour", 
            (unsigned int(AbstractCellProliferativeType::*)() const ) &AbstractCellProliferativeType::GetColour, 
            " " )
    ;
}
