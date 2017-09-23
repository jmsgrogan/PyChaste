#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "TransitCellProliferativeType.hpp"

#include "PythonObjectConverters.hpp"
#include "TransitCellProliferativeType.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef TransitCellProliferativeType TransitCellProliferativeType;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_TransitCellProliferativeType_class(py::module &m){
py::class_<TransitCellProliferativeType  , boost::shared_ptr<TransitCellProliferativeType >  , AbstractCellProliferativeType  >(m, "TransitCellProliferativeType")
        .def(py::init< >())
    ;
}
