#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractLinearPde3_3.pypp.hpp"

namespace py = pybind11;

typedef AbstractLinearPde<3,3 > AbstractLinearPde3_3;

void register_AbstractLinearPde3_3_class(py::module &m){
    py::class_<AbstractLinearPde3_3, std::shared_ptr<AbstractLinearPde3_3 >  >(m, "AbstractLinearPde3_3")
        .def(py::init< >())
    ;
}
