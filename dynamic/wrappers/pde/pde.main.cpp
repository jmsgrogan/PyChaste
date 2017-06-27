#include <pybind11/pybind11.h>
#include "AbstractNonlinearEllipticPde2.pypp.hpp"
#include "AbstractNonlinearEllipticPde3.pypp.hpp"
#include "AbstractBoundaryCondition2.pypp.hpp"
#include "AbstractBoundaryCondition3.pypp.hpp"
#include "ConstBoundaryCondition2.pypp.hpp"
#include "ConstBoundaryCondition3.pypp.hpp"
#include "PdeSimulationTime.pypp.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_pde, m)
{
register_AbstractNonlinearEllipticPde2_class(m);
register_AbstractNonlinearEllipticPde3_class(m);
register_AbstractBoundaryCondition2_class(m);
register_AbstractBoundaryCondition3_class(m);
register_ConstBoundaryCondition2_class(m);
register_ConstBoundaryCondition3_class(m);
register_PdeSimulationTime_class(m);
}
