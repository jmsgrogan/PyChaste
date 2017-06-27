#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PlaneBoundaryCondition2_2.pypp.hpp"

namespace py = pybind11;

typedef PlaneBoundaryCondition<2,2 > PlaneBoundaryCondition2_2;
class PlaneBoundaryCondition2_2_Overloads : public PlaneBoundaryCondition2_2{
    public:
    using PlaneBoundaryCondition2_2::PlaneBoundaryCondition<2, 2>;

        void ImposeBoundaryCondition(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD(
        void,
        PlaneBoundaryCondition2_2,
        ImposeBoundaryCondition,
        rOldLocations        
        );
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
        rParamsFile        
        );
        }

};
void register_PlaneBoundaryCondition2_2_class(py::module &m){
    py::class_<PlaneBoundaryCondition2_2, PlaneBoundaryCondition2_2_Overloads, std::shared_ptr<PlaneBoundaryCondition2_2 >  >(m, "PlaneBoundaryCondition2_2")
        .def(py::init<::AbstractCellPopulation<2, 2> *, ::boost::numeric::ublas::c_vector<double, 2>, ::boost::numeric::ublas::c_vector<double, 2> >())
        .def("rGetPointOnPlane", (::boost::numeric::ublas::c_vector<double, 2> const & (PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::rGetPointOnPlane, "" )
        .def("rGetNormalToPlane", (::boost::numeric::ublas::c_vector<double, 2> const & (PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::rGetNormalToPlane, "" )
        .def("SetUseJiggledNodesOnPlane", (void (PlaneBoundaryCondition2_2::*)(bool)) &PlaneBoundaryCondition2_2::SetUseJiggledNodesOnPlane, "" , py::arg("useJiggledNodesOnPlane"))
        .def("GetUseJiggledNodesOnPlane", (bool (PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::GetUseJiggledNodesOnPlane, "" )
        .def("ImposeBoundaryCondition", (void (PlaneBoundaryCondition2_2::*)(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const &)) &PlaneBoundaryCondition2_2::ImposeBoundaryCondition, "" , py::arg("rOldLocations"))
        .def("VerifyBoundaryCondition", (bool (PlaneBoundaryCondition2_2::*)()) &PlaneBoundaryCondition2_2::VerifyBoundaryCondition, "" )
        .def("OutputCellPopulationBoundaryConditionParameters", (void (PlaneBoundaryCondition2_2::*)(::out_stream &)) &PlaneBoundaryCondition2_2::OutputCellPopulationBoundaryConditionParameters, "" , py::arg("rParamsFile"))
    ;
}
