#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "Node3.pypp.hpp"

namespace py = pybind11;

typedef Node<3 > Node3;

void register_Node3_class(py::module &m){
    py::class_<Node3, std::shared_ptr<Node3 >  >(m, "Node3")
        .def(py::init<unsigned int, ::ChastePoint<3>, bool >())
        .def(py::init<unsigned int, ::std::vector<double, std::allocator<double> >, bool >())
        .def(py::init<unsigned int, ::boost::numeric::ublas::c_vector<double, 3>, bool >())
        .def(py::init<unsigned int, bool, double, double, double >())
        .def(py::init<unsigned int, double *, bool >())
        .def("SetPoint", (void (Node3::*)(::ChastePoint<3>)) &Node3::SetPoint, "" , py::arg("point"))
        .def("SetIndex", (void (Node3::*)(unsigned int)) &Node3::SetIndex, "" , py::arg("index"))
        .def("AddNodeAttribute", (void (Node3::*)(double)) &Node3::AddNodeAttribute, "" , py::arg("attribute"))
        .def("SetAsBoundaryNode", (void (Node3::*)(bool)) &Node3::SetAsBoundaryNode, "" , py::arg("value") = true)
        .def("GetPoint", (::ChastePoint<3> (Node3::*)() const ) &Node3::GetPoint, "" )
        .def("rGetLocation", (::boost::numeric::ublas::c_vector<double, 3> const & (Node3::*)() const ) &Node3::rGetLocation, "" )
        .def("rGetModifiableLocation", (::boost::numeric::ublas::c_vector<double, 3> & (Node3::*)()) &Node3::rGetModifiableLocation, "" )
        .def("GetIndex", (unsigned int (Node3::*)() const ) &Node3::GetIndex, "" )
        .def("IsBoundaryNode", (bool (Node3::*)() const ) &Node3::IsBoundaryNode, "" )
        .def("AddElement", (void (Node3::*)(unsigned int)) &Node3::AddElement, "" , py::arg("index"))
        .def("RemoveElement", (void (Node3::*)(unsigned int)) &Node3::RemoveElement, "" , py::arg("index"))
        .def("RemoveBoundaryElement", (void (Node3::*)(unsigned int)) &Node3::RemoveBoundaryElement, "" , py::arg("index"))
        .def("AddBoundaryElement", (void (Node3::*)(unsigned int)) &Node3::AddBoundaryElement, "" , py::arg("index"))
        .def("AddNeighbour", (void (Node3::*)(unsigned int)) &Node3::AddNeighbour, "" , py::arg("index"))
        .def("ClearNeighbours", (void (Node3::*)()) &Node3::ClearNeighbours, "" )
        .def("RemoveDuplicateNeighbours", (void (Node3::*)()) &Node3::RemoveDuplicateNeighbours, "" )
        .def("NeighboursIsEmpty", (bool (Node3::*)()) &Node3::NeighboursIsEmpty, "" )
        .def("SetNeighboursSetUp", (void (Node3::*)(bool)) &Node3::SetNeighboursSetUp, "" , py::arg("flag"))
        .def("GetNeighboursSetUp", (bool (Node3::*)()) &Node3::GetNeighboursSetUp, "" )
        .def("rGetNeighbours", (::std::vector<unsigned int, std::allocator<unsigned int> > & (Node3::*)()) &Node3::rGetNeighbours, "" )
        .def("rGetContainingElementIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > & (Node3::*)()) &Node3::rGetContainingElementIndices, "" )
        .def("rGetNodeAttributes", (::std::vector<double, std::allocator<double> > & (Node3::*)()) &Node3::rGetNodeAttributes, "" )
        .def("GetNumNodeAttributes", (unsigned int (Node3::*)()) &Node3::GetNumNodeAttributes, "" )
        .def("HasNodeAttributes", (bool (Node3::*)()) &Node3::HasNodeAttributes, "" )
        .def("rGetContainingBoundaryElementIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > & (Node3::*)()) &Node3::rGetContainingBoundaryElementIndices, "" )
        .def("GetNumContainingElements", (unsigned int (Node3::*)() const ) &Node3::GetNumContainingElements, "" )
        .def("GetNumBoundaryElements", (unsigned int (Node3::*)() const ) &Node3::GetNumBoundaryElements, "" )
        .def("rGetAppliedForce", (::boost::numeric::ublas::c_vector<double, 3> & (Node3::*)()) &Node3::rGetAppliedForce, "" )
        .def("ClearAppliedForce", (void (Node3::*)()) &Node3::ClearAppliedForce, "" )
        .def("AddAppliedForceContribution", (void (Node3::*)(::boost::numeric::ublas::c_vector<double, 3> &)) &Node3::AddAppliedForceContribution, "" , py::arg("forceContribution"))
        .def("IsParticle", (bool (Node3::*)()) &Node3::IsParticle, "" )
        .def("SetIsParticle", (void (Node3::*)(bool)) &Node3::SetIsParticle, "" , py::arg("isParticle"))
        .def("GetRadius", (double (Node3::*)()) &Node3::GetRadius, "" )
        .def("SetRadius", (void (Node3::*)(double)) &Node3::SetRadius, "" , py::arg("radius"))
        .def("MarkAsDeleted", (void (Node3::*)()) &Node3::MarkAsDeleted, "" )
        .def("IsDeleted", (bool (Node3::*)() const ) &Node3::IsDeleted, "" )
        .def("MarkAsInternal", (void (Node3::*)()) &Node3::MarkAsInternal, "" )
        .def("IsInternal", (bool (Node3::*)() const ) &Node3::IsInternal, "" )
        .def("SetRegion", (void (Node3::*)(unsigned int)) &Node3::SetRegion, "" , py::arg("region"))
        .def("GetRegion", (unsigned int (Node3::*)() const ) &Node3::GetRegion, "" )
        .def("ContainingElementsBegin", (::Node<3>::ContainingElementIterator (Node3::*)() const ) &Node3::ContainingElementsBegin, "" )
        .def("ContainingElementsEnd", (::Node<3>::ContainingElementIterator (Node3::*)() const ) &Node3::ContainingElementsEnd, "" )
        .def("ContainingBoundaryElementsBegin", (::Node<3>::ContainingBoundaryElementIterator (Node3::*)() const ) &Node3::ContainingBoundaryElementsBegin, "" )
        .def("ContainingBoundaryElementsEnd", (::Node<3>::ContainingBoundaryElementIterator (Node3::*)() const ) &Node3::ContainingBoundaryElementsEnd, "" )
    ;
}
