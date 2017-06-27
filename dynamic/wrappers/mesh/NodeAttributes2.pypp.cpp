#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "NodeAttributes2.pypp.hpp"

namespace py = pybind11;

typedef NodeAttributes<2 > NodeAttributes2;
void register_NodeAttributes2_class(py::module &m){
    py::class_<NodeAttributes2, std::shared_ptr<NodeAttributes2 >  >(m, "NodeAttributes2")
        .def(py::init< >())
        .def("rGetAttributes", (::std::vector<double, std::allocator<double> > & (NodeAttributes2::*)()) &NodeAttributes2::rGetAttributes, "" )
        .def("AddAttribute", (void (NodeAttributes2::*)(double)) &NodeAttributes2::AddAttribute, "" , py::arg("attribute"))
        .def("GetRegion", (unsigned int (NodeAttributes2::*)()) &NodeAttributes2::GetRegion, "" )
        .def("SetRegion", (void (NodeAttributes2::*)(unsigned int)) &NodeAttributes2::SetRegion, "" , py::arg("region"))
        .def("rGetAppliedForce", (::boost::numeric::ublas::c_vector<double, 2> & (NodeAttributes2::*)()) &NodeAttributes2::rGetAppliedForce, "" )
        .def("AddAppliedForceContribution", (void (NodeAttributes2::*)(::boost::numeric::ublas::c_vector<double, 2> &)) &NodeAttributes2::AddAppliedForceContribution, "" , py::arg("appliedForceContribution"))
        .def("ClearAppliedForce", (void (NodeAttributes2::*)()) &NodeAttributes2::ClearAppliedForce, "" )
        .def("AddNeighbour", (void (NodeAttributes2::*)(unsigned int)) &NodeAttributes2::AddNeighbour, "" , py::arg("index"))
        .def("ClearNeighbours", (void (NodeAttributes2::*)()) &NodeAttributes2::ClearNeighbours, "" )
        .def("RemoveDuplicateNeighbours", (void (NodeAttributes2::*)()) &NodeAttributes2::RemoveDuplicateNeighbours, "" )
        .def("NeighboursIsEmpty", (bool (NodeAttributes2::*)()) &NodeAttributes2::NeighboursIsEmpty, "" )
        .def("SetNeighboursSetUp", (void (NodeAttributes2::*)(bool)) &NodeAttributes2::SetNeighboursSetUp, "" , py::arg("flag"))
        .def("GetNeighboursSetUp", (bool (NodeAttributes2::*)()) &NodeAttributes2::GetNeighboursSetUp, "" )
        .def("rGetNeighbours", (::std::vector<unsigned int, std::allocator<unsigned int> > & (NodeAttributes2::*)()) &NodeAttributes2::rGetNeighbours, "" )
        .def("IsParticle", (bool (NodeAttributes2::*)()) &NodeAttributes2::IsParticle, "" )
        .def("SetIsParticle", (void (NodeAttributes2::*)(bool)) &NodeAttributes2::SetIsParticle, "" , py::arg("isParticle"))
        .def("GetRadius", (double (NodeAttributes2::*)()) &NodeAttributes2::GetRadius, "" )
        .def("SetRadius", (void (NodeAttributes2::*)(double)) &NodeAttributes2::SetRadius, "" , py::arg("radius"))
    ;
}
