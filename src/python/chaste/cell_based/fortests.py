import unittest
import chaste.cell_based

class AbstractCellBasedTestSuite(unittest.TestCase):
    
    def setUp(self):
        simulation_time = chaste.cell_based.SimulationTime.Instance()
        simulation_time.SetStartTime(0.0)
        
    def tearDown(self):
        simulation_time = chaste.cell_based.SimulationTime.Instance()
        simulation_time.Destroy()