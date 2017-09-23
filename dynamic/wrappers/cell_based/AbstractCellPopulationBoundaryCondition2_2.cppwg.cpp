#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "AbstractCellPopulationBoundaryCondition.hpp"

#include "PythonObjectConverters.hpp"
#include "AbstractCellPopulationBoundaryCondition2_2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef AbstractCellPopulationBoundaryCondition<2,2 > AbstractCellPopulationBoundaryCondition2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class AbstractCellPopulationBoundaryCondition2_2_Overloads : public AbstractCellPopulationBoundaryCondition2_2{
    public:
    using AbstractCellPopulationBoundaryCondition2_2::AbstractCellPopulationBoundaryCondition;
    void ImposeBoundaryCondition(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const & rOldLocations) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellPopulationBoundaryCondition2_2,
            ImposeBoundaryCondition,
            rOldLocations);
    }
    bool VerifyBoundaryCondition() override {
        PYBIND11_OVERLOAD_PURE(
            bool,
            AbstractCellPopulationBoundaryCondition2_2,
            VerifyBoundaryCondition,
            );
    }
    void OutputCellPopulationBoundaryConditionParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AbstractCellPopulationBoundaryCondition2_2,
            OutputCellPopulationBoundaryConditionParameters,
            rParamsFile);
    }

};
void register_AbstractCellPopulationBoundaryCondition2_2_class(py::module &m){
py::class_<AbstractCellPopulationBoundaryCondition2_2 , AbstractCellPopulationBoundaryCondition2_2_Overloads , boost::shared_ptr<AbstractCellPopulationBoundaryCondition2_2 >   >(m, "AbstractCellPopulationBoundaryCondition2_2")
        .def(py::init<::AbstractCellPopulation<2, 2> * >(), py::arg("pCellPopulation"))
        .def(
            "ImposeBoundaryCondition", 
            (void(AbstractCellPopulationBoundaryCondition2_2::*)(::std::map<Node<2> *, boost::numeric::ublas::c_vector<double, 2>, std::less<Node<2> *>, std::allocator<std::pair<Node<2> *const, boost::numeric::ublas::c_vector<double, 2> > > > const &)) &AbstractCellPopulationBoundaryCondition2_2::ImposeBoundaryCondition, 
            " " , py::arg("rOldLocations") )
        .def(
            "VerifyBoundaryCondition", 
            (bool(AbstractCellPopulationBoundaryCondition2_2::*)()) &AbstractCellPopulationBoundaryCondition2_2::VerifyBoundaryCondition, 
            " "  )
        .def(
            "GetCellPopulation", 
            (::AbstractCellPopulation<2, 2> const *(AbstractCellPopulationBoundaryCondition2_2::*)() const ) &AbstractCellPopulationBoundaryCondition2_2::GetCellPopulation, 
            " "  , py::return_value_policy::reference)
        .def(
            "OutputCellPopulationBoundaryConditionInfo", 
            (void(AbstractCellPopulationBoundaryCondition2_2::*)(::out_stream &)) &AbstractCellPopulationBoundaryCondition2_2::OutputCellPopulationBoundaryConditionInfo, 
            " " , py::arg("rParamsFile") )
        .def(
            "OutputCellPopulationBoundaryConditionParameters", 
            (void(AbstractCellPopulationBoundaryCondition2_2::*)(::out_stream &)) &AbstractCellPopulationBoundaryCondition2_2::OutputCellPopulationBoundaryConditionParameters, 
            " " , py::arg("rParamsFile") )
    ;
}
