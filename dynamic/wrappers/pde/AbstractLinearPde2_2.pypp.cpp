#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractLinearPde2_2.pypp.hpp"

namespace py = pybind11;
typedef AbstractLinearPde<2,2 > AbstractLinearPde2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_AbstractLinearPde2_2_class(py::module &m){
py::class_<AbstractLinearPde2_2  , boost::shared_ptr<AbstractLinearPde2_2 >   >(m, "AbstractLinearPde2_2")
        .def(py::init< >())
    ;
}
