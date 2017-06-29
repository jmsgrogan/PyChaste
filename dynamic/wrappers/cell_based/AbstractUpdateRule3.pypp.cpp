#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractUpdateRule3.pypp.hpp"

namespace py = pybind11;

typedef AbstractUpdateRule<3 > AbstractUpdateRule3;

class AbstractUpdateRule3_Overloads : public AbstractUpdateRule3{
    public:
    using AbstractUpdateRule3::AbstractUpdateRule;

        void OutputUpdateRuleParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractUpdateRule3,
        OutputUpdateRuleParameters,
        rParamsFile        
        );
        }

};
void register_AbstractUpdateRule3_class(py::module &m){
    py::class_<AbstractUpdateRule3, AbstractUpdateRule3_Overloads, std::shared_ptr<AbstractUpdateRule3 > , Identifiable  >(m, "AbstractUpdateRule3")
        .def("OutputUpdateRuleInfo", (void (AbstractUpdateRule3::*)(::out_stream &)) &AbstractUpdateRule3::OutputUpdateRuleInfo, "" , py::arg("rParamsFile"))
        .def("OutputUpdateRuleParameters", (void (AbstractUpdateRule3::*)(::out_stream &)) &AbstractUpdateRule3::OutputUpdateRuleParameters, "" , py::arg("rParamsFile"))
    ;
}
