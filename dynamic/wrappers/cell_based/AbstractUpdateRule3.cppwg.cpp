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
#include "AbstractUpdateRule3.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef AbstractUpdateRule<3 > AbstractUpdateRule3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractUpdateRule3_Overloads : public AbstractUpdateRule3{
    public:
    using AbstractUpdateRule3::AbstractUpdateRule;
    void OutputUpdateRuleParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractUpdateRule3,
            OutputUpdateRuleParameters,
            rParamsFile);
    }

};
void register_AbstractUpdateRule3_class(py::module &m){
py::class_<AbstractUpdateRule3 , AbstractUpdateRule3_Overloads , boost::shared_ptr<AbstractUpdateRule3 >   >(m, "AbstractUpdateRule3")
        .def(py::init< >())
        .def(
            "OutputUpdateRuleInfo", 
            (void(AbstractUpdateRule3::*)(::out_stream &)) &AbstractUpdateRule3::OutputUpdateRuleInfo, 
            " " , py::arg("rParamsFile") )
        .def(
            "OutputUpdateRuleParameters", 
            (void(AbstractUpdateRule3::*)(::out_stream &)) &AbstractUpdateRule3::OutputUpdateRuleParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
