#include "Cell.hpp"
#include "AbstractCellPopulation.hpp"
#include "AbstractOnLatticeCellPopulation.hpp"
#include "CaBasedCellPopulation.hpp"
#include "StemCellProliferativeType.hpp"
#include "DefaultCellProliferativeType.hpp"
#include "UniformCellCycleModel.hpp"
#include "CellPropertyCollection.hpp"
#include "SimulationTime.hpp"
#include "CellsGenerator.hpp"
#include "GenericCellsGenerator.hpp"
#include "AbstractCellProperty.hpp"
#include "AbstractCellCycleModel.hpp"
#include "OnLatticeSimulation.hpp"
#include "OffLatticeSimulation.hpp"
#include "AbstractCellBasedSimulation.hpp"
#include "Identifiable.hpp"
#include "DiffusionCaUpdateRule.hpp"
#include "AbstractCaUpdateRule.hpp"
#include "AbstractUpdateRule.hpp"
#include "VtkSceneModifier.hpp"
#include "AbstractCellBasedSimulationModifier.hpp"
#include "NodeBasedCellPopulation.hpp"
#include "AbstractCentreBasedCellPopulation.hpp"
#include "AbstractOffLatticeCellPopulation.hpp"
#include "MeshBasedCellPopulation.hpp"
#include "VertexBasedCellPopulation.hpp"
#include "PottsBasedCellPopulation.hpp"

template class AbstractCellBasedSimulationModifier<2,2>;
template class AbstractCellBasedSimulationModifier<3,3>;
template class AbstractUpdateRule<2>;
template class AbstractCaUpdateRule<2>;
template class DiffusionCaUpdateRule<2>;
template class CaBasedCellPopulation<2>;
template class CaBasedCellPopulation<3>;
template class AbstractOnLatticeCellPopulation<2>;
template class AbstractOnLatticeCellPopulation<3>;
template class AbstractCellPopulation<2, 2>;
template class AbstractCellPopulation<3, 3>;
template class GenericCellsGenerator<2>;
template class GenericCellsGenerator<3>;
template class OnLatticeSimulation<2>;
template class OnLatticeSimulation<3>;
template class OffLatticeSimulation<2,2>;
template class OffLatticeSimulation<3,3>;
template class VtkSceneModifier<2>;
template class VtkSceneModifier<3>;
template class AbstractCellBasedSimulation<2, 2>;
template class AbstractCellBasedSimulation<3, 3>;
template class NodeBasedCellPopulation<2>;
template class NodeBasedCellPopulation<3>;
template class AbstractCentreBasedCellPopulation<2, 2>;
template class AbstractCentreBasedCellPopulation<3, 3>;
template class AbstractOffLatticeCellPopulation<2, 2>;
template class AbstractOffLatticeCellPopulation<3, 3>;
template class MeshBasedCellPopulation<2, 2>;
template class MeshBasedCellPopulation<3, 3>;
template class VertexBasedCellPopulation<2>;
template class VertexBasedCellPopulation<3>;
template class PottsBasedCellPopulation<2>;
template class PottsBasedCellPopulation<3>;

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef CellsGenerator<UniformCellCycleModel, 2> CellsGeneratorUniformCellCycleModel_2;
typedef CellsGenerator<UniformCellCycleModel, 3> CellsGeneratorUniformCellCycleModel_3;
typedef std::vector<CellPtr> VecCellPtr;
}
}

inline int Instantiation()
{
    return sizeof(CellsGenerator<UniformCellCycleModel, 2>) + sizeof(AbstractCellPopulation<2, 2>) + sizeof(AbstractCellPopulation<3, 3>) +
            sizeof(AbstractCellBasedSimulation<2, 2>) + sizeof(AbstractCellBasedSimulation<3, 3>) +
            sizeof(CellsGenerator<UniformCellCycleModel, 3>);
}

//pyplusplus::aliases
