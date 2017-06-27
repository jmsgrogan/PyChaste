#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellLabelWriter3_3.pypp.hpp"

namespace py = pybind11;

typedef CellLabelWriter<3,3 > CellLabelWriter3_3;
class CellLabelWriter3_3_Overloads : public CellLabelWriter3_3{
    public:
    using CellLabelWriter3_3::CellLabelWriter<3, 3>;

        double GetCellDataForVtkOutput(::CellPtr pCell, ::AbstractCellPopulation<3, 3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        double,
        CellLabelWriter3_3,
        GetCellDataForVtkOutput,
        pCell, 
        pCellPopulation        
        );
        }
        void VisitCell(::CellPtr pCell, ::AbstractCellPopulation<3, 3> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
        void,
        CellLabelWriter3_3,
        VisitCell,
        pCell, 
        pCellPopulation        
        );
        }

};
void register_CellLabelWriter3_3_class(py::module &m){
    py::class_<CellLabelWriter3_3, CellLabelWriter3_3_Overloads, std::shared_ptr<CellLabelWriter3_3 >  >(m, "CellLabelWriter3_3")
        .def(py::init< >())
        .def("GetCellDataForVtkOutput", (double (CellLabelWriter3_3::*)(::CellPtr, ::AbstractCellPopulation<3, 3> *)) &CellLabelWriter3_3::GetCellDataForVtkOutput, "" , py::arg("pCell"), py::arg("pCellPopulation"))
        .def("VisitCell", (void (CellLabelWriter3_3::*)(::CellPtr, ::AbstractCellPopulation<3, 3> *)) &CellLabelWriter3_3::VisitCell, "" , py::arg("pCell"), py::arg("pCellPopulation"))
    ;
}
