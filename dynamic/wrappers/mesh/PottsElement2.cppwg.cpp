#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "PottsElement.hpp"

#include "PottsElement2.cppwg.hpp"

namespace py = pybind11;
typedef PottsElement<2 > PottsElement2;
;

void register_PottsElement2_class(py::module &m){
py::class_<PottsElement2    >(m, "PottsElement2")
        .def(py::init<unsigned int, ::std::vector<Node<2> *, std::allocator<Node<2> *> > const & >(), py::arg("index"), py::arg("rNodes"))
        .def(
            "AddNode", 
            (void(PottsElement2::*)(::Node<2> *, unsigned int const &)) &PottsElement2::AddNode, 
            " " , py::arg("pNode"), py::arg("rIndex") = (2147483647 * 2U + 1U))
        .def(
            "GetAspectRatio", 
            (double(PottsElement2::*)()) &PottsElement2::GetAspectRatio, 
            " " )
    ;
}
