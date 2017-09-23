#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "ApcTwoHitCellMutationState.hpp"

#include "PythonObjectConverters.hpp"
#include "ApcTwoHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef ApcTwoHitCellMutationState ApcTwoHitCellMutationState;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_ApcTwoHitCellMutationState_class(py::module &m){
py::class_<ApcTwoHitCellMutationState  , boost::shared_ptr<ApcTwoHitCellMutationState >  , AbstractCellMutationState  >(m, "ApcTwoHitCellMutationState")
        .def(py::init< >())
    ;
}
