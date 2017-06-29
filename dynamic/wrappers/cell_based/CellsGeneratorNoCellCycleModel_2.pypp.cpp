#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellsGeneratorNoCellCycleModel_2.pypp.hpp"

namespace py = pybind11;

typedef CellsGenerator<NoCellCycleModel,2 > CellsGeneratorNoCellCycleModel_2;

void register_CellsGeneratorNoCellCycleModel_2_class(py::module &m){
    py::class_<CellsGeneratorNoCellCycleModel_2, std::shared_ptr<CellsGeneratorNoCellCycleModel_2 >  >(m, "CellsGeneratorNoCellCycleModel_2")
        .def("GenerateBasic", (void (CellsGeneratorNoCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorNoCellCycleModel_2::GenerateBasic, "" , py::arg("rCells"), py::arg("numCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateBasicRandom", (void (CellsGeneratorNoCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorNoCellCycleModel_2::GenerateBasicRandom, "" , py::arg("rCells"), py::arg("numCells"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateGivenLocationIndices", (void (CellsGeneratorNoCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorNoCellCycleModel_2::GenerateGivenLocationIndices, "" , py::arg("rCells"), py::arg("locationIndices"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
    ;
}
