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
#include "MeshBasedCellPopulationWithGhostNodes3.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();
typedef MeshBasedCellPopulationWithGhostNodes<3 > MeshBasedCellPopulationWithGhostNodes3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::TetrahedralMesh<3, 3> * _TetrahedralMesh_lt_3_3_gt_Ptr;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_;
typedef ::CellPtr _CellPtr;

class MeshBasedCellPopulationWithGhostNodes3_Overloads : public MeshBasedCellPopulationWithGhostNodes3{
    public:
    using MeshBasedCellPopulationWithGhostNodes3::MeshBasedCellPopulationWithGhostNodes;
    ::TetrahedralMesh<3, 3> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
            _TetrahedralMesh_lt_3_3_gt_Ptr,
            MeshBasedCellPopulationWithGhostNodes3,
            GetTetrahedralMeshForPdeModifier,
            );
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_,
            MeshBasedCellPopulationWithGhostNodes3,
            GetNeighbouringLocationIndices,
            pCell);
    }
    bool IsGhostNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
            bool,
            MeshBasedCellPopulationWithGhostNodes3,
            IsGhostNode,
            index);
    }
    void UpdateGhostNodesAfterReMesh(::NodeMap & rMap) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes3,
            UpdateGhostNodesAfterReMesh,
            rMap);
    }
    ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
            _CellPtr,
            MeshBasedCellPopulationWithGhostNodes3,
            AddCell,
            pNewCell, 
pParentCell);
    }
    void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes3,
            OpenWritersFiles,
            rOutputFileHandler);
    }
    void WriteVtkResultsToFile(::std::string const & rDirectory) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes3,
            WriteVtkResultsToFile,
            rDirectory);
    }
    void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes3,
            OutputCellPopulationParameters,
            rParamsFile);
    }
    void AcceptCellWritersAcrossPopulation() override {
        PYBIND11_OVERLOAD(
            void,
            MeshBasedCellPopulationWithGhostNodes3,
            AcceptCellWritersAcrossPopulation,
            );
    }

};
void register_MeshBasedCellPopulationWithGhostNodes3_class(py::module &m){
py::class_<MeshBasedCellPopulationWithGhostNodes3 , MeshBasedCellPopulationWithGhostNodes3_Overloads , boost::shared_ptr<MeshBasedCellPopulationWithGhostNodes3 >  , MeshBasedCellPopulation<3, 3>  >(m, "MeshBasedCellPopulationWithGhostNodes3")
        .def(py::init<::MutableMesh<3, 3> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, ::std::vector<unsigned int, std::allocator<unsigned int> > const, bool, double >(), py::arg("rMesh"), py::arg("rCells"), py::arg("locationIndices") = std::vector<unsigned int>(), py::arg("deleteMesh") = false, py::arg("ghostSpringStiffness") = 15.)
        .def(py::init<::MutableMesh<3, 3> &, double >(), py::arg("rMesh"), py::arg("ghostSpringStiffness") = 15.)
        .def(
            "GetTetrahedralMeshForPdeModifier", 
            (::TetrahedralMesh<3, 3> *(MeshBasedCellPopulationWithGhostNodes3::*)()) &MeshBasedCellPopulationWithGhostNodes3::GetTetrahedralMeshForPdeModifier, 
            " "  , py::return_value_policy::reference)
        .def(
            "GetNeighbouringLocationIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes3::*)(::CellPtr)) &MeshBasedCellPopulationWithGhostNodes3::GetNeighbouringLocationIndices, 
            " " , py::arg("pCell") )
        .def(
            "ApplyGhostForces", 
            (void(MeshBasedCellPopulationWithGhostNodes3::*)()) &MeshBasedCellPopulationWithGhostNodes3::ApplyGhostForces, 
            " "  )
        .def(
            "rGetGhostNodes", 
            (::std::vector<bool, std::allocator<bool> > &(MeshBasedCellPopulationWithGhostNodes3::*)()) &MeshBasedCellPopulationWithGhostNodes3::rGetGhostNodes, 
            " "  , py::return_value_policy::reference_internal)
        .def(
            "IsGhostNode", 
            (bool(MeshBasedCellPopulationWithGhostNodes3::*)(unsigned int)) &MeshBasedCellPopulationWithGhostNodes3::IsGhostNode, 
            " " , py::arg("index") )
        .def(
            "GetGhostNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(MeshBasedCellPopulationWithGhostNodes3::*)()) &MeshBasedCellPopulationWithGhostNodes3::GetGhostNodeIndices, 
            " "  )
        .def(
            "UpdateGhostNodesAfterReMesh", 
            (void(MeshBasedCellPopulationWithGhostNodes3::*)(::NodeMap &)) &MeshBasedCellPopulationWithGhostNodes3::UpdateGhostNodesAfterReMesh, 
            " " , py::arg("rMap") )
        .def(
            "CalculateForceBetweenGhostNodes", 
            (::boost::numeric::ublas::c_vector<double, 3>(MeshBasedCellPopulationWithGhostNodes3::*)(unsigned int const &, unsigned int const &)) &MeshBasedCellPopulationWithGhostNodes3::CalculateForceBetweenGhostNodes, 
            " " , py::arg("rNodeAGlobalIndex"), py::arg("rNodeBGlobalIndex") )
        .def(
            "AddCell", 
            (::CellPtr(MeshBasedCellPopulationWithGhostNodes3::*)(::CellPtr, ::CellPtr)) &MeshBasedCellPopulationWithGhostNodes3::AddCell, 
            " " , py::arg("pNewCell"), py::arg("pParentCell") )
        .def(
            "OpenWritersFiles", 
            (void(MeshBasedCellPopulationWithGhostNodes3::*)(::OutputFileHandler &)) &MeshBasedCellPopulationWithGhostNodes3::OpenWritersFiles, 
            " " , py::arg("rOutputFileHandler") )
        .def(
            "WriteVtkResultsToFile", 
            (void(MeshBasedCellPopulationWithGhostNodes3::*)(::std::string const &)) &MeshBasedCellPopulationWithGhostNodes3::WriteVtkResultsToFile, 
            " " , py::arg("rDirectory") )
        .def(
            "OutputCellPopulationParameters", 
            (void(MeshBasedCellPopulationWithGhostNodes3::*)(::out_stream &)) &MeshBasedCellPopulationWithGhostNodes3::OutputCellPopulationParameters, 
            " " , py::arg("rParamsFile") )
        .def("AddPopulationWriterVoronoiDataWriter", &MeshBasedCellPopulationWithGhostNodes3::AddPopulationWriter<VoronoiDataWriter>)
        .def("AddCellWriterCellLabelWriter", &MeshBasedCellPopulationWithGhostNodes3::AddCellWriter<CellLabelWriter>)
    ;
}
