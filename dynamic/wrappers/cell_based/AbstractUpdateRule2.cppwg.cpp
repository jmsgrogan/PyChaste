#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractUpdateRule.hpp"

#include "PythonObjectConverters.hpp"
#include "AbstractUpdateRule2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef AbstractUpdateRule<2 > AbstractUpdateRule2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractUpdateRule2_Overloads : public AbstractUpdateRule2{
    public:
    using AbstractUpdateRule2::AbstractUpdateRule;
    void OutputUpdateRuleParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractUpdateRule2,
            OutputUpdateRuleParameters,
            rParamsFile);
    }

};
void register_AbstractUpdateRule2_class(py::module &m){
py::class_<AbstractUpdateRule2 , AbstractUpdateRule2_Overloads , boost::shared_ptr<AbstractUpdateRule2 >   >(m, "AbstractUpdateRule2")
        .def(py::init< >())
        .def(
            "OutputUpdateRuleInfo", 
            (void(AbstractUpdateRule2::*)(::out_stream &)) &AbstractUpdateRule2::OutputUpdateRuleInfo, 
            " " , py::arg("rParamsFile") )
        .def(
            "OutputUpdateRuleParameters", 
            (void(AbstractUpdateRule2::*)(::out_stream &)) &AbstractUpdateRule2::OutputUpdateRuleParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
