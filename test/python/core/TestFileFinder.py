import unittest
import chaste.core
chaste.init()

class TestFileFinder(unittest.TestCase):
    
    def test_find_file(self):
        
        file_finder = chaste.core.FileFinder("/projects/PyChaste/test/data/find_me.txt", chaste.core.RelativeTo.ChasteSourceRoot)
        self.assertEqual(file_finder.GetLeafName() ,  "find_me.txt")
        self.assertTrue(file_finder.IsFile())

if __name__ == '__main__':
    unittest.main()