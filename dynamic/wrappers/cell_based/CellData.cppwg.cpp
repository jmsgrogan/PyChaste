#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "CellData.hpp"

#include "CellData.cppwg.hpp"

namespace py = pybind11;
typedef CellData CellData;
;

void register_CellData_class(py::module &m){
py::class_<CellData   , AbstractCellProperty  >(m, "CellData")
        .def(
            "SetItem", 
            (void(CellData::*)(::std::string const &, double)) &CellData::SetItem, 
            " " , py::arg("rVariableName"), py::arg("data"))
        .def(
            "GetItem", 
            (double(CellData::*)(::std::string const &) const ) &CellData::GetItem, 
            " " , py::arg("rVariableName"))
        .def(
            "GetNumItems", 
            (unsigned int(CellData::*)() const ) &CellData::GetNumItems, 
            " " )
        .def(
            "GetKeys", 
            (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >(CellData::*)() const ) &CellData::GetKeys, 
            " " )
    ;
}
