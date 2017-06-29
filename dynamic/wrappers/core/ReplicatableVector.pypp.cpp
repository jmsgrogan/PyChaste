#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ReplicatableVector.pypp.hpp"

namespace py = pybind11;

typedef ReplicatableVector ReplicatableVector;

void register_ReplicatableVector_class(py::module &m){
    py::class_<ReplicatableVector, std::shared_ptr<ReplicatableVector >  >(m, "ReplicatableVector")
        .def(py::init< >())
        .def(py::init<unsigned int >())
        .def("GetSize", (unsigned int (ReplicatableVector::*)()) &ReplicatableVector::GetSize, "" )
        .def("Resize", (void (ReplicatableVector::*)(unsigned int)) &ReplicatableVector::Resize, "" , py::arg("size"))
        .def("Replicate", (void (ReplicatableVector::*)(unsigned int, unsigned int)) &ReplicatableVector::Replicate, "" , py::arg("lo"), py::arg("hi"))
    ;
}
