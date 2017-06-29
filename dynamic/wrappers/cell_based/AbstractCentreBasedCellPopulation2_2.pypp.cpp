#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractCentreBasedCellPopulation2_2.pypp.hpp"

namespace py = pybind11;

typedef AbstractCentreBasedCellPopulation<2,2 > AbstractCentreBasedCellPopulation2_2;
typedef ::boost::numeric::ublas::c_vector<double, 2> _boost_numeric_ublas_c_vectordouble_2;
typedef ::CellPtr _CellPtr;
typedef ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint;
typedef ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & _std_vectorstd_pairNode2Ptr_Node2Ptr_std_allocatorstd_pairNode2Ptr_Node2PtrRef;

class AbstractCentreBasedCellPopulation2_2_Overloads : public AbstractCentreBasedCellPopulation2_2{
    public:
    using AbstractCentreBasedCellPopulation2_2::AbstractCentreBasedCellPopulation;

        ::boost::numeric::ublas::c_vector<double, 2> GetLocationOfCellCentre(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        _boost_numeric_ublas_c_vectordouble_2,
        AbstractCentreBasedCellPopulation2_2,
        GetLocationOfCellCentre,
        pCell        
        );
        }
        double GetCellDataItemAtPdeNode(unsigned int pdeNodeIndex, ::std::string & rVariableName, bool dirichletBoundaryConditionApplies, double dirichletBoundaryValue)override {
        PYBIND11_OVERLOAD(
        double,
        AbstractCentreBasedCellPopulation2_2,
        GetCellDataItemAtPdeNode,
        pdeNodeIndex, 
        rVariableName, 
        dirichletBoundaryConditionApplies, 
        dirichletBoundaryValue        
        );
        }
        ::CellPtr AddCell(::CellPtr pNewCell, ::CellPtr pParentCell)override {
        PYBIND11_OVERLOAD(
        _CellPtr,
        AbstractCentreBasedCellPopulation2_2,
        AddCell,
        pNewCell, 
        pParentCell        
        );
        }
        bool IsCellAssociatedWithADeletedLocation(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        bool,
        AbstractCentreBasedCellPopulation2_2,
        IsCellAssociatedWithADeletedLocation,
        pCell        
        );
        }
        ::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > GetNeighbouringLocationIndices(::CellPtr pCell)override {
        PYBIND11_OVERLOAD(
        _std_setunsignedint_std_lessunsignedint_std_allocatorunsignedint,
        AbstractCentreBasedCellPopulation2_2,
        GetNeighbouringLocationIndices,
        pCell        
        );
        }
        void CheckForStepSizeException(unsigned int nodeIndex, ::boost::numeric::ublas::c_vector<double, 2> & rDisplacement, double dt)override {
        PYBIND11_OVERLOAD(
        void,
        AbstractCentreBasedCellPopulation2_2,
        CheckForStepSizeException,
        nodeIndex, 
        rDisplacement, 
        dt        
        );
        }
        double GetDampingConstant(unsigned int nodeIndex)override {
        PYBIND11_OVERLOAD(
        double,
        AbstractCentreBasedCellPopulation2_2,
        GetDampingConstant,
        nodeIndex        
        );
        }
        bool IsGhostNode(unsigned int index)override {
        PYBIND11_OVERLOAD(
        bool,
        AbstractCentreBasedCellPopulation2_2,
        IsGhostNode,
        index        
        );
        }
        bool IsParticle(unsigned int index)override {
        PYBIND11_OVERLOAD(
        bool,
        AbstractCentreBasedCellPopulation2_2,
        IsParticle,
        index        
        );
        }
        ::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & rGetNodePairs()override {
        PYBIND11_OVERLOAD_PURE(
        _std_vectorstd_pairNode2Ptr_Node2Ptr_std_allocatorstd_pairNode2Ptr_Node2PtrRef,
        AbstractCentreBasedCellPopulation2_2,
        rGetNodePairs,
        
        );
        }
        void OutputCellPopulationParameters(::out_stream & rParamsFile)override {
        PYBIND11_OVERLOAD(
        void,
        AbstractCentreBasedCellPopulation2_2,
        OutputCellPopulationParameters,
        rParamsFile        
        );
        }
        double GetDefaultTimeStep()override {
        PYBIND11_OVERLOAD(
        double,
        AbstractCentreBasedCellPopulation2_2,
        GetDefaultTimeStep,
        
        );
        }
        void WriteVtkResultsToFile(::std::string const & rDirectory)override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractCentreBasedCellPopulation2_2,
        WriteVtkResultsToFile,
        rDirectory        
        );
        }
        void AcceptCellWritersAcrossPopulation()override {
        PYBIND11_OVERLOAD(
        void,
        AbstractCentreBasedCellPopulation2_2,
        AcceptCellWritersAcrossPopulation,
        
        );
        }

};
void register_AbstractCentreBasedCellPopulation2_2_class(py::module &m){
    py::class_<AbstractCentreBasedCellPopulation2_2, AbstractCentreBasedCellPopulation2_2_Overloads, std::shared_ptr<AbstractCentreBasedCellPopulation2_2 >  >(m, "AbstractCentreBasedCellPopulation2_2")
        .def("GetLocationOfCellCentre", (::boost::numeric::ublas::c_vector<double, 2> (AbstractCentreBasedCellPopulation2_2::*)(::CellPtr)) &AbstractCentreBasedCellPopulation2_2::GetLocationOfCellCentre, "" , py::arg("pCell"))
        .def("GetCellDataItemAtPdeNode", (double (AbstractCentreBasedCellPopulation2_2::*)(unsigned int, ::std::string &, bool, double)) &AbstractCentreBasedCellPopulation2_2::GetCellDataItemAtPdeNode, "" , py::arg("pdeNodeIndex"), py::arg("rVariableName"), py::arg("dirichletBoundaryConditionApplies") = false, py::arg("dirichletBoundaryValue") = 0.)
        .def("AddCell", (::CellPtr (AbstractCentreBasedCellPopulation2_2::*)(::CellPtr, ::CellPtr)) &AbstractCentreBasedCellPopulation2_2::AddCell, "" , py::arg("pNewCell"), py::arg("pParentCell") = ::CellPtr( ))
        .def("CreateCellPair", (::std::pair<boost::shared_ptr<Cell>, boost::shared_ptr<Cell> > (AbstractCentreBasedCellPopulation2_2::*)(::CellPtr, ::CellPtr)) &AbstractCentreBasedCellPopulation2_2::CreateCellPair, "" , py::arg("pCell1"), py::arg("pCell2"))
        .def("IsMarkedSpring", (bool (AbstractCentreBasedCellPopulation2_2::*)(::std::pair<boost::shared_ptr<Cell>, boost::shared_ptr<Cell> > const &)) &AbstractCentreBasedCellPopulation2_2::IsMarkedSpring, "" , py::arg("rCellPair"))
        .def("IsCellAssociatedWithADeletedLocation", (bool (AbstractCentreBasedCellPopulation2_2::*)(::CellPtr)) &AbstractCentreBasedCellPopulation2_2::IsCellAssociatedWithADeletedLocation, "" , py::arg("pCell"))
        .def("GetNeighbouringLocationIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (AbstractCentreBasedCellPopulation2_2::*)(::CellPtr)) &AbstractCentreBasedCellPopulation2_2::GetNeighbouringLocationIndices, "" , py::arg("pCell"))
        .def("CheckForStepSizeException", (void (AbstractCentreBasedCellPopulation2_2::*)(unsigned int, ::boost::numeric::ublas::c_vector<double, 2> &, double)) &AbstractCentreBasedCellPopulation2_2::CheckForStepSizeException, "" , py::arg("nodeIndex"), py::arg("rDisplacement"), py::arg("dt"))
        .def("GetDampingConstant", (double (AbstractCentreBasedCellPopulation2_2::*)(unsigned int)) &AbstractCentreBasedCellPopulation2_2::GetDampingConstant, "" , py::arg("nodeIndex"))
        .def("IsGhostNode", (bool (AbstractCentreBasedCellPopulation2_2::*)(unsigned int)) &AbstractCentreBasedCellPopulation2_2::IsGhostNode, "" , py::arg("index"))
        .def("IsParticle", (bool (AbstractCentreBasedCellPopulation2_2::*)(unsigned int)) &AbstractCentreBasedCellPopulation2_2::IsParticle, "" , py::arg("index"))
        .def("rGetNodePairs", (::std::vector<std::pair<Node<2> *, Node<2> *>, std::allocator<std::pair<Node<2> *, Node<2> *> > > & (AbstractCentreBasedCellPopulation2_2::*)()) &AbstractCentreBasedCellPopulation2_2::rGetNodePairs, "" )
        .def("GetMeinekeDivisionSeparation", (double (AbstractCentreBasedCellPopulation2_2::*)()) &AbstractCentreBasedCellPopulation2_2::GetMeinekeDivisionSeparation, "" )
        .def("SetMeinekeDivisionSeparation", (void (AbstractCentreBasedCellPopulation2_2::*)(double)) &AbstractCentreBasedCellPopulation2_2::SetMeinekeDivisionSeparation, "" , py::arg("divisionSeparation"))
        .def("GetCentreBasedDivisionRule", (::boost::shared_ptr<AbstractCentreBasedDivisionRule<2, 2> > (AbstractCentreBasedCellPopulation2_2::*)()) &AbstractCentreBasedCellPopulation2_2::GetCentreBasedDivisionRule, "" )
        .def("SetCentreBasedDivisionRule", (void (AbstractCentreBasedCellPopulation2_2::*)(::boost::shared_ptr<AbstractCentreBasedDivisionRule<2, 2> >)) &AbstractCentreBasedCellPopulation2_2::SetCentreBasedDivisionRule, "" , py::arg("pCentreBasedDivisionRule"))
        .def("OutputCellPopulationParameters", (void (AbstractCentreBasedCellPopulation2_2::*)(::out_stream &)) &AbstractCentreBasedCellPopulation2_2::OutputCellPopulationParameters, "" , py::arg("rParamsFile"))
        .def("GetDefaultTimeStep", (double (AbstractCentreBasedCellPopulation2_2::*)()) &AbstractCentreBasedCellPopulation2_2::GetDefaultTimeStep, "" )
    ;
}
