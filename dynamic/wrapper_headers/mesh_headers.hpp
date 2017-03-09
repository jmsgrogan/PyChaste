/*

Copyright (c) 2005-2017, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "SmartPointers.hpp"
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
#include "Cylindrical2dVertexMesh.hpp"
#include "SharedHoneycombMeshGenerator.hpp"
#include "SharedHoneycombVertexMeshGenerator.hpp"
#include "SharedCylindricalHoneycombVertexMeshGenerator.hpp"

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
            sizeof(MutableVertexMesh<3, 3>);
}

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef std::vector<double> VecDouble;
typedef std::vector<unsigned> VecUnsigned;
typedef std::set<unsigned> SetUnsigned;
typedef std::vector<std::pair<Node<3>, Node<3> > > VecPairNode3;
typedef std::vector<std::pair<Node<2>, Node<2> > > VecPairNode2;
typedef std::vector<c_vector<unsigned, 5> > VecCVectorUnsigned_5;
typedef std::vector<c_vector<double, 3> > VecCVectorDouble_3;
typedef std::vector<c_vector<double, 2> > VecCVectorDouble_2;
typedef c_vector<double, 2> CVectorDouble_2;
typedef c_vector<double, 3> CVectorDouble_3;
typedef c_vector<unsigned, 5> CVectorUnsigned_5;
typedef std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > > VecSetInt;
typedef std::vector<std::vector<unsigned int, std::allocator<unsigned int> >, std::allocator<std::vector<unsigned int, std::allocator<unsigned int> > > > VecVecInt;
typedef std::vector<PottsElement<3>*, std::allocator<PottsElement<3>* > >  VecPottsElementPtr3;
typedef std::vector<PottsElement<2>*, std::allocator<PottsElement<2>* > >  VecPottsElementPtr2;
typedef std::vector<VertexElement<1, 2> *, std::allocator<VertexElement<1, 2> * > >  VecVertexElementPtr1_2;
typedef std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> * > >  VecVertexElementPtr2_2;
typedef std::vector<VertexElement<2, 3> *, std::allocator<VertexElement<2, 3> * > >  VecVertexElementPtr2_3;
typedef std::vector<VertexElement<3, 3> *, std::allocator<VertexElement<3, 3> * > >  VecVertexElementPtr3_3;
typedef std::vector<Element<3, 3>*, std::allocator<Element<3, 3>* > >  VecElementPtr3;
typedef std::vector<Node<3>*, std::allocator<Node<3>* > >  VecNodePtr3;
typedef std::vector<Node<2>*, std::allocator<Node<2>* > >  VecNodePtr2;
typedef std::vector<boost::shared_ptr<Node<3> > >  VecNodeSharedPtr3;
typedef std::vector<boost::shared_ptr<Node<2> > >  VecNodeSharedPtr2;
typedef boost::shared_ptr<Node<3> > NodeSharedPtr3;
typedef boost::shared_ptr<Node<2> > NodeSharedPtr2;
typedef std::pair<Node<3>*, Node<3>*>  PairNodePtr3;
typedef std::pair<Node<2>*, Node<2>*>  PairNodePtr2;
}
}
