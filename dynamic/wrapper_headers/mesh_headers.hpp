#include "ChastePoint.hpp"
#include "NodeAttributes.hpp"
#include "Node.hpp"
#include "Element.hpp"
#include "PottsMesh.hpp"
#include "SharedPottsMeshGenerator.hpp"
#include "PottsElement.hpp"

inline int Instantiation()
{
    return sizeof(ChastePoint<3>) +
            sizeof(Node<3>) +
            sizeof(NodeAttributes<3>) +
            sizeof(PottsMesh<3>)+
            sizeof(SharedPottsMeshGenerator<3>);
}

typedef std::vector<PottsElement<3>*, std::allocator<PottsElement<3>* > >  VecPottsElementPtr3;
typedef std::vector<Element<3, 3>*, std::allocator<Element<3, 3>* > >  VecElementPtr3;
typedef std::vector<Node<3>*, std::allocator<Node<3>* > >  VecNodePtr3;
