/*

Copyright (c) 2005-2016, University of Oxford.
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

// Base
#include "Identifiable.hpp"
#include "Cell.hpp"
#include "CellsGenerator.hpp"
#include "CellId.hpp"
#include "CellPropertyRegistry.hpp"
#include "CellData.hpp"

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

// Update rules
#include "AbstractCaUpdateRule.hpp"
#include "AbstractUpdateRule.hpp"
#include "DiffusionCaUpdateRule.hpp"

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
template class AbstractUpdateRule<3>;
template class AbstractCaUpdateRule<3>;
template class DiffusionCaUpdateRule<3>;

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


//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef CellsGenerator<UniformCellCycleModel, 2> CellsGeneratorUniformCellCycleModel_2;
typedef CellsGenerator<UniformCellCycleModel, 3> CellsGeneratorUniformCellCycleModel_3;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel, 2> CellsGeneratorSimpleOxygenBasedCellCycleModel_2;
typedef CellsGenerator<SimpleOxygenBasedCellCycleModel, 3> CellsGeneratorSimpleOxygenBasedCellCycleModel_3;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel, 2> CellsGeneratorUniformG1GenerationalCellCycleModel_2;
typedef CellsGenerator<UniformG1GenerationalCellCycleModel, 3> CellsGeneratorUniformG1GenerationalCellCycleModel_3;
typedef std::vector<CellPtr> VecCellPtr;
}
}

inline int Instantiation()
{
    return sizeof(CellsGenerator<UniformCellCycleModel, 2>) +
            sizeof(CellsGenerator<UniformCellCycleModel, 3>) +
            sizeof(CellsGenerator<SimpleOxygenBasedCellCycleModel, 2>) +
            sizeof(CellsGenerator<SimpleOxygenBasedCellCycleModel, 3>) +
            sizeof(CellsGenerator<UniformG1GenerationalCellCycleModel, 2>) +
            sizeof(CellsGenerator<UniformG1GenerationalCellCycleModel, 3>);
}

//pyplusplus::aliases
