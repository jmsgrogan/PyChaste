
"""Copyright (c) 2005-2016, University of Oxford.
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
"""
#ifndef
#define TRIGGER_WIKI

## # Introduction
## In this tutorial we show how Chaste can be used to simulate a growing cell monolayer culture or multicellular tumour spheroid. 
## Like the crypt simulations, tumour spheroid simulations include cell-cycle models and force laws to determine how cells divide and move. 
## In tumour spheroid simulations, however, these are also coupled to a system of partial differential equations (PDEs) that
## determine the concentration of specified nutrients (e.g. oxygen) throughout the cell population. Also, unlike in a crypt simulation 
## (for example), the cell population may grow substantially as the simulation progresses.
## In summary, the main difference between this tutorial and the other cell-based simulation tutorials is that a PDE is defined, 
## which is used in the simulation.
##
## ## The Test

import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.pde
import chaste.visualization

class TestRunningTumourSpheroidSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
     
    def test_spheroid(self):
        
        ## First we want to create a non-periodic 'honeycomb' mesh. We use the honeycomb mesh generator, as before, 
        ## saying 10 cells wide and 10 cells high. Note that the thickness of the ghost nodes layer is 0, i.e. 
        ## there are no ghost nodes, and the false indicates that the returned mesh is not cylindrical. In contrast to the 
        ## crypt simulation tutorial, here we call GetMesh() on the HoneycombMeshGenerator object to return the mesh, which is of type MutableMesh.
        
        generator = chaste.mesh.HoneycombMeshGenerator(10, 10, 0)
        mesh = generator.GetMesh()
          
        ## Now create the cells.
        
        cells = chaste.cell_based.VecCellPtr()
                
        ## This line defines a mutation state to be used for all cells, of type WildTypeCellMutationState (i.e. 'healthy')
        
        state = chaste.cell_based.WildTypeCellMutationState()
        stem_type = chaste.cell_based.StemCellProliferativeType()
        
        ## Use a generator to set up the initial cells
                
        cell_generator = chaste.cell_based.CellsGeneratorSimpleOxygenBasedCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumNodes(), stem_type)
        
        for eachCell in cells:
            model = eachCell.GetCellCycleModel()
    
            ## We also alter the default cell-cycle times.

            model.SetStemCellG1Duration(8.0)
            model.SetTransitCellG1Duration(8.0)
             
            ## We now define a random birth time, chosen from [-T,0], where T = t1 + t2, where t1 is a parameter representing the 
            ## G1 duration of a 'stem' cell, and t2 is the basic S+G2+M phases duration...
            
            birth_time = -chaste.core.RandomNumberGenerator.Instance().ranf() * (model.GetStemCellG1Duration() + 
                                                                                 model.GetSG2MDuration())
            eachCell.SetBirthTime(birth_time)

        
        ## Now that we have defined the cells, we can define the CellPopulation. We use a MeshBasedCellPopulation since although 
        ## the cell population is mesh-based, it does not include any ghost nodes. The constructor takes in the mesh and the cells vector.
        
        cell_population = chaste.cell_based.MeshBasedCellPopulation2_2(mesh, cells)
        
        ## Next we instantiate an instance of the PDE class which we defined above. This will be passed into the OffLatticeSimulationWithPdes object. 
        ## The CellwiseSourcePde is a PDE class which inherits from AbstractLinearEllipticPde and represents the PDE u_xx + u_yy = k(x,y) u, where u(x,y)
        ## denotes the oxygen concentration at position (x,y) and the function k(x,y) specifies the rate of consumption by live cells there. 
        ## Here k(x,y) takes the value -0.03 (the coefficient below) if the cell located at (x,y) is a live cell, and zero if the cell has died due 
        ## to oxygen deprivation.
        
        pde = chaste.cell_based.CellwiseSourceEllipticPde2(cell_population, -0.03)
        
        ## We also create a constant-valued boundary condition to associate with the PDE.
        ## This boundary condition object takes in a single argument in its constructor,
        ## the value at the boundary. We also introduce a boolean to specify whether this value is the flux at the boundary
        ## (a Neumann boundary condition) or the value of the state variable at the boundary
        ## (a Dirichlet boundary condition) below
        
        bc = chaste.pde.ConstBoundaryCondition2(1.0)
        is_neumann_bc = False
        
        ## To pass the PDE to our simulator, it must first be encapsulated in a
        ## cell-based PDE modifier object, together with the boundary condition for
        ## the PDE. The latter is specified by the second and third arguments of the
        ## constructor below: the second argument defines the value
        ## of the boundary condition and the third argument defines whether it is of Neumann type
        ## (true) or Dirichlet type (false). Thus, in our case, we are a specifying a constant-value
        ## boundary condition. Note that we currently cannot impose more than one boundary
        ## condition for each PDE (so that e.g. we cannot impose a zero-flux boundary condition
        ## on some part of the boundary and a fixed-value boundary condition on the rest), although
        ## the boundary condition itself can be made spatially varying or time-dependent.
        ## The PDE is tagged to show that the quantity to be solved for (the quantity of interest in
        ## the cells' data is "oxygen".
        ## The `CellData` class, is used to stores the value of the current nutrient concentration for each cell.

        pde_modifier = chaste.cell_based.EllipticGrowingDomainPdeModifier2(pde ,bc, is_neumann_bc)
        pde_modifier.SetDependentVariableName("oxygen")
        
        ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestTumourSpheroid")
        simulator.SetEndTime(1.0)
        simulator.AddSimulationModifier(pde_modifier)

        ## We now pass a force law to the simulation.
         
        force = chaste.cell_based.GeneralisedLinearSpringForce2_2()
        force.SetCutOffLength(3)
        simulator.AddForce(force)

        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        

if __name__ == '__main__':
    unittest.main(verbosity=2)
    
#endif END_WIKI