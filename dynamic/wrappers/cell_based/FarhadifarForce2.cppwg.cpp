#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "FarhadifarForce.hpp"

#include "FarhadifarForce2.cppwg.hpp"

namespace py = pybind11;
typedef FarhadifarForce<2 > FarhadifarForce2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class FarhadifarForce2_Overloads : public FarhadifarForce2{
    public:
    using FarhadifarForce2::FarhadifarForce;
    void AddForceContribution(::AbstractCellPopulation<2, 2> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            FarhadifarForce2,
            AddForceContribution,
            rCellPopulation);
    }
    double GetLineTensionParameter(::Node<2> * pNodeA, ::Node<2> * pNodeB, ::VertexBasedCellPopulation<2> & rVertexCellPopulation) override {
        PYBIND11_OVERLOAD(
            double,
            FarhadifarForce2,
            GetLineTensionParameter,
            pNodeA, 
pNodeB, 
rVertexCellPopulation);
    }
    void OutputForceParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            FarhadifarForce2,
            OutputForceParameters,
            rParamsFile);
    }

};
void register_FarhadifarForce2_class(py::module &m){
py::class_<FarhadifarForce2 , FarhadifarForce2_Overloads , boost::shared_ptr<FarhadifarForce2 >  , AbstractForce<2, 2>  >(m, "FarhadifarForce2")
        .def(py::init< >())
        .def(
            "AddForceContribution", 
            (void(FarhadifarForce2::*)(::AbstractCellPopulation<2, 2> &)) &FarhadifarForce2::AddForceContribution, 
            " " , py::arg("rCellPopulation") )
        .def(
            "GetAreaElasticityParameter", 
            (double(FarhadifarForce2::*)()) &FarhadifarForce2::GetAreaElasticityParameter, 
            " "  )
        .def(
            "GetPerimeterContractilityParameter", 
            (double(FarhadifarForce2::*)()) &FarhadifarForce2::GetPerimeterContractilityParameter, 
            " "  )
        .def(
            "GetBoundaryLineTensionParameter", 
            (double(FarhadifarForce2::*)()) &FarhadifarForce2::GetBoundaryLineTensionParameter, 
            " "  )
        .def(
            "SetAreaElasticityParameter", 
            (void(FarhadifarForce2::*)(double)) &FarhadifarForce2::SetAreaElasticityParameter, 
            " " , py::arg("areaElasticityParameter") )
        .def(
            "SetPerimeterContractilityParameter", 
            (void(FarhadifarForce2::*)(double)) &FarhadifarForce2::SetPerimeterContractilityParameter, 
            " " , py::arg("perimeterContractilityParameter") )
        .def(
            "SetLineTensionParameter", 
            (void(FarhadifarForce2::*)(double)) &FarhadifarForce2::SetLineTensionParameter, 
            " " , py::arg("lineTensionParameter") )
        .def(
            "SetBoundaryLineTensionParameter", 
            (void(FarhadifarForce2::*)(double)) &FarhadifarForce2::SetBoundaryLineTensionParameter, 
            " " , py::arg("boundaryLineTensionParameter") )
        .def(
            "OutputForceParameters", 
            (void(FarhadifarForce2::*)(::out_stream &)) &FarhadifarForce2::OutputForceParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
