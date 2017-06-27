#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "ConstBoundaryCondition2.pypp.hpp"

namespace py = pybind11;

typedef ConstBoundaryCondition<2 > ConstBoundaryCondition2;
class ConstBoundaryCondition2_Overloads : public ConstBoundaryCondition2{
    public:
    using ConstBoundaryCondition2::ConstBoundaryCondition<2>;

        double GetValue(::ChastePoint<2> const & rX) override {
        PYBIND11_OVERLOAD(
        double,
        ConstBoundaryCondition2,
        GetValue,
        rX        
        );
        }

};
void register_ConstBoundaryCondition2_class(py::module &m){
    py::class_<ConstBoundaryCondition2, ConstBoundaryCondition2_Overloads, std::shared_ptr<ConstBoundaryCondition2 >  >(m, "ConstBoundaryCondition2")
        .def(py::init<double const >())
        .def("GetValue", (double (ConstBoundaryCondition2::*)(::ChastePoint<2> const &)) &ConstBoundaryCondition2::GetValue, "" , py::arg("rX"))
    ;
}
