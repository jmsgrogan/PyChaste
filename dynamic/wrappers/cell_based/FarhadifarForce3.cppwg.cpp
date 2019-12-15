#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "FarhadifarForce.hpp"

#include "FarhadifarForce3.cppwg.hpp"

namespace py = pybind11;
typedef FarhadifarForce<3 > FarhadifarForce3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class FarhadifarForce3_Overloads : public FarhadifarForce3{
    public:
    using FarhadifarForce3::FarhadifarForce;
    void AddForceContribution(::AbstractCellPopulation<3, 3> & rCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            FarhadifarForce3,
            AddForceContribution,
            rCellPopulation);
    }
    double GetLineTensionParameter(::Node<3> * pNodeA, ::Node<3> * pNodeB, ::VertexBasedCellPopulation<3> & rVertexCellPopulation) override {
        PYBIND11_OVERLOAD(
            double,
            FarhadifarForce3,
            GetLineTensionParameter,
            pNodeA, 
pNodeB, 
rVertexCellPopulation);
    }
    void OutputForceParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            FarhadifarForce3,
            OutputForceParameters,
            rParamsFile);
    }

};
void register_FarhadifarForce3_class(py::module &m){
py::class_<FarhadifarForce3 , FarhadifarForce3_Overloads , boost::shared_ptr<FarhadifarForce3 >  , AbstractForce<3, 3>  >(m, "FarhadifarForce3")
        .def(py::init< >())
        .def(
            "AddForceContribution", 
            (void(FarhadifarForce3::*)(::AbstractCellPopulation<3, 3> &)) &FarhadifarForce3::AddForceContribution, 
            " " , py::arg("rCellPopulation") )
        .def(
            "GetAreaElasticityParameter", 
            (double(FarhadifarForce3::*)()) &FarhadifarForce3::GetAreaElasticityParameter, 
            " "  )
        .def(
            "GetPerimeterContractilityParameter", 
            (double(FarhadifarForce3::*)()) &FarhadifarForce3::GetPerimeterContractilityParameter, 
            " "  )
        .def(
            "GetBoundaryLineTensionParameter", 
            (double(FarhadifarForce3::*)()) &FarhadifarForce3::GetBoundaryLineTensionParameter, 
            " "  )
        .def(
            "SetAreaElasticityParameter", 
            (void(FarhadifarForce3::*)(double)) &FarhadifarForce3::SetAreaElasticityParameter, 
            " " , py::arg("areaElasticityParameter") )
        .def(
            "SetPerimeterContractilityParameter", 
            (void(FarhadifarForce3::*)(double)) &FarhadifarForce3::SetPerimeterContractilityParameter, 
            " " , py::arg("perimeterContractilityParameter") )
        .def(
            "SetLineTensionParameter", 
            (void(FarhadifarForce3::*)(double)) &FarhadifarForce3::SetLineTensionParameter, 
            " " , py::arg("lineTensionParameter") )
        .def(
            "SetBoundaryLineTensionParameter", 
            (void(FarhadifarForce3::*)(double)) &FarhadifarForce3::SetBoundaryLineTensionParameter, 
            " " , py::arg("boundaryLineTensionParameter") )
        .def(
            "OutputForceParameters", 
            (void(FarhadifarForce3::*)(::out_stream &)) &FarhadifarForce3::OutputForceParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
