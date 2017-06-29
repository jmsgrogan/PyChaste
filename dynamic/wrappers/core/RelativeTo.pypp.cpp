#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "RelativeTo.pypp.hpp"

namespace py = pybind11;
typedef RelativeTo RelativeTo;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_RelativeTo_class(py::module &m){
py::class_<RelativeTo  , boost::shared_ptr<RelativeTo >   >(m, "RelativeTo")
    ;
}
