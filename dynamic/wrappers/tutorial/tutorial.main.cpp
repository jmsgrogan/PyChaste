#include <pybind11/pybind11.h>
#include "Hello.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_tutorial, m)
{
    register_Hello_class(m);
}
