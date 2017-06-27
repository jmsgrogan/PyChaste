#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractBoundaryCondition3.pypp.hpp"

namespace py = pybind11;

typedef AbstractBoundaryCondition<3 > AbstractBoundaryCondition3;
class AbstractBoundaryCondition3_Overloads : public AbstractBoundaryCondition3{
    public:
    using AbstractBoundaryCondition3::AbstractBoundaryCondition<3>;

        double GetValue(::ChastePoint<3> const & rX) override {
        PYBIND11_OVERLOAD_PURE(
        double,
        AbstractBoundaryCondition3,
        GetValue,
        rX        
        );
        }

};
void register_AbstractBoundaryCondition3_class(py::module &m){
    py::class_<AbstractBoundaryCondition3, AbstractBoundaryCondition3_Overloads, std::shared_ptr<AbstractBoundaryCondition3 >  >(m, "AbstractBoundaryCondition3")
        .def("GetValue", (double (AbstractBoundaryCondition3::*)(::ChastePoint<3> const &)) &AbstractBoundaryCondition3::GetValue, "" , py::arg("rX"))
    ;
}
