#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCaUpdateRule3.pypp.hpp"

namespace py = pybind11;

typedef AbstractCaUpdateRule<3 > AbstractCaUpdateRule3;

class AbstractCaUpdateRule3_Overloads : public AbstractCaUpdateRule3{
    public:
    using AbstractCaUpdateRule3::AbstractCaUpdateRule;

        double EvaluateProbability(unsigned int currentNodeIndex, unsigned int targetNodeIndex, ::CaBasedCellPopulation<3> & rCellPopulation, double dt, double deltaX, ::CellPtr cell)override {
        PYBIND11_OVERLOAD_PURE(
        double,
        AbstractCaUpdateRule3,
        EvaluateProbability,
        currentNodeIndex, 
        targetNodeIndex, 
        rCellPopulation, 
        dt, 
        deltaX, 
        cell        
        );
        }
        void OutputUpdateRuleParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        AbstractCaUpdateRule3,
        OutputUpdateRuleParameters,
        rParamsFile        
        );
        }

};
void register_AbstractCaUpdateRule3_class(py::module &m){
    py::class_<AbstractCaUpdateRule3, AbstractCaUpdateRule3_Overloads, std::shared_ptr<AbstractCaUpdateRule3 >  >(m, "AbstractCaUpdateRule3")
        .def("EvaluateProbability", (double (AbstractCaUpdateRule3::*)(unsigned int, unsigned int, ::CaBasedCellPopulation<3> &, double, double, ::CellPtr)) &AbstractCaUpdateRule3::EvaluateProbability, "" , py::arg("currentNodeIndex"), py::arg("targetNodeIndex"), py::arg("rCellPopulation"), py::arg("dt"), py::arg("deltaX"), py::arg("cell"))
        .def("OutputUpdateRuleParameters", (void (AbstractCaUpdateRule3::*)(::out_stream &)) &AbstractCaUpdateRule3::OutputUpdateRuleParameters, "" , py::arg("rParamsFile"))
    ;
}
