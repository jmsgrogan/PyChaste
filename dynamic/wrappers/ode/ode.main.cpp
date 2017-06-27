#include <pybind11/pybind11.h>
#include "AbstractOdeSystemInformation.pypp.hpp"
#include "AbstractPythonOdeSystemInformation.pypp.hpp"
#include "AbstractOdeSystem.pypp.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_ode, m)
{
register_AbstractOdeSystemInformation_class(m);
register_AbstractPythonOdeSystemInformation_class(m);
register_AbstractOdeSystem_class(m);
}
