#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "SphereGeometryBoundaryCondition3.pypp.hpp"

namespace py = pybind11;

typedef SphereGeometryBoundaryCondition<3 > SphereGeometryBoundaryCondition3;
class SphereGeometryBoundaryCondition3_Overloads : public SphereGeometryBoundaryCondition3{
    public:
    using SphereGeometryBoundaryCondition3::SphereGeometryBoundaryCondition<3>;

        void ImposeBoundaryCondition(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD(
        void,
        SphereGeometryBoundaryCondition3,
        ImposeBoundaryCondition,
        rOldLocations        
        );
        }
        bool VerifyBoundaryCondition() override {
        PYBIND11_OVERLOAD(
        bool,
        SphereGeometryBoundaryCondition3,
        VerifyBoundaryCondition,
        
        );
        }
        void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        SphereGeometryBoundaryCondition3,
        OutputCellPopulationBoundaryConditionParameters,
        rParamsFile        
        );
        }

};
void register_SphereGeometryBoundaryCondition3_class(py::module &m){
    py::class_<SphereGeometryBoundaryCondition3, SphereGeometryBoundaryCondition3_Overloads, std::shared_ptr<SphereGeometryBoundaryCondition3 >  >(m, "SphereGeometryBoundaryCondition3")
        .def(py::init<::AbstractCellPopulation<3, 3> *, ::boost::numeric::ublas::c_vector<double, 3>, double, double >())
        .def("rGetCentreOfSphere", (::boost::numeric::ublas::c_vector<double, 3> const & (SphereGeometryBoundaryCondition3::*)()) &SphereGeometryBoundaryCondition3::rGetCentreOfSphere, "" )
        .def("GetRadiusOfSphere", (double (SphereGeometryBoundaryCondition3::*)()) &SphereGeometryBoundaryCondition3::GetRadiusOfSphere, "" )
        .def("ImposeBoundaryCondition", (void (SphereGeometryBoundaryCondition3::*)(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const &)) &SphereGeometryBoundaryCondition3::ImposeBoundaryCondition, "" , py::arg("rOldLocations"))
        .def("VerifyBoundaryCondition", (bool (SphereGeometryBoundaryCondition3::*)()) &SphereGeometryBoundaryCondition3::VerifyBoundaryCondition, "" )
        .def("OutputCellPopulationBoundaryConditionParameters", (void (SphereGeometryBoundaryCondition3::*)(::out_stream &)) &SphereGeometryBoundaryCondition3::OutputCellPopulationBoundaryConditionParameters, "" , py::arg("rParamsFile"))
    ;
}
