#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_3.pypp.hpp"

namespace py = pybind11;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel,3 > CellsGeneratorSimpleOxygenBasedCellCycleModel_3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_CellsGeneratorSimpleOxygenBasedCellCycleModel_3_class(py::module &m){
py::class_<CellsGeneratorSimpleOxygenBasedCellCycleModel_3  , boost::shared_ptr<CellsGeneratorSimpleOxygenBasedCellCycleModel_3 >   >(m, "CellsGeneratorSimpleOxygenBasedCellCycleModel_3")
        .def(
            "GenerateBasic", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_3::GenerateBasic, 
            " " , py::arg("rCells"), py::arg("numCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("pCellProliferativeType") = nullptr)
        .def(
            "GenerateBasicRandom", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_3::GenerateBasicRandom, 
            " " , py::arg("rCells"), py::arg("numCells"), py::arg("pCellProliferativeType") = nullptr)
        .def(
            "GenerateGivenLocationIndices", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_3::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_3::GenerateGivenLocationIndices, 
            " " , py::arg("rCells"), py::arg("locationIndices"), py::arg("pCellProliferativeType") = nullptr)
    ;
}
