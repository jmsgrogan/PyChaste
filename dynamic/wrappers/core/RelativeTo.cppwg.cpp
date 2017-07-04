#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "FileFinder.hpp"

#include "RelativeTo.cppwg.hpp"

namespace py = pybind11;
typedef RelativeTo RelativeTo;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

void register_RelativeTo_class(py::module &m){
py::class_<RelativeTo  , boost::shared_ptr<RelativeTo >   >(m, "RelativeTo")
    ;
}
