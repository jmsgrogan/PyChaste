#ifndef PYCHASTEHEADERS_HPP_
#define PYCHASTEHEADERS_HPP_

// Includes 
#include <vector>
#include <set>
#include <map>
#include "BoostFilesystem.hpp"
#include "FileFinder.hpp"
#include "OutputFileHandler.hpp"
#include "ProgressReporter.hpp"
#include "RandomNumberGenerator.hpp"
#include "SmartPointers.hpp"
#include "TimeStepper.hpp"
#include "Version.hpp"
#include "Identifiable.hpp"
#include "PetscTools.hpp"
#include "ReplicatableVector.hpp"
#include "Timer.hpp"
#include "UblasIncludes.hpp"
#include "AbstractOdeSystemInformation.hpp"
#include "AbstractPythonOdeSystemInformation.hpp"
#include "AbstractOdeSystem.hpp"
#include "AbstractLinearPde.hpp"
#include "AbstractLinearParabolicPde.hpp"
#include "AbstractLinearEllipticPde.hpp"
#include "AbstractNonlinearEllipticPde.hpp"
#include "AbstractBoundaryCondition.hpp"
#include "ConstBoundaryCondition.hpp"
#include "PdeSimulationTime.hpp"
#include "ChastePoint.hpp"
#include "NodeAttributes.hpp"
#include "Node.hpp"
#include "Element.hpp"
#include "NodesOnlyMesh.hpp"
#include "MutableMesh.hpp"
#include "PottsMesh.hpp"
#include "SharedPottsMeshGenerator.hpp"
#include "PottsElement.hpp"
#include "TetrahedralMesh.hpp"
#include "AbstractTetrahedralMesh.hpp"
#include "AbstractMesh.hpp"
#include "VertexMesh.hpp"
#include "MutableVertexMesh.hpp"
#include "Cylindrical2dVertexMesh.hpp"
#include "SharedHoneycombMeshGenerator.hpp"
#include "SharedHoneycombVertexMeshGenerator.hpp"
#include "SharedCylindricalHoneycombVertexMeshGenerator.hpp"
#include "AbstractCellBasedSimulation.hpp"
#include "SimulationTime.hpp"
#include "OnLatticeSimulation.hpp"
#include "OffLatticeSimulation.hpp"
#include "AbstractCellPopulation.hpp"
#include "AbstractOnLatticeCellPopulation.hpp"
#include "AbstractCentreBasedCellPopulation.hpp"
#include "AbstractOffLatticeCellPopulation.hpp"
#include "CaBasedCellPopulation.hpp"
#include "MeshBasedCellPopulation.hpp"
#include "MeshBasedCellPopulationWithGhostNodes.hpp"
#include "VertexBasedCellPopulation.hpp"
#include "PottsBasedCellPopulation.hpp"
#include "NodeBasedCellPopulation.hpp"
#include "VoronoiDataWriter.hpp"
#include "CellLabelWriter.hpp"
#include "AbstractCellPopulationBoundaryCondition.hpp"
#include "PlaneBoundaryCondition.hpp"
#include "AttractingPlaneBoundaryCondition.hpp"
#include "SphereGeometryBoundaryCondition.hpp"
#include "AbstractCellKiller.hpp"
#include "PlaneBasedCellKiller.hpp"
#include "ApoptoticCellKiller.hpp"
#include "AbstractForce.hpp"
#include "AbstractTwoBodyInteractionForce.hpp"
#include "GeneralisedLinearSpringForce.hpp"
#include "NagaiHondaForce.hpp"
#include "AbstractVertexBasedDivisionRule.hpp"
#include "AbstractCaUpdateRule.hpp"
#include "AbstractUpdateRule.hpp"
#include "DiffusionCaUpdateRule.hpp"
#include "AbstractPottsUpdateRule.hpp"
#include "VolumeConstraintPottsUpdateRule.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule.hpp"
#include "DifferentialAdhesionPottsUpdateRule.hpp"
#include "AdhesionPottsUpdateRule.hpp"
#include "CellwiseSourceEllipticPde.hpp"
#include "AveragedSourceEllipticPde.hpp"
#include "AveragedSourceParabolicPde.hpp"
#include "CellwiseSourceParabolicPde.hpp"
#include "AbstractPdeModifier.hpp"
#include "AbstractGrowingDomainPdeModifier.hpp"
#include "EllipticGrowingDomainPdeModifier.hpp"
#include "Cell.hpp"
#include "CellsGenerator.hpp"
#include "AbstractCellCycleModel.hpp"
#include "AbstractPhaseBasedCellCycleModel.hpp"
#include "AbstractSimpleCellCycleModel.hpp"
#include "AbstractSimplePhaseBasedCellCycleModel.hpp"
#include "AbstractSimpleGenerationalCellCycleModel.hpp"
#include "UniformCellCycleModel.hpp"
#include "SimpleOxygenBasedCellCycleModel.hpp"
#include "UniformG1GenerationalCellCycleModel.hpp"
#include "NoCellCycleModel.hpp"
#include "AbstractCellProperty.hpp"
#include "CellPropertyCollection.hpp"
#include "AbstractCellProliferativeType.hpp"
#include "StemCellProliferativeType.hpp"
#include "DefaultCellProliferativeType.hpp"
#include "TransitCellProliferativeType.hpp"
#include "DifferentiatedCellProliferativeType.hpp"
#include "AbstractCellMutationState.hpp"
#include "ApcOneHitCellMutationState.hpp"
#include "ApcTwoHitCellMutationState.hpp"
#include "BetaCateninOneHitCellMutationState.hpp"
#include "WildTypeCellMutationState.hpp"
#include "ApoptoticCellProperty.hpp"
#include "CellData.hpp"
#include "CellLabel.hpp"
#include "CellAncestor.hpp"
#include "CellId.hpp"
#include "CellPropertyRegistry.hpp"
#include "AbstractSrnModel.hpp"
#include "NullSrnModel.hpp"
#include "AbstractTargetAreaModifier.hpp"
#include "SimpleTargetAreaModifier.hpp"
#include "VtkSceneModifier.hpp"
#include "AbstractCellBasedSimulationModifier.hpp"
#include "Hello.hpp"
#include "VtkScene.hpp"
#include "AbstractPyChasteActorGenerator.hpp"
#include "CellPopulationPyChasteActorGenerator.hpp"

// Instantiate Template Classes 
template class AbstractNonlinearEllipticPde<2 >;
template class AbstractNonlinearEllipticPde<3 >;
template class AbstractBoundaryCondition<2 >;
template class AbstractBoundaryCondition<3 >;
template class ConstBoundaryCondition<2 >;
template class ConstBoundaryCondition<3 >;
template class ChastePoint<2 >;
template class ChastePoint<3 >;
template class NodeAttributes<2 >;
template class NodeAttributes<3 >;
template class Node<2 >;
template class Node<3 >;
template class Element<2,2 >;
template class Element<3,3 >;
template class NodesOnlyMesh<2 >;
template class NodesOnlyMesh<3 >;
template class MutableMesh<2,2 >;
template class MutableMesh<3,3 >;
template class PottsMesh<2 >;
template class PottsMesh<3 >;
template class SharedPottsMeshGenerator<2 >;
template class SharedPottsMeshGenerator<3 >;
template class PottsElement<2 >;
template class PottsElement<3 >;
template class TetrahedralMesh<2,2 >;
template class TetrahedralMesh<3,3 >;
template class AbstractTetrahedralMesh<2,2 >;
template class AbstractTetrahedralMesh<3,3 >;
template class AbstractMesh<2,2 >;
template class AbstractMesh<3,3 >;
template class VertexMesh<2,2 >;
template class VertexMesh<3,3 >;
template class MutableVertexMesh<2,2 >;
template class MutableVertexMesh<3,3 >;
template class AbstractCellBasedSimulation<2,2 >;
template class AbstractCellBasedSimulation<3,3 >;
template class OnLatticeSimulation<2 >;
template class OnLatticeSimulation<3 >;
template class OffLatticeSimulation<2,2 >;
template class OffLatticeSimulation<3,3 >;
template class AbstractCellPopulation<2,2 >;
template class AbstractCellPopulation<3,3 >;
template class AbstractOnLatticeCellPopulation<2 >;
template class AbstractOnLatticeCellPopulation<3 >;
template class AbstractCentreBasedCellPopulation<2,2 >;
template class AbstractCentreBasedCellPopulation<3,3 >;
template class AbstractOffLatticeCellPopulation<2,2 >;
template class AbstractOffLatticeCellPopulation<3,3 >;
template class CaBasedCellPopulation<2 >;
template class CaBasedCellPopulation<3 >;
template class MeshBasedCellPopulation<2,2 >;
template class MeshBasedCellPopulation<3,3 >;
template class MeshBasedCellPopulationWithGhostNodes<2 >;
template class MeshBasedCellPopulationWithGhostNodes<3 >;
template class VertexBasedCellPopulation<2 >;
template class VertexBasedCellPopulation<3 >;
template class PottsBasedCellPopulation<2 >;
template class PottsBasedCellPopulation<3 >;
template class NodeBasedCellPopulation<2 >;
template class NodeBasedCellPopulation<3 >;
template class VoronoiDataWriter<2,2 >;
template class VoronoiDataWriter<3,3 >;
template class CellLabelWriter<2,2 >;
template class CellLabelWriter<3,3 >;
template class AbstractCellPopulationBoundaryCondition<2,2 >;
template class AbstractCellPopulationBoundaryCondition<3,3 >;
template class PlaneBoundaryCondition<2,2 >;
template class PlaneBoundaryCondition<3,3 >;
template class AttractingPlaneBoundaryCondition<2,2 >;
template class AttractingPlaneBoundaryCondition<3,3 >;
template class SphereGeometryBoundaryCondition<2 >;
template class SphereGeometryBoundaryCondition<3 >;
template class AbstractCellKiller<2 >;
template class AbstractCellKiller<3 >;
template class PlaneBasedCellKiller<2 >;
template class PlaneBasedCellKiller<3 >;
template class ApoptoticCellKiller<2 >;
template class ApoptoticCellKiller<3 >;
template class AbstractForce<2,2 >;
template class AbstractForce<3,3 >;
template class AbstractTwoBodyInteractionForce<2,2 >;
template class AbstractTwoBodyInteractionForce<3,3 >;
template class GeneralisedLinearSpringForce<2,2 >;
template class GeneralisedLinearSpringForce<3,3 >;
template class NagaiHondaForce<2 >;
template class NagaiHondaForce<3 >;
template class AbstractVertexBasedDivisionRule<2 >;
template class AbstractVertexBasedDivisionRule<3 >;
template class AbstractCaUpdateRule<2 >;
template class AbstractCaUpdateRule<3 >;
template class AbstractUpdateRule<2 >;
template class AbstractUpdateRule<3 >;
template class DiffusionCaUpdateRule<2 >;
template class DiffusionCaUpdateRule<3 >;
template class AbstractPottsUpdateRule<2 >;
template class AbstractPottsUpdateRule<3 >;
template class VolumeConstraintPottsUpdateRule<2 >;
template class VolumeConstraintPottsUpdateRule<3 >;
template class SurfaceAreaConstraintPottsUpdateRule<2 >;
template class SurfaceAreaConstraintPottsUpdateRule<3 >;
template class DifferentialAdhesionPottsUpdateRule<2 >;
template class DifferentialAdhesionPottsUpdateRule<3 >;
template class AdhesionPottsUpdateRule<2 >;
template class AdhesionPottsUpdateRule<3 >;
template class CellwiseSourceEllipticPde<2 >;
template class CellwiseSourceEllipticPde<3 >;
template class AveragedSourceEllipticPde<2 >;
template class AveragedSourceEllipticPde<3 >;
template class AveragedSourceParabolicPde<2 >;
template class AveragedSourceParabolicPde<3 >;
template class CellwiseSourceParabolicPde<2 >;
template class CellwiseSourceParabolicPde<3 >;
template class AbstractPdeModifier<2 >;
template class AbstractPdeModifier<3 >;
template class AbstractGrowingDomainPdeModifier<2 >;
template class AbstractGrowingDomainPdeModifier<3 >;
template class EllipticGrowingDomainPdeModifier<2 >;
template class EllipticGrowingDomainPdeModifier<3 >;
template class CellsGenerator<UniformCellCycleModel,2 >;
template class CellsGenerator<UniformCellCycleModel,3 >;
template class CellsGenerator<SimpleOxygenBasedCellCycleModel,2 >;
template class CellsGenerator<SimpleOxygenBasedCellCycleModel,3 >;
template class CellsGenerator<UniformG1GenerationalCellCycleModel,2 >;
template class CellsGenerator<UniformG1GenerationalCellCycleModel,3 >;
template class CellsGenerator<NoCellCycleModel,2 >;
template class CellsGenerator<NoCellCycleModel,3 >;
template class AbstractTargetAreaModifier<2 >;
template class AbstractTargetAreaModifier<3 >;
template class SimpleTargetAreaModifier<2 >;
template class SimpleTargetAreaModifier<3 >;
template class VtkSceneModifier<2 >;
template class VtkSceneModifier<3 >;
template class AbstractCellBasedSimulationModifier<2,2 >;
template class AbstractCellBasedSimulationModifier<3,3 >;
template class VtkScene<2 >;
template class VtkScene<3 >;
template class AbstractPyChasteActorGenerator<2 >;
template class AbstractPyChasteActorGenerator<3 >;
template class CellPopulationPyChasteActorGenerator<2 >;
template class CellPopulationPyChasteActorGenerator<3 >;

// Typedef for nicer naming
namespace pyplusplus{ 
namespace aliases{ 
typedef AbstractNonlinearEllipticPde<2 > AbstractNonlinearEllipticPde2;
typedef AbstractNonlinearEllipticPde<3 > AbstractNonlinearEllipticPde3;
typedef AbstractBoundaryCondition<2 > AbstractBoundaryCondition2;
typedef AbstractBoundaryCondition<3 > AbstractBoundaryCondition3;
typedef ConstBoundaryCondition<2 > ConstBoundaryCondition2;
typedef ConstBoundaryCondition<3 > ConstBoundaryCondition3;
typedef ChastePoint<2 > ChastePoint2;
typedef ChastePoint<3 > ChastePoint3;
typedef NodeAttributes<2 > NodeAttributes2;
typedef NodeAttributes<3 > NodeAttributes3;
typedef Node<2 > Node2;
typedef Node<3 > Node3;
typedef Element<2,2 > Element2_2;
typedef Element<3,3 > Element3_3;
typedef NodesOnlyMesh<2 > NodesOnlyMesh2;
typedef NodesOnlyMesh<3 > NodesOnlyMesh3;
typedef MutableMesh<2,2 > MutableMesh2_2;
typedef MutableMesh<3,3 > MutableMesh3_3;
typedef PottsMesh<2 > PottsMesh2;
typedef PottsMesh<3 > PottsMesh3;
typedef SharedPottsMeshGenerator<2 > PottsMeshGenerator2;
typedef SharedPottsMeshGenerator<3 > PottsMeshGenerator3;
typedef PottsElement<2 > PottsElement2;
typedef PottsElement<3 > PottsElement3;
typedef TetrahedralMesh<2,2 > TetrahedralMesh2_2;
typedef TetrahedralMesh<3,3 > TetrahedralMesh3_3;
typedef AbstractTetrahedralMesh<2,2 > AbstractTetrahedralMesh2_2;
typedef AbstractTetrahedralMesh<3,3 > AbstractTetrahedralMesh3_3;
typedef AbstractMesh<2,2 > AbstractMesh2_2;
typedef AbstractMesh<3,3 > AbstractMesh3_3;
typedef VertexMesh<2,2 > VertexMesh2_2;
typedef VertexMesh<3,3 > VertexMesh3_3;
typedef MutableVertexMesh<2,2 > MutableVertexMesh2_2;
typedef MutableVertexMesh<3,3 > MutableVertexMesh3_3;
typedef AbstractCellBasedSimulation<2,2 > AbstractCellBasedSimulation2_2;
typedef AbstractCellBasedSimulation<3,3 > AbstractCellBasedSimulation3_3;
typedef OnLatticeSimulation<2 > OnLatticeSimulation2;
typedef OnLatticeSimulation<3 > OnLatticeSimulation3;
typedef OffLatticeSimulation<2,2 > OffLatticeSimulation2_2;
typedef OffLatticeSimulation<3,3 > OffLatticeSimulation3_3;
typedef AbstractCellPopulation<2,2 > AbstractCellPopulation2_2;
typedef AbstractCellPopulation<3,3 > AbstractCellPopulation3_3;
typedef AbstractOnLatticeCellPopulation<2 > AbstractOnLatticeCellPopulation2;
typedef AbstractOnLatticeCellPopulation<3 > AbstractOnLatticeCellPopulation3;
typedef AbstractCentreBasedCellPopulation<2,2 > AbstractCentreBasedCellPopulation2_2;
typedef AbstractCentreBasedCellPopulation<3,3 > AbstractCentreBasedCellPopulation3_3;
typedef AbstractOffLatticeCellPopulation<2,2 > AbstractOffLatticeCellPopulation2_2;
typedef AbstractOffLatticeCellPopulation<3,3 > AbstractOffLatticeCellPopulation3_3;
typedef CaBasedCellPopulation<2 > CaBasedCellPopulation2;
typedef CaBasedCellPopulation<3 > CaBasedCellPopulation3;
typedef MeshBasedCellPopulation<2,2 > MeshBasedCellPopulation2_2;
typedef MeshBasedCellPopulation<3,3 > MeshBasedCellPopulation3_3;
typedef MeshBasedCellPopulationWithGhostNodes<2 > MeshBasedCellPopulationWithGhostNodes2;
typedef MeshBasedCellPopulationWithGhostNodes<3 > MeshBasedCellPopulationWithGhostNodes3;
typedef VertexBasedCellPopulation<2 > VertexBasedCellPopulation2;
typedef VertexBasedCellPopulation<3 > VertexBasedCellPopulation3;
typedef PottsBasedCellPopulation<2 > PottsBasedCellPopulation2;
typedef PottsBasedCellPopulation<3 > PottsBasedCellPopulation3;
typedef NodeBasedCellPopulation<2 > NodeBasedCellPopulation2;
typedef NodeBasedCellPopulation<3 > NodeBasedCellPopulation3;
typedef VoronoiDataWriter<2,2 > VoronoiDataWriter2_2;
typedef VoronoiDataWriter<3,3 > VoronoiDataWriter3_3;
typedef CellLabelWriter<2,2 > CellLabelWriter2_2;
typedef CellLabelWriter<3,3 > CellLabelWriter3_3;
typedef AbstractCellPopulationBoundaryCondition<2,2 > AbstractCellPopulationBoundaryCondition2_2;
typedef AbstractCellPopulationBoundaryCondition<3,3 > AbstractCellPopulationBoundaryCondition3_3;
typedef PlaneBoundaryCondition<2,2 > PlaneBoundaryCondition2_2;
typedef PlaneBoundaryCondition<3,3 > PlaneBoundaryCondition3_3;
typedef AttractingPlaneBoundaryCondition<2,2 > AttractingPlaneBoundaryCondition2_2;
typedef AttractingPlaneBoundaryCondition<3,3 > AttractingPlaneBoundaryCondition3_3;
typedef SphereGeometryBoundaryCondition<2 > SphereGeometryBoundaryCondition2;
typedef SphereGeometryBoundaryCondition<3 > SphereGeometryBoundaryCondition3;
typedef AbstractCellKiller<2 > AbstractCellKiller2;
typedef AbstractCellKiller<3 > AbstractCellKiller3;
typedef PlaneBasedCellKiller<2 > PlaneBasedCellKiller2;
typedef PlaneBasedCellKiller<3 > PlaneBasedCellKiller3;
typedef ApoptoticCellKiller<2 > ApoptoticCellKiller2;
typedef ApoptoticCellKiller<3 > ApoptoticCellKiller3;
typedef AbstractForce<2,2 > AbstractForce2_2;
typedef AbstractForce<3,3 > AbstractForce3_3;
typedef AbstractTwoBodyInteractionForce<2,2 > AbstractTwoBodyInteractionForce2_2;
typedef AbstractTwoBodyInteractionForce<3,3 > AbstractTwoBodyInteractionForce3_3;
typedef GeneralisedLinearSpringForce<2,2 > GeneralisedLinearSpringForce2_2;
typedef GeneralisedLinearSpringForce<3,3 > GeneralisedLinearSpringForce3_3;
typedef NagaiHondaForce<2 > NagaiHondaForce2;
typedef NagaiHondaForce<3 > NagaiHondaForce3;
typedef AbstractVertexBasedDivisionRule<2 > AbstractVertexBasedDivisionRule2;
typedef AbstractVertexBasedDivisionRule<3 > AbstractVertexBasedDivisionRule3;
typedef AbstractCaUpdateRule<2 > AbstractCaUpdateRule2;
typedef AbstractCaUpdateRule<3 > AbstractCaUpdateRule3;
typedef AbstractUpdateRule<2 > AbstractUpdateRule2;
typedef AbstractUpdateRule<3 > AbstractUpdateRule3;
typedef DiffusionCaUpdateRule<2 > DiffusionCaUpdateRule2;
typedef DiffusionCaUpdateRule<3 > DiffusionCaUpdateRule3;
typedef AbstractPottsUpdateRule<2 > AbstractPottsUpdateRule2;
typedef AbstractPottsUpdateRule<3 > AbstractPottsUpdateRule3;
typedef VolumeConstraintPottsUpdateRule<2 > VolumeConstraintPottsUpdateRule2;
typedef VolumeConstraintPottsUpdateRule<3 > VolumeConstraintPottsUpdateRule3;
typedef SurfaceAreaConstraintPottsUpdateRule<2 > SurfaceAreaConstraintPottsUpdateRule2;
typedef SurfaceAreaConstraintPottsUpdateRule<3 > SurfaceAreaConstraintPottsUpdateRule3;
typedef DifferentialAdhesionPottsUpdateRule<2 > DifferentialAdhesionPottsUpdateRule2;
typedef DifferentialAdhesionPottsUpdateRule<3 > DifferentialAdhesionPottsUpdateRule3;
typedef AdhesionPottsUpdateRule<2 > AdhesionPottsUpdateRule2;
typedef AdhesionPottsUpdateRule<3 > AdhesionPottsUpdateRule3;
typedef AbstractLinearPde<2,2 > AbstractLinearPde2_2;
typedef AbstractLinearPde<3,3 > AbstractLinearPde3_3;
typedef AbstractLinearParabolicPde<2,2 > AbstractLinearParabolicPde2_2;
typedef AbstractLinearParabolicPde<3,3 > AbstractLinearParabolicPde3_3;
typedef AbstractLinearEllipticPde<2,2 > AbstractLinearEllipticPde2_2;
typedef AbstractLinearEllipticPde<3,3 > AbstractLinearEllipticPde3_3;
typedef CellwiseSourceEllipticPde<2 > CellwiseSourceEllipticPde2;
typedef CellwiseSourceEllipticPde<3 > CellwiseSourceEllipticPde3;
typedef AveragedSourceEllipticPde<2 > AveragedSourceEllipticPde2;
typedef AveragedSourceEllipticPde<3 > AveragedSourceEllipticPde3;
typedef AveragedSourceParabolicPde<2 > AveragedSourceParabolicPde2;
typedef AveragedSourceParabolicPde<3 > AveragedSourceParabolicPde3;
typedef CellwiseSourceParabolicPde<2 > CellwiseSourceParabolicPde2;
typedef CellwiseSourceParabolicPde<3 > CellwiseSourceParabolicPde3;
typedef AbstractPdeModifier<2 > AbstractPdeModifier2;
typedef AbstractPdeModifier<3 > AbstractPdeModifier3;
typedef AbstractGrowingDomainPdeModifier<2 > AbstractGrowingDomainPdeModifier2;
typedef AbstractGrowingDomainPdeModifier<3 > AbstractGrowingDomainPdeModifier3;
typedef EllipticGrowingDomainPdeModifier<2 > EllipticGrowingDomainPdeModifier2;
typedef EllipticGrowingDomainPdeModifier<3 > EllipticGrowingDomainPdeModifier3;
typedef Cell Cell;
typedef CellsGenerator<UniformCellCycleModel,2 > CellsGeneratorUniformCellCycleModel_2;
typedef CellsGenerator<UniformCellCycleModel,3 > CellsGeneratorUniformCellCycleModel_3;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel,2 > CellsGeneratorSimpleOxygenBasedCellCycleModel_2;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel,3 > CellsGeneratorSimpleOxygenBasedCellCycleModel_3;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel,2 > CellsGeneratorUniformG1GenerationalCellCycleModel_2;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel,3 > CellsGeneratorUniformG1GenerationalCellCycleModel_3;
typedef CellsGenerator<NoCellCycleModel,2 > CellsGeneratorNoCellCycleModel_2;
typedef CellsGenerator<NoCellCycleModel,3 > CellsGeneratorNoCellCycleModel_3;
typedef AbstractCellProperty AbstractCellProperty;
typedef AbstractTargetAreaModifier<2 > AbstractTargetAreaModifier2;
typedef AbstractTargetAreaModifier<3 > AbstractTargetAreaModifier3;
typedef SimpleTargetAreaModifier<2 > SimpleTargetAreaModifier2;
typedef SimpleTargetAreaModifier<3 > SimpleTargetAreaModifier3;
typedef VtkSceneModifier<2 > VtkSceneModifier2;
typedef VtkSceneModifier<3 > VtkSceneModifier3;
typedef AbstractCellBasedSimulationModifier<2,2 > AbstractCellBasedSimulationModifier2_2;
typedef AbstractCellBasedSimulationModifier<3,3 > AbstractCellBasedSimulationModifier3_3;
typedef VtkScene<2 > VtkScene2;
typedef VtkScene<3 > VtkScene3;
typedef AbstractPyChasteActorGenerator<2 > AbstractPyChasteActorGenerator2;
typedef AbstractPyChasteActorGenerator<3 > AbstractPyChasteActorGenerator3;
typedef CellPopulationPyChasteActorGenerator<2 > CellPopulationPyChasteActorGenerator2;
typedef CellPopulationPyChasteActorGenerator<3 > CellPopulationPyChasteActorGenerator3;
    }
}

// Need to specifically instantiate PETSc Vec and Mat 

 inline int Instantiation()
{
return sizeof(Mat) + sizeof(Vec);
}

 inline Mat GetPetscMatForWrapper()
{
Mat A;
PetscTools::SetupMat(A, 3, 3, 3);
return A;
}
#endif // PYCHASTEHEADERS_HPP_
