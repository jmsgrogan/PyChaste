#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "VertexMesh2_2.pypp.hpp"

namespace py = pybind11;

typedef VertexMesh<2,2 > VertexMesh2_2;
class VertexMesh2_2_Overloads : public VertexMesh2_2{
    public:
    using VertexMesh2_2::VertexMesh<2, 2>;

        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        VertexMesh2_2,
        GetNumNodes,
        
        );
        }
        unsigned int GetNumElements() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        VertexMesh2_2,
        GetNumElements,
        
        );
        }
        unsigned int GetNumFaces() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        VertexMesh2_2,
        GetNumFaces,
        
        );
        }
        ::boost::numeric::ublas::c_vector<double, 2> GetCentroidOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_vector<double, 2>,
        VertexMesh2_2,
        GetCentroidOfElement,
        index        
        );
        }
        void Clear() override {
        PYBIND11_OVERLOAD(
        void,
        VertexMesh2_2,
        Clear,
        
        );
        }
        ::boost::numeric::ublas::c_vector<double, 2> GetVectorFromAtoB(::boost::numeric::ublas::c_vector<double, 2> const & rLocationA, ::boost::numeric::ublas::c_vector<double, 2> const & rLocationB) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_vector<double, 2>,
        VertexMesh2_2,
        GetVectorFromAtoB,
        rLocationA, 
        rLocationB        
        );
        }
        double GetVolumeOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        double,
        VertexMesh2_2,
        GetVolumeOfElement,
        index        
        );
        }
        double GetSurfaceAreaOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        double,
        VertexMesh2_2,
        GetSurfaceAreaOfElement,
        index        
        );
        }
        ::boost::numeric::ublas::c_vector<double, 3> CalculateMomentsOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_vector<double, 3>,
        VertexMesh2_2,
        CalculateMomentsOfElement,
        index        
        );
        }
        double CalculateAreaOfFace(::VertexElement<1, 2> * pFace) override {
        PYBIND11_OVERLOAD(
        double,
        VertexMesh2_2,
        CalculateAreaOfFace,
        pFace        
        );
        }
        unsigned int SolveNodeMapping(unsigned int index) override {
        PYBIND11_OVERLOAD(
        unsigned int,
        VertexMesh2_2,
        SolveNodeMapping,
        index        
        );
        }

};
void register_VertexMesh2_2_class(py::module &m){
    py::class_<VertexMesh2_2, VertexMesh2_2_Overloads, std::shared_ptr<VertexMesh2_2 >  >(m, "VertexMesh2_2")
        .def(py::init<::VertexMesh<2, 2> &, ::std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> *> >::iterator, bool >())
        .def(py::init<::std::vector<Node<2> *, std::allocator<Node<2> *> >, ::std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> *> > >())
        .def(py::init<::std::vector<Node<2> *, std::allocator<Node<2> *> >, ::std::vector<VertexElement<1, 2> *, std::allocator<VertexElement<1, 2> *> >, ::std::vector<VertexElement<2, 2> *, std::allocator<VertexElement<2, 2> *> > >())
        .def(py::init<::TetrahedralMesh<2, 2> &, bool >())
        .def(py::init<::TetrahedralMesh<3, 3> & >())
        .def(py::init< >())
        .def("GetElementIteratorBegin", (::VertexMesh<2, 2>::VertexElementIterator (VertexMesh2_2::*)(bool)) &VertexMesh2_2::GetElementIteratorBegin, "" , py::arg("skipDeletedElements") = true)
        .def("GetElementIteratorEnd", (::VertexMesh<2, 2>::VertexElementIterator (VertexMesh2_2::*)()) &VertexMesh2_2::GetElementIteratorEnd, "" )
        .def("GetNumNodes", (unsigned int (VertexMesh2_2::*)()) &VertexMesh2_2::GetNumNodes, "" )
        .def("GetNumElements", (unsigned int (VertexMesh2_2::*)()) &VertexMesh2_2::GetNumElements, "" )
        .def("GetNumAllElements", (unsigned int (VertexMesh2_2::*)()) &VertexMesh2_2::GetNumAllElements, "" )
        .def("GetNumFaces", (unsigned int (VertexMesh2_2::*)()) &VertexMesh2_2::GetNumFaces, "" )
        .def("GetElement", (::VertexElement<2, 2> * (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetElement, "" , py::arg("index"))
        .def("GetCentroidOfElement", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetCentroidOfElement, "" , py::arg("index"))
        .def("ConstructFromMeshReader", (void (VertexMesh2_2::*)(::AbstractMeshReader<2, 2> &)) &VertexMesh2_2::ConstructFromMeshReader, "" , py::arg("rMeshReader"))
        .def("Clear", (void (VertexMesh2_2::*)()) &VertexMesh2_2::Clear, "" )
        .def("GetDelaunayNodeIndexCorrespondingToVoronoiElementIndex", (unsigned int (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetDelaunayNodeIndexCorrespondingToVoronoiElementIndex, "" , py::arg("elementIndex"))
        .def("GetVoronoiElementIndexCorrespondingToDelaunayNodeIndex", (unsigned int (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetVoronoiElementIndexCorrespondingToDelaunayNodeIndex, "" , py::arg("nodeIndex"))
        .def("GetRosetteRankOfElement", (unsigned int (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetRosetteRankOfElement, "" , py::arg("index"))
        .def("GetVectorFromAtoB", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(::boost::numeric::ublas::c_vector<double, 2> const &, ::boost::numeric::ublas::c_vector<double, 2> const &)) &VertexMesh2_2::GetVectorFromAtoB, "" , py::arg("rLocationA"), py::arg("rLocationB"))
        .def("GetVolumeOfElement", (double (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetVolumeOfElement, "" , py::arg("index"))
        .def("GetSurfaceAreaOfElement", (double (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetSurfaceAreaOfElement, "" , py::arg("index"))
        .def("GetAreaGradientOfElementAtNode", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(::VertexElement<2, 2> *, unsigned int)) &VertexMesh2_2::GetAreaGradientOfElementAtNode, "" , py::arg("pElement"), py::arg("localIndex"))
        .def("GetPreviousEdgeGradientOfElementAtNode", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(::VertexElement<2, 2> *, unsigned int)) &VertexMesh2_2::GetPreviousEdgeGradientOfElementAtNode, "" , py::arg("pElement"), py::arg("localIndex"))
        .def("GetNextEdgeGradientOfElementAtNode", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(::VertexElement<2, 2> *, unsigned int)) &VertexMesh2_2::GetNextEdgeGradientOfElementAtNode, "" , py::arg("pElement"), py::arg("localIndex"))
        .def("GetPerimeterGradientOfElementAtNode", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(::VertexElement<2, 2> *, unsigned int)) &VertexMesh2_2::GetPerimeterGradientOfElementAtNode, "" , py::arg("pElement"), py::arg("localIndex"))
        .def("CalculateMomentsOfElement", (::boost::numeric::ublas::c_vector<double, 3> (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::CalculateMomentsOfElement, "" , py::arg("index"))
        .def("GetEdgeLength", (double (VertexMesh2_2::*)(unsigned int, unsigned int)) &VertexMesh2_2::GetEdgeLength, "" , py::arg("elementIndex1"), py::arg("elementIndex2"))
        .def("GetElongationShapeFactorOfElement", (double (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetElongationShapeFactorOfElement, "" , py::arg("elementIndex"))
        .def("CalculateUnitNormalToFaceWithArea", (double (VertexMesh2_2::*)(::VertexElement<1, 2> *, ::boost::numeric::ublas::c_vector<double, 2> &)) &VertexMesh2_2::CalculateUnitNormalToFaceWithArea, "" , py::arg("pFace"), py::arg("rNormal"))
        .def("CalculateAreaOfFace", (double (VertexMesh2_2::*)(::VertexElement<1, 2> *)) &VertexMesh2_2::CalculateAreaOfFace, "" , py::arg("pFace"))
        .def("GetShortAxisOfElement", (::boost::numeric::ublas::c_vector<double, 2> (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetShortAxisOfElement, "" , py::arg("index"))
        .def("GetNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetNeighbouringNodeIndices, "" , py::arg("nodeIndex"))
        .def("GetNeighbouringNodeNotAlsoInElement", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (VertexMesh2_2::*)(unsigned int, unsigned int)) &VertexMesh2_2::GetNeighbouringNodeNotAlsoInElement, "" , py::arg("nodeIndex"), py::arg("elemIndex"))
        .def("GetNeighbouringElementIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (VertexMesh2_2::*)(unsigned int)) &VertexMesh2_2::GetNeighbouringElementIndices, "" , py::arg("elementIndex"))
    ;
}
