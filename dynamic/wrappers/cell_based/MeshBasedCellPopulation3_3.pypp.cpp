#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "MeshBasedCellPopulation3_3.pypp.hpp"

namespace py = pybind11;

typedef MeshBasedCellPopulation<3,3 > MeshBasedCellPopulation3_3;
class MeshBasedCellPopulation3_3_Overloads : public MeshBasedCellPopulation3_3{
    public:
    using MeshBasedCellPopulation3_3::MeshBasedCellPopulation<3, 3>;

        ::TetrahedralMesh<3, 3> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
        ::TetrahedralMesh<3, 3> *,
        MeshBasedCellPopulation3_3,
        GetTetrahedralMeshForPdeModifier,
        
        );
        }
        unsigned int AddNode(::Node<3> * pNewNode) override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation3_3,
        AddNode,
        pNewNode        
        );
        }
        void SetNode(unsigned int nodeIndex, ::ChastePoint<3> & rNewLocation) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        SetNode,
        nodeIndex, 
        rNewLocation        
        );
        }
        double GetDampingConstant(unsigned int nodeIndex) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation3_3,
        GetDampingConstant,
        nodeIndex        
        );
        }
        void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        OpenWritersFiles,
        rOutputFileHandler        
        );
        }
        unsigned int RemoveDeadCells() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation3_3,
        RemoveDeadCells,
        
        );
        }
        ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
        ::CellPtr,
        MeshBasedCellPopulation3_3,
        AddCell,
        pNewCell, 
        pParentCell        
        );
        }
        void WriteResultsToFiles(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        WriteResultsToFiles,
        rDirectory        
        );
        }
        void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> > pPopulationWriter) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        AcceptPopulationWriter,
        pPopulationWriter        
        );
        }
        void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> > pPopulationCountWriter) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        AcceptPopulationCountWriter,
        pPopulationCountWriter        
        );
        }
        void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<3, 3> > pCellWriter, ::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        AcceptCellWriter,
        pCellWriter, 
        pCell        
        );
        }
        void Update(bool hasHadBirthsOrDeaths) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        Update,
        hasHadBirthsOrDeaths        
        );
        }
        ::Node<3> * GetNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::Node<3> *,
        MeshBasedCellPopulation3_3,
        GetNode,
        index        
        );
        }
        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation3_3,
        GetNumNodes,
        
        );
        }
        void WriteVtkResultsToFile(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        WriteVtkResultsToFile,
        rDirectory        
        );
        }
        double GetVolumeOfCell(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation3_3,
        GetVolumeOfCell,
        pCell        
        );
        }
        double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation3_3,
        GetWidth,
        rDimension        
        );
        }
        void WriteDataToVisualizerSetupFile(::out_stream & pVizSetupFile) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        WriteDataToVisualizerSetupFile,
        pVizSetupFile        
        );
        }
        ::std::vector<std::pair<Node<3> *, Node<3> *>, std::allocator<std::pair<Node<3> *, Node<3> *> > > & rGetNodePairs() override {
        PYBIND11_OVERLOAD(
        ::std::vector<std::pair<Node<3> *, Node<3> *>, std::allocator<std::pair<Node<3> *, Node<3> *> > > &,
        MeshBasedCellPopulation3_3,
        rGetNodePairs,
        
        );
        }
        void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        OutputCellPopulationParameters,
        rParamsFile        
        );
        }
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringNodeIndices(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >,
        MeshBasedCellPopulation3_3,
        GetNeighbouringNodeIndices,
        index        
        );
        }
        void UpdateGhostNodesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        UpdateGhostNodesAfterReMesh,
        rMap        
        );
        }
        void Validate() override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation3_3,
        Validate,
        
        );
        }

};
void register_MeshBasedCellPopulation3_3_class(py::module &m){
    py::class_<MeshBasedCellPopulation3_3, MeshBasedCellPopulation3_3_Overloads, std::shared_ptr<MeshBasedCellPopulation3_3 >  >(m, "MeshBasedCellPopulation3_3")
        .def(py::init<::MutableMesh<3, 3> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, bool >())
        .def(py::init<::MutableMesh<3, 3> & >())
        .def(py::init<::MeshBasedCellPopulation<3, 3> &, ::TetrahedralMesh<3, 3>::EdgeIterator >())
        .def("GetTetrahedralMeshForPdeModifier", (::TetrahedralMesh<3, 3> * (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetTetrahedralMeshForPdeModifier, "" )
        .def("UseAreaBasedDampingConstant", (bool (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::UseAreaBasedDampingConstant, "" )
        .def("AddNode", (unsigned int (MeshBasedCellPopulation3_3::*)(::Node<3> *)) &MeshBasedCellPopulation3_3::AddNode, "" , py::arg("pNewNode"))
        .def("SetNode", (void (MeshBasedCellPopulation3_3::*)(unsigned int, ::ChastePoint<3> &)) &MeshBasedCellPopulation3_3::SetNode, "" , py::arg("nodeIndex"), py::arg("rNewLocation"))
        .def("GetDampingConstant", (double (MeshBasedCellPopulation3_3::*)(unsigned int)) &MeshBasedCellPopulation3_3::GetDampingConstant, "" , py::arg("nodeIndex"))
        .def("SetAreaBasedDampingConstant", (void (MeshBasedCellPopulation3_3::*)(bool)) &MeshBasedCellPopulation3_3::SetAreaBasedDampingConstant, "" , py::arg("useAreaBasedDampingConstant"))
        .def("OpenWritersFiles", (void (MeshBasedCellPopulation3_3::*)(::OutputFileHandler &)) &MeshBasedCellPopulation3_3::OpenWritersFiles, "" , py::arg("rOutputFileHandler"))
        .def("RemoveDeadCells", (unsigned int (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::RemoveDeadCells, "" )
        .def("AddCell", (::CellPtr (MeshBasedCellPopulation3_3::*)(::CellPtr, ::CellPtr)) &MeshBasedCellPopulation3_3::AddCell, "" , py::arg("pNewCell"), py::arg("pParentCell"))
        .def("WriteResultsToFiles", (void (MeshBasedCellPopulation3_3::*)(::std::string const &)) &MeshBasedCellPopulation3_3::WriteResultsToFiles, "" , py::arg("rDirectory"))
        .def("AcceptPopulationWriter", (void (MeshBasedCellPopulation3_3::*)(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> >)) &MeshBasedCellPopulation3_3::AcceptPopulationWriter, "" , py::arg("pPopulationWriter"))
        .def("AcceptPopulationCountWriter", (void (MeshBasedCellPopulation3_3::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> >)) &MeshBasedCellPopulation3_3::AcceptPopulationCountWriter, "" , py::arg("pPopulationCountWriter"))
        .def("AcceptCellWriter", (void (MeshBasedCellPopulation3_3::*)(::boost::shared_ptr<AbstractCellWriter<3, 3> >, ::CellPtr)) &MeshBasedCellPopulation3_3::AcceptCellWriter, "" , py::arg("pCellWriter"), py::arg("pCell"))
        .def("Update", (void (MeshBasedCellPopulation3_3::*)(bool)) &MeshBasedCellPopulation3_3::Update, "" , py::arg("hasHadBirthsOrDeaths") = true)
        .def("TessellateIfNeeded", (void (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::TessellateIfNeeded, "" )
        .def("DivideLongSprings", (void (MeshBasedCellPopulation3_3::*)(double)) &MeshBasedCellPopulation3_3::DivideLongSprings, "" , py::arg("springDivisionThreshold"))
        .def("GetNode", (::Node<3> * (MeshBasedCellPopulation3_3::*)(unsigned int)) &MeshBasedCellPopulation3_3::GetNode, "" , py::arg("index"))
        .def("GetNumNodes", (unsigned int (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetNumNodes, "" )
        .def("WriteVtkResultsToFile", (void (MeshBasedCellPopulation3_3::*)(::std::string const &)) &MeshBasedCellPopulation3_3::WriteVtkResultsToFile, "" , py::arg("rDirectory"))
        .def("GetVolumeOfCell", (double (MeshBasedCellPopulation3_3::*)(::CellPtr)) &MeshBasedCellPopulation3_3::GetVolumeOfCell, "" , py::arg("pCell"))
        .def("CreateVoronoiTessellation", (void (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::CreateVoronoiTessellation, "" )
        .def("GetVoronoiTessellation", (::VertexMesh<3, 3> * (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetVoronoiTessellation, "" )
        .def("GetVolumeOfVoronoiElement", (double (MeshBasedCellPopulation3_3::*)(unsigned int)) &MeshBasedCellPopulation3_3::GetVolumeOfVoronoiElement, "" , py::arg("index"))
        .def("GetSurfaceAreaOfVoronoiElement", (double (MeshBasedCellPopulation3_3::*)(unsigned int)) &MeshBasedCellPopulation3_3::GetSurfaceAreaOfVoronoiElement, "" , py::arg("index"))
        .def("GetVoronoiEdgeLength", (double (MeshBasedCellPopulation3_3::*)(unsigned int, unsigned int)) &MeshBasedCellPopulation3_3::GetVoronoiEdgeLength, "" , py::arg("index1"), py::arg("index2"))
        .def("GetWidth", (double (MeshBasedCellPopulation3_3::*)(unsigned int const &)) &MeshBasedCellPopulation3_3::GetWidth, "" , py::arg("rDimension"))
        .def("WriteDataToVisualizerSetupFile", (void (MeshBasedCellPopulation3_3::*)(::out_stream &)) &MeshBasedCellPopulation3_3::WriteDataToVisualizerSetupFile, "" , py::arg("pVizSetupFile"))
        .def("GetNodeA", (::Node<3> * (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetNodeA, "" )
        .def("GetNodeB", (::Node<3> * (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetNodeB, "" )
        .def("GetCellA", (::CellPtr (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetCellA, "" )
        .def("GetCellB", (::CellPtr (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetCellB, "" )
        .def("SpringsBegin", (::MeshBasedCellPopulation<3, 3>::SpringIterator (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::SpringsBegin, "" )
        .def("SpringsEnd", (::MeshBasedCellPopulation<3, 3>::SpringIterator (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::SpringsEnd, "" )
        .def("CheckCellPointers", (void (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::CheckCellPointers, "" )
        .def("GetAreaBasedDampingConstantParameter", (double (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetAreaBasedDampingConstantParameter, "" )
        .def("SetAreaBasedDampingConstantParameter", (void (MeshBasedCellPopulation3_3::*)(double)) &MeshBasedCellPopulation3_3::SetAreaBasedDampingConstantParameter, "" , py::arg("areaBasedDampingConstantParameter"))
        .def("rGetNodePairs", (::std::vector<std::pair<Node<3> *, Node<3> *>, std::allocator<std::pair<Node<3> *, Node<3> *> > > & (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::rGetNodePairs, "" )
        .def("OutputCellPopulationParameters", (void (MeshBasedCellPopulation3_3::*)(::out_stream &)) &MeshBasedCellPopulation3_3::OutputCellPopulationParameters, "" , py::arg("rParamsFile"))
        .def("SetWriteVtkAsPoints", (void (MeshBasedCellPopulation3_3::*)(bool)) &MeshBasedCellPopulation3_3::SetWriteVtkAsPoints, "" , py::arg("writeVtkAsPoints"))
        .def("GetWriteVtkAsPoints", (bool (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetWriteVtkAsPoints, "" )
        .def("SetOutputMeshInVtk", (void (MeshBasedCellPopulation3_3::*)(bool)) &MeshBasedCellPopulation3_3::SetOutputMeshInVtk, "" , py::arg("outputMeshInVtk"))
        .def("GetOutputMeshInVtk", (bool (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::GetOutputMeshInVtk, "" )
        .def("GetNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (MeshBasedCellPopulation3_3::*)(unsigned int)) &MeshBasedCellPopulation3_3::GetNeighbouringNodeIndices, "" , py::arg("index"))
        .def("CalculateRestLengths", (void (MeshBasedCellPopulation3_3::*)()) &MeshBasedCellPopulation3_3::CalculateRestLengths, "" )
        .def("GetRestLength", (double (MeshBasedCellPopulation3_3::*)(unsigned int, unsigned int)) &MeshBasedCellPopulation3_3::GetRestLength, "" , py::arg("indexA"), py::arg("indexB"))
        .def("SetRestLength", (void (MeshBasedCellPopulation3_3::*)(unsigned int, unsigned int, double)) &MeshBasedCellPopulation3_3::SetRestLength, "" , py::arg("indexA"), py::arg("indexB"), py::arg("restLength"))
    ;
}
