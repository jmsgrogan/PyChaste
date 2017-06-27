#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "VoronoiDataWriter3_3.pypp.hpp"

namespace py = pybind11;

typedef VoronoiDataWriter<3,3 > VoronoiDataWriter3_3;
class VoronoiDataWriter3_3_Overloads : public VoronoiDataWriter3_3{
    public:
    using VoronoiDataWriter3_3::VoronoiDataWriter<3, 3>;

        void Visit(::MeshBasedCellPopulation<3, 3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter3_3,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::CaBasedCellPopulation<3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter3_3,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::NodeBasedCellPopulation<3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter3_3,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::PottsBasedCellPopulation<3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter3_3,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::VertexBasedCellPopulation<3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter3_3,
        Visit,
        pCellPopulation        
        );
        }

};
void register_VoronoiDataWriter3_3_class(py::module &m){
    py::class_<VoronoiDataWriter3_3, VoronoiDataWriter3_3_Overloads, std::shared_ptr<VoronoiDataWriter3_3 >  >(m, "VoronoiDataWriter3_3")
        .def(py::init< >())
        .def("Visit", (void (VoronoiDataWriter3_3::*)(::MeshBasedCellPopulation<3, 3> *)) &VoronoiDataWriter3_3::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter3_3::*)(::CaBasedCellPopulation<3> *)) &VoronoiDataWriter3_3::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter3_3::*)(::NodeBasedCellPopulation<3> *)) &VoronoiDataWriter3_3::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter3_3::*)(::PottsBasedCellPopulation<3> *)) &VoronoiDataWriter3_3::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter3_3::*)(::VertexBasedCellPopulation<3> *)) &VoronoiDataWriter3_3::Visit, "" , py::arg("pCellPopulation"))
    ;
}
