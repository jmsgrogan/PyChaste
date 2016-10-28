# PyChaste
Unofficial Python bindings for Chaste

## Installation
A [conda](http://conda.pydata.org/docs/intro.html) Python package for Linux is currently under development. However, at the moment, the package needs to be built from source using the development version of Chaste and CMake. 

First, Chaste dependencies need to be built from source following the [Chaste Install Guide](https://chaste.cs.ox.ac.uk/trac/wiki/InstallGuides/InstallGuide). In addition to the normal Chaste dependencies, this project also requires Boost Python and a Python shared library. These may already be on your system, in which case an attempt will be made to find them automatically. If not, Boost Python can be built by adding `python` to the list of libraries when following the Boost build instructions [here](https://chaste.cs.ox.ac.uk/trac/wiki/InstallGuides/InstallGuide).

The project only supports the development version of Chaste. This can be obtained by doing:

```bash
git clone https://chaste.cs.ox.ac.uk/git/chaste.git $CHASTE_SOURCE_DIR
```

The project code itself can be obtained by doing: 

```bash
git clone https://github.com/jmsgrogan/PyChaste.git $PYCHASTE_PROJECT_SOURCE_DIR
```

The PyChaste project code needs to be included in the `projects` folder of the main Chaste source. This can be done with a symbolic link:

```bash
cd $CHASTE_SOURCE_DIR/projects
ln -s $PYCHASTE_PROJECT_SOURCE_DIR
```

or just by copying the project in. To build, create a build directory outside the source tree and proceed as:

```bash
cd $BUILD_DIR
cmake $CHASTE_SOURCE_DIR
make project_PyChaste
make project_PyChaste_Python
``` 

The Python package `chaste` will be in `$BUILD_DIR` under `Chaste/projects/PyChaste/python`. For convenience, the directory `$BUILD_DIR/Chaste/projects/PyChaste/python` should be added to your PYTHONPATH. A proper Python build script (i.e. `setup.py`) is still under development.

## Usage
The package can be imported in Python as normal. For example, in a Python session do:

```python
>>> import chaste.core
>>> file_handler = chaste.core.OutputFileHandler("Directory_For_My_Output_Files", False)
>>> print file_handler.GetOutputDirectoryFullPath()

/some/directories/Directory_For_My_Output_Files/
```

Often it is neccessary to initialize MPI/PETSc when launching the C++ version of Chaste. This is the same for the Python version, with MPI initialization errors returned if you try to use functions which depend on it. To use MPI/PETSc functionality it is neccessary to install the `petsc4py` Python interface to PETSc. This can be done using pip:

```python
pip install petsc4py
``` 

however care should be taken to ensure that the installed version of `petsc4py` matches your PETSc version. To initialize MPI/PETSc with Chaste you can do:

```python
import chaste
chaste.init()
``` 

## User Projects
User projects can have their own Python packages, which depend on PyChaste. They can be placed in the `chaste/projects` module of PyChaste and can be loaded as follows:

```python
import chaste
chaste.init()
import chaste.projects.my_user_project
```

## Binding Regeneration (Developers Only)
PyChaste is a mix of manual and automatically generated bindings. Binding logic is in `WrapPython.cmake` and `dynamic\generate_X_bindings.py`. To regenerate the automatic binding code do:

```bash
cd $BUILD_DIR
cmake $CHASTE_SOURCE_DIR
make project_PyChaste
make project_PyChaste_Python_Bindings
```

This can take some time to run.

