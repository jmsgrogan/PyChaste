#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ConstBoundaryCondition3.pypp.hpp"

namespace py = pybind11;

typedef ConstBoundaryCondition<3 > ConstBoundaryCondition3;
class ConstBoundaryCondition3_Overloads : public ConstBoundaryCondition3{
    public:
    using ConstBoundaryCondition3::ConstBoundaryCondition<3>;

        double GetValue(::ChastePoint<3> const & rX) override {
        PYBIND11_OVERLOAD(
        double,
        ConstBoundaryCondition3,
        GetValue,
        rX        
        );
        }

};
void register_ConstBoundaryCondition3_class(py::module &m){
    py::class_<ConstBoundaryCondition3, ConstBoundaryCondition3_Overloads, std::shared_ptr<ConstBoundaryCondition3 >  >(m, "ConstBoundaryCondition3")
        .def(py::init<double const >())
        .def("GetValue", (double (ConstBoundaryCondition3::*)(::ChastePoint<3> const &)) &ConstBoundaryCondition3::GetValue, "" , py::arg("rX"))
    ;
}
