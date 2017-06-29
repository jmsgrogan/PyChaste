#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "DifferentialAdhesionPottsUpdateRule2.pypp.hpp"

namespace py = pybind11;

typedef DifferentialAdhesionPottsUpdateRule<2 > DifferentialAdhesionPottsUpdateRule2;

class DifferentialAdhesionPottsUpdateRule2_Overloads : public DifferentialAdhesionPottsUpdateRule2{
    public:
    using DifferentialAdhesionPottsUpdateRule2::DifferentialAdhesionPottsUpdateRule;

        double GetCellCellAdhesionEnergy(::CellPtr pCellA, ::CellPtr pCellB)override {
        PYBIND11_OVERLOAD(
        double,
        DifferentialAdhesionPottsUpdateRule2,
        GetCellCellAdhesionEnergy,
        pCellA, 
        pCellB        
        );
        }
        double GetCellBoundaryAdhesionEnergy(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        double,
        DifferentialAdhesionPottsUpdateRule2,
        GetCellBoundaryAdhesionEnergy,
        pCell        
        );
        }
        void OutputUpdateRuleParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        DifferentialAdhesionPottsUpdateRule2,
        OutputUpdateRuleParameters,
        rParamsFile        
        );
        }

};
void register_DifferentialAdhesionPottsUpdateRule2_class(py::module &m){
    py::class_<DifferentialAdhesionPottsUpdateRule2, DifferentialAdhesionPottsUpdateRule2_Overloads, std::shared_ptr<DifferentialAdhesionPottsUpdateRule2 >  >(m, "DifferentialAdhesionPottsUpdateRule2")
        .def(py::init< >())
        .def("GetCellCellAdhesionEnergy", (double (DifferentialAdhesionPottsUpdateRule2::*)(::CellPtr, ::CellPtr)) &DifferentialAdhesionPottsUpdateRule2::GetCellCellAdhesionEnergy, "" , py::arg("pCellA"), py::arg("pCellB"))
        .def("GetCellBoundaryAdhesionEnergy", (double (DifferentialAdhesionPottsUpdateRule2::*)(::CellPtr)) &DifferentialAdhesionPottsUpdateRule2::GetCellBoundaryAdhesionEnergy, "" , py::arg("pCell"))
        .def("GetLabelledCellLabelledCellAdhesionEnergyParameter", (double (DifferentialAdhesionPottsUpdateRule2::*)()) &DifferentialAdhesionPottsUpdateRule2::GetLabelledCellLabelledCellAdhesionEnergyParameter, "" )
        .def("GetLabelledCellCellAdhesionEnergyParameter", (double (DifferentialAdhesionPottsUpdateRule2::*)()) &DifferentialAdhesionPottsUpdateRule2::GetLabelledCellCellAdhesionEnergyParameter, "" )
        .def("GetLabelledCellBoundaryAdhesionEnergyParameter", (double (DifferentialAdhesionPottsUpdateRule2::*)()) &DifferentialAdhesionPottsUpdateRule2::GetLabelledCellBoundaryAdhesionEnergyParameter, "" )
        .def("SetLabelledCellLabelledCellAdhesionEnergyParameter", (void (DifferentialAdhesionPottsUpdateRule2::*)(double)) &DifferentialAdhesionPottsUpdateRule2::SetLabelledCellLabelledCellAdhesionEnergyParameter, "" , py::arg("labelledCellLabelledCellAdhesionEnergyParameter"))
        .def("SetLabelledCellCellAdhesionEnergyParameter", (void (DifferentialAdhesionPottsUpdateRule2::*)(double)) &DifferentialAdhesionPottsUpdateRule2::SetLabelledCellCellAdhesionEnergyParameter, "" , py::arg("labelledCellCellAdhesionEnergyParameter"))
        .def("SetLabelledCellBoundaryAdhesionEnergyParameter", (void (DifferentialAdhesionPottsUpdateRule2::*)(double)) &DifferentialAdhesionPottsUpdateRule2::SetLabelledCellBoundaryAdhesionEnergyParameter, "" , py::arg("labelledCellBoundaryAdhesionEnergyParameter"))
        .def("OutputUpdateRuleParameters", (void (DifferentialAdhesionPottsUpdateRule2::*)(::out_stream &)) &DifferentialAdhesionPottsUpdateRule2::OutputUpdateRuleParameters, "" , py::arg("rParamsFile"))
    ;
}
