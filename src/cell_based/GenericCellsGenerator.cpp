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

#include "GenericCellsGenerator.hpp"

template<unsigned DIM>
GenericCellsGenerator<DIM>::GenericCellsGenerator() :
    mNumCells(0),
    mpMutationState(CellPropertyRegistry::Instance()->Get<WildTypeCellMutationState>()),
    mpProliferativeType(CellPropertyRegistry::Instance()->Get<StemCellProliferativeType>()),
    mpCellCycleModel(boost::shared_ptr<UniformCellCycleModel>(new UniformCellCycleModel))
{
    mpCellCycleModel->SetDimension(DIM);
}

template<unsigned DIM>
GenericCellsGenerator<DIM>::~GenericCellsGenerator()
{

}

template<unsigned DIM>
void GenericCellsGenerator<DIM>::SetCellMutationState(boost::shared_ptr<AbstractCellProperty> pMutationState)
{
    mpMutationState = pMutationState;
}

template<unsigned DIM>
void GenericCellsGenerator<DIM>::SetCellProliferativeType(boost::shared_ptr<AbstractCellProperty> pProliferativeType)
{
    mpProliferativeType = pProliferativeType;
}

template<unsigned DIM>
void GenericCellsGenerator<DIM>::SetCellCycleModel(boost::shared_ptr<AbstractCellCycleModel> pCellCycleModel)
{
    mpCellCycleModel = pCellCycleModel;
}

template<unsigned DIM>
void GenericCellsGenerator<DIM>::SetNumCells(unsigned numCells)
{
    mNumCells = numCells;
}

template<unsigned DIM>
std::vector<CellPtr> GenericCellsGenerator<DIM>::GenerateBasic()
{
    std::vector<CellPtr> cells;
    cells.reserve(mNumCells);

    // Create cells
    for (unsigned i=0; i<mNumCells; i++)
    {
        CellPtr p_cell(new Cell(mpMutationState, mpCellCycleModel.get()));
        p_cell->SetCellProliferativeType(mpProliferativeType);
        double birth_time = 0.0 - i;
        p_cell->SetBirthTime(birth_time);
        cells.push_back(p_cell);
    }
    return cells;
}

// Explicit instantiation
template class GenericCellsGenerator<2>;
template class GenericCellsGenerator<3>;
