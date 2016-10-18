
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

import unittest
import chaste.cell_based
import chaste.mesh
chaste.init()

class TestCell(unittest.TestCase):
    
    def test_construct(self):
        
        # Do Setup
        simulation_time = chaste.cell_based.SimulationTime.Instance()
        simulation_time.SetStartTime(0.0)

        mesh_generator = chaste.mesh.PottsMeshGenerator3(10, 0, 0, 10, 0, 0, 10, 0, 0)
        mesh = mesh_generator.GetMesh()
         
        # Make the cells
        cells = chaste.cell_based.VecCellPtr()
        proliferative_type = chaste.cell_based.DefaultCellProliferativeType()
        cell_generator = chaste.cell_based.CellsGeneratorUniformCellCycleModel_2()
        cell_generator.GenerateBasic(cells, 2)
         
        # Make the cell population
        lattice_indices = range(2)
        cell_population = chaste.cell_based.CaBasedCellPopulation3(mesh, cells, lattice_indices)
         
        # Set up the simulation
        simulator = chaste.cell_based.OnLatticeSimulation3(cell_population)
        simulator.SetOutputDirectory("PythonTestCell");
        simulator.SetEndTime(100.0);
        simulator.SetDt(1.0);
        simulator.SetSamplingTimestepMultiple(1);
        simulator.Solve();


if __name__ == '__main__':
    unittest.main()