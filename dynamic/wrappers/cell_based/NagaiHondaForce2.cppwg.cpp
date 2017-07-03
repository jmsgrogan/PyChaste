#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "NagaiHondaForce.hpp"

#include "NagaiHondaForce2.cppwg.hpp"

namespace py = pybind11;
typedef NagaiHondaForce<2 > NagaiHondaForce2;
;

class NagaiHondaForce2_Overloads : public NagaiHondaForce2{
    public:
    using NagaiHondaForce2::NagaiHondaForce;
    void AddForceContribution(::AbstractCellPopulation<2, 2> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            NagaiHondaForce2,
            AddForceContribution,
            rCellPopulation);
    }
    double GetAdhesionParameter(::Node<2> * pNodeA, ::Node<2> * pNodeB, ::VertexBasedCellPopulation<2> & rVertexCellPopulation) override {
        PYBIND11_OVERLOAD(
            double,
            NagaiHondaForce2,
            GetAdhesionParameter,
            pNodeA, 
pNodeB, 
rVertexCellPopulation);
    }
    void OutputForceParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            NagaiHondaForce2,
            OutputForceParameters,
            rParamsFile);
    }

};
void register_NagaiHondaForce2_class(py::module &m){
py::class_<NagaiHondaForce2 , NagaiHondaForce2_Overloads   >(m, "NagaiHondaForce2")
        .def(py::init< >())
        .def(
            "AddForceContribution", 
            (void(NagaiHondaForce2::*)(::AbstractCellPopulation<2, 2> &)) &NagaiHondaForce2::AddForceContribution, 
            " " , py::arg("rCellPopulation"))
        .def(
            "GetAdhesionParameter", 
            (double(NagaiHondaForce2::*)(::Node<2> *, ::Node<2> *, ::VertexBasedCellPopulation<2> &)) &NagaiHondaForce2::GetAdhesionParameter, 
            " " , py::arg("pNodeA"), py::arg("pNodeB"), py::arg("rVertexCellPopulation"))
        .def(
            "GetNagaiHondaDeformationEnergyParameter", 
            (double(NagaiHondaForce2::*)()) &NagaiHondaForce2::GetNagaiHondaDeformationEnergyParameter, 
            " " )
        .def(
            "GetNagaiHondaMembraneSurfaceEnergyParameter", 
            (double(NagaiHondaForce2::*)()) &NagaiHondaForce2::GetNagaiHondaMembraneSurfaceEnergyParameter, 
            " " )
        .def(
            "GetNagaiHondaCellCellAdhesionEnergyParameter", 
            (double(NagaiHondaForce2::*)()) &NagaiHondaForce2::GetNagaiHondaCellCellAdhesionEnergyParameter, 
            " " )
        .def(
            "GetNagaiHondaCellBoundaryAdhesionEnergyParameter", 
            (double(NagaiHondaForce2::*)()) &NagaiHondaForce2::GetNagaiHondaCellBoundaryAdhesionEnergyParameter, 
            " " )
        .def(
            "SetNagaiHondaDeformationEnergyParameter", 
            (void(NagaiHondaForce2::*)(double)) &NagaiHondaForce2::SetNagaiHondaDeformationEnergyParameter, 
            " " , py::arg("nagaiHondaDeformationEnergyParameter"))
        .def(
            "SetNagaiHondaMembraneSurfaceEnergyParameter", 
            (void(NagaiHondaForce2::*)(double)) &NagaiHondaForce2::SetNagaiHondaMembraneSurfaceEnergyParameter, 
            " " , py::arg("nagaiHondaMembraneSurfaceEnergyParameter"))
        .def(
            "SetNagaiHondaCellCellAdhesionEnergyParameter", 
            (void(NagaiHondaForce2::*)(double)) &NagaiHondaForce2::SetNagaiHondaCellCellAdhesionEnergyParameter, 
            " " , py::arg("nagaiHondaCellCellAdhesionEnergyEnergyParameter"))
        .def(
            "SetNagaiHondaCellBoundaryAdhesionEnergyParameter", 
            (void(NagaiHondaForce2::*)(double)) &NagaiHondaForce2::SetNagaiHondaCellBoundaryAdhesionEnergyParameter, 
            " " , py::arg("nagaiHondaCellBoundaryAdhesionEnergyParameter"))
        .def(
            "OutputForceParameters", 
            (void(NagaiHondaForce2::*)(::out_stream &)) &NagaiHondaForce2::OutputForceParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
