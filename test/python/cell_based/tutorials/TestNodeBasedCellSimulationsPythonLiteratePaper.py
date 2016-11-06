
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
## In this tutorial we show how Chaste can be used to create, run and visualize node-based simulations. Full details of the mechanical model can be found in Pathamathan et 
## al "A computational study of discrete mechanical tissue models", Physical Biology. Vol. 6. No. 3. 2009.. DOI (10.1088/1478-3975/6/3/036001). 
##
## ## The Test

import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningNodeBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
    ## ## Test 1 - A basic node-based simulation
    ## In the first test, we run a simple node-based simulation, in which we create a monolayer of cells, 
    ## using a nodes only mesh. Each cell is assigned a uniform cell-cycle model.
    
    def test_monolayer(self):
        
        ## The first thing we do is generate a nodes only mesh. To do this we first create a `MutableMesh` to use as a generating mesh. 
        ## To do this we can use the `HoneycombMeshGenerator`. This generates a honeycomb-shaped mesh, in which all nodes are equidistant.
        ## Here the first and second arguments define the size of the mesh - we have chosen a mesh that is 2 nodes (i.e. cells) wide, and 2 nodes high.
        
        generator = chaste.mesh.HoneycombMeshGenerator(2, 2)
        generating_mesh = generator.GetMesh()
        
        ## Once we have a MutableMesh we can generate a NodesOnlyMesh from it using the following commands.
        ## Note you can also generate the NodesOnlyMesh from a collection of nodes.
        
        mesh = chaste.mesh.NodesOnlyMesh2()
        
        ## To run node-based simulations you need to define a cut off length (second argument in `ConstructNodesWithoutMesh`), 
        ## which defines the connectivity of the nodes by defining a radius of interaction.
        
        mesh.ConstructNodesWithoutMesh(generating_mesh, 1.5)
          
        ## Having created a mesh, we now create a (wrapped) vector of CellPtrs. To do this, we use the `CellsGenerator` helper class, 
        ## which is specialized for the type of cell model required (here `UniformCellCycleModel`) and the dimension. 
        ## We create an empty vector of cells and pass this into the method along with the mesh. 
        ## The second argument represents the size of that the vector cells should become - one cell for each node, 
        ## the third argument specifies the proliferative type of the cell.
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumNodes(), transit_type)
          
        ## Now we have a mesh and a set of cells to go with it, we can create a `CellPopulation`. 
        ## In general, this class associates a collection of cells with a mesh. For this test, 
        ## because we have a `NodesOnlyMesh`, we use a particular type of cell population called a `NodeBasedCellPopulation`.
        
        cell_population = chaste.cell_based.NodeBasedCellPopulation2(mesh, cells)

        ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestNodeBasedCellPopulation")
        simulator.SetSamplingTimestepMultiple(12)
        simulator.SetEndTime(10.0)

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
        
    ## ## Test 2 - a basic node-based simulation in 3D
    ## In the second test we run a simple node-based simulation in 3D. This is very similar to the 2D test with the dimension changed from 2 to 3 and 
    ## instead of using a mesh generator we generate the nodes directly.
    
    def test_spheroid(self):
        
        ## First, we generate a nodes only mesh. This time we specify the nodes manually by first creating a vector of nodes
        
        nodes = []
        nodes.append(chaste.mesh.Node3(0, False, 0.5, 0.0, 0.0))
        nodes.append(chaste.mesh.Node3(1, False, -0.5, 0.0, 0.0))
        nodes.append(chaste.mesh.Node3(2, False, 0.0, 0.5, 0.0))
        nodes.append(chaste.mesh.Node3(3, False, 0.0, -0.5, 0.0))
        
        ## Finally a NodesOnlyMesh is created and the vector of nodes is passed to the ConstructNodesWithoutMesh method.
        
        mesh = chaste.mesh.NodesOnlyMesh3()
        
        ## To run node-based simulations you need to define a cut off length (second argument in ConstructNodesWithoutMesh), 
        ## which defines the connectivity of the nodes by defining a radius of interaction.
        
        mesh.ConstructNodesWithoutMesh(nodes, 1.5)
          
        ## Having created a mesh, we now create a std::vector of CellPtrs. 
        ## As before, we do this with the CellsGenerator helper class (this time with dimension 3).
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_3()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumNodes(), transit_type)
          
        ## Now we have a mesh and a set of cells to go with it, we can create a `CellPopulation`. 
        ## In general, this class associates a collection of cells with a mesh. For this test, 
        ## because we have a `NodesOnlyMesh`, we use a particular type of cell population called a `NodeBasedCellPopulation`.
        
        cell_population = chaste.cell_based.NodeBasedCellPopulation3(mesh, cells)

        ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

        simulator = chaste.cell_based.OffLatticeSimulation3_3(cell_population)
        simulator.SetOutputDirectory("Python/TestNodeBasedSpheroidCellPopulation")
        simulator.SetSamplingTimestepMultiple(12)
        simulator.SetEndTime(10.0)

        ## We now pass a force law to the simulation.
        
        force = chaste.cell_based.GeneralisedLinearSpringForce3_3()
        simulator.AddForce(force)

        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        
        ## The next two lines are for test purposes only and are not part of this tutorial. 
        ## If different simulation input parameters are being explored the lines should be removed.
        
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)
        
        ## Note that you cannot view the results of a 3D simulation using the Java visualiser but to visualize the results, 
        ## use Paraview. See the UserTutorials/VisualizingWithParaview tutorial for more information.
        
    ## ## Test 3 - a node-based simulation on a restricted geometry
    ## In the second test we run a simple node-based simulation in 3D. This is very similar to the 2D test with the dimension changed from 2 to 3 and 
    ## instead of using a mesh generator we generate the nodes directly.
    
    def test_spheroid_on_sphere(self):
        
        ## In the third test we run a node-based simulation restricted to the surface of a sphere.
        
        nodes = []
        nodes.append(chaste.mesh.Node3(0, False, 0.5, 0.0, 0.0))
        nodes.append(chaste.mesh.Node3(1, False, -0.5, 0.0, 0.0))
        nodes.append(chaste.mesh.Node3(2, False, 0.0, 0.5, 0.0))
        nodes.append(chaste.mesh.Node3(3, False, 0.0, -0.5, 0.0))
        mesh = chaste.mesh.NodesOnlyMesh3()
        
        ## To run node-based simulations you need to define a cut off length (second argument in ConstructNodesWithoutMesh), 
        ## which defines the connectivity of the nodes by defining a radius of interaction.
        
        mesh.ConstructNodesWithoutMesh(nodes, 1.5)
        
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_3()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumNodes(), transit_type)
          
        cell_population = chaste.cell_based.NodeBasedCellPopulation3(mesh, cells)

        simulator = chaste.cell_based.OffLatticeSimulation3_3(cell_population)
        simulator.SetOutputDirectory("Python/TestNodeBasedOnSphereCellPopulation")
        simulator.SetSamplingTimestepMultiple(12)
        simulator.SetEndTime(10.0)

        ## We now pass a force law to the simulation.
        
        force = chaste.cell_based.GeneralisedLinearSpringForce3_3()
        simulator.AddForce(force)
        
        ## This time we create a CellPopulationBoundaryCondition and pass this to the OffLatticeSimulation. 
        ## Here we use a SphereGeometryBoundaryCondition which restricts cells to lie on a sphere (in 3D) or circle (in 2D).
        ## For a list of possible boundary conditions see subclasses of AbstractCellPopulationBoundaryCondition. 
        ## Note that some of these boundary conditions are not compatible with node-based simulations see the specific class documentation 
        ## for details, if you try to use an incompatible class then you will receive a warning.
        ## First we set the centre (0,0,1) and radius of the sphere (1).
        
        centre = (0.0, 0.0, 1.0)
        radius = 1.0
        boundary_condition = chaste.cell_based.SphereGeometryBoundaryCondition3(cell_population, centre, radius)
        simulator.AddCellPopulationBoundaryCondition(boundary_condition)
        
        ## To run the simulation, we call `Solve()`.
    
        simulator.Solve();
        
        ## The next two lines are for test purposes only and are not part of this tutorial. 
        ## If different simulation input parameters are being explored the lines should be removed.
        
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)
        
        ## Note that you cannot view the results of a 3D simulation using the Java visualiser but to visualize the results, 
        ## use Paraview. See the UserTutorials/VisualizingWithParaview tutorial for more information.

if __name__ == '__main__':
    unittest.main(verbosity=2)
    
#endif END_WIKI