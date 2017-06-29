#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PottsBasedCellPopulation3.pypp.hpp"

namespace py = pybind11;

typedef PottsBasedCellPopulation<3 > PottsBasedCellPopulation3;
typedef ::TetrahedralMesh<3, 3> * _TetrahedralMesh3_3Ptr;
typedef ::Node<3> * _Node3Ptr;
typedef unsigned int unsignedint;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint;
typedef ::boost::numeric::ublas::c_vector<double, 3> _boost_numeric_ublas_c_vectordouble_3;
typedef ::CellPtr _CellPtr;
typedef unsigned int unsignedint;

class PottsBasedCellPopulation3_Overloads : public PottsBasedCellPopulation3{
    public:
    using PottsBasedCellPopulation3::PottsBasedCellPopulation;

        ::TetrahedralMesh<3, 3> * GetTetrahedralMeshForPdeModifier()override {
        PYBIND11_OVERLOAD(
        _TetrahedralMesh3_3Ptr,
        PottsBasedCellPopulation3,
        GetTetrahedralMeshForPdeModifier,
        
        );
        }
        ::Node<3> * GetNode(unsigned int index)override {
        PYBIND11_OVERLOAD(
        _Node3Ptr,
        PottsBasedCellPopulation3,
        GetNode,
        index        
        );
        }
        unsigned int GetNumNodes()override {
        PYBIND11_OVERLOAD(
        unsignedint,
        PottsBasedCellPopulation3,
        GetNumNodes,
        
        );
        }
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint,
        PottsBasedCellPopulation3,
        GetNeighbouringLocationIndices,
        pCell        
        );
        }
        ::boost::numeric::ublas::c_vector<double, 3> GetLocationOfCellCentre(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        _boost_numeric_ublas_c_vectordouble_3,
        PottsBasedCellPopulation3,
        GetLocationOfCellCentre,
        pCell        
        );
        }
        ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell)override {
        PYBIND11_OVERLOAD(
        _CellPtr,
        PottsBasedCellPopulation3,
        AddCell,
        pNewCell, 
        pParentCell        
        );
        }
        unsigned int RemoveDeadCells()override {
        PYBIND11_OVERLOAD(
        unsignedint,
        PottsBasedCellPopulation3,
        RemoveDeadCells,
        
        );
        }
        void UpdateCellLocations(double dt)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        UpdateCellLocations,
        dt        
        );
        }
        bool IsCellAssociatedWithADeletedLocation(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        bool,
        PottsBasedCellPopulation3,
        IsCellAssociatedWithADeletedLocation,
        pCell        
        );
        }
        void Update(bool hasHadBirthsOrDeaths)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        Update,
        hasHadBirthsOrDeaths        
        );
        }
        void OpenWritersFiles(::OutputFileHandler & rOutputFileHandler)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        OpenWritersFiles,
        rOutputFileHandler        
        );
        }
        void WriteResultsToFiles(::std::string const & rDirectory)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        WriteResultsToFiles,
        rDirectory        
        );
        }
        void AcceptPopulationWriter(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> > pPopulationWriter)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        AcceptPopulationWriter,
        pPopulationWriter        
        );
        }
        void AcceptPopulationCountWriter(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> > pPopulationCountWriter)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        AcceptPopulationCountWriter,
        pPopulationCountWriter        
        );
        }
        void AcceptCellWriter(::boost::shared_ptr<AbstractCellWriter<3, 3> > pCellWriter, ::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        AcceptCellWriter,
        pCellWriter, 
        pCell        
        );
        }
        double GetVolumeOfCell(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        double,
        PottsBasedCellPopulation3,
        GetVolumeOfCell,
        pCell        
        );
        }
        double GetWidth(unsigned int const & rDimension)override {
        PYBIND11_OVERLOAD(
        double,
        PottsBasedCellPopulation3,
        GetWidth,
        rDimension        
        );
        }
        void OutputCellPopulationParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        OutputCellPopulationParameters,
        rParamsFile        
        );
        }
        void AddUpdateRule(::boost::shared_ptr<AbstractUpdateRule<3> > pUpdateRule)override {
        PYBIND11_OVERLOAD(
        void,
        PottsBasedCellPopulation3,
        AddUpdateRule,
        pUpdateRule        
        );
        }
        double GetCellDataItemAtPdeNode(unsigned int pdeNodeIndex, ::std::string & rVariableName, bool dirichletBoundaryConditionApplies, double dirichletBoundaryValue)override {
        PYBIND11_OVERLOAD(
        double,
        PottsBasedCellPopulation3,
        GetCellDataItemAtPdeNode,
        pdeNodeIndex, 
        rVariableName, 
        dirichletBoundaryConditionApplies, 
        dirichletBoundaryValue        
        );
        }

};
void register_PottsBasedCellPopulation3_class(py::module &m){
    py::class_<PottsBasedCellPopulation3, PottsBasedCellPopulation3_Overloads, std::shared_ptr<PottsBasedCellPopulation3 >  >(m, "PottsBasedCellPopulation3")
        .def(py::init<::PottsMesh<3> &, ::std::vector<boost::shared_ptr<Cell>, std::allocator<boost::shared_ptr<Cell> > > &, bool, bool, ::std::vector<unsigned int, std::allocator<unsigned int> > const >())
        .def(py::init<::PottsMesh<3> & >())
        .def("GetNumElements", (unsigned int (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::GetNumElements, "" )
        .def("GetNode", (::Node<3> * (PottsBasedCellPopulation3::*)(unsigned int)) &PottsBasedCellPopulation3::GetNode, "" , py::arg("index"))
        .def("GetNumNodes", (unsigned int (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::GetNumNodes, "" )
        .def("GetNeighbouringLocationIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (PottsBasedCellPopulation3::*)(::CellPtr)) &PottsBasedCellPopulation3::GetNeighbouringLocationIndices, "" , py::arg("pCell"))
        .def("GetLocationOfCellCentre", (::boost::numeric::ublas::c_vector<double, 3> (PottsBasedCellPopulation3::*)(::CellPtr)) &PottsBasedCellPopulation3::GetLocationOfCellCentre, "" , py::arg("pCell"))
        .def("AddCell", (::CellPtr (PottsBasedCellPopulation3::*)(::CellPtr, ::CellPtr)) &PottsBasedCellPopulation3::AddCell, "" , py::arg("pNewCell"), py::arg("pParentCell") = ::CellPtr( ))
        .def("RemoveDeadCells", (unsigned int (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::RemoveDeadCells, "" )
        .def("UpdateCellLocations", (void (PottsBasedCellPopulation3::*)(double)) &PottsBasedCellPopulation3::UpdateCellLocations, "" , py::arg("dt"))
        .def("IsCellAssociatedWithADeletedLocation", (bool (PottsBasedCellPopulation3::*)(::CellPtr)) &PottsBasedCellPopulation3::IsCellAssociatedWithADeletedLocation, "" , py::arg("pCell"))
        .def("Update", (void (PottsBasedCellPopulation3::*)(bool)) &PottsBasedCellPopulation3::Update, "" , py::arg("hasHadBirthsOrDeaths") = true)
        .def("OpenWritersFiles", (void (PottsBasedCellPopulation3::*)(::OutputFileHandler &)) &PottsBasedCellPopulation3::OpenWritersFiles, "" , py::arg("rOutputFileHandler"))
        .def("WriteResultsToFiles", (void (PottsBasedCellPopulation3::*)(::std::string const &)) &PottsBasedCellPopulation3::WriteResultsToFiles, "" , py::arg("rDirectory"))
        .def("AcceptPopulationWriter", (void (PottsBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellPopulationWriter<3, 3> >)) &PottsBasedCellPopulation3::AcceptPopulationWriter, "" , py::arg("pPopulationWriter"))
        .def("AcceptPopulationCountWriter", (void (PottsBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellPopulationCountWriter<3, 3> >)) &PottsBasedCellPopulation3::AcceptPopulationCountWriter, "" , py::arg("pPopulationCountWriter"))
        .def("AcceptCellWriter", (void (PottsBasedCellPopulation3::*)(::boost::shared_ptr<AbstractCellWriter<3, 3> >, ::CellPtr)) &PottsBasedCellPopulation3::AcceptCellWriter, "" , py::arg("pCellWriter"), py::arg("pCell"))
        .def("GetVolumeOfCell", (double (PottsBasedCellPopulation3::*)(::CellPtr)) &PottsBasedCellPopulation3::GetVolumeOfCell, "" , py::arg("pCell"))
        .def("GetWidth", (double (PottsBasedCellPopulation3::*)(unsigned int const &)) &PottsBasedCellPopulation3::GetWidth, "" , py::arg("rDimension"))
        .def("OutputCellPopulationParameters", (void (PottsBasedCellPopulation3::*)(::out_stream &)) &PottsBasedCellPopulation3::OutputCellPopulationParameters, "" , py::arg("rParamsFile"))
        .def("SetTemperature", (void (PottsBasedCellPopulation3::*)(double)) &PottsBasedCellPopulation3::SetTemperature, "" , py::arg("temperature"))
        .def("GetTemperature", (double (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::GetTemperature, "" )
        .def("SetNumSweepsPerTimestep", (void (PottsBasedCellPopulation3::*)(unsigned int)) &PottsBasedCellPopulation3::SetNumSweepsPerTimestep, "" , py::arg("numSweepsPerTimestep"))
        .def("GetNumSweepsPerTimestep", (unsigned int (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::GetNumSweepsPerTimestep, "" )
        .def("CreateElementTessellation", (void (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::CreateElementTessellation, "" )
        .def("CreateMutableMesh", (void (PottsBasedCellPopulation3::*)()) &PottsBasedCellPopulation3::CreateMutableMesh, "" )
        .def("AddUpdateRule", (void (PottsBasedCellPopulation3::*)(::boost::shared_ptr<AbstractUpdateRule<3> >)) &PottsBasedCellPopulation3::AddUpdateRule, "" , py::arg("pUpdateRule"))
        .def("GetCellDataItemAtPdeNode", (double (PottsBasedCellPopulation3::*)(unsigned int, ::std::string &, bool, double)) &PottsBasedCellPopulation3::GetCellDataItemAtPdeNode, "" , py::arg("pdeNodeIndex"), py::arg("rVariableName"), py::arg("dirichletBoundaryConditionApplies") = false, py::arg("dirichletBoundaryValue") = 0.)
    ;
}
