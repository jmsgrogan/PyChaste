
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
## This tutorial is an example of cell growth using the most simple type of cell population, a cellular automaton.
##
## ## The Test

import unittest # Python testing framework
import matplotlib.pyplot as plt # Plotting
import numpy as np # Matrix tools
import chaste # The PyChaste module
chaste.init() # Set up MPI
import chaste.cell_based # Contains cell populations
import chaste.mesh # Contains meshes
import chaste.visualization # Visualization tools

class TestRunningCaBasedSimulationsTutorial(chaste.cell_based.AbstractCellBasedTestSuite):
    ## ## Test 1 - Free growing cells
    ## In the first test we will label two sets of cells and allow them to migrate toward one another
    ## by means of a random walk. This example will illustrate several Chaste features, including setting
    ## up a cell population, labelling cells and applying rules for cell migration. It will also 
    ## illustrate several PyChaste features such as visualization and real-time population data collection.
    ## 
    
    def test_merging_subpopulations(self):
        
        ## Chaste is based on the concept of 'Cells' and 'Meshes'. 'Cells' do not store their position in space,
        ## or connectivity, these are managed by a Mesh. The first step in most Chaste simulations is to
        ## set up a mesh, on which we can locate cells. A collection of 'Cells' and a 'Mesh' are a 'Cell Population'
        ## in Chaste terminology. The most simple 'Cell Population' is the `CaBasedCellPopulation` which corresponds
        ## to cells occupying discrete locations on a regular grid. Our first step is to set up the regular grid.
        ## Here we set up a 2D grid with 10 points in x and 10 in y.
        
        num_points_in_x = 100
        num_points_in_y = 10
        generator = chaste.mesh.PottsMeshGenerator2(num_points_in_x, 0, 0, num_points_in_y, 0, 0)
        mesh = generator.GetMesh()
          
        ## Note that we are using a `PottsMeshGenerator2` to set up the grid and we are setting some terms to 0. Chaste
        ## design is based on re-use of components, the `PottsMeshGenerator` can be used to set up other types of
        ## cell population which require these extra terms. Note also the '2' at the end of the class name. This
        ## tells us that we are working in 2D. Most Chaste classes are specialized (templated) for spatial dimension
        ## so we need to make sure we are consistent in the dimensionality of the classes we are using. It is useful to
        ## check the mesh to make sure we have set it up correctly. To do this we will set up a `VtkScene`, add the mesh
        ## to it and make a picture of the result.
        
        scene= chaste.visualization.VtkScene2()
        #scene.SetSaveAsImages(True)
        file_handler = chaste.core.OutputFileHandler("Python/TestRunningCaBasedSimulationsTutorial")
        print file_handler.GetOutputDirectoryFullPath()
        scene.SetOutputFilePath(file_handler.GetOutputDirectoryFullPath() + "/initial_mesh")
        #scene.Start()
        
        ## Note that we have set up something called an `OutputFileHandler`. This object makes sure that there is
        ## an output directory set up in our chosen location. By default the path is relative to one set in an
        ## environment variable CHASTE_TEST_OUTPUT. We have just printed it to console so we can see where it is there.
        ## We should see an image of the grid in this location.
        ##
        ## Next we set up some cells. We create and empty container `VecCellPtr` (which will behave like a Python list)
        ## and will fill it with cells of our chosen type. In Chaste cells can be assinged a number of proliferative types
        ## (Default, Differentiated, Stem, Transit or User Defined). These types will define how cells behave in certain
        ## simulations, for example whether they will proliferate. We just want our cells to migrate in this example, so
        ## we set a DifferentiatedCellProliferativeType. 
        
        cells = chaste.cell_based.VecCellPtr()
        differentiated_type = chaste.cell_based.DifferentiatedCellProliferativeType()
        
        ## We are not interested in cell cycling so we specialize the generator to NoCellCycleModel.
        
        #cell_generator = chaste.cell_based.CellsGeneratorNoCellCycleModel_2()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        
        ## We want two sets of cells, starting on opposite sides of the mesh. We use `location_indices` to map cells onto
        ## locations (or Nodes) on the mesh. For our regular mesh the Node indices increase fastest in x, then y. We will
        ## add three layers of cells to each side of the mesh.
        
        bottom_location_indices = range(3*num_points_in_x)
        num_grid_points = num_points_in_x*num_points_in_y
        top_location_indices = range(num_grid_points-1, num_grid_points - 3*num_points_in_x-1, -1)
        cell_generator.GenerateGivenLocationIndices(cells, bottom_location_indices + top_location_indices, 
                                                    differentiated_type)
        
        ## Next we need to give our cell sub-populations two different labels, so we can see them mixing.
        
        bottom_label = chaste.cell_based.CellLabel(1)
        top_label = chaste.cell_based.CellLabel(2)
        for idx, eachCell in enumerate(cells):
            if idx<3*num_points_in_x:
                eachCell.AddCellProperty(bottom_label)
            else:
                eachCell.AddCellProperty(top_label)                
            
        ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 

        cell_population = chaste.cell_based.CaBasedCellPopulation2(mesh, cells, bottom_location_indices + top_location_indices)
        
        ## We can add the population to our scene to make sure it looks as expected
        
        scene.SetIsInteractive(True)
        scene.SetCellPopulation(cell_population)
        scene.GetCellPopulationActorGenerator().SetShowCellCentres(True)
        
        ## Next, we set up an `OffLatticeSimulation` which will manage the solver. We need to add some custom rules to 
        ## this solver to specify how we want the cells to migrate.

        simulator = chaste.cell_based.OnLatticeSimulation2(cell_population)
        simulator.SetOutputDirectory("Python/TestRunningCaBasedSimulationsTutorial")
        simulator.SetEndTime(5.0)
        simulator.SetDt(0.1)
        simulator.SetSamplingTimestepMultiple(1)

        ## We must now create a rule for cell migration. We will use an existing diffusion type rule.
        
        diffusion_update_rule = chaste.cell_based.DiffusionCaUpdateRule2()
        simulator.AddUpdateRule(diffusion_update_rule)
        
        ## We can watch the cell population change in real time by adding a `VtkSceneModifier`. Such
        ## modifiers are called by the simulator at regular periods during the main time loop and
        ## have access to the cell population. We will use a similar idea in a moment to record cell
        ## positions for real time plotting.
        
        scene_modifier = chaste.cell_based.VtkSceneModifier2()
        scene_modifier.SetVtkScene(scene)
        scene_modifier.SetUpdateFrequency(1)
        simulator.AddSimulationModifier(scene_modifier)

        ## Chaste and PyChaste use object oriented programming. This may require some background reading,
        ## but allows for great flexibility in terms of quickly modifying existing functionality. In 
        ## order to pull the data we want out of the simulation as it runs we will create our own 
        ## simulation modifier class and use it for real time plotting. This Python class over-rides
        ## one of the built-in classes, giving us access to the quantities we want during the simulation.
        ## Usually we would define such a class in a different module and import it, it is placed
        ## here for the purposed of the tutorial.
        
        class PlottingModifier(chaste.cell_based.AbstractCellBasedSimulationModifier2_2):
    
            def __init__(self):
                super(PlottingModifier, self).__init__()
                
                # Set up a figure for plotting
                self.fig = plt.figure()
                self.fig.ax = self.fig.add_subplot(111) 
                self.fig.ax.set_xlabel("y - Position (Cell Lengths)")
                self.fig.ax.set_ylabel("Number Of Cells")
                self.plot_frequency = 10 # only plot every 10 steps
                
            def UpdateAtEndOfTimeStep(self, cell_population):
                
                # Make some bins
                y_locations = np.linspace(0, num_points_in_y, num_points_in_y)
                num_cells = []
                for idx in range(num_points_in_y):
                    counter = 0
                    for jdx in range(num_points_in_x):
                        if cell_population.IsCellAttachedToLocationIndex(jdx + idx*num_points_in_x):
                            counter +=1
                    num_cells.append(counter)   
                    
                self.fig.ax.plot(y_locations, num_cells, color='black')
                self.fig.canvas.draw()
                
            def SetupSolve(self, cell_population, outputdirectory):
                 
                cell_population.Update()
                
            def OutputSimulationModifierParameters(self, rParamsFile):
                 
                pass

        plotting_modifier = PlottingModifier()
        simulator.AddSimulationModifier(plotting_modifier)
        
        ## To run the simulation, we call `Solve()` and optionally set up interactive plotting.
        
        scene.Start()
        plt.ion()
        plt.show()
        simulator.Solve();
        scene.StartInteractiveEventHandler()

#         
#         ## The next two lines are for test purposes only and are not part of this tutorial. 
#         ## If different simulation input parameters are being explored the lines should be removed.
#         
#         self.assertEqual(cell_population.GetNumRealCells(), 64)
#         self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 50.0, 6)
# 
#     ## ## Test 2 - Cell sorting
#     ## The next test generates a collection of cells, there are two types of cells, labelled ones and non labelled ones, 
#     ## there is differential adhesion between the cell types. For the parameters specified, the cells sort into separate types.
#     
#     def test_potts_monolayer_cell_sorting(self):
#         
#         ## First, we generate a Potts mesh. To create a PottsMesh, we can use the PottsMeshGenerator. 
#         ## This generates a regular square-shaped mesh, in which all elements are the same size. 
#         ## We have chosen an 8 by 8 block of elements each consisting of 4 by 4 ( = 16) lattice sites.
#         
#         generator = chaste.mesh.PottsMeshGenerator2(50, 8, 4, 50, 8, 4)
#         mesh = generator.GetMesh()
#           
#         ## Having created a mesh, we now create a VecCellPtrs. To do this, we the CellsGenerator helper class, 
#         ## as before but this time the third argument is set to make all cells non-proliferative.
#         
#         cells = chaste.cell_based.VecCellPtr()
#         differentiated_type = chaste.cell_based.DifferentiatedCellProliferativeType()
#         cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
#         cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), differentiated_type)
#         
#         ## Before we make a CellPopulation we make a cell label and then assign this label to some randomly chosen cells.
#         
#         label = chaste.cell_based.CellLabel()
#         for eachCell in cells:
#             if(chaste.core.RandomNumberGenerator.Instance().ranf()<0.5):
#                 eachCell.AddCellProperty(label)
#           
#         ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 
#         
#         cell_population = chaste.cell_based.PottsBasedCellPopulation2(mesh, cells)
#         
#         ## In order to visualize labelled cells we need to use the following command.
#         
#         cell_population.AddCellWriterCellLabelWriter();
# 
#         ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory and end time
# 
#         simulator = chaste.cell_based.OnLatticeSimulation2(cell_population)
#         simulator.SetOutputDirectory("Python/TestPottsBasedCellSorting")
#         simulator.SetEndTime(20.0)
#         simulator.SetSamplingTimestepMultiple(10)
# 
#         ## We must now create one or more update rules, which determine the Hamiltonian in the Potts simulation. 
#         ## For this test, we use two update rules based upon a volume constraint (VolumeConstraintPottsUpdateRule) and 
#         ## differential adhesion between cells (DifferentialAdhesionPottsUpdateRule), set appropriate parameters, and 
#         ## pass them to the OnLatticeSimulation.
#         
#         volume_constraint_update_rule = chaste.cell_based.VolumeConstraintPottsUpdateRule2()
#         volume_constraint_update_rule.SetMatureCellTargetVolume(16)
#         volume_constraint_update_rule.SetDeformationEnergyParameter(0.2)
#         simulator.AddUpdateRule(volume_constraint_update_rule)
#         
#         ## We repeat the process for any other update rules.
# 
#         differential_adhesion_update_rule = chaste.cell_based.DifferentialAdhesionPottsUpdateRule2() 
#         differential_adhesion_update_rule.SetLabelledCellLabelledCellAdhesionEnergyParameter(0.16)
#         differential_adhesion_update_rule.SetLabelledCellCellAdhesionEnergyParameter(0.11)
#         differential_adhesion_update_rule.SetCellCellAdhesionEnergyParameter(0.02)
#         differential_adhesion_update_rule.SetLabelledCellBoundaryAdhesionEnergyParameter(0.16)
#         differential_adhesion_update_rule.SetCellBoundaryAdhesionEnergyParameter(0.16)       
#         simulator.AddUpdateRule(differential_adhesion_update_rule)
#         
#         ## To run the simulation, we call `Solve()`.
#     
#         simulator.Solve();
#         
#         ## The next two lines are for test purposes only and are not part of this tutorial. 
#         ## If different simulation input parameters are being explored the lines should be removed.
#         
#         self.assertEqual(cell_population.GetNumRealCells(), 64)
#         self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 20.0, 6)
#         
#     ## ## Test 3 - 3D Cell Sorting
#     ## The next test extends the previous example to three dimensions.
#     
#     def xtest_potts_spheroid_cell_sorting(self):
#         
#         ## First, we generate a Potts mesh. To create a PottsMesh, we can use the PottsMeshGenerator. 
#         ## This generates a regular square-shaped mesh, in which all elements are the same size.
#         ## Here the first three arguments specify the domain width; the number of elements across; and the width of elements. 
#         ## The second set of three arguments specify the domain height; the number of elements up; and the height of individual elements. 
#         ## The third set of three arguments specify the domain depth; the number of elements deep; and the depth of individual elements. 
#         ## We have chosen an 4 by 4 by 4 ( = 64) block of elements each consisting of 2 by 2 by 2 ( = 8) lattice sites.
#         
#         generator = chaste.mesh.PottsMeshGenerator3(10, 4, 2, 10, 4, 2, 10, 4, 2)
#         mesh = generator.GetMesh()
#           
#         ## Having created a mesh, we now create a VecCellPtrs. To do this, we the CellsGenerator helper class, 
#         ## as before but this time the third argument is set to make all cells non-proliferative.
#         
#         cells = chaste.cell_based.VecCellPtr()
#         differentiated_type = chaste.cell_based.DifferentiatedCellProliferativeType()
#         cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_3()
#         cell_generator.GenerateBasicRandom(cells, mesh.GetNumElements(), differentiated_type)
#         
#         ## As for the 2D case before we make a CellPopulation we make a pointer to a cell label and then assign this label to some randomly chosen cells.
#         
#         label = chaste.cell_based.CellLabel()
#         for eachCell in cells:
#             if(chaste.core.RandomNumberGenerator.Instance().ranf()<0.5):
#                 eachCell.AddCellProperty(label)
#           
#         ## Now we have a mesh and a set of cells to go with it, we can create a CellPopulation. 
#         
#         cell_population = chaste.cell_based.PottsBasedCellPopulation3(mesh, cells)
#         
#         ## In order to visualize labelled cells we need to use the following command.
#         
#         cell_population.AddCellWriterCellLabelWriter();
# 
#         ## We then pass in the cell population into an `OffLatticeSimulation`, and set the output directory and end time
# 
#         simulator = chaste.cell_based.OnLatticeSimulation3(cell_population)
#         simulator.SetOutputDirectory("Python/TestPottsBasedCellSorting3D")
#         simulator.SetEndTime(20.0)
#         simulator.SetSamplingTimestepMultiple(10)
# 
#         ## We must now create one or more update rules, which determine the Hamiltonian in the Potts simulation. 
#         ## Now set the target volume to be appropriate for this 3D simulation.
#         
#         volume_constraint_update_rule = chaste.cell_based.VolumeConstraintPottsUpdateRule3()
#         volume_constraint_update_rule.SetMatureCellTargetVolume(8)
#         volume_constraint_update_rule.SetDeformationEnergyParameter(0.2)
#         simulator.AddUpdateRule(volume_constraint_update_rule)
#         
#         ## We use the same differential adhesion parameters as in the 2D case.
# 
#         differential_adhesion_update_rule = chaste.cell_based.DifferentialAdhesionPottsUpdateRule3() 
#         differential_adhesion_update_rule.SetLabelledCellLabelledCellAdhesionEnergyParameter(0.16)
#         differential_adhesion_update_rule.SetLabelledCellCellAdhesionEnergyParameter(0.11)
#         differential_adhesion_update_rule.SetCellCellAdhesionEnergyParameter(0.02)
#         differential_adhesion_update_rule.SetLabelledCellBoundaryAdhesionEnergyParameter(0.16)
#         differential_adhesion_update_rule.SetCellBoundaryAdhesionEnergyParameter(0.16)       
#         simulator.AddUpdateRule(differential_adhesion_update_rule)
#         
#         ## To run the simulation, we call `Solve()`.
#     
#         simulator.Solve();
#         
#         ## The next two lines are for test purposes only and are not part of this tutorial. 
#         ## If different simulation input parameters are being explored the lines should be removed.
#         
#         self.assertEqual(cell_population.GetNumRealCells(), 64)
#         self.assertAlmostEqual(chaste.cell_based.SimulationTime.Instance().GetTime(), 20.0, 6)
        

if __name__ == '__main__':
    unittest.main(verbosity=2)
    
#endif END_WIKI