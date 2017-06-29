#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PlaneBoundaryCondition3_3.pypp.hpp"

namespace py = pybind11;
typedef PlaneBoundaryCondition<3,3 > PlaneBoundaryCondition3_3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class PlaneBoundaryCondition3_3_Overloads : public PlaneBoundaryCondition3_3{
    public:
    using PlaneBoundaryCondition3_3::PlaneBoundaryCondition;
    void ImposeBoundaryCondition(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBoundaryCondition3_3,
            ImposeBoundaryCondition,
            rOldLocations);
    }
    bool VerifyBoundaryCondition() override {
        PYBIND11_OVERLOAD(
            bool,
            PlaneBoundaryCondition3_3,
            VerifyBoundaryCondition,
            );
    }
    void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBoundaryCondition3_3,
            OutputCellPopulationBoundaryConditionParameters,
            rParamsFile);
    }

};
void register_PlaneBoundaryCondition3_3_class(py::module &m){
py::class_<PlaneBoundaryCondition3_3 , PlaneBoundaryCondition3_3_Overloads , boost::shared_ptr<PlaneBoundaryCondition3_3 >   >(m, "PlaneBoundaryCondition3_3")
        .def(py::init<::AbstractCellPopulation<3, 3> *, ::boost::numeric::ublas::c_vector<double, 3>, ::boost::numeric::ublas::c_vector<double, 3> >())
        .def(
            "rGetPointOnPlane", 
            (::boost::numeric::ublas::c_vector<double, 3> const &(PlaneBoundaryCondition3_3::*)() const ) &PlaneBoundaryCondition3_3::rGetPointOnPlane, 
            " " )
        .def(
            "rGetNormalToPlane", 
            (::boost::numeric::ublas::c_vector<double, 3> const &(PlaneBoundaryCondition3_3::*)() const ) &PlaneBoundaryCondition3_3::rGetNormalToPlane, 
            " " )
        .def(
            "SetUseJiggledNodesOnPlane", 
            (void(PlaneBoundaryCondition3_3::*)(bool)) &PlaneBoundaryCondition3_3::SetUseJiggledNodesOnPlane, 
            " " , py::arg("useJiggledNodesOnPlane"))
        .def(
            "GetUseJiggledNodesOnPlane", 
            (bool(PlaneBoundaryCondition3_3::*)()) &PlaneBoundaryCondition3_3::GetUseJiggledNodesOnPlane, 
            " " )
        .def(
            "ImposeBoundaryCondition", 
            (void(PlaneBoundaryCondition3_3::*)(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const &)) &PlaneBoundaryCondition3_3::ImposeBoundaryCondition, 
            " " , py::arg("rOldLocations"))
        .def(
            "VerifyBoundaryCondition", 
            (bool(PlaneBoundaryCondition3_3::*)()) &PlaneBoundaryCondition3_3::VerifyBoundaryCondition, 
            " " )
        .def(
            "OutputCellPopulationBoundaryConditionParameters", 
            (void(PlaneBoundaryCondition3_3::*)(::out_stream &)) &PlaneBoundaryCondition3_3::OutputCellPopulationBoundaryConditionParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
