#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "RelativeTo.pypp.hpp"

namespace py = pybind11;

typedef RelativeTo RelativeTo;
void register_RelativeTo_class(py::module &m){
    py::class_<RelativeTo, std::shared_ptr<RelativeTo >  >(m, "RelativeTo")
    ;
}
