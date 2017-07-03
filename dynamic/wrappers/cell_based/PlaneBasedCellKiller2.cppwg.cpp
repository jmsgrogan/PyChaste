#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "PlaneBasedCellKiller.hpp"

#include "PlaneBasedCellKiller2.cppwg.hpp"

namespace py = pybind11;
typedef PlaneBasedCellKiller<2 > PlaneBasedCellKiller2;
;

class PlaneBasedCellKiller2_Overloads : public PlaneBasedCellKiller2{
    public:
    using PlaneBasedCellKiller2::PlaneBasedCellKiller;
    void CheckAndLabelCellsForApoptosisOrDeath() override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBasedCellKiller2,
            CheckAndLabelCellsForApoptosisOrDeath,
            );
    }
    void OutputCellKillerParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBasedCellKiller2,
            OutputCellKillerParameters,
            rParamsFile);
    }

};
void register_PlaneBasedCellKiller2_class(py::module &m){
py::class_<PlaneBasedCellKiller2 , PlaneBasedCellKiller2_Overloads   >(m, "PlaneBasedCellKiller2")
        .def(py::init<::AbstractCellPopulation<2, 2> *, ::boost::numeric::ublas::c_vector<double, 2>, ::boost::numeric::ublas::c_vector<double, 2> >(), py::arg("pCellPopulation"), py::arg("point"), py::arg("normal"))
        .def(
            "rGetPointOnPlane", 
            (::boost::numeric::ublas::c_vector<double, 2> const &(PlaneBasedCellKiller2::*)() const ) &PlaneBasedCellKiller2::rGetPointOnPlane, 
            " " )
        .def(
            "rGetNormalToPlane", 
            (::boost::numeric::ublas::c_vector<double, 2> const &(PlaneBasedCellKiller2::*)() const ) &PlaneBasedCellKiller2::rGetNormalToPlane, 
            " " )
        .def(
            "CheckAndLabelCellsForApoptosisOrDeath", 
            (void(PlaneBasedCellKiller2::*)()) &PlaneBasedCellKiller2::CheckAndLabelCellsForApoptosisOrDeath, 
            " " )
        .def(
            "OutputCellKillerParameters", 
            (void(PlaneBasedCellKiller2::*)(::out_stream &)) &PlaneBasedCellKiller2::OutputCellKillerParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
