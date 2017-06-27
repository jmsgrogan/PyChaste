#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "NullSrnModel.pypp.hpp"

namespace py = pybind11;

typedef NullSrnModel NullSrnModel;
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
        ::AbstractSrnModel *,
        NullSrnModel,
        CreateSrnModel,
        
        );
        }

};
void register_NullSrnModel_class(py::module &m){
    py::class_<NullSrnModel, NullSrnModel_Overloads, std::shared_ptr<NullSrnModel > , AbstractSrnModel  >(m, "NullSrnModel")
        .def(py::init< >())
        .def("SimulateToCurrentTime", (void (NullSrnModel::*)()) &NullSrnModel::SimulateToCurrentTime, "" )
        .def("CreateSrnModel", (::AbstractSrnModel * (NullSrnModel::*)()) &NullSrnModel::CreateSrnModel, "" )
    ;
}
