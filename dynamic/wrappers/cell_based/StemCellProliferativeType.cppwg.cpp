#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "StemCellProliferativeType.hpp"

#include "StemCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
typedef StemCellProliferativeType StemCellProliferativeType;
;

void register_StemCellProliferativeType_class(py::module &m){
py::class_<StemCellProliferativeType   , AbstractCellProliferativeType  >(m, "StemCellProliferativeType")
        .def(py::init< >())
    ;
}
