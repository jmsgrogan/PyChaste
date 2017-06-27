#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PottsMesh3.pypp.hpp"

namespace py = pybind11;

typedef PottsMesh<3 > PottsMesh3;
class PottsMesh3_Overloads : public PottsMesh3{
    public:
    using PottsMesh3::PottsMesh<3>;

        unsigned int GetNumNodes() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        PottsMesh3,
        GetNumNodes,
        
        );
        }
        unsigned int GetNumElements() override {
        PYBIND11_OVERLOAD(
        unsigned int,
        PottsMesh3,
        GetNumElements,
        
        );
        }
        ::boost::numeric::ublas::c_vector<double, 3> GetCentroidOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        ::boost::numeric::ublas::c_vector<double, 3>,
        PottsMesh3,
        GetCentroidOfElement,
        index        
        );
        }
        void Clear() override {
        PYBIND11_OVERLOAD(
        void,
        PottsMesh3,
        Clear,
        
        );
        }
        double GetVolumeOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        double,
        PottsMesh3,
        GetVolumeOfElement,
        index        
        );
        }
        double GetSurfaceAreaOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
        double,
        PottsMesh3,
        GetSurfaceAreaOfElement,
        index        
        );
        }
        unsigned int SolveNodeMapping(unsigned int index) override {
        PYBIND11_OVERLOAD(
        unsigned int,
        PottsMesh3,
        SolveNodeMapping,
        index        
        );
        }

};
void register_PottsMesh3_class(py::module &m){
    py::class_<PottsMesh3, PottsMesh3_Overloads, std::shared_ptr<PottsMesh3 >  >(m, "PottsMesh3")
        .def(py::init<::PottsMesh<3> &, ::std::vector<PottsElement<3> *, std::allocator<PottsElement<3> *> >::iterator, bool >())
        .def(py::init<::std::vector<Node<3> *, std::allocator<Node<3> *> >, ::std::vector<PottsElement<3> *, std::allocator<PottsElement<3> *> >, ::std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > >, ::std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > > >())
        .def(py::init< >())
        .def("GetElementIteratorBegin", (::PottsMesh<3>::PottsElementIterator (PottsMesh3::*)(bool)) &PottsMesh3::GetElementIteratorBegin, "" , py::arg("skipDeletedElements") = true)
        .def("GetElementIteratorEnd", (::PottsMesh<3>::PottsElementIterator (PottsMesh3::*)()) &PottsMesh3::GetElementIteratorEnd, "" )
        .def("GetNumNodes", (unsigned int (PottsMesh3::*)()) &PottsMesh3::GetNumNodes, "" )
        .def("GetNumElements", (unsigned int (PottsMesh3::*)()) &PottsMesh3::GetNumElements, "" )
        .def("GetNumAllElements", (unsigned int (PottsMesh3::*)()) &PottsMesh3::GetNumAllElements, "" )
        .def("GetElement", (::PottsElement<3> * (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetElement, "" , py::arg("index"))
        .def("GetCentroidOfElement", (::boost::numeric::ublas::c_vector<double, 3> (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetCentroidOfElement, "" , py::arg("index"))
        .def("ConstructFromMeshReader", (void (PottsMesh3::*)(::AbstractMeshReader<3, 3> &)) &PottsMesh3::ConstructFromMeshReader, "" , py::arg("rMeshReader"))
        .def("Clear", (void (PottsMesh3::*)()) &PottsMesh3::Clear, "" )
        .def("GetVolumeOfElement", (double (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetVolumeOfElement, "" , py::arg("index"))
        .def("GetSurfaceAreaOfElement", (double (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetSurfaceAreaOfElement, "" , py::arg("index"))
        .def("GetMooreNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetMooreNeighbouringNodeIndices, "" , py::arg("nodeIndex"))
        .def("GetVonNeumannNeighbouringNodeIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetVonNeumannNeighbouringNodeIndices, "" , py::arg("nodeIndex"))
        .def("DeleteNode", (void (PottsMesh3::*)(unsigned int)) &PottsMesh3::DeleteNode, "" , py::arg("index"))
        .def("DeleteElement", (void (PottsMesh3::*)(unsigned int)) &PottsMesh3::DeleteElement, "" , py::arg("index"))
        .def("RemoveDeletedElements", (void (PottsMesh3::*)()) &PottsMesh3::RemoveDeletedElements, "" )
        .def("DivideElement", (unsigned int (PottsMesh3::*)(::PottsElement<3> *, bool)) &PottsMesh3::DivideElement, "" , py::arg("pElement"), py::arg("placeOriginalElementBelow") = false)
        .def("AddElement", (unsigned int (PottsMesh3::*)(::PottsElement<3> *)) &PottsMesh3::AddElement, "" , py::arg("pNewElement"))
        .def("GetNeighbouringElementIndices", (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > (PottsMesh3::*)(unsigned int)) &PottsMesh3::GetNeighbouringElementIndices, "" , py::arg("elementIndex"))
    ;
}
