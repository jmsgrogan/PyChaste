#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "DefaultCellProliferativeType.hpp"

#include "DefaultCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
typedef DefaultCellProliferativeType DefaultCellProliferativeType;
;

void register_DefaultCellProliferativeType_class(py::module &m){
py::class_<DefaultCellProliferativeType   , AbstractCellProliferativeType  >(m, "DefaultCellProliferativeType")
        .def(py::init< >())
    ;
}
