#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "PythonObjectConverters.hpp"
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "PlaneBoundaryCondition.hpp"

#include "PythonObjectConverters.hpp"
#include "PlaneBoundaryCondition2_2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef PlaneBoundaryCondition<2,2 > PlaneBoundaryCondition2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class PlaneBoundaryCondition2_2_Overloads : public PlaneBoundaryCondition2_2{
    public:
    using PlaneBoundaryCondition2_2::PlaneBoundaryCondition;
    void ImposeBoundaryCondition(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBoundaryCondition2_2,
            ImposeBoundaryCondition,
            rOldLocations);
    }
    bool VerifyBoundaryCondition() override {
        PYBIND11_OVERLOAD(
            bool,
            PlaneBoundaryCondition2_2,
            VerifyBoundaryCondition,
            );
    }
    void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBoundaryCondition2_2,
            OutputCellPopulationBoundaryConditionParameters,
            rParamsFile);
    }

};
void register_PlaneBoundaryCondition2_2_class(py::module &m){
py::class_<PlaneBoundaryCondition2_2 , PlaneBoundaryCondition2_2_Overloads , boost::shared_ptr<PlaneBoundaryCondition2_2 >  , AbstractCellPopulationBoundaryCondition<2, 2>  >(m, "PlaneBoundaryCondition2_2")
        .def(py::init<::AbstractCellPopulation<2, 2> *, ::boost::numeric::ublas::c_vector<double, 2>, ::boost::numeric::ublas::c_vector<double, 2> >(), py::arg("pCellPopulation"), py::arg("point"), py::arg("normal"))
        .def(
            "rGetPointOnPlane", 
            (::boost::numeric::ublas::c_vector<double, 2> const &(PlaneBoundaryCondition2_2::*)() const ) &PlaneBoundaryCondition2_2::rGetPointOnPlane, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "rGetNormalToPlane", 
            (::boost::numeric::ublas::c_vector<double, 2> const &(PlaneBoundaryCondition2_2::*)() const ) &PlaneBoundaryCondition2_2::rGetNormalToPlane, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "SetUseJiggledNodesOnPlane", 
            (void(PlaneBoundaryCondition2_2::*)(bool)) &PlaneBoundaryCondition2_2::SetUseJiggledNodesOnPlane, 
            " " , py::arg("useJiggledNodesOnPlane") )
        .def(
            "GetUseJiggledNodesOnPlane", 
            (bool(PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::GetUseJiggledNodesOnPlane, 
            " "  )
        .def(
            "ImposeBoundaryCondition", 
            (void(PlaneBoundaryCondition2_2::*)(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const &)) &PlaneBoundaryCondition2_2::ImposeBoundaryCondition, 
            " " , py::arg("rOldLocations") )
        .def(
            "VerifyBoundaryCondition", 
            (bool(PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::VerifyBoundaryCondition, 
            " "  )
        .def(
            "OutputCellPopulationBoundaryConditionParameters", 
            (void(PlaneBoundaryCondition2_2::*)(::out_stream &)) &PlaneBoundaryCondition2_2::OutputCellPopulationBoundaryConditionParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
