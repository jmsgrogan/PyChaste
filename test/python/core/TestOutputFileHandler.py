import unittest
import chaste.core

class TestFileHandler(unittest.TestCase):
    
    def test_create_directory(self):
        
        file_handler = chaste.core.OutputFileHandler("TestOutputFileHandler", False)
        chaste_output_dir = file_handler.GetChasteTestOutputDirectory()
        self.assertEqual(chaste_output_dir + "TestOutputFileHandler/", file_handler.GetOutputDirectoryFullPath())

if __name__ == '__main__':
    unittest.main()