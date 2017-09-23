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
#include "MeshBasedCellPopulationWithGhostNodes.hpp"

#include "PythonObjectConverters.hpp"
#include "MeshBasedCellPopulationWithGhostNodes2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
//PYBIND11_VTK_TYPECASTER(vtkRenderer);
//PYBIND11_VTK_TYPECASTER(vtkUnsignedCharArray);   
typedef MeshBasedCellPopulationWithGhostNodes<2 > MeshBasedCellPopulationWithGhostNodes2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::TetrahedralMesh<2, 2> * _TetrahedralMesh_lt_2_2_gt_Ptr;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_;
typedef ::CellPtr _CellPtr;

class MeshBasedCellPopulationWithGhostNodes2_Overloads : public MeshBasedCellPopulationWithGhostNodes2{
    public:
    using MeshBasedCellPopulationWithGhostNodes2::MeshBasedCellPopulationWithGhostNodes;
    ::TetrahedralMesh<2, 2> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
            _TetrahedralMesh_lt_2_2_gt_Ptr,
            MeshBasedCellPopulationWithGhostNodes2,
            GetTetrahedralMeshForPdeModifier,
            );
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_,
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
py::class_<MeshBasedCellPopulationWithGhostNodes2 , MeshBasedCellPopulationWithGhostNodes2_Overloads , boost::shared_ptr<MeshBasedCellPopulationWithGhostNodes2 >  , MeshBasedCellPopulation<2, 2>  >(m, "MeshBasedCellPopulationWithGhostNodes2")
        .def(py::init<::MutableMesh<2, 2> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, double >(), py::arg("rMesh"), py::arg("rCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("deleteMesh") = false, py::arg("ghostSpringStiffness") = 15.)
        .def(py::init<::MutableMesh<2, 2> &, double >(), py::arg("rMesh"), py::arg("ghostSpringStiffness") = 15.)
        .def(
            "GetTetrahedralMeshForPdeModifier", 
            (::TetrahedralMesh<2, 2> *(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::GetTetrahedralMeshForPdeModifier, 
            " "  , py::return_value_policy::reference)
        .def(
            "GetNeighbouringLocationIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes2::*)(::CellPtr)) &MeshBasedCellPopulationWithGhostNodes2::GetNeighbouringLocationIndices, 
            " " , py::arg("pCell") )
        .def(
            "ApplyGhostForces", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::ApplyGhostForces, 
            " "  )
        .def(
            "rGetGhostNodes", 
            (::std::vector<bool, std::allocator<bool> > &(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::rGetGhostNodes, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "IsGhostNode", 
            (bool(MeshBasedCellPopulationWithGhostNodes2::*)(unsigned int)) &MeshBasedCellPopulationWithGhostNodes2::IsGhostNode, 
            " " , py::arg("index") )
        .def(
            "GetGhostNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes2::*)()) &MeshBasedCellPopulationWithGhostNodes2::GetGhostNodeIndices, 
            " "  )
        .def(
            "UpdateGhostNodesAfterReMesh", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::NodeMap &)) &MeshBasedCellPopulationWithGhostNodes2::UpdateGhostNodesAfterReMesh, 
            " " , py::arg("rMap") )
        .def(
            "CalculateForceBetweenGhostNodes", 
            (::boost::numeric::ublas::c_vector<double, 2>(MeshBasedCellPopulationWithGhostNodes2::*)(unsigned int const &, unsigned int const &)) &MeshBasedCellPopulationWithGhostNodes2::CalculateForceBetweenGhostNodes, 
            " " , py::arg("rNodeAGlobalIndex"), py::arg("rNodeBGlobalIndex") )
        .def(
            "AddCell", 
            (::CellPtr(MeshBasedCellPopulationWithGhostNodes2::*)(::CellPtr, ::CellPtr)) &MeshBasedCellPopulationWithGhostNodes2::AddCell, 
            " " , py::arg("pNewCell"), py::arg("pParentCell") )
        .def(
            "OpenWritersFiles", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::OutputFileHandler &)) &MeshBasedCellPopulationWithGhostNodes2::OpenWritersFiles, 
            " " , py::arg("rOutputFileHandler") )
        .def(
            "WriteVtkResultsToFile", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::std::string const &)) &MeshBasedCellPopulationWithGhostNodes2::WriteVtkResultsToFile, 
            " " , py::arg("rDirectory") )
        .def(
            "OutputCellPopulationParameters", 
            (void(MeshBasedCellPopulationWithGhostNodes2::*)(::out_stream &)) &MeshBasedCellPopulationWithGhostNodes2::OutputCellPopulationParameters, 
            " " , py::arg("rParamsFile") )
        .def("AddPopulationWriterVoronoiDataWriter", &MeshBasedCellPopulationWithGhostNodes2::AddPopulationWriter<VoronoiDataWriter>)
        .def("AddCellWriterCellLabelWriter", &MeshBasedCellPopulationWithGhostNodes2::AddCellWriter<CellLabelWriter>)
    ;
}
