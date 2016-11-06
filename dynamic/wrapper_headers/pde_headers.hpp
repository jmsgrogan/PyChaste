#include "AbstractLinearEllipticPde.hpp"
#include "AbstractBoundaryCondition.hpp"
#include "ConstBoundaryCondition.hpp"

template class AbstractBoundaryCondition<2>;
template class ConstBoundaryCondition<2>;
template class AbstractLinearEllipticPde<2, 2>;
template class AbstractBoundaryCondition<3>;
template class ConstBoundaryCondition<3>;
template class AbstractLinearEllipticPde<3, 3>;
