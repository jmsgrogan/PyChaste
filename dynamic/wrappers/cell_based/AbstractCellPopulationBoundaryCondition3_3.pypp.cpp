#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCellPopulationBoundaryCondition3_3.pypp.hpp"

namespace py = pybind11;
typedef AbstractCellPopulationBoundaryCondition<3,3 > AbstractCellPopulationBoundaryCondition3_3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractCellPopulationBoundaryCondition3_3_Overloads : public AbstractCellPopulationBoundaryCondition3_3{
    public:
    using AbstractCellPopulationBoundaryCondition3_3::AbstractCellPopulationBoundaryCondition;
    void ImposeBoundaryCondition(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellPopulationBoundaryCondition3_3,
            ImposeBoundaryCondition,
            rOldLocations);
    }
    bool VerifyBoundaryCondition() override {
        PYBIND11_OVERLOAD_PURE(
            bool,
            AbstractCellPopulationBoundaryCondition3_3,
            VerifyBoundaryCondition,
            );
    }
    void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellPopulationBoundaryCondition3_3,
            OutputCellPopulationBoundaryConditionParameters,
            rParamsFile);
    }

};
void register_AbstractCellPopulationBoundaryCondition3_3_class(py::module &m){
py::class_<AbstractCellPopulationBoundaryCondition3_3 , AbstractCellPopulationBoundaryCondition3_3_Overloads , boost::shared_ptr<AbstractCellPopulationBoundaryCondition3_3 >  , Identifiable  >(m, "AbstractCellPopulationBoundaryCondition3_3")
        .def(
            "ImposeBoundaryCondition", 
            (void(AbstractCellPopulationBoundaryCondition3_3::*)(::std::map<Node<3> *, boost::numeric::ublas::c_vector<double, 3>, std::less<Node<3> *>, std::allocator<std::pair<Node<3> *const, boost::numeric::ublas::c_vector<double, 3> > > > const &)) &AbstractCellPopulationBoundaryCondition3_3::ImposeBoundaryCondition, 
            " " , py::arg("rOldLocations"))
        .def(
            "VerifyBoundaryCondition", 
            (bool(AbstractCellPopulationBoundaryCondition3_3::*)()) &AbstractCellPopulationBoundaryCondition3_3::VerifyBoundaryCondition, 
            " " )
        .def(
            "GetCellPopulation", 
            (::AbstractCellPopulation<3, 3> const *(AbstractCellPopulationBoundaryCondition3_3::*)() const ) &AbstractCellPopulationBoundaryCondition3_3::GetCellPopulation, 
            " " )
        .def(
            "OutputCellPopulationBoundaryConditionInfo", 
            (void(AbstractCellPopulationBoundaryCondition3_3::*)(::out_stream &)) &AbstractCellPopulationBoundaryCondition3_3::OutputCellPopulationBoundaryConditionInfo, 
            " " , py::arg("rParamsFile"))
        .def(
            "OutputCellPopulationBoundaryConditionParameters", 
            (void(AbstractCellPopulationBoundaryCondition3_3::*)(::out_stream &)) &AbstractCellPopulationBoundaryCondition3_3::OutputCellPopulationBoundaryConditionParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
