import os, sys
from _chaste_project_PyChaste_preload import *
import chaste.core

def init(master_output_directory = os.getcwd()):
    import petsc4py
    
    # If CHASTE_TEST_OUTPUT is not set give it a user specified value, or CWD if there is none
    if os.environ.get('CHASTE_TEST_OUTPUT') is None:
        os.environ["CHASTE_TEST_OUTPUT"] = master_output_directory

    petsc4py.init(sys.argv)
    return chaste.core.OutputFileHandler("", False)