#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PdeSimulationTime.pypp.hpp"

namespace py = pybind11;

typedef PdeSimulationTime PdeSimulationTime;
void register_PdeSimulationTime_class(py::module &m){
    py::class_<PdeSimulationTime, std::shared_ptr<PdeSimulationTime >  >(m, "PdeSimulationTime")
        .def_static("SetTime", (void (*)(double)) &PdeSimulationTime::SetTime, "" , py::arg("time"))
        .def_static("GetTime", (double (*)()) &PdeSimulationTime::GetTime, "" )
        .def_static("SetPdeTimeStepAndNextTime", (void (*)(double, double)) &PdeSimulationTime::SetPdeTimeStepAndNextTime, "" , py::arg("timestep"), py::arg("next_time"))
        .def_static("GetPdeTimeStep", (double (*)()) &PdeSimulationTime::GetPdeTimeStep, "" )
        .def_static("GetNextTime", (double (*)()) &PdeSimulationTime::GetNextTime, "" )
        .def_static("GetPdeTimeStepInverse", (double (*)()) &PdeSimulationTime::GetPdeTimeStepInverse, "" )
    ;
}
