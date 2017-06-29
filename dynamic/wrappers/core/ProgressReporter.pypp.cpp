#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ProgressReporter.pypp.hpp"

namespace py = pybind11;

typedef ProgressReporter ProgressReporter;

void register_ProgressReporter_class(py::module &m){
    py::class_<ProgressReporter, std::shared_ptr<ProgressReporter >  >(m, "ProgressReporter")
        .def(py::init<::std::string, double, double >())
        .def("Update", (void (ProgressReporter::*)(double)) &ProgressReporter::Update, "" , py::arg("currentTime"))
        .def("PrintFinalising", (void (ProgressReporter::*)()) &ProgressReporter::PrintFinalising, "" )
        .def("PrintInitialising", (void (ProgressReporter::*)()) &ProgressReporter::PrintInitialising, "" )
    ;
}
