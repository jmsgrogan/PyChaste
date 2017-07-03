#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractVertexBasedDivisionRule.hpp"

#include "AbstractVertexBasedDivisionRule2.cppwg.hpp"

namespace py = pybind11;
typedef AbstractVertexBasedDivisionRule<2 > AbstractVertexBasedDivisionRule2;
;
typedef ::boost::numeric::ublas::c_vector<double, 2> _boost_numeric_ublas_c_vectordouble_2;

class AbstractVertexBasedDivisionRule2_Overloads : public AbstractVertexBasedDivisionRule2{
    public:
    using AbstractVertexBasedDivisionRule2::AbstractVertexBasedDivisionRule;
    ::boost::numeric::ublas::c_vector<double, 2> CalculateCellDivisionVector(::CellPtr pParentCell, ::VertexBasedCellPopulation<2> & rCellPopulation) override {
        PYBIND11_OVERLOAD_PURE(
            _boost_numeric_ublas_c_vectordouble_2,
            AbstractVertexBasedDivisionRule2,
            CalculateCellDivisionVector,
            pParentCell, 
rCellPopulation);
    }
    void OutputCellVertexBasedDivisionRuleParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            AbstractVertexBasedDivisionRule2,
            OutputCellVertexBasedDivisionRuleParameters,
            rParamsFile);
    }

};
void register_AbstractVertexBasedDivisionRule2_class(py::module &m){
py::class_<AbstractVertexBasedDivisionRule2 , AbstractVertexBasedDivisionRule2_Overloads   >(m, "AbstractVertexBasedDivisionRule2")
        .def(
            "CalculateCellDivisionVector", 
            (::boost::numeric::ublas::c_vector<double, 2>(AbstractVertexBasedDivisionRule2::*)(::CellPtr, ::VertexBasedCellPopulation<2> &)) &AbstractVertexBasedDivisionRule2::CalculateCellDivisionVector, 
            " " , py::arg("pParentCell"), py::arg("rCellPopulation"))
        .def(
            "OutputCellVertexBasedDivisionRuleInfo", 
            (void(AbstractVertexBasedDivisionRule2::*)(::out_stream &)) &AbstractVertexBasedDivisionRule2::OutputCellVertexBasedDivisionRuleInfo, 
            " " , py::arg("rParamsFile"))
    ;
}
