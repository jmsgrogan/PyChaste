#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "TimeStepper.pypp.hpp"

namespace py = pybind11;
typedef TimeStepper TimeStepper;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_TimeStepper_class(py::module &m){
py::class_<TimeStepper  , boost::shared_ptr<TimeStepper >   >(m, "TimeStepper")
        .def(py::init<double, double, double, bool, ::std::vector<double, std::allocator<double> > >())
        .def(
            "AdvanceOneTimeStep", 
            (void(TimeStepper::*)()) &TimeStepper::AdvanceOneTimeStep, 
            " " )
        .def(
            "GetTime", 
            (double(TimeStepper::*)() const ) &TimeStepper::GetTime, 
            " " )
        .def(
            "GetNextTime", 
            (double(TimeStepper::*)() const ) &TimeStepper::GetNextTime, 
            " " )
        .def(
            "GetNextTimeStep", 
            (double(TimeStepper::*)()) &TimeStepper::GetNextTimeStep, 
            " " )
        .def(
            "GetIdealTimeStep", 
            (double(TimeStepper::*)()) &TimeStepper::GetIdealTimeStep, 
            " " )
        .def(
            "IsTimeAtEnd", 
            (bool(TimeStepper::*)() const ) &TimeStepper::IsTimeAtEnd, 
            " " )
        .def(
            "EstimateTimeSteps", 
            (unsigned int(TimeStepper::*)() const ) &TimeStepper::EstimateTimeSteps, 
            " " )
        .def(
            "GetTotalTimeStepsTaken", 
            (unsigned int(TimeStepper::*)() const ) &TimeStepper::GetTotalTimeStepsTaken, 
            " " )
        .def(
            "ResetTimeStep", 
            (void(TimeStepper::*)(double)) &TimeStepper::ResetTimeStep, 
            " " , py::arg("dt"))
    ;
}
