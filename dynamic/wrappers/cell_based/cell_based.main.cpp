#include <pybind11/pybind11.h>
#include "AbstractCellCycleModel.cppwg.hpp"
#include "AbstractPhaseBasedCellCycleModel.cppwg.hpp"
#include "AbstractSimpleCellCycleModel.cppwg.hpp"
#include "AbstractSimplePhaseBasedCellCycleModel.cppwg.hpp"
#include "AbstractSimpleGenerationalCellCycleModel.cppwg.hpp"
#include "UniformCellCycleModel.cppwg.hpp"
#include "SimpleOxygenBasedCellCycleModel.cppwg.hpp"
#include "UniformG1GenerationalCellCycleModel.cppwg.hpp"
#include "NoCellCycleModel.cppwg.hpp"
#include "AbstractCellCycleModelOdeSolver.cppwg.hpp"
#include "AbstractCellProperty.cppwg.hpp"
#include "CellPropertyCollection.cppwg.hpp"
#include "AbstractCellProliferativeType.cppwg.hpp"
#include "StemCellProliferativeType.cppwg.hpp"
#include "DefaultCellProliferativeType.cppwg.hpp"
#include "TransitCellProliferativeType.cppwg.hpp"
#include "DifferentiatedCellProliferativeType.cppwg.hpp"
#include "AbstractCellMutationState.cppwg.hpp"
#include "ApcOneHitCellMutationState.cppwg.hpp"
#include "ApcTwoHitCellMutationState.cppwg.hpp"
#include "BetaCateninOneHitCellMutationState.cppwg.hpp"
#include "WildTypeCellMutationState.cppwg.hpp"
#include "ApoptoticCellProperty.cppwg.hpp"
#include "CellData.cppwg.hpp"
#include "CellLabel.cppwg.hpp"
#include "CellAncestor.cppwg.hpp"
#include "CellId.cppwg.hpp"
#include "CellPropertyRegistry.cppwg.hpp"
#include "AbstractSrnModel.cppwg.hpp"
#include "NullSrnModel.cppwg.hpp"
#include "Cell.cppwg.hpp"
#include "CellsGeneratorNoCellCycleModel_2.cppwg.hpp"
#include "CellsGeneratorNoCellCycleModel_3.cppwg.hpp"
#include "CellsGeneratorUniformCellCycleModel_2.cppwg.hpp"
#include "CellsGeneratorUniformCellCycleModel_3.cppwg.hpp"
#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_2.cppwg.hpp"
#include "CellsGeneratorSimpleOxygenBasedCellCycleModel_3.cppwg.hpp"
#include "CellsGeneratorUniformG1GenerationalCellCycleModel_2.cppwg.hpp"
#include "CellsGeneratorUniformG1GenerationalCellCycleModel_3.cppwg.hpp"
#include "CellwiseSourceEllipticPde2.cppwg.hpp"
#include "CellwiseSourceEllipticPde3.cppwg.hpp"
#include "AveragedSourceEllipticPde2.cppwg.hpp"
#include "AveragedSourceEllipticPde3.cppwg.hpp"
#include "CellwiseSourceParabolicPde2.cppwg.hpp"
#include "CellwiseSourceParabolicPde3.cppwg.hpp"
#include "AbstractCellBasedSimulationModifier2_2.cppwg.hpp"
#include "AbstractCellBasedSimulationModifier3_3.cppwg.hpp"
#include "AbstractPdeModifier2.cppwg.hpp"
#include "AbstractPdeModifier3.cppwg.hpp"
#include "AbstractGrowingDomainPdeModifier2.cppwg.hpp"
#include "AbstractGrowingDomainPdeModifier3.cppwg.hpp"
#include "EllipticGrowingDomainPdeModifier2.cppwg.hpp"
#include "EllipticGrowingDomainPdeModifier3.cppwg.hpp"
#include "VoronoiDataWriter2_2.cppwg.hpp"
#include "VoronoiDataWriter3_3.cppwg.hpp"
#include "CellLabelWriter2_2.cppwg.hpp"
#include "CellLabelWriter3_3.cppwg.hpp"
#include "AbstractUpdateRule2.cppwg.hpp"
#include "AbstractUpdateRule3.cppwg.hpp"
#include "AbstractCaUpdateRule2.cppwg.hpp"
#include "AbstractCaUpdateRule3.cppwg.hpp"
#include "DiffusionCaUpdateRule2.cppwg.hpp"
#include "DiffusionCaUpdateRule3.cppwg.hpp"
#include "AbstractPottsUpdateRule2.cppwg.hpp"
#include "AbstractPottsUpdateRule3.cppwg.hpp"
#include "VolumeConstraintPottsUpdateRule2.cppwg.hpp"
#include "VolumeConstraintPottsUpdateRule3.cppwg.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule2.cppwg.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule3.cppwg.hpp"
#include "AdhesionPottsUpdateRule2.cppwg.hpp"
#include "AdhesionPottsUpdateRule3.cppwg.hpp"
#include "DifferentialAdhesionPottsUpdateRule2.cppwg.hpp"
#include "DifferentialAdhesionPottsUpdateRule3.cppwg.hpp"
#include "AbstractVertexBasedDivisionRule2.cppwg.hpp"
#include "AbstractVertexBasedDivisionRule3.cppwg.hpp"
#include "AbstractForce2_2.cppwg.hpp"
#include "AbstractForce3_3.cppwg.hpp"
#include "AbstractTwoBodyInteractionForce2_2.cppwg.hpp"
#include "AbstractTwoBodyInteractionForce3_3.cppwg.hpp"
#include "GeneralisedLinearSpringForce2_2.cppwg.hpp"
#include "GeneralisedLinearSpringForce3_3.cppwg.hpp"
#include "NagaiHondaForce2.cppwg.hpp"
#include "NagaiHondaForce3.cppwg.hpp"
#include "AbstractCellKiller2.cppwg.hpp"
#include "AbstractCellKiller3.cppwg.hpp"
#include "PlaneBasedCellKiller2.cppwg.hpp"
#include "PlaneBasedCellKiller3.cppwg.hpp"
#include "ApoptoticCellKiller2.cppwg.hpp"
#include "ApoptoticCellKiller3.cppwg.hpp"
#include "AbstractCellPopulationBoundaryCondition2_2.cppwg.hpp"
#include "AbstractCellPopulationBoundaryCondition3_3.cppwg.hpp"
#include "PlaneBoundaryCondition2_2.cppwg.hpp"
#include "PlaneBoundaryCondition3_3.cppwg.hpp"
#include "AttractingPlaneBoundaryCondition2_2.cppwg.hpp"
#include "AttractingPlaneBoundaryCondition3_3.cppwg.hpp"
#include "SphereGeometryBoundaryCondition2.cppwg.hpp"
#include "SphereGeometryBoundaryCondition3.cppwg.hpp"
#include "AbstractCellPopulation2_2.cppwg.hpp"
#include "AbstractCellPopulation3_3.cppwg.hpp"
#include "AbstractOffLatticeCellPopulation2_2.cppwg.hpp"
#include "AbstractOffLatticeCellPopulation3_3.cppwg.hpp"
#include "AbstractCentreBasedCellPopulation2_2.cppwg.hpp"
#include "AbstractCentreBasedCellPopulation3_3.cppwg.hpp"
#include "AbstractOnLatticeCellPopulation2.cppwg.hpp"
#include "AbstractOnLatticeCellPopulation3.cppwg.hpp"
#include "CaBasedCellPopulation2.cppwg.hpp"
#include "CaBasedCellPopulation3.cppwg.hpp"
#include "MeshBasedCellPopulation2_2.cppwg.hpp"
#include "MeshBasedCellPopulation3_3.cppwg.hpp"
#include "MeshBasedCellPopulationWithGhostNodes2.cppwg.hpp"
#include "MeshBasedCellPopulationWithGhostNodes3.cppwg.hpp"
#include "VertexBasedCellPopulation2.cppwg.hpp"
#include "VertexBasedCellPopulation3.cppwg.hpp"
#include "PottsBasedCellPopulation2.cppwg.hpp"
#include "PottsBasedCellPopulation3.cppwg.hpp"
#include "NodeBasedCellPopulation2.cppwg.hpp"
#include "NodeBasedCellPopulation3.cppwg.hpp"
#include "AbstractTargetAreaModifier2.cppwg.hpp"
#include "AbstractTargetAreaModifier3.cppwg.hpp"
#include "SimpleTargetAreaModifier2.cppwg.hpp"
#include "SimpleTargetAreaModifier3.cppwg.hpp"
#include "VtkSceneModifier2.cppwg.hpp"
#include "VtkSceneModifier3.cppwg.hpp"
#include "AbstractCellBasedSimulation2_2.cppwg.hpp"
#include "AbstractCellBasedSimulation3_3.cppwg.hpp"
#include "SimulationTime.cppwg.hpp"
#include "OnLatticeSimulation2.cppwg.hpp"
#include "OnLatticeSimulation3.cppwg.hpp"
#include "OffLatticeSimulation2_2.cppwg.hpp"
#include "OffLatticeSimulation3_3.cppwg.hpp"
#include "PythonSimulationModifier2.cppwg.hpp"
#include "PythonSimulationModifier3.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_cell_based, m)
{
    register_AbstractCellCycleModel_class(m);
    register_AbstractPhaseBasedCellCycleModel_class(m);
    register_AbstractSimpleCellCycleModel_class(m);
    register_AbstractSimplePhaseBasedCellCycleModel_class(m);
    register_AbstractSimpleGenerationalCellCycleModel_class(m);
    register_UniformCellCycleModel_class(m);
    register_SimpleOxygenBasedCellCycleModel_class(m);
    register_UniformG1GenerationalCellCycleModel_class(m);
    register_NoCellCycleModel_class(m);
    register_AbstractCellCycleModelOdeSolver_class(m);
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
    register_CellsGeneratorNoCellCycleModel_2_class(m);
    register_CellsGeneratorNoCellCycleModel_3_class(m);
    register_CellsGeneratorUniformCellCycleModel_2_class(m);
    register_CellsGeneratorUniformCellCycleModel_3_class(m);
    register_CellsGeneratorSimpleOxygenBasedCellCycleModel_2_class(m);
    register_CellsGeneratorSimpleOxygenBasedCellCycleModel_3_class(m);
    register_CellsGeneratorUniformG1GenerationalCellCycleModel_2_class(m);
    register_CellsGeneratorUniformG1GenerationalCellCycleModel_3_class(m);
    register_CellwiseSourceEllipticPde2_class(m);
    register_CellwiseSourceEllipticPde3_class(m);
    register_AveragedSourceEllipticPde2_class(m);
    register_AveragedSourceEllipticPde3_class(m);
    register_CellwiseSourceParabolicPde2_class(m);
    register_CellwiseSourceParabolicPde3_class(m);
    register_AbstractCellBasedSimulationModifier2_2_class(m);
    register_AbstractCellBasedSimulationModifier3_3_class(m);
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
    register_AbstractUpdateRule2_class(m);
    register_AbstractUpdateRule3_class(m);
    register_AbstractCaUpdateRule2_class(m);
    register_AbstractCaUpdateRule3_class(m);
    register_DiffusionCaUpdateRule2_class(m);
    register_DiffusionCaUpdateRule3_class(m);
    register_AbstractPottsUpdateRule2_class(m);
    register_AbstractPottsUpdateRule3_class(m);
    register_VolumeConstraintPottsUpdateRule2_class(m);
    register_VolumeConstraintPottsUpdateRule3_class(m);
    register_SurfaceAreaConstraintPottsUpdateRule2_class(m);
    register_SurfaceAreaConstraintPottsUpdateRule3_class(m);
    register_AdhesionPottsUpdateRule2_class(m);
    register_AdhesionPottsUpdateRule3_class(m);
    register_DifferentialAdhesionPottsUpdateRule2_class(m);
    register_DifferentialAdhesionPottsUpdateRule3_class(m);
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
    register_AbstractOffLatticeCellPopulation2_2_class(m);
    register_AbstractOffLatticeCellPopulation3_3_class(m);
    register_AbstractCentreBasedCellPopulation2_2_class(m);
    register_AbstractCentreBasedCellPopulation3_3_class(m);
    register_AbstractOnLatticeCellPopulation2_class(m);
    register_AbstractOnLatticeCellPopulation3_class(m);
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
    register_AbstractCellBasedSimulation2_2_class(m);
    register_AbstractCellBasedSimulation3_3_class(m);
    register_SimulationTime_class(m);
    register_OnLatticeSimulation2_class(m);
    register_OnLatticeSimulation3_class(m);
    register_OffLatticeSimulation2_2_class(m);
    register_OffLatticeSimulation3_3_class(m);
    register_PythonSimulationModifier2_class(m);
    register_PythonSimulationModifier3_class(m);
}
