# PyChaste

This is an unofficial collection of Python bindings for [Chaste](http://www.cs.ox.ac.uk/chaste/). Currently a limited number of
features are supported, mostly related to Cell Based Chaste.

# Features 

* On- and off-lattice agent based cell modelling
* Visualization using VTK

See the [project wiki](https://github.com/jmsgrogan/PyChaste/wiki) for some sample applications. Further examples based on the [Chaste User Tutorials](https://chaste.cs.ox.ac.uk/trac/wiki/UserTutorials) are under development.

## Installation (Linux Only)

### Conda
A [conda](http://conda.pydata.org/docs/intro.html) Python package for Linux is available. Just do:

```bash
conda config --add channels conda-forge jmsgrogan
conda install chaste
```

If you do not have conda you can do (accepting defaults):

```bash
wget https://repo.continuum.io/miniconda/Miniconda2-latest-Linux-x86_64.sh
chmod 777 Miniconda2-latest-Linux-x86_64.sh
./Miniconda2-latest-Linux-x86_64.sh
conda update conda
```

and then proceed to install PyChaste as above. If you install this version you can proceed straight to the [project wiki](https://github.com/jmsgrogan/PyChaste/wiki) for some sample applications.

### Install from Source

Chaste dependencies need to be built from source following the [Chaste Install Guide](https://chaste.cs.ox.ac.uk/trac/wiki/InstallGuides/InstallGuide). In addition to the normal Chaste dependencies, this project also requires Boost Python and a Python shared library. These may already be on your system, in which case an attempt will be made to find them automatically. If not, Boost Python can be built by adding `python` to the list of libraries when following the Boost build instructions [here](https://chaste.cs.ox.ac.uk/trac/wiki/InstallGuides/InstallGuide).

The project only supports the development version of Chaste. This can be obtained by doing:

```bash
git clone -b develop https://chaste.cs.ox.ac.uk/git/chaste.git $CHASTE_SOURCE_DIR
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

The Python package `chaste` will be in `$BUILD_DIR` under `projects/PyChaste/python`. You can either add `$BUILD_DIR/projects/PyChaste/python` to your PYTHONPATH or do:

```bash
cd $BUILD_DIR/projects/PyChaste/python
python setup.py install
``` 
To use MPI/PETSc functionality (as is required in much of Chaste) it is neccessary to install the `petsc4py` Python interface to PETSc. This can be done using pip:

```python
pip install petsc4py
``` 

taking to ensure that the installed version of `petsc4py` matches your PETSc version and that the environment variable PETSC_DIR points to the version of PETSc you want to use. 


## Usage
The package can be imported in Python as normal. For example, in a Python session do:

```python
>>> import chaste.core
>>> file_handler = chaste.core.OutputFileHandler("Directory_For_My_Output_Files", False)
>>> print file_handler.GetOutputDirectoryFullPath()

/some/directories/Directory_For_My_Output_Files/
```

Often it is neccessary to initialize MPI/PETSc when launching the C++ version of Chaste. This is the same for the Python version, with MPI initialization errors returned if you try to use functions which depend on it. To initialize MPI/PETSc with Chaste you can do:

```python
import chaste
chaste.init()
``` 

## Extending
PyChaste can be extended for use with Chaste User-Projects or new wrappers for existing Chaste code can be added. See the [developer section](https://github.com/jmsgrogan/PyChaste/wiki) on the project wiki for further details.

