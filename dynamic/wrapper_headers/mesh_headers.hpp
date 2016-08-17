#include "ChastePoint.hpp"
#include "NodeAttributes.hpp"
#include "Node.hpp"

inline int Instantiation()
{
    return sizeof(ChastePoint<3>) + sizeof(Node<3>) +
            sizeof(NodeAttributes<3>);
}

typedef std::vector<double, std::allocator<double> >  VecDouble;
typedef std::vector<unsigned, std::allocator<unsigned> >  VecUnsigned;
