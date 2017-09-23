#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "AbstractCellBasedSimulation.hpp"
#include "AbstractVertexBasedDivisionRule.hpp"
#include "CellLabelWriter.hpp"
#include "VoronoiDataWriter.hpp"
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "VertexBasedCellPopulation.hpp"

#include "PythonObjectConverters.hpp"
#include "VertexBasedCellPopulation2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef VertexBasedCellPopulation<2 > VertexBasedCellPopulation2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef unsigned int unsignedint;
typedef ::boost::numeric::ublas::c_vector<double, 2> _boost_numeric_ublas_c_vector_lt_double_2_gt_;
typedef ::Node<2> * _Node_lt_2_gt_Ptr;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_;
typedef unsigned int unsignedint;
typedef ::CellPtr _CellPtr;
typedef unsigned int unsignedint;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_;
typedef ::TetrahedralMesh<2, 2> * _TetrahedralMesh_lt_2_2_gt_Ptr;

class VertexBasedCellPopulation2_Overloads : public VertexBasedCellPopulation2{
    public:
    using VertexBasedCellPopulation2::VertexBasedCellPopulation;
    double GetDampingConstant(unsigned int nodeIndex) override {
        PYBIND11_OVERLOAD(
            double,
            VertexBasedCellPopulation2,
            GetDampingConstant,
            nodeIndex);
    }
    unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            VertexBasedCellPopulation2,
            GetNumNodes,
            );
    }
    ::boost::numeric::ublas::c_vector<double, 2> GetLocationOfCellCentre(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            _boost_numeric_ublas_c_vector_lt_double_2_gt_,
            VertexBasedCellPopulation2,
            GetLocationOfCellCentre,
            pCell);
    }
    ::Node<2> * GetNode(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _Node_lt_2_gt_Ptr,
            VertexBasedCellPopulation2,
            GetNode,
            index);
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_,
            VertexBasedCellPopulation2,
            GetNeighbouringLocationIndices,
            pCell);
    }
    unsigned int AddNode(::Node<2> * pNewNode) override {
        PYBIND11_OVERLOAD(
            unsignedint,
            VertexBasedCellPopulation2,
            AddNode,
            pNewNode);
    }
    void CheckForStepSizeException(unsigned int nodeIndex, ::boost::numeric::ublas::c_vector<double, 2> & rDisplacement, double dt) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            CheckForStepSizeException,
            nodeIndex, 
rDisplacement, 
dt);
    }
    void SetNode(unsigned int index, ::ChastePoint<2> & rNewLocation) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            SetNode,
            index, 
rNewLocation);
    }
    ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell) override {
        PYBIND11_OVERLOAD(
            _CellPtr,
            VertexBasedCellPopulation2,
            AddCell,
            pNewCell, 
pParentCell);
    }
    unsigned int RemoveDeadCells() override {
        PYBIND11_OVERLOAD(
            unsignedint,
            VertexBasedCellPopulation2,
            RemoveDeadCells,
            );
    }
    bool IsCellAssociatedWithADeletedLocation(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            bool,
            VertexBasedCellPopulation2,
            IsCellAssociatedWithADeletedLocation,
            pCell);
    }
    void Update(bool hasHadBirthsOrDeaths) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            Update,
            hasHadBirthsOrDeaths);
    }
    void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            OpenWritersFiles,
            rOutputFileHandler);
    }
    void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> > pPopulationWriter) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            AcceptPopulationWriter,
            pPopulationWriter);
    }
    void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> > pPopulationCountWriter) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            AcceptPopulationCountWriter,
            pPopulationCountWriter);
    }
    void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<2, 2> > pCellWriter, ::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            AcceptCellWriter,
            pCellWriter, 
pCell);
    }
    double GetVolumeOfCell(::CellPtr pCell) override {
        PYBIND11_OVERLOAD(
            double,
            VertexBasedCellPopulation2,
            GetVolumeOfCell,
            pCell);
    }
    void OutputCellPopulationParameters(::out_stream & rParamsFile) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            OutputCellPopulationParameters,
            rParamsFile);
    }
    double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
            double,
            VertexBasedCellPopulation2,
            GetWidth,
            rDimension);
    }
    ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringNodeIndices(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _std_set_lt_unsignedint_std_less_lt_unsignedint_gt__std_allocator_lt_unsignedint_gt__gt_,
            VertexBasedCellPopulation2,
            GetNeighbouringNodeIndices,
            index);
    }
    ::TetrahedralMesh<2, 2> * GetTetrahedralMeshForPdeModifier() override {
        PYBIND11_OVERLOAD(
            _TetrahedralMesh_lt_2_2_gt_Ptr,
            VertexBasedCellPopulation2,
            GetTetrahedralMeshForPdeModifier,
            );
    }
    bool IsPdeNodeAssociatedWithNonApoptoticCell(unsigned int pdeNodeIndex) override {
        PYBIND11_OVERLOAD(
            bool,
            VertexBasedCellPopulation2,
            IsPdeNodeAssociatedWithNonApoptoticCell,
            pdeNodeIndex);
    }
    double GetCellDataItemAtPdeNode(unsigned int pdeNodeIndex, ::std::string & rVariableName, bool dirichletBoundaryConditionApplies, double dirichletBoundaryValue) override {
        PYBIND11_OVERLOAD(
            double,
            VertexBasedCellPopulation2,
            GetCellDataItemAtPdeNode,
            pdeNodeIndex, 
rVariableName, 
dirichletBoundaryConditionApplies, 
dirichletBoundaryValue);
    }
    double GetDefaultTimeStep() override {
        PYBIND11_OVERLOAD(
            double,
            VertexBasedCellPopulation2,
            GetDefaultTimeStep,
            );
    }
    void WriteDataToVisualizerSetupFile(::out_stream & pVizSetupFile) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            WriteDataToVisualizerSetupFile,
            pVizSetupFile);
    }
    void SimulationSetupHook(::AbstractCellBasedSimulation<2, 2> * pSimulation) override {
        PYBIND11_OVERLOAD(
            void,
            VertexBasedCellPopulation2,
            SimulationSetupHook,
            pSimulation);
    }

};
void register_VertexBasedCellPopulation2_class(py::module &m){
py::class_<VertexBasedCellPopulation2 , VertexBasedCellPopulation2_Overloads , boost::shared_ptr<VertexBasedCellPopulation2 >  , AbstractOffLatticeCellPopulation<2, 2>  >(m, "VertexBasedCellPopulation2")
        .def(py::init<::MutableVertexMesh<2, 2> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, bool, bool, ::std::vector<unsigned int, std::allocator<unsigned int> > const >(), py::arg("rMesh"), py::arg("rCells"), py::arg("deleteMesh") = false, py::arg("validate") = true, py::arg("locationIndices") = std::vector<unsigned int>())
        .def(py::init<::MutableVertexMesh<2, 2> & >(), py::arg("rMesh"))
        .def(
            "GetDampingConstant", 
            (double(VertexBasedCellPopulation2::*)(unsigned int)) &VertexBasedCellPopulation2::GetDampingConstant, 
            " " , py::arg("nodeIndex") )
        .def(
            "GetNumElements", 
            (unsigned int(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetNumElements, 
            " "  )
        .def(
            "GetNumNodes", 
            (unsigned int(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetNumNodes, 
            " "  )
        .def(
            "GetLocationOfCellCentre", 
            (::boost::numeric::ublas::c_vector<double, 2>(VertexBasedCellPopulation2::*)(::CellPtr)) &VertexBasedCellPopulation2::GetLocationOfCellCentre, 
            " " , py::arg("pCell") )
        .def(
            "GetNode", 
            (::Node<2> *(VertexBasedCellPopulation2::*)(unsigned int)) &VertexBasedCellPopulation2::GetNode, 
            " " , py::arg("index") , py::return_value_policy::reference)
        .def(
            "GetNeighbouringLocationIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(VertexBasedCellPopulation2::*)(::CellPtr)) &VertexBasedCellPopulation2::GetNeighbouringLocationIndices, 
            " " , py::arg("pCell") )
        .def(
            "AddNode", 
            (unsigned int(VertexBasedCellPopulation2::*)(::Node<2> *)) &VertexBasedCellPopulation2::AddNode, 
            " " , py::arg("pNewNode") )
        .def(
            "CheckForStepSizeException", 
            (void(VertexBasedCellPopulation2::*)(unsigned int, ::boost::numeric::ublas::c_vector<double, 2> &, double)) &VertexBasedCellPopulation2::CheckForStepSizeException, 
            " " , py::arg("nodeIndex"), py::arg("rDisplacement"), py::arg("dt") )
        .def(
            "SetNode", 
            (void(VertexBasedCellPopulation2::*)(unsigned int, ::ChastePoint<2> &)) &VertexBasedCellPopulation2::SetNode, 
            " " , py::arg("index"), py::arg("rNewLocation") )
        .def(
            "AddCell", 
            (::CellPtr(VertexBasedCellPopulation2::*)(::CellPtr, ::CellPtr)) &VertexBasedCellPopulation2::AddCell, 
            " " , py::arg("pNewCell"), py::arg("pParentCell") = ::CellPtr( ) )
        .def(
            "RemoveDeadCells", 
            (unsigned int(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::RemoveDeadCells, 
            " "  )
        .def(
            "IsCellAssociatedWithADeletedLocation", 
            (bool(VertexBasedCellPopulation2::*)(::CellPtr)) &VertexBasedCellPopulation2::IsCellAssociatedWithADeletedLocation, 
            " " , py::arg("pCell") )
        .def(
            "Update", 
            (void(VertexBasedCellPopulation2::*)(bool)) &VertexBasedCellPopulation2::Update, 
            " " , py::arg("hasHadBirthsOrDeaths") = true )
        .def(
            "OpenWritersFiles", 
            (void(VertexBasedCellPopulation2::*)(::OutputFileHandler &)) &VertexBasedCellPopulation2::OpenWritersFiles, 
            " " , py::arg("rOutputFileHandler") )
        .def(
            "AcceptPopulationWriter", 
            (void(VertexBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellPopulationWriter<2, 2> >)) &VertexBasedCellPopulation2::AcceptPopulationWriter, 
            " " , py::arg("pPopulationWriter") )
        .def(
            "AcceptPopulationCountWriter", 
            (void(VertexBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<2, 2> >)) &VertexBasedCellPopulation2::AcceptPopulationCountWriter, 
            " " , py::arg("pPopulationCountWriter") )
        .def(
            "AcceptCellWriter", 
            (void(VertexBasedCellPopulation2::*)(::boost::shared_ptr<AbstractCellWriter<2, 2> >, ::CellPtr)) &VertexBasedCellPopulation2::AcceptCellWriter, 
            " " , py::arg("pCellWriter"), py::arg("pCell") )
        .def(
            "GetRosetteRankOfCell", 
            (unsigned int(VertexBasedCellPopulation2::*)(::CellPtr)) &VertexBasedCellPopulation2::GetRosetteRankOfCell, 
            " " , py::arg("pCell") )
        .def(
            "GetVolumeOfCell", 
            (double(VertexBasedCellPopulation2::*)(::CellPtr)) &VertexBasedCellPopulation2::GetVolumeOfCell, 
            " " , py::arg("pCell") )
        .def(
            "GetLocationsOfT2Swaps", 
            (::std::vector<boost::numeric::ublas::c_vector<double, 2>, std::allocator<boost::numeric::ublas::c_vector<double, 2> > >(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetLocationsOfT2Swaps, 
            " "  )
        .def(
            "GetCellIdsOfT2Swaps", 
            (::std::vector<unsigned int, std::allocator<unsigned int> >(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetCellIdsOfT2Swaps, 
            " "  )
        .def(
            "AddLocationOfT2Swap", 
            (void(VertexBasedCellPopulation2::*)(::boost::numeric::ublas::c_vector<double, 2>)) &VertexBasedCellPopulation2::AddLocationOfT2Swap, 
            " " , py::arg("locationOfT2Swap") )
        .def(
            "AddCellIdOfT2Swap", 
            (void(VertexBasedCellPopulation2::*)(unsigned int)) &VertexBasedCellPopulation2::AddCellIdOfT2Swap, 
            " " , py::arg("idOfT2Swap") )
        .def(
            "ClearLocationsAndCellIdsOfT2Swaps", 
            (void(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::ClearLocationsAndCellIdsOfT2Swaps, 
            " "  )
        .def(
            "GetOutputCellRearrangementLocations", 
            (bool(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetOutputCellRearrangementLocations, 
            " "  )
        .def(
            "SetOutputCellRearrangementLocations", 
            (void(VertexBasedCellPopulation2::*)(bool)) &VertexBasedCellPopulation2::SetOutputCellRearrangementLocations, 
            " " , py::arg("outputCellRearrangementLocations") )
        .def(
            "OutputCellPopulationParameters", 
            (void(VertexBasedCellPopulation2::*)(::out_stream &)) &VertexBasedCellPopulation2::OutputCellPopulationParameters, 
            " " , py::arg("rParamsFile") )
        .def(
            "GetWidth", 
            (double(VertexBasedCellPopulation2::*)(unsigned int const &)) &VertexBasedCellPopulation2::GetWidth, 
            " " , py::arg("rDimension") )
        .def(
            "GetNeighbouringNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(VertexBasedCellPopulation2::*)(unsigned int)) &VertexBasedCellPopulation2::GetNeighbouringNodeIndices, 
            " " , py::arg("index") )
        .def(
            "IsPdeNodeAssociatedWithNonApoptoticCell", 
            (bool(VertexBasedCellPopulation2::*)(unsigned int)) &VertexBasedCellPopulation2::IsPdeNodeAssociatedWithNonApoptoticCell, 
            " " , py::arg("pdeNodeIndex") )
        .def(
            "GetCellDataItemAtPdeNode", 
            (double(VertexBasedCellPopulation2::*)(unsigned int, ::std::string &, bool, double)) &VertexBasedCellPopulation2::GetCellDataItemAtPdeNode, 
            " " , py::arg("pdeNodeIndex"), py::arg("rVariableName"), py::arg("dirichletBoundaryConditionApplies") = false, py::arg("dirichletBoundaryValue") = 0. )
        .def(
            "GetVertexBasedDivisionRule", 
            (::boost::shared_ptr<AbstractVertexBasedDivisionRule<2> >(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetVertexBasedDivisionRule, 
            " "  )
        .def(
            "SetVertexBasedDivisionRule", 
            (void(VertexBasedCellPopulation2::*)(::boost::shared_ptr<AbstractVertexBasedDivisionRule<2> >)) &VertexBasedCellPopulation2::SetVertexBasedDivisionRule, 
            " " , py::arg("pVertexBasedDivisionRule") )
        .def(
            "GetDefaultTimeStep", 
            (double(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetDefaultTimeStep, 
            " "  )
        .def(
            "WriteDataToVisualizerSetupFile", 
            (void(VertexBasedCellPopulation2::*)(::out_stream &)) &VertexBasedCellPopulation2::WriteDataToVisualizerSetupFile, 
            " " , py::arg("pVizSetupFile") )
        .def(
            "SimulationSetupHook", 
            (void(VertexBasedCellPopulation2::*)(::AbstractCellBasedSimulation<2, 2> *)) &VertexBasedCellPopulation2::SimulationSetupHook, 
            " " , py::arg("pSimulation") )
        .def(
            "GetRestrictVertexMovementBoolean", 
            (bool(VertexBasedCellPopulation2::*)()) &VertexBasedCellPopulation2::GetRestrictVertexMovementBoolean, 
            " "  )
        .def(
            "SetRestrictVertexMovementBoolean", 
            (void(VertexBasedCellPopulation2::*)(bool)) &VertexBasedCellPopulation2::SetRestrictVertexMovementBoolean, 
            " " , py::arg("restrictVertexMovement") )
        .def("AddPopulationWriterVoronoiDataWriter", &VertexBasedCellPopulation2::AddPopulationWriter<VoronoiDataWriter>)
        .def("AddCellWriterCellLabelWriter", &VertexBasedCellPopulation2::AddCellWriter<CellLabelWriter>)
    ;
}
