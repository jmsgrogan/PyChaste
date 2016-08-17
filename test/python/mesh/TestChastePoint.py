import unittest
import chaste.mesh
chaste.init()

class TestChastePoint(unittest.TestCase):
    
    def test_construct(self):
        
        chaste_point = chaste.mesh.ChastePoint3(1.0, 2.0, 3.0)
        print chaste_point.rGetLocation()

if __name__ == '__main__':
    unittest.main()