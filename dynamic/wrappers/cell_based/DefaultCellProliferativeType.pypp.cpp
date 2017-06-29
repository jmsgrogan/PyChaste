#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "DefaultCellProliferativeType.pypp.hpp"

namespace py = pybind11;
typedef DefaultCellProliferativeType DefaultCellProliferativeType;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_DefaultCellProliferativeType_class(py::module &m){
py::class_<DefaultCellProliferativeType  , boost::shared_ptr<DefaultCellProliferativeType >  , AbstractCellProliferativeType  >(m, "DefaultCellProliferativeType")
        .def(py::init< >())
    ;
}
