#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "TransitCellProliferativeType.hpp"

#include "TransitCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
typedef TransitCellProliferativeType TransitCellProliferativeType;
;

void register_TransitCellProliferativeType_class(py::module &m){
py::class_<TransitCellProliferativeType   , AbstractCellProliferativeType  >(m, "TransitCellProliferativeType")
        .def(py::init< >())
    ;
}
