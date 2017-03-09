/*

Copyright (c) 2005-2017, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef PYCHASTECELLBASEDHEADERS_HPP_
#define PYCHASTECELLBASEDHEADERS_HPP_

#include "AttractingPlaneBoundaryCondition.hpp"
#include "PetscTools.hpp"

// Base
#include "Identifiable.hpp"
#include "Cell.hpp"
#include "CellsGenerator.hpp"
#include "CellId.hpp"
#include "CellPropertyRegistry.hpp"
#include "CellData.hpp"
#include "CellLabel.hpp"
#include "CellAncestor.hpp"

// Populations
#include "AbstractCellPopulation.hpp"
#include "AbstractOnLatticeCellPopulation.hpp"
#include "CaBasedCellPopulation.hpp"
#include "AbstractCentreBasedCellPopulation.hpp"
#include "AbstractOffLatticeCellPopulation.hpp"
#include "MeshBasedCellPopulation.hpp"
#include "MeshBasedCellPopulationWithGhostNodes.hpp"
#include "VertexBasedCellPopulation.hpp"
#include "PottsBasedCellPopulation.hpp"
#include "NodeBasedCellPopulation.hpp"

// Writers
#include "VoronoiDataWriter.hpp"
#include "CellLabelWriter.hpp"

// Cell properties
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

// Cycle models
#include "AbstractCellCycleModel.hpp"
#include "AbstractPhaseBasedCellCycleModel.hpp"
#include "AbstractSimpleCellCycleModel.hpp"
#include "AbstractSimplePhaseBasedCellCycleModel.hpp"
#include "AbstractSimpleGenerationalCellCycleModel.hpp"
#include "UniformCellCycleModel.hpp"
#include "SimpleOxygenBasedCellCycleModel.hpp"
#include "UniformG1GenerationalCellCycleModel.hpp"
#include "NoCellCycleModel.hpp"

// Update rules
#include "AbstractCaUpdateRule.hpp"
#include "AbstractUpdateRule.hpp"
#include "DiffusionCaUpdateRule.hpp"
#include "AbstractPottsUpdateRule.hpp"
#include "VolumeConstraintPottsUpdateRule.hpp"
#include "SurfaceAreaConstraintPottsUpdateRule.hpp"
#include "DifferentialAdhesionPottsUpdateRule.hpp"
#include "AdhesionPottsUpdateRule.hpp"

// Forces
#include "AbstractForce.hpp"
#include "AbstractTwoBodyInteractionForce.hpp"
#include "GeneralisedLinearSpringForce.hpp"
#include "NagaiHondaForce.hpp"

// Simulations
#include "AbstractCellBasedSimulation.hpp"
#include "SimulationTime.hpp"
#include "OnLatticeSimulation.hpp"
#include "OffLatticeSimulation.hpp"

// Simulation modifiers
#include "AbstractCellBasedSimulationModifier.hpp"
#include "AbstractTargetAreaModifier.hpp"
#include "SimpleTargetAreaModifier.hpp"
#include "VtkSceneModifier.hpp"

// Boundary conditions
#include "AbstractCellPopulationBoundaryCondition.hpp"
#include "PlaneBoundaryCondition.hpp"
#include "SphereGeometryBoundaryCondition.hpp"

// Killers
#include "AbstractCellKiller.hpp"
#include "PlaneBasedCellKiller.hpp"
#include "ApoptoticCellKiller.hpp"
#include "RandomCellKiller.hpp"

// Pdes
#include "CellwiseSourceEllipticPde.hpp"
#include "AbstractPdeModifier.hpp"
#include "AbstractGrowingDomainPdeModifier.hpp"
#include "EllipticGrowingDomainPdeModifier.hpp"

// Dependencies
#include "AbstractLinearEllipticPde.hpp"
#include "AbstractLinearPde.hpp"


// Populations
template class AbstractCellPopulation<2, 2>;
template class AbstractCentreBasedCellPopulation<2, 2>;
template class AbstractOffLatticeCellPopulation<2, 2>;
template class AbstractOnLatticeCellPopulation<2>;
template class CaBasedCellPopulation<2>;
template class NodeBasedCellPopulation<2>;
template class MeshBasedCellPopulation<2, 2>;
template class MeshBasedCellPopulationWithGhostNodes<2>;
template class VertexBasedCellPopulation<2>;
template class PottsBasedCellPopulation<2>;
template class AbstractCellPopulation<3, 3>;
template class AbstractCentreBasedCellPopulation<3, 3>;
template class AbstractOffLatticeCellPopulation<3, 3>;
template class AbstractOnLatticeCellPopulation<3>;
template class CaBasedCellPopulation<3>;
template class NodeBasedCellPopulation<3>;
template class MeshBasedCellPopulation<3, 3>;
template class MeshBasedCellPopulationWithGhostNodes<3>;
template class VertexBasedCellPopulation<3>;
template class PottsBasedCellPopulation<3>;

// Simulations
template class AbstractCellBasedSimulation<2, 2>;
template class OnLatticeSimulation<2>;
template class OffLatticeSimulation<2,2>;
template class AbstractCellBasedSimulation<3, 3>;
template class OnLatticeSimulation<3>;
template class OffLatticeSimulation<3,3>;

// Update rules
template class AbstractUpdateRule<2>;
template class AbstractCaUpdateRule<2>;
template class DiffusionCaUpdateRule<2>;
template class AbstractPottsUpdateRule<2>;
template class VolumeConstraintPottsUpdateRule<2>;
template class SurfaceAreaConstraintPottsUpdateRule<2>;
template class DifferentialAdhesionPottsUpdateRule<2>;
template class AdhesionPottsUpdateRule<2>;
template class AbstractUpdateRule<3>;
template class AbstractCaUpdateRule<3>;
template class DiffusionCaUpdateRule<3>;
template class AbstractPottsUpdateRule<3>;
template class VolumeConstraintPottsUpdateRule<3>;
template class SurfaceAreaConstraintPottsUpdateRule<3>;
template class DifferentialAdhesionPottsUpdateRule<3>;
template class AdhesionPottsUpdateRule<3>;

// Simulation modifiers
template class AbstractCellBasedSimulationModifier<2,2>;
template class VtkSceneModifier<2>;
template class AbstractTargetAreaModifier<2>;
template class SimpleTargetAreaModifier<2>;
template class AbstractCellBasedSimulationModifier<3,3>;
template class VtkSceneModifier<3>;
template class AbstractTargetAreaModifier<3>;
template class SimpleTargetAreaModifier<3>;

// Forces
template class AbstractForce<2, 2>;
template class AbstractTwoBodyInteractionForce<2, 2>;
template class GeneralisedLinearSpringForce<2, 2>;
template class NagaiHondaForce<2>;
template class AbstractForce<3, 3>;
template class AbstractTwoBodyInteractionForce<3, 3>;
template class GeneralisedLinearSpringForce<3, 3>;
template class NagaiHondaForce<3>;

// Boundary Conditions
template class AbstractCellPopulationBoundaryCondition<2, 2>;
template class PlaneBoundaryCondition<2, 2>;
template class AttractingPlaneBoundaryCondition<2, 2>;
template class SphereGeometryBoundaryCondition<2>;
template class AbstractCellPopulationBoundaryCondition<3, 3>;
template class PlaneBoundaryCondition<3, 3>;
template class AttractingPlaneBoundaryCondition<3, 3>;
template class SphereGeometryBoundaryCondition<3>;

// Killers
template class AbstractCellKiller<2>;
template class PlaneBasedCellKiller<2>;
template class ApoptoticCellKiller<2>;
template class RandomCellKiller<2>;
template class AbstractCellKiller<3>;
template class PlaneBasedCellKiller<3>;
template class ApoptoticCellKiller<3>;
template class RandomCellKiller<3>;

// PDE
template class AbstractLinearPde<2, 2>;
template class AbstractLinearEllipticPde<2, 2>;
template class CellwiseSourceEllipticPde<2>;
template class AbstractPdeModifier<2>;
template class AbstractGrowingDomainPdeModifier<2>;
template class EllipticGrowingDomainPdeModifier<2>;
template class AbstractLinearPde<3, 3>;
template class AbstractLinearEllipticPde<3, 3>;
template class CellwiseSourceEllipticPde<3>;
template class AbstractPdeModifier<3>;
template class AbstractGrowingDomainPdeModifier<3>;
template class EllipticGrowingDomainPdeModifier<3>;

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef std::vector<unsigned> VecUnsigned;
typedef std::vector<bool> VecDouble;
typedef std::vector<double> VecBool;
typedef std::set<unsigned> SetUnsigned;
typedef CellsGenerator<NoCellCycleModel, 2> CellsGeneratorNoCellCycleModel_2;
typedef CellsGenerator<NoCellCycleModel, 3> CellsGeneratorNoCellCycleModel_3;
typedef CellsGenerator<UniformCellCycleModel, 2> CellsGeneratorUniformCellCycleModel_2;
typedef CellsGenerator<UniformCellCycleModel, 3> CellsGeneratorUniformCellCycleModel_3;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel, 2> CellsGeneratorSimpleOxygenBasedCellCycleModel_2;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel, 3> CellsGeneratorSimpleOxygenBasedCellCycleModel_3;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel, 2> CellsGeneratorUniformG1GenerationalCellCycleModel_2;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel, 3> CellsGeneratorUniformG1GenerationalCellCycleModel_3;
typedef std::vector<CellPtr> VecCellPtr;
typedef std::set<CellPtr> SetCellPtr;
typedef std::vector<c_vector<double, 2> > VecCVectorDouble_2;
typedef std::vector<c_vector<double, 3> > VecCVectorDouble_3;
typedef c_vector<double, 2> CVectorDouble_2;
typedef c_vector<double, 3> CVectorDouble_3;
typedef std::vector<boost::shared_ptr<AbstractCellProperty> >  VecAbstractCellProperty;
typedef std::vector<boost::shared_ptr<AbstractUpdateRule<2> > >  VecAbstractUpdateRule2;
typedef std::vector<boost::shared_ptr<AbstractUpdateRule<3> > >  VecAbstractUpdateRule3;
typedef boost::shared_ptr<AbstractCellProperty> AbstractCellPropertySharedPtr;
typedef boost::shared_ptr<CellData> CellDataSharedPtr;
typedef boost::shared_ptr<AbstractUpdateRule<2> > AbstractUpdateRule2SharedPtr;
typedef boost::shared_ptr<AbstractUpdateRule<3> > AbstractUpdateRule3SharedPtr;
typedef boost::shared_ptr<Cell> CellPtr;
typedef std::map<boost::shared_ptr<Cell>, unsigned> MapCellUnsigned;
typedef std::map<Node<2>*, c_vector<double, 2> > MapNodePtr2CVectorDouble_2;
typedef std::map<Node<3>*, c_vector<double, 3> > MapNodePtr2CVectorDouble_3;
typedef std::pair<Node<3>*, Node<3>*>  PairNodePtr3;
typedef std::pair<Node<2>*, Node<2>*>  PairNodePtr2;
typedef std::vector<std::pair<Node<3>*, Node<3>*> > VecPairNodePtr3;
typedef std::vector<std::pair<Node<2>*, Node<2>*> > VecPairNodePtr2;
}
}

inline int Instantiation()
{
    return sizeof(CellsGenerator<UniformCellCycleModel, 2>) +
            sizeof(CellsGenerator<UniformCellCycleModel, 3>) +
            sizeof(CellsGenerator<NoCellCycleModel, 2>) +
            sizeof(CellsGenerator<NoCellCycleModel, 3>) +
            sizeof(CellsGenerator<SimpleOxygenBasedCellCycleModel, 2>) +
            sizeof(CellsGenerator<SimpleOxygenBasedCellCycleModel, 3>) +
            sizeof(CellsGenerator<UniformG1GenerationalCellCycleModel, 2>) +
            sizeof(CellsGenerator<UniformG1GenerationalCellCycleModel, 3>) +
            sizeof(Mat) + sizeof(Vec);
}

inline Mat GetPetscMatForWrapper()
{
    Mat A;
    PetscTools::SetupMat(A, 3, 3, 3);
    return A;
}

inline Vec GetPetscVecForWrapper()
{
    Vec A = PetscTools::CreateAndSetVec(1, 1.0);
    return A;
}

#endif //PYCHASTECELLBASEDHEADERS_HPP_
