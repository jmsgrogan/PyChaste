
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
## In this tutorial we show how Chaste can be used to create, run and visualize Potts-based simulations. 
## Full details of the mathematical model can be found in Graner, F. and Glazier, J. A. (1992). 
## Simulation of biological cell sorting using a two-dimensional extended Potts model. Phys. Rev. Lett., 69(13):2015–2016.
##
## ## The Test

import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningPottsBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
    ## ## Test 1 - A basic node-based simulation
    ## In the first test, we run a simple Potts-based simulation, in which we create a monolayer of cells, using a Potts mesh. 
    ## Each cell is assigned a stochastic cell-cycle model.
    
    def test_monolayer(self):
        
        ## First, we generate a Potts mesh. To create a PottsMesh, we can use the PottsMeshGenerator. 
        ## This generates a regular square-shaped mesh, in which all elements are the same size. 
        ## Here the first three arguments specify the domain width; the number of elements across; and the width of elements. 
        ## The second set of three arguments specify the domain height; the number of elements up; and the height of individual elements. 
        ## We have chosen a 2 by 2 block of elements, each consisting of 4 by 4 ( = 16) lattice sites.
        
        generator = chaste.mesh.PottsMeshGenerator2(50, 2, 4, 50, 2, 4)
        mesh = generator.GetMesh()
          
        ## Having created a mesh, we now create a vector of CellPtrs. To do this, we the CellsGenerator helper class, 
        ## which is templated over the type of cell model required and the dimension. 
        ## We create an empty vector of cells and pass this into the method along with the mesh. 
        ## The second argument represents the size of that the vector cells should become - one cell for each element. 
        ## Third argument makes all cells proliferate.
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), transit_type)
          
        ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 
        ## In general, this class associates a collection of cells with a mesh. For this test, because we have a PottsMesh, 
        ## we use a particular type of cell population called a PottsBasedCellPopulation.
        
        cell_population = chaste.cell_based.PottsBasedCellPopulation2(mesh, cells)
        
        ## We can set the "Temperature" to be used in the Potts Simulation using the optional command below. The default value is 0.1.
        
        cell_population.SetTemperature(0.1)
        
        ## By default the Potts simulation will make 1 sweep over the whole domain per timestep. 
        ## To use a different number of sweeps per timestep use the command.

        cell_population.SetNumSweepsPerTimestep(1)

        ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory and end time

        simulator = chaste.cell_based.OnLatticeSimulation2(cell_population)
        simulator.SetOutputDirectory("Python/TestPottsBasedCellPopulation")
        simulator.SetEndTime(50.0)
        
        ## The default timestep is 0.1, but can be changed using the below command. The timestep is used in conjunction with the "Temperature" 
        ## and number of sweeps per timestep to specify the relationship between cell movement and proliferation. 
        ## We also set the simulation to only output every 10 steps i.e. once per hour.
        
        simulator.SetDt(0.1)
        simulator.SetSamplingTimestepMultiple(10)

        ## We now pass a force law to the simulation.
        
        force = chaste.cell_based.GeneralisedLinearSpringForce2_2()
        simulator.AddForce(force)

        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        
        ## The next two lines are for test purposes only and are not part of this tutorial. 
        ## If different simulation input parameters are being explored the lines should be removed.
        
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)
        
        ## To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim.
        ## Then do: `java Visualize2dCentreCells /tmp/$USER/testoutput/NodeBasedMonolayer/results_from_time_0`. 
        ## We need to select the 'Cells as circles' option to be able to visualize the cells, as opposed to just the centres. 
        ## We may have to do: `javac Visualize2dCentreCells.java` beforehand to create the java executable.
        ## Alternatively to view in Paraview Load the file `/tmp/$USER/testoutput/NodeBasedMonolayer/results_from_time_0/results.pvd`,
        ## and add glyphs to represent cells. An option is to use 3D spherical glyphs and then make a planar cut.

if __name__ == '__main__':
    unittest.main(verbosity=2)
    
#endif END_WIKI