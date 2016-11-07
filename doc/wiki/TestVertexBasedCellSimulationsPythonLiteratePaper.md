This tutorial is automatically generated from the file test/python/cell_based/tutorials/TestVertexBasedCellSimulationsPythonLiteratePaper.py.
Note that the code is given in full at the bottom of the page.



# Introduction
In this tutorial we show how Chaste can be used to create, run and visualize vertex-based simulations.
Full details of the mechanical model proposed by T. Nagai and H. Honda ("A dynamic cell model for the formation of epithelial tissues",
Philosophical Magazine Part B 81:699-719).

## The Test

```python
import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningVertexBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
```
## Test 1 - A basic vertex-based simulation
In the first test, we run a simple vertex-based simulation, in which we create a monolayer of cells,
using a mutable vertex mesh. Each cell is assigned a stochastic cell-cycle model.

```python
    def xtest_monolayer(self):

```
First, we generate a vertex mesh. To create a MutableVertexMesh, we can use the HoneycombVertexMeshGenerator.
This generates a honeycomb-shaped mesh, in which all nodes are equidistant. Here the first and second arguments
define the size of the mesh - we have chosen a mesh that is 2 elements (i.e. cells) wide, and 2 elements high.

```python
        generator = chaste.mesh.HoneycombVertexMeshGenerator(2, 2)
        mesh = generator.GetMesh()

```
Having created a mesh, we now create a std::vector of CellPtrs. To do this, we use the CellsGenerator helper class,
which is templated over the type of cell model required
and the dimension. We create an empty vector of cells and pass this into the method along with the mesh.
The second argument represents the size of that the vector cells should become - one cell for each element,
the third argument specifies the proliferative type of the cell.

```python
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformG1GenerationalCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), transit_type)

```
Now we have a mesh and a set of cells to go with it, we can create a CellPopulation.
In general, this class associates a collection of cells with a mesh. For this test, because we have a MutableVertexMesh,
we use a particular type of cell population called a VertexBasedCellPopulation.

```python
        cell_population = chaste.cell_based.VertexBasedCellPopulation2(mesh, cells)

```
We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

```python
        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestVertexBasedCellPopulation")
        simulator.SetEndTime(1.0)

```
For longer simulations, we may not want to output the results every time step.
In this case we can use the following method, to print results every 50 time steps instead.
As the default time step used by the simulator (for vertex based simulations), is 0.02 hours, this method
will cause the simulator to print results every 6 minutes (i.e. 0.1 hours).

```python
        simulator.SetSamplingTimestepMultiple(50)

```
We must now create one or more force laws, which determine the mechanics of the vertices of each cell in a cell population.
For this test, we use one force law, based on the Nagai-Honda mechanics, and pass it to the OffLatticeSimulation.
For a list of possible forces see subclasses of AbstractForce.
Note that some of these forces are not compatible with vertex-based simulations see the specific class documentation for details,
if you try to use an incompatible class then you will receive a warning.

```python
        force = chaste.cell_based.NagaiHondaForce2()
        simulator.AddForce(force)

```
A NagaiHondaForce assumes that each cell has a target area. The target areas of cells are used to determine
pressure forces on each vertex and eventually determine the size of each cell in the simulation.
In order to assign target areas to cells and update them in each time step we add a SimpleTargetAreaModifier
to the simulation, which inherits from AbstractTargetAreaModifier.

```python
        growth_modifier = chaste.cell_based.SimpleTargetAreaModifier2()
        simulator.AddSimulationModifier(growth_modifier)

```
To run the simulation, we call `Solve()`.

```python
        simulator.Solve();

```
The next two lines are for test purposes only and are not part of this tutorial.
If different simulation input parameters are being explored the lines should be removed.

```python
        self.assertEqual(cell_population.GetNumRealCells(), 4)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 1.0, 6)

```
To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim.
Then do: java Visualize2dVertexCells /tmp/$USER/testoutput/VertexBasedMonolayer/results_from_time_0.
We may have to do: javac Visualize2dVertexCells.java beforehand to create the java executable.

## Test 2 - introducing periodicity, boundaries and cell killers
In the second test, we run a simple vertex-based simulation, in which we create a monolayer of cells in a periodic geometry,
using a cylindrical vertex mesh. We also include a fixed boundary which cells can't pass through and a cell killer which removes
cells once they leave a region. As before each cell is assigned a stochastic cell-cycle model.

```python
    def test_periodoc_monolayer(self):

```
First, we generate a periodic vertex mesh. To create a Cylindrical2dVertexMesh, we can use the CylindricalHoneycombVertexMeshGenerator.
This generates a honeycomb-shaped mesh, in which all nodes are equidistant and the right hand side is associated with the left hand side.
Here the first and second arguments define the size of the mesh - we have chosen a mesh that is
4 elements (i.e. cells) wide, and 4 elements high.

```python
        generator = chaste.mesh.CylindricalHoneycombVertexMeshGenerator(4, 4)
        mesh = generator.GetCylindricalMesh()

```
Having created a mesh, we now create a VecCellPtrs. This is exactly the same as the above test.

```python
        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformG1GenerationalCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), transit_type)

```
Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. This is also the same as in the above test.

```python
        cell_population = chaste.cell_based.VertexBasedCellPopulation2(mesh, cells)

```
We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

```python
        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestPeriodicVertexBasedCellPopulation")
        simulator.SetEndTime(1.0)
        simulator.SetSamplingTimestepMultiple(50)

```
We now make a pointer to an appropriate force and pass it to the OffLatticeSimulation.

```python
        force = chaste.cell_based.NagaiHondaForce2()
        simulator.AddForce(force)

```
We also make a pointer to the target area modifier and add it to the simulator.

```python
        growth_modifier = chaste.cell_based.SimpleTargetAreaModifier2()
        simulator.AddSimulationModifier(growth_modifier)

```
We now create one or more CellPopulationBoundaryConditions, which determine any conditions which each cell in a cell population must satisfy.
For this test, we use a PlaneBoundaryCondition, and pass it to the OffLatticeSimulation. For a list of possible boundary condition
see subclasses of AbstractCellPopulationBoundaryCondition.
Note that some of these boundary conditions are not compatible with vertex-based simulations see the specific class documentation
for details, if you try to use an incompatible class then you will receive a warning.
The first step is to define a point on the plane boundary and a normal to the plane.
point = (0.0, 0.0)
```python
        normal = (0.0, -1.0)

```
We can now make a PlaneBoundaryCondition (passing the point and normal to the plane) and pass it to the OffLatticeSimulation.

```python
        bc = chaste.cell_based.PlaneBoundaryCondition2_2(cell_population, point, normal)
        simulator.AddCellPopulationBoundaryCondition(bc)

```
We now create one or more CellKillers, which determine how cells are removed from the simulation.
For this test, we use a PlaneBasedCellKiller, and pass it to the OffLatticeSimulation.
For a list of possible cell killers see subclasses of AbstractCellKiller.
The first step is to define a point on the plane boundary and a normal to the plane.

```python
        point = (0.0, 3.0)
        normal = (0.0, 1.0)

```
Finally we now make a PlaneBasedCellKiller (passing the point and normal to the plane) and pass it to the OffLatticeSimulation.

```python
        killer = chaste.cell_based.PlaneBasedCellKiller2(cell_population, point, normal)
        simulator.AddCellKiller(killer)

```
To run the simulation, we call `Solve()`.

```python
        simulator.Solve();

```
The next two lines are for test purposes only and are not part of this tutorial.
If different simulation input parameters are being explored the lines should be removed.

```python
        self.assertEqual(cell_population.GetNumRealCells(), 12)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 1.0, 6)

```
To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim.
Then do: java Visualize2dVertexCells /tmp/$USER/testoutput/VertexBasedMonolayer/results_from_time_0.
We may have to do: javac Visualize2dVertexCells.java beforehand to create the java executable.
You should see that the edges of the mesh are identical on both sides; cells no longer pass through the line y=0; and cells are removed at y=3.

```python
if __name__ == '__main__':
    unittest.main(verbosity=2)

```


# Code 
The full code is given below


## File name `TestVertexBasedCellSimulationsPythonLiteratePaper.py` 

```python
import unittest
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningVertexBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
    def xtest_monolayer(self):

        generator = chaste.mesh.HoneycombVertexMeshGenerator(2, 2)
        mesh = generator.GetMesh()

        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformG1GenerationalCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), transit_type)

        cell_population = chaste.cell_based.VertexBasedCellPopulation2(mesh, cells)

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestVertexBasedCellPopulation")
        simulator.SetEndTime(1.0)

        simulator.SetSamplingTimestepMultiple(50)

        force = chaste.cell_based.NagaiHondaForce2()
        simulator.AddForce(force)

        growth_modifier = chaste.cell_based.SimpleTargetAreaModifier2()
        simulator.AddSimulationModifier(growth_modifier)

        simulator.Solve();

        self.assertEqual(cell_population.GetNumRealCells(), 4)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 1.0, 6)

    def test_periodoc_monolayer(self):

        generator = chaste.mesh.CylindricalHoneycombVertexMeshGenerator(4, 4)
        mesh = generator.GetCylindricalMesh()

        cells = chaste.cell_based.VecCellPtr()
        transit_type = chaste.cell_based.TransitCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformG1GenerationalCellCycleModel_2()
        cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), transit_type)

        cell_population = chaste.cell_based.VertexBasedCellPopulation2(mesh, cells)

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("Python/TestPeriodicVertexBasedCellPopulation")
        simulator.SetEndTime(1.0)
        simulator.SetSamplingTimestepMultiple(50)

        force = chaste.cell_based.NagaiHondaForce2()
        simulator.AddForce(force)

        growth_modifier = chaste.cell_based.SimpleTargetAreaModifier2()
        simulator.AddSimulationModifier(growth_modifier)

        normal = (0.0, -1.0)

        bc = chaste.cell_based.PlaneBoundaryCondition2_2(cell_population, point, normal)
        simulator.AddCellPopulationBoundaryCondition(bc)

        point = (0.0, 3.0)
        normal = (0.0, 1.0)

        killer = chaste.cell_based.PlaneBasedCellKiller2(cell_population, point, normal)
        simulator.AddCellKiller(killer)

        simulator.Solve();

        self.assertEqual(cell_population.GetNumRealCells(), 12)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 1.0, 6)

if __name__ == '__main__':
    unittest.main(verbosity=2)

```

