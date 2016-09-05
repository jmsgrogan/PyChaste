#include "AbstractLinearEllipticPde.hpp"

namespace chaste
{
    namespace pde
    {
        inline int Instantiation()
        {
            return sizeof(AbstractLinearEllipticPde<3, 3>);
        }
    }
}
