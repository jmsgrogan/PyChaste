# PyChaste

This is a Python wrapper for [Chaste](http://www.cs.ox.ac.uk/chaste/). See the [project website](https://jmsgrogan.github.io/PyChaste/) for more details.

## Install from Source (Linux Only)

Chaste dependencies need to be built following the [Chaste Install Guide](https://chaste.cs.ox.ac.uk/trac/wiki/InstallGuides/InstallGuide). 

The project currently tracks the Chaste master version. This can be obtained by doing:

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

The Python package `chaste` will be in `$BUILD_DIR` under `projects/PyChaste/python`. You can either add `$BUILD_DIR/projects/PyChaste/python` to your PYTHONPATH or do:

```bash
cd $BUILD_DIR/projects/PyChaste/python
python setup.py install
``` 

To use MPI/PETSc functionality (as is required in much of Chaste) it is neccessary to install the `petsc4py` Python interface to PETSc. This can be done using pip:

```python
pip install petsc4py
``` 

taking care to ensure that the installed version of `petsc4py` matches your PETSc version and that the environment variable `$PETSC_DIR` points to the version of PETSc that you want to use. 


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
PyChaste can be extended for use with Chaste User-Projects or new wrappers for existing Chaste code can be added. The difficulty in doing so can range from adding one line of text and re-building the wrapper with CMake through to needing to write custom Python scripts and learning the PyBind11 API. The more complicated a class interface is the more likely it is that you will need to customize the generator.

The wrapper code is automatically generated using the [cppwg](https://github.com/jmsgrogan/cppwg) package, which was purpose written for PyChaste. It is recommended that the simple wrapping example in the `cppwg` documentation is quickly consulted before modifying the Chaste wrapper.

The main logic for wrapper generation is in the file `dynamic/wrapper_generators/package_info.yaml`. Wrapping a new class can be as simple as adding its name to the list under the desired module in `package_info.yaml`. Classes with more complicated interfaces, for example templated methods or methods taking or returning raw pointers, may need further input in the YAML file. The current file should be consulted as a template.

For more complicated wrapping logic still, the YAML file can be pointed to Python scripts for custom wrapper generation. The file `dynamic/wrapper_utilities/CellsGenerator_custom.py` is an example of this.

Once the `package_info.yaml` file has been suitable modified the wrapper can be re-built by doing:

```bash
make project_PyChaste_Python_Bindings
make project_PyChaste_Python -j 4
```

The first operation should take no longer than 10 minutes. The second may take up to an hour. Chaste developers are welcome to commit any wapper modifications to the `develop` branch, which is automatically tested on Travis. Pull-requests are welcome from external developers.