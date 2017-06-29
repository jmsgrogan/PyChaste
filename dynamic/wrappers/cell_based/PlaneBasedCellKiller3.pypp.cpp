#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PlaneBasedCellKiller3.pypp.hpp"

namespace py = pybind11;
typedef PlaneBasedCellKiller<3 > PlaneBasedCellKiller3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class PlaneBasedCellKiller3_Overloads : public PlaneBasedCellKiller3{
    public:
    using PlaneBasedCellKiller3::PlaneBasedCellKiller;
    void CheckAndLabelCellsForApoptosisOrDeath() override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBasedCellKiller3,
            CheckAndLabelCellsForApoptosisOrDeath,
            );
    }
    void OutputCellKillerParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            PlaneBasedCellKiller3,
            OutputCellKillerParameters,
            rParamsFile);
    }

};
void register_PlaneBasedCellKiller3_class(py::module &m){
py::class_<PlaneBasedCellKiller3 , PlaneBasedCellKiller3_Overloads , boost::shared_ptr<PlaneBasedCellKiller3 >   >(m, "PlaneBasedCellKiller3")
        .def(py::init<::AbstractCellPopulation<3, 3> *, ::boost::numeric::ublas::c_vector<double, 3>, ::boost::numeric::ublas::c_vector<double, 3> >())
        .def(
            "rGetPointOnPlane", 
            (::boost::numeric::ublas::c_vector<double, 3> const &(PlaneBasedCellKiller3::*)() const ) &PlaneBasedCellKiller3::rGetPointOnPlane, 
            " " )
        .def(
            "rGetNormalToPlane", 
            (::boost::numeric::ublas::c_vector<double, 3> const &(PlaneBasedCellKiller3::*)() const ) &PlaneBasedCellKiller3::rGetNormalToPlane, 
            " " )
        .def(
            "CheckAndLabelCellsForApoptosisOrDeath", 
            (void(PlaneBasedCellKiller3::*)()) &PlaneBasedCellKiller3::CheckAndLabelCellsForApoptosisOrDeath, 
            " " )
        .def(
            "OutputCellKillerParameters", 
            (void(PlaneBasedCellKiller3::*)(::out_stream &)) &PlaneBasedCellKiller3::OutputCellKillerParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
