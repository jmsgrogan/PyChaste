#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "MeshBasedCellPopulationWithGhostNodes2.pypp.hpp"

namespace py = pybind11;
typedef MeshBasedCellPopulationWithGhostNodes<2 > MeshBasedCellPopulationWithGhostNodes2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::TetrahedralMesh<2, 2> * _TetrahedralMesh2_2Ptr;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint;
typedef ::CellPtr _CellPtr;

class MeshBasedCellPopulationWithGhostNodes2_Overloads : public MeshBasedCellPopulationWithGhostNodes2{
    public:
    using MeshBasedCellPopulationWithGhostNodes2::MeshBasedCellPopulationWithGhostNodes;
    ::TetrahedralMesh<2, 2> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
            _TetrahedralMesh2_2Ptr,
            MeshBasedCellPopulationWithGhostNodes2,
            GetTetrahedralMeshForPdeModifier,
            );
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint,
            MeshBasedCellPopulationWithGhostNodes2,
            GetNeighbouringLocationIndices,
            pCell);
    }
    bool IsGhostNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
            bool,
            MeshBasedCellPopulationWithGhostNodes2,
            IsGhostNode,
            index);
    }
    void UpdateGhostNodesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes2,
            UpdateGhostNodesAfterReMesh,
            rMap);
    }
    ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
            _CellPtr,
            MeshBasedCellPopulationWithGhostNodes2,
            AddCell,
            pNewCell, 
pParentCell);
    }
    void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes2,
            OpenWritersFiles,
            rOutputFileHandler);
    }
    void WriteVtkResultsToFile(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes2,
            WriteVtkResultsToFile,
            rDirectory);
    }
    void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes2,
            OutputCellPopulationParameters,
            rParamsFile);
    }
    void AcceptCellWritersAcrossPopulation() override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes2,
            AcceptCellWritersAcrossPopulation,
            );
    }

};
void register_MeshBasedCellPopulationWithGhostNodes2_class(py::module &m){
py::class_<MeshBasedCellPopulationWithGhostNodes2 , MeshBasedCellPopulationWithGhostNodes2_Overloads , boost::shared_ptr<MeshBasedCellPopulationWithGhostNodes2 >   >(m, "MeshBasedCellPopulationWithGhostNodes2")
        .def(py::init<::MutableMesh<2, 2> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, double >())
        .def(py::init<::MutableMesh<2, 2> &, double >())
        .def(
            "GetTetrahedralMeshForPdeModifier", 
            (::TetrahedralMesh<2, 2> *(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::GetTetrahedralMeshForPdeModifier, 
            " " )
        .def(
            "GetNeighbouringLocationIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes2::*)(::CellPtr)) &MeshBasedCellPopulationWithGhostNodes2::GetNeighbouringLocationIndices, 
            " " , py::arg("pCell"))
        .def(
            "ApplyGhostForces", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::ApplyGhostForces, 
            " " )
        .def(
            "rGetGhostNodes", 
            (::std::vector<bool, std::allocator<bool> > &(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::rGetGhostNodes, 
            " " )
        .def(
            "IsGhostNode", 
            (bool(MeshBasedCellPopulationWithGhostNodes2::*)(unsigned int)) &MeshBasedCellPopulationWithGhostNodes2::IsGhostNode, 
            " " , py::arg("index"))
        .def(
            "GetGhostNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::GetGhostNodeIndices, 
            " " )
        .def(
            "UpdateGhostNodesAfterReMesh", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::NodeMap &)) &MeshBasedCellPopulationWithGhostNodes2::UpdateGhostNodesAfterReMesh, 
            " " , py::arg("rMap"))
        .def(
            "CalculateForceBetweenGhostNodes", 
            (::boost::numeric::ublas::c_vector<double, 2>(MeshBasedCellPopulationWithGhostNodes2::*)(unsigned int const &, unsigned int const &)) &MeshBasedCellPopulationWithGhostNodes2::CalculateForceBetweenGhostNodes, 
            " " , py::arg("rNodeAGlobalIndex"), py::arg("rNodeBGlobalIndex"))
        .def(
            "AddCell", 
            (::CellPtr(MeshBasedCellPopulationWithGhostNodes2::*)(::CellPtr, ::CellPtr)) &MeshBasedCellPopulationWithGhostNodes2::AddCell, 
            " " , py::arg("pNewCell"), py::arg("pParentCell"))
        .def(
            "OpenWritersFiles", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::OutputFileHandler &)) &MeshBasedCellPopulationWithGhostNodes2::OpenWritersFiles, 
            " " , py::arg("rOutputFileHandler"))
        .def(
            "WriteVtkResultsToFile", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::std::string const &)) &MeshBasedCellPopulationWithGhostNodes2::WriteVtkResultsToFile, 
            " " , py::arg("rDirectory"))
        .def(
            "OutputCellPopulationParameters", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::out_stream &)) &MeshBasedCellPopulationWithGhostNodes2::OutputCellPopulationParameters, 
            " " , py::arg("rParamsFile"))
    ;
}
