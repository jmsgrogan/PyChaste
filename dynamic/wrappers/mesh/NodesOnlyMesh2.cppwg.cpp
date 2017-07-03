#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "NodesOnlyMesh.hpp"

#include "NodesOnlyMesh2.cppwg.hpp"

namespace py = pybind11;
typedef NodesOnlyMesh<2 > NodesOnlyMesh2;
;
typedef unsigned int unsignedint;
typedef ::Node<2> * _Node2Ptr;
typedef unsigned int unsignedint;
typedef unsigned int unsignedint;
typedef unsigned int unsignedint;

class NodesOnlyMesh2_Overloads : public NodesOnlyMesh2{
    public:
    using NodesOnlyMesh2::NodesOnlyMesh;
    void Clear() override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            Clear,
            );
    }
    unsigned int SolveNodeMapping(unsigned int index) const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodesOnlyMesh2,
            SolveNodeMapping,
            index);
    }
    ::Node<2> * GetNodeOrHaloNode(unsigned int index) const  override {
        PYBIND11_OVERLOAD(
            _Node2Ptr,
            NodesOnlyMesh2,
            GetNodeOrHaloNode,
            index);
    }
    unsigned int GetNumNodes() const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodesOnlyMesh2,
            GetNumNodes,
            );
    }
    unsigned int GetMaximumNodeIndex() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodesOnlyMesh2,
            GetMaximumNodeIndex,
            );
    }
    double GetWidth(unsigned int const & rDimension) const  override {
        PYBIND11_OVERLOAD(
            double,
            NodesOnlyMesh2,
            GetWidth,
            rDimension);
    }
    void ReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            ReMesh,
            rMap);
    }
    void SetNode(unsigned int nodeIndex, ::ChastePoint<2> point, bool concreteMove) override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            SetNode,
            nodeIndex, 
point, 
concreteMove);
    }
    unsigned int AddNode(::Node<2> * pNewNode) override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodesOnlyMesh2,
            AddNode,
            pNewNode);
    }
    void DeleteNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            DeleteNode,
            index);
    }
    void ConstructFromMeshReader(::AbstractMeshReader<2, 2> & rMeshReader) override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            ConstructFromMeshReader,
            rMeshReader);
    }
    void SetUpBoxCollection(double cutOffLength, ::boost::numeric::ublas::c_vector<double, 4> domainSize, int numLocalRows, bool isPeriodic) override {
        PYBIND11_OVERLOAD(
            void,
            NodesOnlyMesh2,
            SetUpBoxCollection,
            cutOffLength, 
domainSize, 
numLocalRows, 
isPeriodic);
    }

};
void register_NodesOnlyMesh2_class(py::module &m){
py::class_<NodesOnlyMesh2 , NodesOnlyMesh2_Overloads   >(m, "NodesOnlyMesh2")
        .def(py::init< >())
        .def(
            "ConstructNodesWithoutMesh", 
            (void(NodesOnlyMesh2::*)(::std::vector<Node<2> *, std::allocator<Node<2> *> > const &, double)) &NodesOnlyMesh2::ConstructNodesWithoutMesh, 
            " " , py::arg("rNodes"), py::arg("maxInteractionDistance"))
        .def(
            "ConstructNodesWithoutMesh", 
            (void(NodesOnlyMesh2::*)(::std::vector<boost::shared_ptr<Node<2> >, std::allocator<boost::shared_ptr<Node<2> > > > const &, double)) &NodesOnlyMesh2::ConstructNodesWithoutMesh, 
            " " , py::arg("rNodes"), py::arg("maxInteractionDistance"))
        .def(
            "ConstructNodesWithoutMesh", 
            (void(NodesOnlyMesh2::*)(::AbstractMesh<2, 2> const &, double)) &NodesOnlyMesh2::ConstructNodesWithoutMesh, 
            " " , py::arg("rGeneratingMesh"), py::arg("maxInteractionDistance"))
        .def(
            "rGetInitiallyOwnedNodes", 
            (::std::vector<bool, std::allocator<bool> > &(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::rGetInitiallyOwnedNodes, 
            " " )
        .def(
            "Clear", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::Clear, 
            " " )
        .def(
            "SolveNodeMapping", 
            (unsigned int(NodesOnlyMesh2::*)(unsigned int) const ) &NodesOnlyMesh2::SolveNodeMapping, 
            " " , py::arg("index"))
        .def(
            "GetNodeOrHaloNode", 
            (::Node<2> *(NodesOnlyMesh2::*)(unsigned int) const ) &NodesOnlyMesh2::GetNodeOrHaloNode, 
            " " , py::arg("index"))
        .def(
            "IsOwned", 
            (bool(NodesOnlyMesh2::*)(::boost::numeric::ublas::c_vector<double, 2> &)) &NodesOnlyMesh2::IsOwned, 
            " " , py::arg("location"))
        .def(
            "GetNumNodes", 
            (unsigned int(NodesOnlyMesh2::*)() const ) &NodesOnlyMesh2::GetNumNodes, 
            " " )
        .def(
            "GetMaximumNodeIndex", 
            (unsigned int(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::GetMaximumNodeIndex, 
            " " )
        .def(
            "SetMaximumInteractionDistance", 
            (void(NodesOnlyMesh2::*)(double)) &NodesOnlyMesh2::SetMaximumInteractionDistance, 
            " " , py::arg("maxDistance"))
        .def(
            "GetMaximumInteractionDistance", 
            (double(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::GetMaximumInteractionDistance, 
            " " )
        .def(
            "GetWidth", 
            (double(NodesOnlyMesh2::*)(unsigned int const &) const ) &NodesOnlyMesh2::GetWidth, 
            " " , py::arg("rDimension"))
        .def(
            "SetCalculateNodeNeighbours", 
            (void(NodesOnlyMesh2::*)(bool)) &NodesOnlyMesh2::SetCalculateNodeNeighbours, 
            " " , py::arg("calculateNodeNeighbours"))
        .def(
            "CalculateInteriorNodePairs", 
            (void(NodesOnlyMesh2::*)(::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > &)) &NodesOnlyMesh2::CalculateInteriorNodePairs, 
            " " , py::arg("rNodePairs"))
        .def(
            "CalculateBoundaryNodePairs", 
            (void(NodesOnlyMesh2::*)(::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > &)) &NodesOnlyMesh2::CalculateBoundaryNodePairs, 
            " " , py::arg("rNodePairs"))
        .def(
            "ReMesh", 
            (void(NodesOnlyMesh2::*)(::NodeMap &)) &NodesOnlyMesh2::ReMesh, 
            " " , py::arg("rMap"))
        .def(
            "SetInitialBoxCollection", 
            (void(NodesOnlyMesh2::*)(::boost::numeric::ublas::c_vector<double, 4> const, double)) &NodesOnlyMesh2::SetInitialBoxCollection, 
            " " , py::arg("domainSize"), py::arg("maxInteractionDistance"))
        .def(
            "UpdateBoxCollection", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::UpdateBoxCollection, 
            " " )
        .def(
            "ResizeBoxCollection", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::ResizeBoxCollection, 
            " " )
        .def(
            "AddNodesToBoxes", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::AddNodesToBoxes, 
            " " )
        .def(
            "AddHaloNodesToBoxes", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::AddHaloNodesToBoxes, 
            " " )
        .def(
            "CalculateNodesOutsideLocalDomain", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::CalculateNodesOutsideLocalDomain, 
            " " )
        .def(
            "rGetNodesToSendLeft", 
            (::std::vector<unsigned int, std::allocator<unsigned int> > &(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::rGetNodesToSendLeft, 
            " " )
        .def(
            "rGetNodesToSendRight", 
            (::std::vector<unsigned int, std::allocator<unsigned int> > &(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::rGetNodesToSendRight, 
            " " )
        .def(
            "rGetHaloNodesToSendRight", 
            (::std::vector<unsigned int, std::allocator<unsigned int> > &(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::rGetHaloNodesToSendRight, 
            " " )
        .def(
            "rGetHaloNodesToSendLeft", 
            (::std::vector<unsigned int, std::allocator<unsigned int> > &(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::rGetHaloNodesToSendLeft, 
            " " )
        .def(
            "AddHaloNode", 
            (void(NodesOnlyMesh2::*)(::boost::shared_ptr<Node<2> >)) &NodesOnlyMesh2::AddHaloNode, 
            " " , py::arg("pNewNode"))
        .def(
            "ClearHaloNodes", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::ClearHaloNodes, 
            " " )
        .def(
            "SetNode", 
            (void(NodesOnlyMesh2::*)(unsigned int, ::ChastePoint<2>, bool)) &NodesOnlyMesh2::SetNode, 
            " " , py::arg("nodeIndex"), py::arg("point"), py::arg("concreteMove") = false)
        .def(
            "AddNode", 
            (unsigned int(NodesOnlyMesh2::*)(::Node<2> *)) &NodesOnlyMesh2::AddNode, 
            " " , py::arg("pNewNode"))
        .def(
            "AddMovedNode", 
            (void(NodesOnlyMesh2::*)(::boost::shared_ptr<Node<2> >)) &NodesOnlyMesh2::AddMovedNode, 
            " " , py::arg("pMovedNode"))
        .def(
            "DeleteNode", 
            (void(NodesOnlyMesh2::*)(unsigned int)) &NodesOnlyMesh2::DeleteNode, 
            " " , py::arg("index"))
        .def(
            "DeleteMovedNode", 
            (void(NodesOnlyMesh2::*)(unsigned int)) &NodesOnlyMesh2::DeleteMovedNode, 
            " " , py::arg("index"))
        .def(
            "SetMinimumNodeDomainBoundarySeparation", 
            (void(NodesOnlyMesh2::*)(double)) &NodesOnlyMesh2::SetMinimumNodeDomainBoundarySeparation, 
            " " , py::arg("separation"))
        .def(
            "LoadBalanceMesh", 
            (void(NodesOnlyMesh2::*)()) &NodesOnlyMesh2::LoadBalanceMesh, 
            " " )
        .def(
            "ConstructFromMeshReader", 
            (void(NodesOnlyMesh2::*)(::AbstractMeshReader<2, 2> &)) &NodesOnlyMesh2::ConstructFromMeshReader, 
            " " , py::arg("rMeshReader"))
    ;
}
