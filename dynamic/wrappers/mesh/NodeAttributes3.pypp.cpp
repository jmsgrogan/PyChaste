#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "NodeAttributes3.pypp.hpp"

namespace py = pybind11;

typedef NodeAttributes<3 > NodeAttributes3;
void register_NodeAttributes3_class(py::module &m){
    py::class_<NodeAttributes3, std::shared_ptr<NodeAttributes3 >  >(m, "NodeAttributes3")
        .def(py::init< >())
        .def("rGetAttributes", (::std::vector<double, std::allocator<double> > & (NodeAttributes3::*)()) &NodeAttributes3::rGetAttributes, "" )
        .def("AddAttribute", (void (NodeAttributes3::*)(double)) &NodeAttributes3::AddAttribute, "" , py::arg("attribute"))
        .def("GetRegion", (unsigned int (NodeAttributes3::*)()) &NodeAttributes3::GetRegion, "" )
        .def("SetRegion", (void (NodeAttributes3::*)(unsigned int)) &NodeAttributes3::SetRegion, "" , py::arg("region"))
        .def("rGetAppliedForce", (::boost::numeric::ublas::c_vector<double, 3> & (NodeAttributes3::*)()) &NodeAttributes3::rGetAppliedForce, "" )
        .def("AddAppliedForceContribution", (void (NodeAttributes3::*)(::boost::numeric::ublas::c_vector<double, 3> &)) &NodeAttributes3::AddAppliedForceContribution, "" , py::arg("appliedForceContribution"))
        .def("ClearAppliedForce", (void (NodeAttributes3::*)()) &NodeAttributes3::ClearAppliedForce, "" )
        .def("AddNeighbour", (void (NodeAttributes3::*)(unsigned int)) &NodeAttributes3::AddNeighbour, "" , py::arg("index"))
        .def("ClearNeighbours", (void (NodeAttributes3::*)()) &NodeAttributes3::ClearNeighbours, "" )
        .def("RemoveDuplicateNeighbours", (void (NodeAttributes3::*)()) &NodeAttributes3::RemoveDuplicateNeighbours, "" )
        .def("NeighboursIsEmpty", (bool (NodeAttributes3::*)()) &NodeAttributes3::NeighboursIsEmpty, "" )
        .def("SetNeighboursSetUp", (void (NodeAttributes3::*)(bool)) &NodeAttributes3::SetNeighboursSetUp, "" , py::arg("flag"))
        .def("GetNeighboursSetUp", (bool (NodeAttributes3::*)()) &NodeAttributes3::GetNeighboursSetUp, "" )
        .def("rGetNeighbours", (::std::vector<unsigned int, std::allocator<unsigned int> > & (NodeAttributes3::*)()) &NodeAttributes3::rGetNeighbours, "" )
        .def("IsParticle", (bool (NodeAttributes3::*)()) &NodeAttributes3::IsParticle, "" )
        .def("SetIsParticle", (void (NodeAttributes3::*)(bool)) &NodeAttributes3::SetIsParticle, "" , py::arg("isParticle"))
        .def("GetRadius", (double (NodeAttributes3::*)()) &NodeAttributes3::GetRadius, "" )
        .def("SetRadius", (void (NodeAttributes3::*)(double)) &NodeAttributes3::SetRadius, "" , py::arg("radius"))
    ;
}
