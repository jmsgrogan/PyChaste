#include <pybind11/pybind11.h>
#include "AbstractLinearPde2_2.cppwg.hpp"
#include "AbstractLinearPde3_3.cppwg.hpp"
#include "AbstractLinearParabolicPde2_2.cppwg.hpp"
#include "AbstractLinearParabolicPde3_3.cppwg.hpp"
#include "AbstractLinearEllipticPde2_2.cppwg.hpp"
#include "AbstractLinearEllipticPde3_3.cppwg.hpp"
#include "AbstractNonlinearEllipticPde2.cppwg.hpp"
#include "AbstractNonlinearEllipticPde3.cppwg.hpp"
#include "AbstractBoundaryCondition2.cppwg.hpp"
#include "AbstractBoundaryCondition3.cppwg.hpp"
#include "ConstBoundaryCondition2.cppwg.hpp"
#include "ConstBoundaryCondition3.cppwg.hpp"
#include "PdeSimulationTime.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_pde, m)
{
    register_AbstractLinearPde2_2_class(m);
    register_AbstractLinearPde3_3_class(m);
    register_AbstractLinearParabolicPde2_2_class(m);
    register_AbstractLinearParabolicPde3_3_class(m);
    register_AbstractLinearEllipticPde2_2_class(m);
    register_AbstractLinearEllipticPde3_3_class(m);
    register_AbstractNonlinearEllipticPde2_class(m);
    register_AbstractNonlinearEllipticPde3_class(m);
    register_AbstractBoundaryCondition2_class(m);
    register_AbstractBoundaryCondition3_class(m);
    register_ConstBoundaryCondition2_class(m);
    register_ConstBoundaryCondition3_class(m);
    register_PdeSimulationTime_class(m);
}
