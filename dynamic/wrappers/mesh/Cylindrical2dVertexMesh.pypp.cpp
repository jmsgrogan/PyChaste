#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "Cylindrical2dVertexMesh.pypp.hpp"

namespace py = pybind11;

typedef Cylindrical2dVertexMesh Cylindrical2dVertexMesh;
class Cylindrical2dVertexMesh_Overloads : public Cylindrical2dVertexMesh{
    public:
    using Cylindrical2dVertexMesh::Cylindrical2dVertexMesh;

        ::boost::numeric::ublas::c_vector<double, 2> GetVectorFromAtoB(::boost::numeric::ublas::c_vector<double, 2> const & rLocation1, ::boost::numeric::ublas::c_vector<double, 2> const & rLocation2) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_vector<double, 2>,
        Cylindrical2dVertexMesh,
        GetVectorFromAtoB,
        rLocation1, 
        rLocation2        
        );
        }
        void SetNode(unsigned int nodeIndex, ::ChastePoint<2> point) override {
        PYBIND11_OVERLOAD(
        void,
        Cylindrical2dVertexMesh,
        SetNode,
        nodeIndex, 
        point        
        );
        }
        double GetWidth(unsigned int const & rDimension) override {
        PYBIND11_OVERLOAD(
        double,
        Cylindrical2dVertexMesh,
        GetWidth,
        rDimension        
        );
        }
        void Scale(double const xScale, double const yScale, double const zScale) override {
        PYBIND11_OVERLOAD(
        void,
        Cylindrical2dVertexMesh,
        Scale,
        xScale, 
        yScale, 
        zScale        
        );
        }

};
void register_Cylindrical2dVertexMesh_class(py::module &m){
    py::class_<Cylindrical2dVertexMesh, Cylindrical2dVertexMesh_Overloads, std::shared_ptr<Cylindrical2dVertexMesh >  >(m, "Cylindrical2dVertexMesh")
        .def(py::init<double, ::std::vector<Node<2> *, std::allocator<Node<2> *> >, ::std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> *> >, double, double >())
        .def(py::init<::Cylindrical2dMesh & >())
        .def("GetVectorFromAtoB", (::boost::numeric::ublas::c_vector<double, 2> (Cylindrical2dVertexMesh::*)(::boost::numeric::ublas::c_vector<double, 2> const &, ::boost::numeric::ublas::c_vector<double, 2> const &)) &Cylindrical2dVertexMesh::GetVectorFromAtoB, "" , py::arg("rLocation1"), py::arg("rLocation2"))
        .def("SetNode", (void (Cylindrical2dVertexMesh::*)(unsigned int, ::ChastePoint<2>)) &Cylindrical2dVertexMesh::SetNode, "" , py::arg("nodeIndex"), py::arg("point"))
        .def("GetWidth", (double (Cylindrical2dVertexMesh::*)(unsigned int const &)) &Cylindrical2dVertexMesh::GetWidth, "" , py::arg("rDimension"))
        .def("AddNode", (unsigned int (Cylindrical2dVertexMesh::*)(::Node<2> *)) &Cylindrical2dVertexMesh::AddNode, "" , py::arg("pNewNode"))
        .def("Scale", (void (Cylindrical2dVertexMesh::*)(double const, double const, double const)) &Cylindrical2dVertexMesh::Scale, "" , py::arg("xScale") = 1., py::arg("yScale") = 1., py::arg("zScale") = 1.)
        .def("GetMeshForVtk", (::MutableVertexMesh<2, 2> * (Cylindrical2dVertexMesh::*)()) &Cylindrical2dVertexMesh::GetMeshForVtk, "" )
    ;
}
