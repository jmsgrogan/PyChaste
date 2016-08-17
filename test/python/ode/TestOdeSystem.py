import unittest
import chaste.ode
chaste.init()

class MyOdeSystem(chaste.ode.AbstractOdeSystem):
    
    def __init__(self, OdeSystemInfo):
        super(MyOdeSystem, self).__init__(1)
        
    def EvaluateYDerivatives(self, time, rY, rDy):
        rDy[0] = rY[0]*rY[0] + time*time
        
class MyOdeSystemInformation(chaste.ode.AbstractPythonOdeSystemInformation):
    
    def __init__(self):
        super(MyOdeSystemInformation, self).__init__()
        
    def Initialise(self):
        self.SetIsInitialised(True)
        self.AddVariableName("myvar")
        self.AddVariableUnit("dimensionless")
        self.SetDefaultInitialConditions([1.0])

class TestOdeSystem(unittest.TestCase):
    
    def test_create_system(self):
        
        my_ode_system_information = MyOdeSystemInformation()
        my_ode_system_information.Initialise()
        
        my_ode_system = MyOdeSystem(my_ode_system_information)

if __name__ == '__main__':
    unittest.main()