#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "MutableVertexMesh3_3.pypp.hpp"

namespace py = pybind11;

typedef MutableVertexMesh<3,3 > MutableVertexMesh3_3;
class MutableVertexMesh3_3_Overloads : public MutableVertexMesh3_3{
    public:
    using MutableVertexMesh3_3::MutableVertexMesh<3, 3>;

        void SetNode(unsigned int nodeIndex, ::ChastePoint<3> point) override {
        PYBIND11_OVERLOAD(
        void,
        MutableVertexMesh3_3,
        SetNode,
        nodeIndex, 
        point        
        );
        }
        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MutableVertexMesh3_3,
        GetNumNodes,
        
        );
        }
        unsigned int GetNumElements() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MutableVertexMesh3_3,
        GetNumElements,
        
        );
        }
        void Clear() override {
        PYBIND11_OVERLOAD(
        void,
        MutableVertexMesh3_3,
        Clear,
        
        );
        }
        void ReMesh(::VertexElementMap & rElementMap) override {
        PYBIND11_OVERLOAD(
        void,
        MutableVertexMesh3_3,
        ReMesh,
        rElementMap        
        );
        }
        void IdentifySwapType(::Node<3> * pNodeA, ::Node<3> * pNodeB) override {
        PYBIND11_OVERLOAD(
        void,
        MutableVertexMesh3_3,
        IdentifySwapType,
        pNodeA, 
        pNodeB        
        );
        }
        void HandleHighOrderJunctions(::Node<3> * pNodeA, ::Node<3> * pNodeB) override {
        PYBIND11_OVERLOAD(
        void,
        MutableVertexMesh3_3,
        HandleHighOrderJunctions,
        pNodeA, 
        pNodeB        
        );
        }

};
void register_MutableVertexMesh3_3_class(py::module &m){
    py::class_<MutableVertexMesh3_3, MutableVertexMesh3_3_Overloads, std::shared_ptr<MutableVertexMesh3_3 >  >(m, "MutableVertexMesh3_3")
        .def(py::init<::std::vector<Node<3> *, std::allocator<Node<3> *> >, ::std::vector<VertexElement<3, 3> *, std::allocator<VertexElement<3, 3> *> >, double, double, double, double, double, double >())
        .def(py::init< >())
        .def("SetCellRearrangementThreshold", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetCellRearrangementThreshold, "" , py::arg("cellRearrangementThreshold"))
        .def("SetT2Threshold", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetT2Threshold, "" , py::arg("t2Threshold"))
        .def("SetCellRearrangementRatio", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetCellRearrangementRatio, "" , py::arg("cellRearrangementRatio"))
        .def("SetProtorosetteFormationProbability", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetProtorosetteFormationProbability, "" , py::arg("protorosetteFormationProbability"))
        .def("SetProtorosetteResolutionProbabilityPerTimestep", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetProtorosetteResolutionProbabilityPerTimestep, "" , py::arg("protorosetteResolutionProbabilityPerTimestep"))
        .def("SetRosetteResolutionProbabilityPerTimestep", (void (MutableVertexMesh3_3::*)(double)) &MutableVertexMesh3_3::SetRosetteResolutionProbabilityPerTimestep, "" , py::arg("rosetteResolutionProbabilityPerTimestep"))
        .def("SetNode", (void (MutableVertexMesh3_3::*)(unsigned int, ::ChastePoint<3>)) &MutableVertexMesh3_3::SetNode, "" , py::arg("nodeIndex"), py::arg("point"))
        .def("SetCheckForInternalIntersections", (void (MutableVertexMesh3_3::*)(bool)) &MutableVertexMesh3_3::SetCheckForInternalIntersections, "" , py::arg("checkForInternalIntersections"))
        .def("GetCellRearrangementThreshold", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetCellRearrangementThreshold, "" )
        .def("GetT2Threshold", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetT2Threshold, "" )
        .def("GetCellRearrangementRatio", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetCellRearrangementRatio, "" )
        .def("GetProtorosetteFormationProbability", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetProtorosetteFormationProbability, "" )
        .def("GetProtorosetteResolutionProbabilityPerTimestep", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetProtorosetteResolutionProbabilityPerTimestep, "" )
        .def("GetRosetteResolutionProbabilityPerTimestep", (double (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetRosetteResolutionProbabilityPerTimestep, "" )
        .def("GetNumNodes", (unsigned int (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetNumNodes, "" )
        .def("GetNumElements", (unsigned int (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetNumElements, "" )
        .def("GetCheckForInternalIntersections", (bool (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetCheckForInternalIntersections, "" )
        .def("GetLocationsOfT1Swaps", (::std::vector<boost::numeric::ublas::c_vector<double, 3>, std::allocator<boost::numeric::ublas::c_vector<double, 3> > > (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetLocationsOfT1Swaps, "" )
        .def("GetLastT2SwapLocation", (::boost::numeric::ublas::c_vector<double, 3> (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetLastT2SwapLocation, "" )
        .def("GetLocationsOfT3Swaps", (::std::vector<boost::numeric::ublas::c_vector<double, 3>, std::allocator<boost::numeric::ublas::c_vector<double, 3> > > (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::GetLocationsOfT3Swaps, "" )
        .def("ClearLocationsOfT1Swaps", (void (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::ClearLocationsOfT1Swaps, "" )
        .def("ClearLocationsOfT3Swaps", (void (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::ClearLocationsOfT3Swaps, "" )
        .def("AddNode", (unsigned int (MutableVertexMesh3_3::*)(::Node<3> *)) &MutableVertexMesh3_3::AddNode, "" , py::arg("pNewNode"))
        .def("DeleteElementPriorToReMesh", (void (MutableVertexMesh3_3::*)(unsigned int)) &MutableVertexMesh3_3::DeleteElementPriorToReMesh, "" , py::arg("index"))
        .def("DeleteNodePriorToReMesh", (void (MutableVertexMesh3_3::*)(unsigned int)) &MutableVertexMesh3_3::DeleteNodePriorToReMesh, "" , py::arg("index"))
        .def("DivideElementAlongShortAxis", (unsigned int (MutableVertexMesh3_3::*)(::VertexElement<3, 3> *, bool)) &MutableVertexMesh3_3::DivideElementAlongShortAxis, "" , py::arg("pElement"), py::arg("placeOriginalElementBelow") = false)
        .def("DivideElementAlongGivenAxis", (unsigned int (MutableVertexMesh3_3::*)(::VertexElement<3, 3> *, ::boost::numeric::ublas::c_vector<double, 3>, bool)) &MutableVertexMesh3_3::DivideElementAlongGivenAxis, "" , py::arg("pElement"), py::arg("axisOfDivision"), py::arg("placeOriginalElementBelow") = false)
        .def("AddElement", (unsigned int (MutableVertexMesh3_3::*)(::VertexElement<3, 3> *)) &MutableVertexMesh3_3::AddElement, "" , py::arg("pNewElement"))
        .def("CheckForT2Swaps", (bool (MutableVertexMesh3_3::*)(::VertexElementMap &)) &MutableVertexMesh3_3::CheckForT2Swaps, "" , py::arg("rElementMap"))
        .def("Clear", (void (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::Clear, "" )
        .def("DivideEdge", (void (MutableVertexMesh3_3::*)(::Node<3> *, ::Node<3> *)) &MutableVertexMesh3_3::DivideEdge, "" , py::arg("pNodeA"), py::arg("pNodeB"))
        .def("RemoveDeletedNodesAndElements", (void (MutableVertexMesh3_3::*)(::VertexElementMap &)) &MutableVertexMesh3_3::RemoveDeletedNodesAndElements, "" , py::arg("rElementMap"))
        .def("RemoveDeletedNodes", (void (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::RemoveDeletedNodes, "" )
        .def("ReMesh", (void (MutableVertexMesh3_3::*)(::VertexElementMap &)) &MutableVertexMesh3_3::ReMesh, "" , py::arg("rElementMap"))
        .def("ReMesh", (void (MutableVertexMesh3_3::*)()) &MutableVertexMesh3_3::ReMesh, "" )
    ;
}
