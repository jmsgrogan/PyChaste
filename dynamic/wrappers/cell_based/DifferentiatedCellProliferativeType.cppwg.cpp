#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "DifferentiatedCellProliferativeType.hpp"

#include "DifferentiatedCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
typedef DifferentiatedCellProliferativeType DifferentiatedCellProliferativeType;
;

void register_DifferentiatedCellProliferativeType_class(py::module &m){
py::class_<DifferentiatedCellProliferativeType   , AbstractCellProliferativeType  >(m, "DifferentiatedCellProliferativeType")
        .def(py::init< >())
    ;
}
