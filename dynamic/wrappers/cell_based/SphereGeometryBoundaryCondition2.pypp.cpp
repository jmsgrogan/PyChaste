#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "SphereGeometryBoundaryCondition2.pypp.hpp"

namespace py = pybind11;

typedef SphereGeometryBoundaryCondition<2 > SphereGeometryBoundaryCondition2;

class SphereGeometryBoundaryCondition2_Overloads : public SphereGeometryBoundaryCondition2{
    public:
    using SphereGeometryBoundaryCondition2::SphereGeometryBoundaryCondition;

        void ImposeBoundaryCondition(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const & rOldLocations)override {
        PYBIND11_OVERLOAD(
        void,
        SphereGeometryBoundaryCondition2,
        ImposeBoundaryCondition,
        rOldLocations        
        );
        }
        bool VerifyBoundaryCondition()override {
        PYBIND11_OVERLOAD(
        bool,
        SphereGeometryBoundaryCondition2,
        VerifyBoundaryCondition,
        
        );
        }
        void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        SphereGeometryBoundaryCondition2,
        OutputCellPopulationBoundaryConditionParameters,
        rParamsFile        
        );
        }

};
void register_SphereGeometryBoundaryCondition2_class(py::module &m){
    py::class_<SphereGeometryBoundaryCondition2, SphereGeometryBoundaryCondition2_Overloads, std::shared_ptr<SphereGeometryBoundaryCondition2 >  >(m, "SphereGeometryBoundaryCondition2")
        .def(py::init<::AbstractCellPopulation<2, 2> *, ::boost::numeric::ublas::c_vector<double, 2>, double, double >())
        .def("rGetCentreOfSphere", (::boost::numeric::ublas::c_vector<double, 2> const & (SphereGeometryBoundaryCondition2::*)() const ) &SphereGeometryBoundaryCondition2::rGetCentreOfSphere, "" )
        .def("GetRadiusOfSphere", (double (SphereGeometryBoundaryCondition2::*)() const ) &SphereGeometryBoundaryCondition2::GetRadiusOfSphere, "" )
        .def("ImposeBoundaryCondition", (void (SphereGeometryBoundaryCondition2::*)(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const &)) &SphereGeometryBoundaryCondition2::ImposeBoundaryCondition, "" , py::arg("rOldLocations"))
        .def("VerifyBoundaryCondition", (bool (SphereGeometryBoundaryCondition2::*)()) &SphereGeometryBoundaryCondition2::VerifyBoundaryCondition, "" )
        .def("OutputCellPopulationBoundaryConditionParameters", (void (SphereGeometryBoundaryCondition2::*)(::out_stream &)) &SphereGeometryBoundaryCondition2::OutputCellPopulationBoundaryConditionParameters, "" , py::arg("rParamsFile"))
    ;
}
