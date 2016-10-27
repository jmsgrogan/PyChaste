#include "ChastePoint.hpp"
#include "NodeAttributes.hpp"
#include "Node.hpp"
#include "Element.hpp"
#include "NodesOnlyMesh.hpp"
#include "MutableMesh.hpp"
#include "PottsMesh.hpp"
#include "SharedPottsMeshGenerator.hpp"
#include "PottsElement.hpp"
#include "TetrahedralMesh.hpp"
#include "AbstractTetrahedralMesh.hpp"
#include "AbstractMesh.hpp"
#include "VertexMesh.hpp"
#include "MutableVertexMesh.hpp"
#include "SharedHoneycombMeshGenerator.hpp"
#include "SharedHoneycombVertexMeshGenerator.hpp"

inline int Instantiation()
{
    return sizeof(ChastePoint<3>) +
            sizeof(Node<3>) +
            sizeof(NodeAttributes<3>) +
            sizeof(PottsMesh<3>)+
            sizeof(SharedPottsMeshGenerator<3>) +
            sizeof(ChastePoint<2>) +
            sizeof(Node<2>) +
            sizeof(NodeAttributes<2>) +
            sizeof(PottsMesh<2>)+
            sizeof(SharedPottsMeshGenerator<2>) +
            sizeof(NodesOnlyMesh<2>) +
            sizeof(NodesOnlyMesh<3>) +
            sizeof(MutableMesh<2, 2>) +
            sizeof(MutableMesh<3, 3>) +
            sizeof(TetrahedralMesh<2, 2>) +
            sizeof(TetrahedralMesh<3, 3>) +
            sizeof(AbstractTetrahedralMesh<2, 2>) +
            sizeof(AbstractTetrahedralMesh<3, 3>) +
            sizeof(AbstractMesh<2, 2>) +
            sizeof(AbstractMesh<3, 3>) +
            sizeof(VertexMesh<2, 2>) +
            sizeof(VertexMesh<3, 3>) +
            sizeof(MutableVertexMesh<2, 2>) +
            sizeof(MutableVertexMesh<3, 3>)
            ;
}

typedef std::vector<PottsElement<3>*, std::allocator<PottsElement<3>* > >  VecPottsElementPtr3;
typedef std::vector<Element<3, 3>*, std::allocator<Element<3, 3>* > >  VecElementPtr3;
typedef std::vector<Node<3>*, std::allocator<Node<3>* > >  VecNodePtr3;
