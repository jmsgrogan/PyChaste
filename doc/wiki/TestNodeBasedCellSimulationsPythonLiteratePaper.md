This tutorial is automatically generated from the file test/python/cell_based/tutorials/TestNodeBasedCellSimulationsPythonLiteratePaper.py.
Note that the code is given in full at the bottom of the page.



# Introduction
In this tutorial we show how Chaste can be used to create, run and visualize node-based simulations. Full details of the mechanical model can be found in Pathamathan et
al "A computational study of discrete mechanical tissue models", Physical Biology. Vol. 6. No. 3. 2009.. DOI (10.1088/1478-3975/6/3/036001).

## The Test

```python
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningNodeBasedSimulationsTutorial(AbstractCellBasedTestSuite):
```
## Test 1 - A basic node-based simulation
In the first test, we run a simple node-based simulation, in which we create a monolayer of cells,
using a nodes only mesh. Each cell is assigned a uniform cell-cycle model.

```python
    def test_monolayer(self):

```
The first thing we do is generate a nodes only mesh. To do this we first create a `MutableMesh` to use as a generating mesh.
To do this we can use the `HoneycombMeshGenerator`. This generates a honeycomb-shaped mesh, in which all nodes are equidistant.
Here the first and second arguments define the size of the mesh - we have chosen a mesh that is 2 nodes (i.e. cells) wide, and 2 nodes high.

```python
        generator = chaste.mesh.HoneycombMeshGenerator(2, 2)
        generating_mesh = generator.GetMesh()

```
Once we have a MutableMesh we can generate a NodesOnlyMesh from it using the following commands.
Note you can also generate the NodesOnlyMesh from a collection of nodes, see ​`NodesOnlyMesh` for details.

```python
        mesh = chaste.mesh.NodesOnlyMesh2()

```
To run node-based simulations you need to define a cut off length (second argument in `ConstructNodesWithoutMesh`),
which defines the connectivity of the nodes by defining a radius of interaction.

```python
        mesh.ConstructNodesWithoutMesh(generating_mesh, 1.5)

```
Having created a mesh, we now create a (wrapped) vector of CellPtrs. To do this, we use the `CellsGenerator` helper class,
which is specialized for the type of cell model required (here `UniformCellCycleModel`) and the dimension.
We create an empty vector of cells and pass this into the method along with the mesh.
The second argument represents the size of that the vector cells should become - one cell for each node,
the third argument specifies the proliferative type of the cell.

```python
        cells = chaste.cell_based.VecCellPtr()
        default_type = chaste.cell_based.DefaultCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRnadom(cells, mesh.GetNumNodes(), default_type)

```
Now we have a mesh and a set of cells to go with it, we can create a `CellPopulation`.
In general, this class associates a collection of cells with a mesh. For this test,
because we have a `NodesOnlyMesh`, we use a particular type of cell population called a `NodeBasedCellPopulation`.

```python
        cell_population = chaste.cell_based.NodeBasedCellPopulation2(nodes_only_mesh, cells)

```
We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory, output multiple and end time

```python
        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("PythonTestNodeBasedCellPopulation")
        simulator.SetSamplingTimestepMultiple(12)
        simulator.SetEndTime(10.0)

```
We now pass a force law to the simulation.

```python
        force = chaste.cell_based.GeneralisedLinearSpringForce()
        simulator.AddForce(force)

```
To run the simulation, we call `Solve()`.

```python
        simulator.Solve();

```
The next two lines are for test purposes only and are not part of this tutorial.
If different simulation input parameters are being explored the lines should be removed.

```python
        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)

```
To visualize the results, open a new terminal, cd to the Chaste directory, then cd to anim.
Then do: `java Visualize2dCentreCells /tmp/$USER/testoutput/NodeBasedMonolayer/results_from_time_0`.
We need to select the 'Cells as circles' option to be able to visualize the cells, as opposed to just the centres.
We may have to do: `javac Visualize2dCentreCells.java` beforehand to create the java executable.
Alternatively to view in Paraview Load the file `/tmp/$USER/testoutput/NodeBasedMonolayer/results_from_time_0/results.pvd`,
and add glyphs to represent cells. An option is to use 3D spherical glyphs and then make a planar cut.

```python
if __name__ == '__main__':
    unittest.main()

```


# Code 
The full code is given below


## File name `TestNodeBasedCellSimulationsPythonLiteratePaper.py` 

```python
import chaste.core
chaste.init()
import chaste.cell_based
import chaste.mesh
import chaste.visualization

class TestRunningNodeBasedSimulationsTutorial(AbstractCellBasedTestSuite):
    def test_monolayer(self):

        generator = chaste.mesh.HoneycombMeshGenerator(2, 2)
        generating_mesh = generator.GetMesh()

        mesh = chaste.mesh.NodesOnlyMesh2()

        mesh.ConstructNodesWithoutMesh(generating_mesh, 1.5)

        cells = chaste.cell_based.VecCellPtr()
        default_type = chaste.cell_based.DefaultCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasicRnadom(cells, mesh.GetNumNodes(), default_type)

        cell_population = chaste.cell_based.NodeBasedCellPopulation2(nodes_only_mesh, cells)

        simulator = chaste.cell_based.OffLatticeSimulation2_2(cell_population)
        simulator.SetOutputDirectory("PythonTestNodeBasedCellPopulation")
        simulator.SetSamplingTimestepMultiple(12)
        simulator.SetEndTime(10.0)

        force = chaste.cell_based.GeneralisedLinearSpringForce()
        simulator.AddForce(force)

        simulator.Solve();

        self.assertEqual(cell_population.GetNumRealCells(), 8)
        self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 10.0, 6)

if __name__ == '__main__':
    unittest.main()

```
        ## Once we have a MutableMesh we can generate a NodesOnlyMesh from it using the following commands.
        ## Note you can also generate the NodesOnlyMesh from a collection of nodes, see ​`NodesOnlyMesh` for details


