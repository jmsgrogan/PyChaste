#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellsGeneratorUniformCellCycleModel_2.pypp.hpp"

namespace py = pybind11;

typedef CellsGenerator<UniformCellCycleModel,2 > CellsGeneratorUniformCellCycleModel_2;

void register_CellsGeneratorUniformCellCycleModel_2_class(py::module &m){
    py::class_<CellsGeneratorUniformCellCycleModel_2, std::shared_ptr<CellsGeneratorUniformCellCycleModel_2 >  >(m, "CellsGeneratorUniformCellCycleModel_2")
        .def("GenerateBasic", (void (CellsGeneratorUniformCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformCellCycleModel_2::GenerateBasic, "" , py::arg("rCells"), py::arg("numCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateBasicRandom", (void (CellsGeneratorUniformCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformCellCycleModel_2::GenerateBasicRandom, "" , py::arg("rCells"), py::arg("numCells"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateGivenLocationIndices", (void (CellsGeneratorUniformCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformCellCycleModel_2::GenerateGivenLocationIndices, "" , py::arg("rCells"), py::arg("locationIndices"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
    ;
}
