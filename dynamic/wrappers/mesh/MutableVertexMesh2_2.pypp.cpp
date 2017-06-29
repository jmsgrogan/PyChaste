#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "MutableVertexMesh2_2.pypp.hpp"

namespace py = pybind11;
typedef MutableVertexMesh<2,2 > MutableVertexMesh2_2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef unsigned int unsignedint;
typedef unsigned int unsignedint;

class MutableVertexMesh2_2_Overloads : public MutableVertexMesh2_2{
    public:
    using MutableVertexMesh2_2::MutableVertexMesh;
    void SetNode(unsigned int nodeIndex, ::ChastePoint<2> point) override {
        PYBIND11_OVERLOAD(
            void,
            MutableVertexMesh2_2,
            SetNode,
            nodeIndex, 
point);
    }
    unsigned int GetNumNodes() const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            MutableVertexMesh2_2,
            GetNumNodes,
            );
    }
    unsigned int GetNumElements() const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            MutableVertexMesh2_2,
            GetNumElements,
            );
    }
    void Clear() override {
        PYBIND11_OVERLOAD(
            void,
            MutableVertexMesh2_2,
            Clear,
            );
    }
    void ReMesh(::VertexElementMap & rElementMap) override {
        PYBIND11_OVERLOAD(
            void,
            MutableVertexMesh2_2,
            ReMesh,
            rElementMap);
    }
    void IdentifySwapType(::Node<2> * pNodeA, ::Node<2> * pNodeB) override {
        PYBIND11_OVERLOAD(
            void,
            MutableVertexMesh2_2,
            IdentifySwapType,
            pNodeA, 
pNodeB);
    }
    void HandleHighOrderJunctions(::Node<2> * pNodeA, ::Node<2> * pNodeB) override {
        PYBIND11_OVERLOAD(
            void,
            MutableVertexMesh2_2,
            HandleHighOrderJunctions,
            pNodeA, 
pNodeB);
    }

};
void register_MutableVertexMesh2_2_class(py::module &m){
py::class_<MutableVertexMesh2_2 , MutableVertexMesh2_2_Overloads , boost::shared_ptr<MutableVertexMesh2_2 >   >(m, "MutableVertexMesh2_2")
        .def(py::init<::std::vector<Node<2> *, std::allocator<Node<2> *> >, ::std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> *> >, double, double, double, double, double, double >())
        .def(py::init< >())
        .def(
            "SetCellRearrangementThreshold", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetCellRearrangementThreshold, 
            " " , py::arg("cellRearrangementThreshold"))
        .def(
            "SetT2Threshold", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetT2Threshold, 
            " " , py::arg("t2Threshold"))
        .def(
            "SetCellRearrangementRatio", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetCellRearrangementRatio, 
            " " , py::arg("cellRearrangementRatio"))
        .def(
            "SetProtorosetteFormationProbability", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetProtorosetteFormationProbability, 
            " " , py::arg("protorosetteFormationProbability"))
        .def(
            "SetProtorosetteResolutionProbabilityPerTimestep", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetProtorosetteResolutionProbabilityPerTimestep, 
            " " , py::arg("protorosetteResolutionProbabilityPerTimestep"))
        .def(
            "SetRosetteResolutionProbabilityPerTimestep", 
            (void(MutableVertexMesh2_2::*)(double)) &MutableVertexMesh2_2::SetRosetteResolutionProbabilityPerTimestep, 
            " " , py::arg("rosetteResolutionProbabilityPerTimestep"))
        .def(
            "SetNode", 
            (void(MutableVertexMesh2_2::*)(unsigned int, ::ChastePoint<2>)) &MutableVertexMesh2_2::SetNode, 
            " " , py::arg("nodeIndex"), py::arg("point"))
        .def(
            "SetCheckForInternalIntersections", 
            (void(MutableVertexMesh2_2::*)(bool)) &MutableVertexMesh2_2::SetCheckForInternalIntersections, 
            " " , py::arg("checkForInternalIntersections"))
        .def(
            "GetCellRearrangementThreshold", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetCellRearrangementThreshold, 
            " " )
        .def(
            "GetT2Threshold", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetT2Threshold, 
            " " )
        .def(
            "GetCellRearrangementRatio", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetCellRearrangementRatio, 
            " " )
        .def(
            "GetProtorosetteFormationProbability", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetProtorosetteFormationProbability, 
            " " )
        .def(
            "GetProtorosetteResolutionProbabilityPerTimestep", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetProtorosetteResolutionProbabilityPerTimestep, 
            " " )
        .def(
            "GetRosetteResolutionProbabilityPerTimestep", 
            (double(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetRosetteResolutionProbabilityPerTimestep, 
            " " )
        .def(
            "GetNumNodes", 
            (unsigned int(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetNumNodes, 
            " " )
        .def(
            "GetNumElements", 
            (unsigned int(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetNumElements, 
            " " )
        .def(
            "GetCheckForInternalIntersections", 
            (bool(MutableVertexMesh2_2::*)() const ) &MutableVertexMesh2_2::GetCheckForInternalIntersections, 
            " " )
        .def(
            "GetLocationsOfT1Swaps", 
            (::std::vector<boost::numeric::ublas::c_vector<double, 2>, std::allocator<boost::numeric::ublas::c_vector<double, 2> > >(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::GetLocationsOfT1Swaps, 
            " " )
        .def(
            "GetLastT2SwapLocation", 
            (::boost::numeric::ublas::c_vector<double, 2>(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::GetLastT2SwapLocation, 
            " " )
        .def(
            "GetLocationsOfT3Swaps", 
            (::std::vector<boost::numeric::ublas::c_vector<double, 2>, std::allocator<boost::numeric::ublas::c_vector<double, 2> > >(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::GetLocationsOfT3Swaps, 
            " " )
        .def(
            "ClearLocationsOfT1Swaps", 
            (void(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::ClearLocationsOfT1Swaps, 
            " " )
        .def(
            "ClearLocationsOfT3Swaps", 
            (void(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::ClearLocationsOfT3Swaps, 
            " " )
        .def(
            "AddNode", 
            (unsigned int(MutableVertexMesh2_2::*)(::Node<2> *)) &MutableVertexMesh2_2::AddNode, 
            " " , py::arg("pNewNode"))
        .def(
            "DeleteElementPriorToReMesh", 
            (void(MutableVertexMesh2_2::*)(unsigned int)) &MutableVertexMesh2_2::DeleteElementPriorToReMesh, 
            " " , py::arg("index"))
        .def(
            "DeleteNodePriorToReMesh", 
            (void(MutableVertexMesh2_2::*)(unsigned int)) &MutableVertexMesh2_2::DeleteNodePriorToReMesh, 
            " " , py::arg("index"))
        .def(
            "DivideElementAlongShortAxis", 
            (unsigned int(MutableVertexMesh2_2::*)(::VertexElement<2, 2> *, bool)) &MutableVertexMesh2_2::DivideElementAlongShortAxis, 
            " " , py::arg("pElement"), py::arg("placeOriginalElementBelow") = false)
        .def(
            "DivideElementAlongGivenAxis", 
            (unsigned int(MutableVertexMesh2_2::*)(::VertexElement<2, 2> *, ::boost::numeric::ublas::c_vector<double, 2>, bool)) &MutableVertexMesh2_2::DivideElementAlongGivenAxis, 
            " " , py::arg("pElement"), py::arg("axisOfDivision"), py::arg("placeOriginalElementBelow") = false)
        .def(
            "AddElement", 
            (unsigned int(MutableVertexMesh2_2::*)(::VertexElement<2, 2> *)) &MutableVertexMesh2_2::AddElement, 
            " " , py::arg("pNewElement"))
        .def(
            "CheckForT2Swaps", 
            (bool(MutableVertexMesh2_2::*)(::VertexElementMap &)) &MutableVertexMesh2_2::CheckForT2Swaps, 
            " " , py::arg("rElementMap"))
        .def(
            "Clear", 
            (void(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::Clear, 
            " " )
        .def(
            "DivideEdge", 
            (void(MutableVertexMesh2_2::*)(::Node<2> *, ::Node<2> *)) &MutableVertexMesh2_2::DivideEdge, 
            " " , py::arg("pNodeA"), py::arg("pNodeB"))
        .def(
            "RemoveDeletedNodesAndElements", 
            (void(MutableVertexMesh2_2::*)(::VertexElementMap &)) &MutableVertexMesh2_2::RemoveDeletedNodesAndElements, 
            " " , py::arg("rElementMap"))
        .def(
            "RemoveDeletedNodes", 
            (void(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::RemoveDeletedNodes, 
            " " )
        .def(
            "ReMesh", 
            (void(MutableVertexMesh2_2::*)(::VertexElementMap &)) &MutableVertexMesh2_2::ReMesh, 
            " " , py::arg("rElementMap"))
        .def(
            "ReMesh", 
            (void(MutableVertexMesh2_2::*)()) &MutableVertexMesh2_2::ReMesh, 
            " " )
    ;
}
