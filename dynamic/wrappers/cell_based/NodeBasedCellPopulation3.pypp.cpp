#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "NodeBasedCellPopulation3.pypp.hpp"

namespace py = pybind11;

typedef NodeBasedCellPopulation<3 > NodeBasedCellPopulation3;
class NodeBasedCellPopulation3_Overloads : public NodeBasedCellPopulation3{
    public:
    using NodeBasedCellPopulation3::NodeBasedCellPopulation<3>;

        void SetNode(unsigned int nodeIndex, ::ChastePoint<3> & rNewLocation) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        SetNode,
        nodeIndex, 
        rNewLocation        
        );
        }
        ::TetrahedralMesh<3, 3> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
        ::TetrahedralMesh<3, 3> *,
        NodeBasedCellPopulation3,
        GetTetrahedralMeshForPdeModifier,
        
        );
        }
        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        NodeBasedCellPopulation3,
        GetNumNodes,
        
        );
        }
        ::CellPtr GetCellUsingLocationIndex(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::CellPtr,
        NodeBasedCellPopulation3,
        GetCellUsingLocationIndex,
        index        
        );
        }
        ::Node<3> * GetNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::Node<3> *,
        NodeBasedCellPopulation3,
        GetNode,
        index        
        );
        }
        unsigned int RemoveDeadCells() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        NodeBasedCellPopulation3,
        RemoveDeadCells,
        
        );
        }
        void Update(bool hasHadBirthsOrDeaths) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        Update,
        hasHadBirthsOrDeaths        
        );
        }
        ::std::vector<std::pair<Node<3> *, Node<3> *>, std::allocator<std::pair<Node<3> *, Node<3> *> > > & rGetNodePairs() override {
        PYBIND11_OVERLOAD(
        ::std::vector<std::pair<Node<3> *, Node<3> *>, std::allocator<std::pair<Node<3> *, Node<3> *> > > &,
        NodeBasedCellPopulation3,
        rGetNodePairs,
        
        );
        }
        void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        OutputCellPopulationParameters,
        rParamsFile        
        );
        }
        void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> > pPopulationWriter) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        AcceptPopulationWriter,
        pPopulationWriter        
        );
        }
        void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> > pPopulationCountWriter) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        AcceptPopulationCountWriter,
        pPopulationCountWriter        
        );
        }
        void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<3, 3> > pCellWriter, ::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        AcceptCellWriter,
        pCellWriter, 
        pCell        
        );
        }
        double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
        double,
        NodeBasedCellPopulation3,
        GetWidth,
        rDimension        
        );
        }
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringNodeIndices(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >,
        NodeBasedCellPopulation3,
        GetNeighbouringNodeIndices,
        index        
        );
        }
        ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
        ::CellPtr,
        NodeBasedCellPopulation3,
        AddCell,
        pNewCell, 
        pParentCell        
        );
        }
        double GetVolumeOfCell(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        double,
        NodeBasedCellPopulation3,
        GetVolumeOfCell,
        pCell        
        );
        }
        void UpdateCellProcessLocation() override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        UpdateCellProcessLocation,
        
        );
        }
        void UpdateParticlesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        UpdateParticlesAfterReMesh,
        rMap        
        );
        }
        void Validate() override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        Validate,
        
        );
        }
        unsigned int AddNode(::Node<3> * pNewNode) override {
        PYBIND11_OVERLOAD(
        unsigned int,
        NodeBasedCellPopulation3,
        AddNode,
        pNewNode        
        );
        }
        void WriteVtkResultsToFile(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        NodeBasedCellPopulation3,
        WriteVtkResultsToFile,
        rDirectory        
        );
        }

};
void register_NodeBasedCellPopulation3_class(py::module &m){
    py::class_<NodeBasedCellPopulation3, NodeBasedCellPopulation3_Overloads, std::shared_ptr<NodeBasedCellPopulation3 >  >(m, "NodeBasedCellPopulation3")
        .def(py::init<::NodesOnlyMesh<3> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, bool >())
        .def(py::init<::NodesOnlyMesh<3> & >())
        .def("SetNode", (void (NodeBasedCellPopulation3::*)(unsigned int, ::ChastePoint<3> &)) &NodeBasedCellPopulation3::SetNode, "" , py::arg("nodeIndex"), py::arg("rNewLocation"))
        .def("GetNumNodes", (unsigned int (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::GetNumNodes, "" )
        .def("GetCellUsingLocationIndex", (::CellPtr (NodeBasedCellPopulation3::*)(unsigned int)) &NodeBasedCellPopulation3::GetCellUsingLocationIndex, "" , py::arg("index"))
        .def("GetNode", (::Node<3> * (NodeBasedCellPopulation3::*)(unsigned int)) &NodeBasedCellPopulation3::GetNode, "" , py::arg("index"))
        .def("RemoveDeadCells", (unsigned int (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::RemoveDeadCells, "" )
        .def("Clear", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::Clear, "" )
        .def("Update", (void (NodeBasedCellPopulation3::*)(bool)) &NodeBasedCellPopulation3::Update, "" , py::arg("hasHadBirthsOrDeaths") = true)
        .def("OutputCellPopulationParameters", (void (NodeBasedCellPopulation3::*)(::out_stream &)) &NodeBasedCellPopulation3::OutputCellPopulationParameters, "" , py::arg("rParamsFile"))
        .def("AcceptPopulationWriter", (void (NodeBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> >)) &NodeBasedCellPopulation3::AcceptPopulationWriter, "" , py::arg("pPopulationWriter"))
        .def("AcceptPopulationCountWriter", (void (NodeBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> >)) &NodeBasedCellPopulation3::AcceptPopulationCountWriter, "" , py::arg("pPopulationCountWriter"))
        .def("AcceptCellWriter", (void (NodeBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellWriter<3, 3> >, ::CellPtr)) &NodeBasedCellPopulation3::AcceptCellWriter, "" , py::arg("pCellWriter"), py::arg("pCell"))
        .def("GetMechanicsCutOffLength", (double (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::GetMechanicsCutOffLength, "" )
        .def("GetUseVariableRadii", (bool (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::GetUseVariableRadii, "" )
        .def("SetUseVariableRadii", (void (NodeBasedCellPopulation3::*)(bool)) &NodeBasedCellPopulation3::SetUseVariableRadii, "" , py::arg("useVariableRadii") = true)
        .def("SetLoadBalanceMesh", (void (NodeBasedCellPopulation3::*)(bool)) &NodeBasedCellPopulation3::SetLoadBalanceMesh, "" , py::arg("loadBalanceMesh"))
        .def("SetLoadBalanceFrequency", (void (NodeBasedCellPopulation3::*)(unsigned int)) &NodeBasedCellPopulation3::SetLoadBalanceFrequency, "" , py::arg("loadBalanceFrequency"))
        .def("GetWidth", (double (NodeBasedCellPopulation3::*)(unsigned int const &)) &NodeBasedCellPopulation3::GetWidth, "" , py::arg("rDimension"))
        .def("GetSizeOfCellPopulation", (::boost::numeric::ublas::c_vector<double, 3> (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::GetSizeOfCellPopulation, "" )
        .def("GetNodesWithinNeighbourhoodRadius", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (NodeBasedCellPopulation3::*)(unsigned int, double)) &NodeBasedCellPopulation3::GetNodesWithinNeighbourhoodRadius, "" , py::arg("index"), py::arg("neighbourhoodRadius"))
        .def("GetNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (NodeBasedCellPopulation3::*)(unsigned int)) &NodeBasedCellPopulation3::GetNeighbouringNodeIndices, "" , py::arg("index"))
        .def("AddCell", (::CellPtr (NodeBasedCellPopulation3::*)(::CellPtr, ::CellPtr)) &NodeBasedCellPopulation3::AddCell, "" , py::arg("pNewCell"), py::arg("pParentCell"))
        .def("GetVolumeOfCell", (double (NodeBasedCellPopulation3::*)(::CellPtr)) &NodeBasedCellPopulation3::GetVolumeOfCell, "" , py::arg("pCell"))
        .def("SendCellsToNeighbourProcesses", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::SendCellsToNeighbourProcesses, "" )
        .def("NonBlockingSendCellsToNeighbourProcesses", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::NonBlockingSendCellsToNeighbourProcesses, "" )
        .def("GetReceivedCells", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::GetReceivedCells, "" )
        .def("GetCellNodePair", (::std::pair<boost::shared_ptr<Cell>, Node<3> *> (NodeBasedCellPopulation3::*)(unsigned int)) &NodeBasedCellPopulation3::GetCellNodePair, "" , py::arg("nodeIndex"))
        .def("AddReceivedCells", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::AddReceivedCells, "" )
        .def("UpdateCellProcessLocation", (void (NodeBasedCellPopulation3::*)()) &NodeBasedCellPopulation3::UpdateCellProcessLocation, "" )
    ;
}
