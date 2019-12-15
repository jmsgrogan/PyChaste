#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "AbstractCellPopulation.hpp"
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "CellLabelWriter.hpp"

#include "CellLabelWriter2_2.cppwg.hpp"

namespace py = pybind11;
typedef CellLabelWriter<2,2 > CellLabelWriter2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

class CellLabelWriter2_2_Overloads : public CellLabelWriter2_2{
    public:
    using CellLabelWriter2_2::CellLabelWriter;
    double GetCellDataForVtkOutput(::CellPtr pCell, ::AbstractCellPopulation<2, 2> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
            double,
            CellLabelWriter2_2,
            GetCellDataForVtkOutput,
            pCell, 
pCellPopulation);
    }
    void VisitCell(::CellPtr pCell, ::AbstractCellPopulation<2, 2> * pCellPopulation) override {
        PYBIND11_OVERLOAD(
            void,
            CellLabelWriter2_2,
            VisitCell,
            pCell, 
pCellPopulation);
    }

};
void register_CellLabelWriter2_2_class(py::module &m){
py::class_<CellLabelWriter2_2 , CellLabelWriter2_2_Overloads , boost::shared_ptr<CellLabelWriter2_2 >   >(m, "CellLabelWriter2_2")
        .def(py::init< >())
        .def(
            "GetCellDataForVtkOutput", 
            (double(CellLabelWriter2_2::*)(::CellPtr, ::AbstractCellPopulation<2, 2> *)) &CellLabelWriter2_2::GetCellDataForVtkOutput, 
            " " , py::arg("pCell"), py::arg("pCellPopulation") )
        .def(
            "VisitCell", 
            (void(CellLabelWriter2_2::*)(::CellPtr, ::AbstractCellPopulation<2, 2> *)) &CellLabelWriter2_2::VisitCell, 
            " " , py::arg("pCell"), py::arg("pCellPopulation") )
    ;
}
