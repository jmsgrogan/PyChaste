#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "NullSrnModel.hpp"

#include "NullSrnModel.cppwg.hpp"

namespace py = pybind11;
typedef NullSrnModel NullSrnModel;
;
typedef ::AbstractSrnModel * _AbstractSrnModelPtr;

class NullSrnModel_Overloads : public NullSrnModel{
    public:
    using NullSrnModel::NullSrnModel;
    void SimulateToCurrentTime() override {
        PYBIND11_OVERLOAD(
            void,
            NullSrnModel,
            SimulateToCurrentTime,
            );
    }
    ::AbstractSrnModel * CreateSrnModel() override {
        PYBIND11_OVERLOAD(
            _AbstractSrnModelPtr,
            NullSrnModel,
            CreateSrnModel,
            );
    }

};
void register_NullSrnModel_class(py::module &m){
py::class_<NullSrnModel , NullSrnModel_Overloads  , AbstractSrnModel  >(m, "NullSrnModel")
        .def(py::init< >())
        .def(
            "SimulateToCurrentTime", 
            (void(NullSrnModel::*)()) &NullSrnModel::SimulateToCurrentTime, 
            " " )
        .def(
            "CreateSrnModel", 
            (::AbstractSrnModel *(NullSrnModel::*)()) &NullSrnModel::CreateSrnModel, 
            " " )
    ;
}
