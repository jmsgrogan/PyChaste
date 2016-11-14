
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
## In this tutorial we show how Chaste can be used to create, run and visualize mesh-based simulations. 
## Full details of the mathematical model can be found in van Leeuwen et al. (2009) [doi:10.1111/j.1365-2184.2009.00627.x].
##
## ## The Test

import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningMeshBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
    
    ## ## Test 1 - a basic mesh-based simulation
    ## In the first test, we run a simple mesh-based simulation, 
    ## in which we create a monolayer of cells, using a mutable mesh. Each cell is assigned a stochastic cell-cycle model.
    
    def test_monolayer(self):
        
        ## Next, we generate a mutable mesh. To create a MutableMesh, we can use the HoneycombMeshGenerator. 
        ## This generates a honeycomb-shaped mesh, in which all nodes are equidistant. Here the first and second arguments define the size of the mesh - 
        ## we have chosen a mesh that is 2 nodes (i.e. cells) wide, and 2 nodes high.
        
        generator = chaste.mesh.HoneycombMeshGenerator(2, 2)
        mesh = generator.GetMesh()
          
        ## Having created a mesh, we now create a VecCellPtrs. To do this, we use the CellsGenerator helper class, 
        ## which is templated over the type of cell cycle model required (here UniformCellCycleModel) and the dimension. 
        ## For a list of possible cell cycle models see subclasses of AbstractCellCycleModel. 
        ## Note that some of these models will require information on the surrounding medium such as Oxygen concentration to work, 
        ## see specific class documentation for details. 
        ## Some of these will be covered in later tutorials (UserTutorials/RunningContactInhibitionSimulations, UserTutorials/RunningDeltaNotchSimulations, 
        ## and UserTutorials/RunningTumourSpheroidSimulations). 
        ## We create an empty vector of cells and pass this into the method along with the mesh. 
        ## The second argument represents the size of that the vector cells should become - one cell for each node, 
        ## the third argument specifies the proliferative type of the cell.
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumNodes(), transit_type)
          
        ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 
        ## In general, this class associates a collection of cells with a mesh. For this test, because we have a MutableMesh, 
        ## we use a particular type of cell population called a MeshBasedCellPopulation.
        
        cell_population = chaste.cell_based.MeshBasedCellPopulation2_2(mesh, cells)
        
        ## To view the results of this and the next test in Paraview it is necessary to explicitly generate the required .vtu files. 
        ## This is detailed in the UserTutorials/VisualizingWithParaview tutorial. Note that the results in Paraview may appear different 
        ## to those in the java based visualizer. This is related to the different methods used to generate voronoi tesselations in each and 
        ## is resolved through the use of 'ghost nodes', as shown in the next test.
        
        cell_population.AddPopulationWriterVoronoiDataWriter()

        ## We then pass in the cell population into an OffLatticeSimulation, and set the output directory and end time.

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestMeshBasedCellPopulation")
        simulator.SetEndTime(10.0)
        
        ## For longer simulations, we may not want to output the results every time step. In this case we can use the following method, 
        ## to print results every 12 time steps instead. As the default time step used by the simulator is 30 seconds, 
        ## this method will cause the simulator to print results every 6 minutes (or 0.1 hours).
        
        simulator.SetSamplingTimestepMultiple(12)

        ## We must now create one or more force laws, which determine the mechanics of the centres of each cell in a cell population. 
        ## For this test, we use one force law, based on the spring based model, and pass it to the OffLatticeSimulation. 
        ## For a list of possible forces see subclasses of AbstractForce. Note that some of these forces are not compatible with mesh-based simulations, 
        ## see the specific class documentation for details. If you try to use an incompatible class then you will receive a warning.
        
        force = chaste.cell_based.GeneralisedLinearSpringForce2_2()
        simulator.AddForce(force)

        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        
        ## The next two lines are for test purposes only and are not part of this tutorial. 
        ## If different simulation input parameters are being explored the lines should be removed.
        
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)
        
        ## To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim. 
        ## Then do: java Visualize2dCentreCells /tmp/$USER/testoutput/MeshBasedMonolayer/results_from_time_0. We may have to do: 
        ## javac Visualize2dCentreCells.java beforehand to create the java executable. For further details on visualization, see ChasteGuides/RunningCellBasedVisualization.
        ## You will notice that half of each cell cell around the edge is missing.
        ## This is because the Voronoi region for nodes on the edge of the mesh can be infinite, therefore we only visualize the part inside the mesh. 
        ## This also means there may be "long" edges in the mesh which can cause the cells to move due long range interactions resulting in an artificially rounded shapeThere are two solutions to this. 
        ## The first is to define a cut off length on the force, which can be done by using the command p_force->SetCutOffLength(1.5); on the GeneralisedLinearSpringForce. 
        ## Here there will be no forces exerted on any "springs" which are longer than 1.5 cell radii.
        ## The second solution is to use 'ghost nodes'. Ghost nodes can be added to mesh-based simulations to remove infinite voronoi regions and long edges. To do this, a set of nodes (known as ghost nodes) 
        ## are added around the original mesh which exert forces on each other but do not exert forces on the nodes of the original mesh (known as real nodes). In addition real nodes exert forces on ghost nodes 
        ## so the ghost nodes remain surrounding the cell population.
        
    ## ## Test 2 -  a basic mesh-based simulation with ghost nodes
    ## In the second test, we run a simple mesh-based simulation with ghost nodes, in which we create a monolayer of cells, using a mutable mesh. 
    ## Each cell is assigned a stochastic cell-cycle model.
    
    def test_monolayer_with_ghost_nodes(self):
        
        ## We start by generating a mutable mesh. To create a MutableMesh, we can use the HoneycombMeshGenerator as before. 
        ## Here the first and second arguments define the size of the mesh - we have chosen a mesh that is 2 nodes (i.e. cells) wide, 
        ## and 2 nodes high. The third argument specifies the number of layers of ghost nodes to make.
        
        generator = chaste.mesh.HoneycombMeshGenerator(2, 2, 2)
        mesh = generator.GetMesh()
        
        ## We only want to create cells to attach to real nodes, so we use the method GetCellLocationIndices to get the 
        ## indices of the real nodes in the mesh. This will be passed in to the cell population later on.
        
        location_indices = generator.GetCellLocationIndices()
          
        ## Having created a mesh, we now create a std::vector of CellPtrs. To do this, we the CellsGenerator helper class again. 
        ## This time the second argument is different and is the number of real nodes in the mesh. 
        ## As before all cells have TransitCellProliferativeType.
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, len(location_indices), transit_type)
          
        ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 
        ## In general, this class associates a collection of cells with a set of elements or a mesh. 
        ## For this test, because we have a MutableMesh, and ghost nodes we use a particular type of cell population called 
        ## a MeshBasedCellPopulationWithGhostNodes. The third argument of the constructor takes a vector of the indices of the real nodes 
        ## and should be the same length as the vector of cell pointers.
        
        cell_population = chaste.cell_based.MeshBasedCellPopulationWithGhostNodes2(mesh, cells, location_indices)
        
        ## Again Paraview output is explicitly requested.
        
        cell_population.AddPopulationWriterVoronoiDataWriter()

        ## We then pass in the cell population into an OffLatticeSimulation, and set the output directory, output multiple and end time.

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestMeshBasedCellPopulationWithGhostNodes")
        simulator.SetEndTime(10.0)
        simulator.SetSamplingTimestepMultiple(12)

        ## Again we create a force law, and pass it to the OffLatticeSimulation. 
        ## This force law ensures that ghost nodes don't exert forces on real nodes but real nodes exert forces on ghost nodes.
        
        force = chaste.cell_based.GeneralisedLinearSpringForce2_2()
        simulator.AddForce(force)

        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        
        ## The next two lines are for test purposes only and are not part of this tutorial. 
        ## If different simulation input parameters are being explored the lines should be removed.
        
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)
        
        ## To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim. 
        ## Then do: java Visualize2dCentreCells /tmp/$USER/testoutput/MeshBasedMonolayerWithGhostNodes/results_from_time_0.

if __name__ == '__main__':
    unittest.main(verbosity=2)
    
#endif END_WIKI