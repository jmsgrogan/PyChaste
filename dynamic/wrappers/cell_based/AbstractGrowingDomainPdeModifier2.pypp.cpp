#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractGrowingDomainPdeModifier2.pypp.hpp"

namespace py = pybind11;

typedef AbstractGrowingDomainPdeModifier<2 > AbstractGrowingDomainPdeModifier2;
class AbstractGrowingDomainPdeModifier2_Overloads : public AbstractGrowingDomainPdeModifier2{
    public:
    using AbstractGrowingDomainPdeModifier2::AbstractGrowingDomainPdeModifier<2>;

        void OutputSimulationModifierParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        AbstractGrowingDomainPdeModifier2,
        OutputSimulationModifierParameters,
        rParamsFile        
        );
        }

};
void register_AbstractGrowingDomainPdeModifier2_class(py::module &m){
    py::class_<AbstractGrowingDomainPdeModifier2, AbstractGrowingDomainPdeModifier2_Overloads, std::shared_ptr<AbstractGrowingDomainPdeModifier2 >  >(m, "AbstractGrowingDomainPdeModifier2")
        .def("GenerateFeMesh", (void (AbstractGrowingDomainPdeModifier2::*)(::AbstractCellPopulation<2, 2> &)) &AbstractGrowingDomainPdeModifier2::GenerateFeMesh, "" , py::arg("rCellPopulation"))
        .def("UpdateCellData", (void (AbstractGrowingDomainPdeModifier2::*)(::AbstractCellPopulation<2, 2> &)) &AbstractGrowingDomainPdeModifier2::UpdateCellData, "" , py::arg("rCellPopulation"))
        .def("OutputSimulationModifierParameters", (void (AbstractGrowingDomainPdeModifier2::*)(::out_stream &)) &AbstractGrowingDomainPdeModifier2::OutputSimulationModifierParameters, "" , py::arg("rParamsFile"))
    ;
}
