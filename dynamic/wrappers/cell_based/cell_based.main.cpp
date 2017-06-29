#include <pybind11/pybind11.h>
#include "PottsMesh2.pypp.hpp"
#include "PottsMesh3.pypp.hpp"
#include "PottsElement2.pypp.hpp"
#include "PottsElement3.pypp.hpp"
#include "AbstractCellCycleModel.pypp.hpp"
#include "AbstractPhaseBasedCellCycleModel.pypp.hpp"
#include "AbstractSimpleCellCycleModel.pypp.hpp"
#include "AbstractSimplePhaseBasedCellCycleModel.pypp.hpp"
#include "AbstractSimpleGenerationalCellCycleModel.pypp.hpp"
#include "UniformCellCycleModel.pypp.hpp"
#include "SimpleOxygenBasedCellCycleModel.pypp.hpp"
#include "UniformG1GenerationalCellCycleModel.pypp.hpp"
#include "NoCellCycleModel.pypp.hpp"
#include "AbstractCellProperty.pypp.hpp"
#include "CellPropertyCollection.pypp.hpp"
#include "AbstractCellProliferativeType.pypp.hpp"
#include "StemCellProliferativeType.pypp.hpp"
#include "DefaultCellProliferativeType.pypp.hpp"
#include "TransitCellProliferativeType.pypp.hpp"
#include "DifferentiatedCellProliferativeType.pypp.hpp"
#include "AbstractCellMutationState.pypp.hpp"
#include "ApcOneHitCellMutationState.pypp.hpp"
#include "ApcTwoHitCellMutationState.pypp.hpp"
#include "BetaCateninOneHitCellMutationState.pypp.hpp"
#include "WildTypeCellMutationState.pypp.hpp"
#include "ApoptoticCellProperty.pypp.hpp"
#include "CellData.pypp.hpp"
#include "CellLabel.pypp.hpp"
#include "CellAncestor.pypp.hpp"
#include "CellId.pypp.hpp"
#include "CellPropertyRegistry.pypp.hpp"
#include "AbstractSrnModel.pypp.hpp"
#include "NullSrnModel.pypp.hpp"
#include "Cell.pypp.hpp"
#include "CellsGeneratorUniformCellCycleModel_2.pypp.hpp"
#include "CellsGeneratorUniformCellCycleModel_3.pypp.hpp"
#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_2.pypp.hpp"
#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_3.pypp.hpp"
#include "CellsGeneratorUniformG1GenerationalCellCycleModel_2.pypp.hpp"
#include "CellsGeneratorUniformG1GenerationalCellCycleModel_3.pypp.hpp"
#include "CellsGeneratorNoCellCycleModel_2.pypp.hpp"
#include "CellsGeneratorNoCellCycleModel_3.pypp.hpp"
#include "AbstractLinearPde2_2.pypp.hpp"
#include "AbstractLinearPde3_3.pypp.hpp"
#include "AbstractLinearParabolicPde2_2.pypp.hpp"
#include "AbstractLinearParabolicPde3_3.pypp.hpp"
#include "AbstractLinearEllipticPde2_2.pypp.hpp"
#include "AbstractLinearEllipticPde3_3.pypp.hpp"
#include "CellwiseSourceEllipticPde2.pypp.hpp"
#include "CellwiseSourceEllipticPde3.pypp.hpp"
#include "AveragedSourceEllipticPde2.pypp.hpp"
#include "AveragedSourceEllipticPde3.pypp.hpp"
#include "AveragedSourceParabolicPde2.pypp.hpp"
#include "AveragedSourceParabolicPde3.pypp.hpp"
#include "CellwiseSourceParabolicPde2.pypp.hpp"
#include "CellwiseSourceParabolicPde3.pypp.hpp"
#include "AbstractPdeModifier2.pypp.hpp"
#include "AbstractPdeModifier3.pypp.hpp"
#include "AbstractGrowingDomainPdeModifier2.pypp.hpp"
#include "AbstractGrowingDomainPdeModifier3.pypp.hpp"
#include "EllipticGrowingDomainPdeModifier2.pypp.hpp"
#include "EllipticGrowingDomainPdeModifier3.pypp.hpp"
#include "VoronoiDataWriter2_2.pypp.hpp"
#include "VoronoiDataWriter3_3.pypp.hpp"
#include "CellLabelWriter2_2.pypp.hpp"
#include "CellLabelWriter3_3.pypp.hpp"
#include "AbstractCaUpdateRule2.pypp.hpp"
#include "AbstractCaUpdateRule3.pypp.hpp"
#include "AbstractUpdateRule2.pypp.hpp"
#include "AbstractUpdateRule3.pypp.hpp"
#include "DiffusionCaUpdateRule2.pypp.hpp"
#include "DiffusionCaUpdateRule3.pypp.hpp"
#include "AbstractPottsUpdateRule2.pypp.hpp"
#include "AbstractPottsUpdateRule3.pypp.hpp"
#include "VolumeConstraintPottsUpdateRule2.pypp.hpp"
#include "VolumeConstraintPottsUpdateRule3.pypp.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule2.pypp.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule3.pypp.hpp"
#include "DifferentialAdhesionPottsUpdateRule2.pypp.hpp"
#include "DifferentialAdhesionPottsUpdateRule3.pypp.hpp"
#include "AdhesionPottsUpdateRule2.pypp.hpp"
#include "AdhesionPottsUpdateRule3.pypp.hpp"
#include "AbstractVertexBasedDivisionRule2.pypp.hpp"
#include "AbstractVertexBasedDivisionRule3.pypp.hpp"
#include "AbstractForce2_2.pypp.hpp"
#include "AbstractForce3_3.pypp.hpp"
#include "AbstractTwoBodyInteractionForce2_2.pypp.hpp"
#include "AbstractTwoBodyInteractionForce3_3.pypp.hpp"
#include "GeneralisedLinearSpringForce2_2.pypp.hpp"
#include "GeneralisedLinearSpringForce3_3.pypp.hpp"
#include "NagaiHondaForce2.pypp.hpp"
#include "NagaiHondaForce3.pypp.hpp"
#include "AbstractCellKiller2.pypp.hpp"
#include "AbstractCellKiller3.pypp.hpp"
#include "PlaneBasedCellKiller2.pypp.hpp"
#include "PlaneBasedCellKiller3.pypp.hpp"
#include "ApoptoticCellKiller2.pypp.hpp"
#include "ApoptoticCellKiller3.pypp.hpp"
#include "AbstractCellPopulationBoundaryCondition2_2.pypp.hpp"
#include "AbstractCellPopulationBoundaryCondition3_3.pypp.hpp"
#include "PlaneBoundaryCondition2_2.pypp.hpp"
#include "PlaneBoundaryCondition3_3.pypp.hpp"
#include "AttractingPlaneBoundaryCondition2_2.pypp.hpp"
#include "AttractingPlaneBoundaryCondition3_3.pypp.hpp"
#include "SphereGeometryBoundaryCondition2.pypp.hpp"
#include "SphereGeometryBoundaryCondition3.pypp.hpp"
#include "AbstractCellPopulation2_2.pypp.hpp"
#include "AbstractCellPopulation3_3.pypp.hpp"
#include "AbstractOnLatticeCellPopulation2.pypp.hpp"
#include "AbstractOnLatticeCellPopulation3.pypp.hpp"
#include "AbstractCentreBasedCellPopulation2_2.pypp.hpp"
#include "AbstractCentreBasedCellPopulation3_3.pypp.hpp"
#include "AbstractOffLatticeCellPopulation2_2.pypp.hpp"
#include "AbstractOffLatticeCellPopulation3_3.pypp.hpp"
#include "CaBasedCellPopulation2.pypp.hpp"
#include "CaBasedCellPopulation3.pypp.hpp"
#include "MeshBasedCellPopulation2_2.pypp.hpp"
#include "MeshBasedCellPopulation3_3.pypp.hpp"
#include "MeshBasedCellPopulationWithGhostNodes2.pypp.hpp"
#include "MeshBasedCellPopulationWithGhostNodes3.pypp.hpp"
#include "VertexBasedCellPopulation2.pypp.hpp"
#include "VertexBasedCellPopulation3.pypp.hpp"
#include "PottsBasedCellPopulation2.pypp.hpp"
#include "PottsBasedCellPopulation3.pypp.hpp"
#include "NodeBasedCellPopulation2.pypp.hpp"
#include "NodeBasedCellPopulation3.pypp.hpp"
#include "AbstractTargetAreaModifier2.pypp.hpp"
#include "AbstractTargetAreaModifier3.pypp.hpp"
#include "SimpleTargetAreaModifier2.pypp.hpp"
#include "SimpleTargetAreaModifier3.pypp.hpp"
#include "VtkSceneModifier2.pypp.hpp"
#include "VtkSceneModifier3.pypp.hpp"
#include "AbstractCellBasedSimulationModifier2_2.pypp.hpp"
#include "AbstractCellBasedSimulationModifier3_3.pypp.hpp"
#include "AbstractCellBasedSimulation2_2.pypp.hpp"
#include "AbstractCellBasedSimulation3_3.pypp.hpp"
#include "SimulationTime.pypp.hpp"
#include "OnLatticeSimulation2.pypp.hpp"
#include "OnLatticeSimulation3.pypp.hpp"
#include "OffLatticeSimulation2_2.pypp.hpp"
#include "OffLatticeSimulation3_3.pypp.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_cell_based, m)
{
register_PottsMesh2_class(m);
register_PottsMesh3_class(m);
register_PottsElement2_class(m);
register_PottsElement3_class(m);
register_AbstractCellCycleModel_class(m);
register_AbstractPhaseBasedCellCycleModel_class(m);
register_AbstractSimpleCellCycleModel_class(m);
register_AbstractSimplePhaseBasedCellCycleModel_class(m);
register_AbstractSimpleGenerationalCellCycleModel_class(m);
register_UniformCellCycleModel_class(m);
register_SimpleOxygenBasedCellCycleModel_class(m);
register_UniformG1GenerationalCellCycleModel_class(m);
register_NoCellCycleModel_class(m);
register_AbstractCellProperty_class(m);
register_CellPropertyCollection_class(m);
register_AbstractCellProliferativeType_class(m);
register_StemCellProliferativeType_class(m);
register_DefaultCellProliferativeType_class(m);
register_TransitCellProliferativeType_class(m);
register_DifferentiatedCellProliferativeType_class(m);
register_AbstractCellMutationState_class(m);
register_ApcOneHitCellMutationState_class(m);
register_ApcTwoHitCellMutationState_class(m);
register_BetaCateninOneHitCellMutationState_class(m);
register_WildTypeCellMutationState_class(m);
register_ApoptoticCellProperty_class(m);
register_CellData_class(m);
register_CellLabel_class(m);
register_CellAncestor_class(m);
register_CellId_class(m);
register_CellPropertyRegistry_class(m);
register_AbstractSrnModel_class(m);
register_NullSrnModel_class(m);
register_Cell_class(m);
register_CellsGeneratorUniformCellCycleModel_2_class(m);
register_CellsGeneratorUniformCellCycleModel_3_class(m);
register_CellsGeneratorSimpleOxygenBasedCellCycleModel_2_class(m);
register_CellsGeneratorSimpleOxygenBasedCellCycleModel_3_class(m);
register_CellsGeneratorUniformG1GenerationalCellCycleModel_2_class(m);
register_CellsGeneratorUniformG1GenerationalCellCycleModel_3_class(m);
register_CellsGeneratorNoCellCycleModel_2_class(m);
register_CellsGeneratorNoCellCycleModel_3_class(m);
register_AbstractLinearPde2_2_class(m);
register_AbstractLinearPde3_3_class(m);
register_AbstractLinearParabolicPde2_2_class(m);
register_AbstractLinearParabolicPde3_3_class(m);
register_AbstractLinearEllipticPde2_2_class(m);
register_AbstractLinearEllipticPde3_3_class(m);
register_CellwiseSourceEllipticPde2_class(m);
register_CellwiseSourceEllipticPde3_class(m);
register_AveragedSourceEllipticPde2_class(m);
register_AveragedSourceEllipticPde3_class(m);
register_AveragedSourceParabolicPde2_class(m);
register_AveragedSourceParabolicPde3_class(m);
register_CellwiseSourceParabolicPde2_class(m);
register_CellwiseSourceParabolicPde3_class(m);
register_AbstractPdeModifier2_class(m);
register_AbstractPdeModifier3_class(m);
register_AbstractGrowingDomainPdeModifier2_class(m);
register_AbstractGrowingDomainPdeModifier3_class(m);
register_EllipticGrowingDomainPdeModifier2_class(m);
register_EllipticGrowingDomainPdeModifier3_class(m);
register_VoronoiDataWriter2_2_class(m);
register_VoronoiDataWriter3_3_class(m);
register_CellLabelWriter2_2_class(m);
register_CellLabelWriter3_3_class(m);
register_AbstractCaUpdateRule2_class(m);
register_AbstractCaUpdateRule3_class(m);
register_AbstractUpdateRule2_class(m);
register_AbstractUpdateRule3_class(m);
register_DiffusionCaUpdateRule2_class(m);
register_DiffusionCaUpdateRule3_class(m);
register_AbstractPottsUpdateRule2_class(m);
register_AbstractPottsUpdateRule3_class(m);
register_VolumeConstraintPottsUpdateRule2_class(m);
register_VolumeConstraintPottsUpdateRule3_class(m);
register_SurfaceAreaConstraintPottsUpdateRule2_class(m);
register_SurfaceAreaConstraintPottsUpdateRule3_class(m);
register_DifferentialAdhesionPottsUpdateRule2_class(m);
register_DifferentialAdhesionPottsUpdateRule3_class(m);
register_AdhesionPottsUpdateRule2_class(m);
register_AdhesionPottsUpdateRule3_class(m);
register_AbstractVertexBasedDivisionRule2_class(m);
register_AbstractVertexBasedDivisionRule3_class(m);
register_AbstractForce2_2_class(m);
register_AbstractForce3_3_class(m);
register_AbstractTwoBodyInteractionForce2_2_class(m);
register_AbstractTwoBodyInteractionForce3_3_class(m);
register_GeneralisedLinearSpringForce2_2_class(m);
register_GeneralisedLinearSpringForce3_3_class(m);
register_NagaiHondaForce2_class(m);
register_NagaiHondaForce3_class(m);
register_AbstractCellKiller2_class(m);
register_AbstractCellKiller3_class(m);
register_PlaneBasedCellKiller2_class(m);
register_PlaneBasedCellKiller3_class(m);
register_ApoptoticCellKiller2_class(m);
register_ApoptoticCellKiller3_class(m);
register_AbstractCellPopulationBoundaryCondition2_2_class(m);
register_AbstractCellPopulationBoundaryCondition3_3_class(m);
register_PlaneBoundaryCondition2_2_class(m);
register_PlaneBoundaryCondition3_3_class(m);
register_AttractingPlaneBoundaryCondition2_2_class(m);
register_AttractingPlaneBoundaryCondition3_3_class(m);
register_SphereGeometryBoundaryCondition2_class(m);
register_SphereGeometryBoundaryCondition3_class(m);
register_AbstractCellPopulation2_2_class(m);
register_AbstractCellPopulation3_3_class(m);
register_AbstractOnLatticeCellPopulation2_class(m);
register_AbstractOnLatticeCellPopulation3_class(m);
register_AbstractCentreBasedCellPopulation2_2_class(m);
register_AbstractCentreBasedCellPopulation3_3_class(m);
register_AbstractOffLatticeCellPopulation2_2_class(m);
register_AbstractOffLatticeCellPopulation3_3_class(m);
register_CaBasedCellPopulation2_class(m);
register_CaBasedCellPopulation3_class(m);
register_MeshBasedCellPopulation2_2_class(m);
register_MeshBasedCellPopulation3_3_class(m);
register_MeshBasedCellPopulationWithGhostNodes2_class(m);
register_MeshBasedCellPopulationWithGhostNodes3_class(m);
register_VertexBasedCellPopulation2_class(m);
register_VertexBasedCellPopulation3_class(m);
register_PottsBasedCellPopulation2_class(m);
register_PottsBasedCellPopulation3_class(m);
register_NodeBasedCellPopulation2_class(m);
register_NodeBasedCellPopulation3_class(m);
register_AbstractTargetAreaModifier2_class(m);
register_AbstractTargetAreaModifier3_class(m);
register_SimpleTargetAreaModifier2_class(m);
register_SimpleTargetAreaModifier3_class(m);
register_VtkSceneModifier2_class(m);
register_VtkSceneModifier3_class(m);
register_AbstractCellBasedSimulationModifier2_2_class(m);
register_AbstractCellBasedSimulationModifier3_3_class(m);
register_AbstractCellBasedSimulation2_2_class(m);
register_AbstractCellBasedSimulation3_3_class(m);
register_SimulationTime_class(m);
register_OnLatticeSimulation2_class(m);
register_OnLatticeSimulation3_class(m);
register_OffLatticeSimulation2_2_class(m);
register_OffLatticeSimulation3_3_class(m);
}
