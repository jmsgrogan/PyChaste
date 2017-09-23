#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "ApcOneHitCellMutationState.hpp"

#include "PythonObjectConverters.hpp"
#include "ApcOneHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef ApcOneHitCellMutationState ApcOneHitCellMutationState;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_ApcOneHitCellMutationState_class(py::module &m){
py::class_<ApcOneHitCellMutationState  , boost::shared_ptr<ApcOneHitCellMutationState >  , AbstractCellMutationState  >(m, "ApcOneHitCellMutationState")
        .def(py::init< >())
    ;
}
