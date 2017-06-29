#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellsGeneratorUniformG1GenerationalCellCycleModel_3.pypp.hpp"

namespace py = pybind11;

typedef CellsGenerator<UniformG1GenerationalCellCycleModel,3 > CellsGeneratorUniformG1GenerationalCellCycleModel_3;

void register_CellsGeneratorUniformG1GenerationalCellCycleModel_3_class(py::module &m){
    py::class_<CellsGeneratorUniformG1GenerationalCellCycleModel_3, std::shared_ptr<CellsGeneratorUniformG1GenerationalCellCycleModel_3 >  >(m, "CellsGeneratorUniformG1GenerationalCellCycleModel_3")
        .def("GenerateBasic", (void (CellsGeneratorUniformG1GenerationalCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformG1GenerationalCellCycleModel_3::GenerateBasic, "" , py::arg("rCells"), py::arg("numCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateBasicRandom", (void (CellsGeneratorUniformG1GenerationalCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformG1GenerationalCellCycleModel_3::GenerateBasicRandom, "" , py::arg("rCells"), py::arg("numCells"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
        .def("GenerateGivenLocationIndices", (void (CellsGeneratorUniformG1GenerationalCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorUniformG1GenerationalCellCycleModel_3::GenerateGivenLocationIndices, "" , py::arg("rCells"), py::arg("locationIndices"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>())
    ;
}
