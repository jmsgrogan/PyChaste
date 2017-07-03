#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "ReplicatableVector.hpp"

#include "ReplicatableVector.cppwg.hpp"

namespace py = pybind11;
typedef ReplicatableVector ReplicatableVector;
;

void register_ReplicatableVector_class(py::module &m){
py::class_<ReplicatableVector    >(m, "ReplicatableVector")
        .def(py::init< >())
        .def(py::init<unsigned int >(), py::arg("size"))
        .def(
            "GetSize", 
            (unsigned int(ReplicatableVector::*)()) &ReplicatableVector::GetSize, 
            " " )
        .def(
            "Resize", 
            (void(ReplicatableVector::*)(unsigned int)) &ReplicatableVector::Resize, 
            " " , py::arg("size"))
        .def(
            "Replicate", 
            (void(ReplicatableVector::*)(unsigned int, unsigned int)) &ReplicatableVector::Replicate, 
            " " , py::arg("lo"), py::arg("hi"))
    ;
}
