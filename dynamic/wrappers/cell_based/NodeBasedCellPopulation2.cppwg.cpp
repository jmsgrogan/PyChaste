#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "CellLabelWriter.hpp"
#include "VoronoiDataWriter.hpp"
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "NodeBasedCellPopulation.hpp"

#include "NodeBasedCellPopulation2.cppwg.hpp"

namespace py = pybind11;
typedef NodeBasedCellPopulation<2 > NodeBasedCellPopulation2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::TetrahedralMesh<2, 2> * _TetrahedralMesh_lt_2_2_gt_Ptr;
typedef unsigned int unsignedint;
typedef ::CellPtr _CellPtr;
typedef ::Node<2> * _Node_lt_2_gt_Ptr;
typedef unsigned int unsignedint;
typedef ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & _std_vector_lt_std_pair_lt_Node_lt_2_gt_Ptr_Node_lt_2_gt_Ptr_gt__std_allocator_lt_std_pair_lt_Node_lt_2_gt_Ptr_Node_lt_2_gt_Ptr_gt__gt__gt_Ref;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_;
typedef ::CellPtr _CellPtr;
typedef unsigned int unsignedint;

class NodeBasedCellPopulation2_Overloads : public NodeBasedCellPopulation2{
    public:
    using NodeBasedCellPopulation2::NodeBasedCellPopulation;
    void SetNode(unsigned int nodeIndex, ::ChastePoint<2> & rNewLocation) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            SetNode,
            nodeIndex, 
rNewLocation);
    }
    ::TetrahedralMesh<2, 2> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
            _TetrahedralMesh_lt_2_2_gt_Ptr,
            NodeBasedCellPopulation2,
            GetTetrahedralMeshForPdeModifier,
            );
    }
    unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodeBasedCellPopulation2,
            GetNumNodes,
            );
    }
    ::CellPtr GetCellUsingLocationIndex(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _CellPtr,
            NodeBasedCellPopulation2,
            GetCellUsingLocationIndex,
            index);
    }
    ::Node<2> * GetNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _Node_lt_2_gt_Ptr,
            NodeBasedCellPopulation2,
            GetNode,
            index);
    }
    unsigned int RemoveDeadCells() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            NodeBasedCellPopulation2,
            RemoveDeadCells,
            );
    }
    void Update(bool hasHadBirthsOrDeaths) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            Update,
            hasHadBirthsOrDeaths);
    }
    ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & rGetNodePairs() override {
        PYBIND11_OVERLOAD(
            _std_vector_lt_std_pair_lt_Node_lt_2_gt_Ptr_Node_lt_2_gt_Ptr_gt__std_allocator_lt_std_pair_lt_Node_lt_2_gt_Ptr_Node_lt_2_gt_Ptr_gt__gt__gt_Ref,
            NodeBasedCellPopulation2,
            rGetNodePairs,
            );
    }
    void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            OutputCellPopulationParameters,
            rParamsFile);
    }
    void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> > pPopulationWriter) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            AcceptPopulationWriter,
            pPopulationWriter);
    }
    void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> > pPopulationCountWriter) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            AcceptPopulationCountWriter,
            pPopulationCountWriter);
    }
    void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<2, 2> > pCellWriter, ::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            AcceptCellWriter,
            pCellWriter, 
pCell);
    }
    double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
            double,
            NodeBasedCellPopulation2,
            GetWidth,
            rDimension);
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringNodeIndices(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_,
            NodeBasedCellPopulation2,
            GetNeighbouringNodeIndices,
            index);
    }
    ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
            _CellPtr,
            NodeBasedCellPopulation2,
            AddCell,
            pNewCell, 
pParentCell);
    }
    double GetVolumeOfCell(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            double,
            NodeBasedCellPopulation2,
            GetVolumeOfCell,
            pCell);
    }
    void UpdateCellProcessLocation() override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            UpdateCellProcessLocation,
            );
    }
    void UpdateParticlesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            UpdateParticlesAfterReMesh,
            rMap);
    }
    void Validate() override {
        PYBIND11_OVERLOAD(
            void,
            NodeBasedCellPopulation2,
            Validate,
            );
    }

};
void register_NodeBasedCellPopulation2_class(py::module &m){
py::class_<NodeBasedCellPopulation2 , NodeBasedCellPopulation2_Overloads , boost::shared_ptr<NodeBasedCellPopulation2 >  , AbstractCentreBasedCellPopulation<2, 2>  >(m, "NodeBasedCellPopulation2")
        .def(py::init<::NodesOnlyMesh<2> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, bool >(), py::arg("rMesh"), py::arg("rCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("deleteMesh") = false, py::arg("validate") = true)
        .def(py::init<::NodesOnlyMesh<2> & >(), py::arg("rMesh"))
        .def(
            "SetNode", 
            (void(NodeBasedCellPopulation2::*)(unsigned int, ::ChastePoint<2> &)) &NodeBasedCellPopulation2::SetNode, 
            " " , py::arg("nodeIndex"), py::arg("rNewLocation") )
        .def(
            "GetNumNodes", 
            (unsigned int(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::GetNumNodes, 
            " "  )
        .def(
            "GetCellUsingLocationIndex", 
            (::CellPtr(NodeBasedCellPopulation2::*)(unsigned int)) &NodeBasedCellPopulation2::GetCellUsingLocationIndex, 
            " " , py::arg("index") )
        .def(
            "GetNode", 
            (::Node<2> *(NodeBasedCellPopulation2::*)(unsigned int)) &NodeBasedCellPopulation2::GetNode, 
            " " , py::arg("index") , py::return_value_policy::reference)
        .def(
            "RemoveDeadCells", 
            (unsigned int(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::RemoveDeadCells, 
            " "  )
        .def(
            "Clear", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::Clear, 
            " "  )
        .def(
            "Update", 
            (void(NodeBasedCellPopulation2::*)(bool)) &NodeBasedCellPopulation2::Update, 
            " " , py::arg("hasHadBirthsOrDeaths") = true )
        .def(
            "OutputCellPopulationParameters", 
            (void(NodeBasedCellPopulation2::*)(::out_stream &)) &NodeBasedCellPopulation2::OutputCellPopulationParameters, 
            " " , py::arg("rParamsFile") )
        .def(
            "AcceptPopulationWriter", 
            (void(NodeBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> >)) &NodeBasedCellPopulation2::AcceptPopulationWriter, 
            " " , py::arg("pPopulationWriter") )
        .def(
            "AcceptPopulationCountWriter", 
            (void(NodeBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> >)) &NodeBasedCellPopulation2::AcceptPopulationCountWriter, 
            " " , py::arg("pPopulationCountWriter") )
        .def(
            "AcceptCellWriter", 
            (void(NodeBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellWriter<2, 2> >, ::CellPtr)) &NodeBasedCellPopulation2::AcceptCellWriter, 
            " " , py::arg("pCellWriter"), py::arg("pCell") )
        .def(
            "GetMechanicsCutOffLength", 
            (double(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::GetMechanicsCutOffLength, 
            " "  )
        .def(
            "GetUseVariableRadii", 
            (bool(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::GetUseVariableRadii, 
            " "  )
        .def(
            "SetUseVariableRadii", 
            (void(NodeBasedCellPopulation2::*)(bool)) &NodeBasedCellPopulation2::SetUseVariableRadii, 
            " " , py::arg("useVariableRadii") = true )
        .def(
            "SetLoadBalanceMesh", 
            (void(NodeBasedCellPopulation2::*)(bool)) &NodeBasedCellPopulation2::SetLoadBalanceMesh, 
            " " , py::arg("loadBalanceMesh") )
        .def(
            "SetLoadBalanceFrequency", 
            (void(NodeBasedCellPopulation2::*)(unsigned int)) &NodeBasedCellPopulation2::SetLoadBalanceFrequency, 
            " " , py::arg("loadBalanceFrequency") )
        .def(
            "GetWidth", 
            (double(NodeBasedCellPopulation2::*)(unsigned int const &)) &NodeBasedCellPopulation2::GetWidth, 
            " " , py::arg("rDimension") )
        .def(
            "GetSizeOfCellPopulation", 
            (::boost::numeric::ublas::c_vector<double, 2>(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::GetSizeOfCellPopulation, 
            " "  )
        .def(
            "GetNodesWithinNeighbourhoodRadius", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(NodeBasedCellPopulation2::*)(unsigned int, double)) &NodeBasedCellPopulation2::GetNodesWithinNeighbourhoodRadius, 
            " " , py::arg("index"), py::arg("neighbourhoodRadius") )
        .def(
            "GetNeighbouringNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(NodeBasedCellPopulation2::*)(unsigned int)) &NodeBasedCellPopulation2::GetNeighbouringNodeIndices, 
            " " , py::arg("index") )
        .def(
            "AddCell", 
            (::CellPtr(NodeBasedCellPopulation2::*)(::CellPtr, ::CellPtr)) &NodeBasedCellPopulation2::AddCell, 
            " " , py::arg("pNewCell"), py::arg("pParentCell") )
        .def(
            "GetVolumeOfCell", 
            (double(NodeBasedCellPopulation2::*)(::CellPtr)) &NodeBasedCellPopulation2::GetVolumeOfCell, 
            " " , py::arg("pCell") )
        .def(
            "SendCellsToNeighbourProcesses", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::SendCellsToNeighbourProcesses, 
            " "  )
        .def(
            "NonBlockingSendCellsToNeighbourProcesses", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::NonBlockingSendCellsToNeighbourProcesses, 
            " "  )
        .def(
            "GetReceivedCells", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::GetReceivedCells, 
            " "  )
        .def(
            "GetCellNodePair", 
            (::std::pair<boost::shared_ptr<Cell>, Node<2> *>(NodeBasedCellPopulation2::*)(unsigned int)) &NodeBasedCellPopulation2::GetCellNodePair, 
            " " , py::arg("nodeIndex") )
        .def(
            "AddReceivedCells", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::AddReceivedCells, 
            " "  )
        .def(
            "UpdateCellProcessLocation", 
            (void(NodeBasedCellPopulation2::*)()) &NodeBasedCellPopulation2::UpdateCellProcessLocation, 
            " "  )
        .def("AddPopulationWriterVoronoiDataWriter", &NodeBasedCellPopulation2::AddPopulationWriter<VoronoiDataWriter>)
        .def("AddCellWriterCellLabelWriter", &NodeBasedCellPopulation2::AddCellWriter<CellLabelWriter>)
    ;
}
