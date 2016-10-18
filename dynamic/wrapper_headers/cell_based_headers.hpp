#include "Cell.hpp"
#include "CaBasedCellPopulation.hpp"
#include "StemCellProliferativeType.hpp"
#include "DefaultCellProliferativeType.hpp"
#include "UniformCellCycleModel.hpp"
#include "CellPropertyCollection.hpp"
#include "SimulationTime.hpp"
#include "CellsGenerator.hpp"
#include "GenericCellsGenerator.hpp"

template class CaBasedCellPopulation<2>;
template class CaBasedCellPopulation<3>;
template class GenericCellsGenerator<2>;
template class GenericCellsGenerator<3>;

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef CellsGenerator<UniformCellCycleModel, 2> CellsGeneratorUniformCellCycleModel_2;
typedef std::vector<CellPtr> VecCellPtr;
}
}

inline int Instantiation()
{
    return sizeof(CellsGenerator<UniformCellCycleModel, 2>);
}

//pyplusplus::aliases
