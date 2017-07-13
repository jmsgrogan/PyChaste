#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "UniformCellCycleModel.hpp"
#include "SimpleOxygenBasedCellCycleModel.hpp"
#include "UniformG1GenerationalCellCycleModel.hpp"
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "CellsGenerator.hpp"

#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_2.cppwg.hpp"

namespace py = pybind11;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel,2 > CellsGeneratorSimpleOxygenBasedCellCycleModel_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_CellsGeneratorSimpleOxygenBasedCellCycleModel_2_class(py::module &m){
py::class_<CellsGeneratorSimpleOxygenBasedCellCycleModel_2  , boost::shared_ptr<CellsGeneratorSimpleOxygenBasedCellCycleModel_2 >   >(m, "CellsGeneratorSimpleOxygenBasedCellCycleModel_2")
        .def(
            "GenerateBasic", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_2::GenerateBasic, 
            " " , py::arg("rCells"), py::arg("numCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>() )
        .def(
            "GenerateBasicRandom", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, unsigned int, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_2::GenerateBasicRandom, 
            " " , py::arg("rCells"), py::arg("numCells"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>() )
        .def(
            "GenerateGivenLocationIndices", 
            (void(CellsGeneratorSimpleOxygenBasedCellCycleModel_2::*)(::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, ::boost::shared_ptr<AbstractCellProperty>)) &CellsGeneratorSimpleOxygenBasedCellCycleModel_2::GenerateGivenLocationIndices, 
            " " , py::arg("rCells"), py::arg("locationIndices"), py::arg("pCellProliferativeType") = boost::shared_ptr<AbstractCellProperty>() )
    ;
}
