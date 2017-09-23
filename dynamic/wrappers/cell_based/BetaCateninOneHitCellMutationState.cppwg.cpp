#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "BetaCateninOneHitCellMutationState.hpp"

#include "PythonObjectConverters.hpp"
#include "BetaCateninOneHitCellMutationState.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef BetaCateninOneHitCellMutationState BetaCateninOneHitCellMutationState;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_BetaCateninOneHitCellMutationState_class(py::module &m){
py::class_<BetaCateninOneHitCellMutationState  , boost::shared_ptr<BetaCateninOneHitCellMutationState >  , AbstractCellMutationState  >(m, "BetaCateninOneHitCellMutationState")
        .def(py::init< >())
    ;
}
