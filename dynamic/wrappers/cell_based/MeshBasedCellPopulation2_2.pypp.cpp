#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "MeshBasedCellPopulation2_2.pypp.hpp"

namespace py = pybind11;

typedef MeshBasedCellPopulation<2,2 > MeshBasedCellPopulation2_2;
class MeshBasedCellPopulation2_2_Overloads : public MeshBasedCellPopulation2_2{
    public:
    using MeshBasedCellPopulation2_2::MeshBasedCellPopulation<2, 2>;

        ::TetrahedralMesh<2, 2> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
        ::TetrahedralMesh<2, 2> *,
        MeshBasedCellPopulation2_2,
        GetTetrahedralMeshForPdeModifier,
        
        );
        }
        unsigned int AddNode(::Node<2> * pNewNode) override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation2_2,
        AddNode,
        pNewNode        
        );
        }
        void SetNode(unsigned int nodeIndex, ::ChastePoint<2> & rNewLocation) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        SetNode,
        nodeIndex, 
        rNewLocation        
        );
        }
        double GetDampingConstant(unsigned int nodeIndex) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation2_2,
        GetDampingConstant,
        nodeIndex        
        );
        }
        void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        OpenWritersFiles,
        rOutputFileHandler        
        );
        }
        unsigned int RemoveDeadCells() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation2_2,
        RemoveDeadCells,
        
        );
        }
        ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
        ::CellPtr,
        MeshBasedCellPopulation2_2,
        AddCell,
        pNewCell, 
        pParentCell        
        );
        }
        void WriteResultsToFiles(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        WriteResultsToFiles,
        rDirectory        
        );
        }
        void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> > pPopulationWriter) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        AcceptPopulationWriter,
        pPopulationWriter        
        );
        }
        void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> > pPopulationCountWriter) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        AcceptPopulationCountWriter,
        pPopulationCountWriter        
        );
        }
        void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<2, 2> > pCellWriter, ::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        AcceptCellWriter,
        pCellWriter, 
        pCell        
        );
        }
        void Update(bool hasHadBirthsOrDeaths) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        Update,
        hasHadBirthsOrDeaths        
        );
        }
        ::Node<2> * GetNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::Node<2> *,
        MeshBasedCellPopulation2_2,
        GetNode,
        index        
        );
        }
        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        MeshBasedCellPopulation2_2,
        GetNumNodes,
        
        );
        }
        void WriteVtkResultsToFile(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        WriteVtkResultsToFile,
        rDirectory        
        );
        }
        double GetVolumeOfCell(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation2_2,
        GetVolumeOfCell,
        pCell        
        );
        }
        double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
        double,
        MeshBasedCellPopulation2_2,
        GetWidth,
        rDimension        
        );
        }
        void WriteDataToVisualizerSetupFile(::out_stream & pVizSetupFile) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        WriteDataToVisualizerSetupFile,
        pVizSetupFile        
        );
        }
        ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & rGetNodePairs() override {
        PYBIND11_OVERLOAD(
        ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > &,
        MeshBasedCellPopulation2_2,
        rGetNodePairs,
        
        );
        }
        void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        OutputCellPopulationParameters,
        rParamsFile        
        );
        }
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringNodeIndices(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >,
        MeshBasedCellPopulation2_2,
        GetNeighbouringNodeIndices,
        index        
        );
        }
        void UpdateGhostNodesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        UpdateGhostNodesAfterReMesh,
        rMap        
        );
        }
        void Validate() override {
        PYBIND11_OVERLOAD(
        void,
        MeshBasedCellPopulation2_2,
        Validate,
        
        );
        }

};
void register_MeshBasedCellPopulation2_2_class(py::module &m){
    py::class_<MeshBasedCellPopulation2_2, MeshBasedCellPopulation2_2_Overloads, std::shared_ptr<MeshBasedCellPopulation2_2 >  >(m, "MeshBasedCellPopulation2_2")
        .def(py::init<::MutableMesh<2, 2> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, bool >())
        .def(py::init<::MutableMesh<2, 2> & >())
        .def(py::init<::MeshBasedCellPopulation<2, 2> &, ::TetrahedralMesh<2, 2>::EdgeIterator >())
        .def("GetTetrahedralMeshForPdeModifier", (::TetrahedralMesh<2, 2> * (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetTetrahedralMeshForPdeModifier, "" )
        .def("UseAreaBasedDampingConstant", (bool (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::UseAreaBasedDampingConstant, "" )
        .def("AddNode", (unsigned int (MeshBasedCellPopulation2_2::*)(::Node<2> *)) &MeshBasedCellPopulation2_2::AddNode, "" , py::arg("pNewNode"))
        .def("SetNode", (void (MeshBasedCellPopulation2_2::*)(unsigned int, ::ChastePoint<2> &)) &MeshBasedCellPopulation2_2::SetNode, "" , py::arg("nodeIndex"), py::arg("rNewLocation"))
        .def("GetDampingConstant", (double (MeshBasedCellPopulation2_2::*)(unsigned int)) &MeshBasedCellPopulation2_2::GetDampingConstant, "" , py::arg("nodeIndex"))
        .def("SetAreaBasedDampingConstant", (void (MeshBasedCellPopulation2_2::*)(bool)) &MeshBasedCellPopulation2_2::SetAreaBasedDampingConstant, "" , py::arg("useAreaBasedDampingConstant"))
        .def("OpenWritersFiles", (void (MeshBasedCellPopulation2_2::*)(::OutputFileHandler &)) &MeshBasedCellPopulation2_2::OpenWritersFiles, "" , py::arg("rOutputFileHandler"))
        .def("RemoveDeadCells", (unsigned int (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::RemoveDeadCells, "" )
        .def("AddCell", (::CellPtr (MeshBasedCellPopulation2_2::*)(::CellPtr, ::CellPtr)) &MeshBasedCellPopulation2_2::AddCell, "" , py::arg("pNewCell"), py::arg("pParentCell"))
        .def("WriteResultsToFiles", (void (MeshBasedCellPopulation2_2::*)(::std::string const &)) &MeshBasedCellPopulation2_2::WriteResultsToFiles, "" , py::arg("rDirectory"))
        .def("AcceptPopulationWriter", (void (MeshBasedCellPopulation2_2::*)(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> >)) &MeshBasedCellPopulation2_2::AcceptPopulationWriter, "" , py::arg("pPopulationWriter"))
        .def("AcceptPopulationCountWriter", (void (MeshBasedCellPopulation2_2::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> >)) &MeshBasedCellPopulation2_2::AcceptPopulationCountWriter, "" , py::arg("pPopulationCountWriter"))
        .def("AcceptCellWriter", (void (MeshBasedCellPopulation2_2::*)(::boost::shared_ptr<AbstractCellWriter<2, 2> >, ::CellPtr)) &MeshBasedCellPopulation2_2::AcceptCellWriter, "" , py::arg("pCellWriter"), py::arg("pCell"))
        .def("Update", (void (MeshBasedCellPopulation2_2::*)(bool)) &MeshBasedCellPopulation2_2::Update, "" , py::arg("hasHadBirthsOrDeaths") = true)
        .def("TessellateIfNeeded", (void (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::TessellateIfNeeded, "" )
        .def("DivideLongSprings", (void (MeshBasedCellPopulation2_2::*)(double)) &MeshBasedCellPopulation2_2::DivideLongSprings, "" , py::arg("springDivisionThreshold"))
        .def("GetNode", (::Node<2> * (MeshBasedCellPopulation2_2::*)(unsigned int)) &MeshBasedCellPopulation2_2::GetNode, "" , py::arg("index"))
        .def("GetNumNodes", (unsigned int (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetNumNodes, "" )
        .def("WriteVtkResultsToFile", (void (MeshBasedCellPopulation2_2::*)(::std::string const &)) &MeshBasedCellPopulation2_2::WriteVtkResultsToFile, "" , py::arg("rDirectory"))
        .def("GetVolumeOfCell", (double (MeshBasedCellPopulation2_2::*)(::CellPtr)) &MeshBasedCellPopulation2_2::GetVolumeOfCell, "" , py::arg("pCell"))
        .def("CreateVoronoiTessellation", (void (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::CreateVoronoiTessellation, "" )
        .def("GetVoronoiTessellation", (::VertexMesh<2, 2> * (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetVoronoiTessellation, "" )
        .def("GetVolumeOfVoronoiElement", (double (MeshBasedCellPopulation2_2::*)(unsigned int)) &MeshBasedCellPopulation2_2::GetVolumeOfVoronoiElement, "" , py::arg("index"))
        .def("GetSurfaceAreaOfVoronoiElement", (double (MeshBasedCellPopulation2_2::*)(unsigned int)) &MeshBasedCellPopulation2_2::GetSurfaceAreaOfVoronoiElement, "" , py::arg("index"))
        .def("GetVoronoiEdgeLength", (double (MeshBasedCellPopulation2_2::*)(unsigned int, unsigned int)) &MeshBasedCellPopulation2_2::GetVoronoiEdgeLength, "" , py::arg("index1"), py::arg("index2"))
        .def("GetWidth", (double (MeshBasedCellPopulation2_2::*)(unsigned int const &)) &MeshBasedCellPopulation2_2::GetWidth, "" , py::arg("rDimension"))
        .def("WriteDataToVisualizerSetupFile", (void (MeshBasedCellPopulation2_2::*)(::out_stream &)) &MeshBasedCellPopulation2_2::WriteDataToVisualizerSetupFile, "" , py::arg("pVizSetupFile"))
        .def("GetNodeA", (::Node<2> * (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetNodeA, "" )
        .def("GetNodeB", (::Node<2> * (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetNodeB, "" )
        .def("GetCellA", (::CellPtr (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetCellA, "" )
        .def("GetCellB", (::CellPtr (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetCellB, "" )
        .def("SpringsBegin", (::MeshBasedCellPopulation<2, 2>::SpringIterator (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::SpringsBegin, "" )
        .def("SpringsEnd", (::MeshBasedCellPopulation<2, 2>::SpringIterator (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::SpringsEnd, "" )
        .def("CheckCellPointers", (void (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::CheckCellPointers, "" )
        .def("GetAreaBasedDampingConstantParameter", (double (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetAreaBasedDampingConstantParameter, "" )
        .def("SetAreaBasedDampingConstantParameter", (void (MeshBasedCellPopulation2_2::*)(double)) &MeshBasedCellPopulation2_2::SetAreaBasedDampingConstantParameter, "" , py::arg("areaBasedDampingConstantParameter"))
        .def("rGetNodePairs", (::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::rGetNodePairs, "" )
        .def("OutputCellPopulationParameters", (void (MeshBasedCellPopulation2_2::*)(::out_stream &)) &MeshBasedCellPopulation2_2::OutputCellPopulationParameters, "" , py::arg("rParamsFile"))
        .def("SetWriteVtkAsPoints", (void (MeshBasedCellPopulation2_2::*)(bool)) &MeshBasedCellPopulation2_2::SetWriteVtkAsPoints, "" , py::arg("writeVtkAsPoints"))
        .def("GetWriteVtkAsPoints", (bool (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetWriteVtkAsPoints, "" )
        .def("SetOutputMeshInVtk", (void (MeshBasedCellPopulation2_2::*)(bool)) &MeshBasedCellPopulation2_2::SetOutputMeshInVtk, "" , py::arg("outputMeshInVtk"))
        .def("GetOutputMeshInVtk", (bool (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::GetOutputMeshInVtk, "" )
        .def("GetNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (MeshBasedCellPopulation2_2::*)(unsigned int)) &MeshBasedCellPopulation2_2::GetNeighbouringNodeIndices, "" , py::arg("index"))
        .def("CalculateRestLengths", (void (MeshBasedCellPopulation2_2::*)()) &MeshBasedCellPopulation2_2::CalculateRestLengths, "" )
        .def("GetRestLength", (double (MeshBasedCellPopulation2_2::*)(unsigned int, unsigned int)) &MeshBasedCellPopulation2_2::GetRestLength, "" , py::arg("indexA"), py::arg("indexB"))
        .def("SetRestLength", (void (MeshBasedCellPopulation2_2::*)(unsigned int, unsigned int, double)) &MeshBasedCellPopulation2_2::SetRestLength, "" , py::arg("indexA"), py::arg("indexB"), py::arg("restLength"))
    ;
}
