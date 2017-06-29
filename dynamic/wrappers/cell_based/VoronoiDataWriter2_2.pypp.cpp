#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "VoronoiDataWriter2_2.pypp.hpp"

namespace py = pybind11;

typedef VoronoiDataWriter<2,2 > VoronoiDataWriter2_2;

class VoronoiDataWriter2_2_Overloads : public VoronoiDataWriter2_2{
    public:
    using VoronoiDataWriter2_2::VoronoiDataWriter;

        void Visit(::MeshBasedCellPopulation<2, 2> * pCellPopulation)override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter2_2,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::CaBasedCellPopulation<2> * pCellPopulation)override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter2_2,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::NodeBasedCellPopulation<2> * pCellPopulation)override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter2_2,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::PottsBasedCellPopulation<2> * pCellPopulation)override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter2_2,
        Visit,
        pCellPopulation        
        );
        }
        void Visit(::VertexBasedCellPopulation<2> * pCellPopulation)override {
        PYBIND11_OVERLOAD(
        void,
        VoronoiDataWriter2_2,
        Visit,
        pCellPopulation        
        );
        }

};
void register_VoronoiDataWriter2_2_class(py::module &m){
    py::class_<VoronoiDataWriter2_2, VoronoiDataWriter2_2_Overloads, std::shared_ptr<VoronoiDataWriter2_2 >  >(m, "VoronoiDataWriter2_2")
        .def(py::init< >())
        .def("Visit", (void (VoronoiDataWriter2_2::*)(::MeshBasedCellPopulation<2, 2> *)) &VoronoiDataWriter2_2::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter2_2::*)(::CaBasedCellPopulation<2> *)) &VoronoiDataWriter2_2::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter2_2::*)(::NodeBasedCellPopulation<2> *)) &VoronoiDataWriter2_2::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter2_2::*)(::PottsBasedCellPopulation<2> *)) &VoronoiDataWriter2_2::Visit, "" , py::arg("pCellPopulation"))
        .def("Visit", (void (VoronoiDataWriter2_2::*)(::VertexBasedCellPopulation<2> *)) &VoronoiDataWriter2_2::Visit, "" , py::arg("pCellPopulation"))
    ;
}
