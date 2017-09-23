#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "SmartPointers.hpp"
#include "UblasIncludes.hpp"
#include "PottsMesh.hpp"

#include "PythonObjectConverters.hpp"
#include "PottsMesh2.cppwg.hpp"

namespace py = pybind11;
PYBIND11_CVECTOR_TYPECASTER2();
PYBIND11_CVECTOR_TYPECASTER3();   
typedef PottsMesh<2 > PottsMesh2;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef unsigned int unsignedint;
typedef unsigned int unsignedint;
typedef ::boost::numeric::ublas::c_vector<double, 2> _boost_numeric_ublas_c_vector_lt_double_2_gt_;
typedef unsigned int unsignedint;

class PottsMesh2_Overloads : public PottsMesh2{
    public:
    using PottsMesh2::PottsMesh;
    unsigned int GetNumNodes() const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            PottsMesh2,
            GetNumNodes,
            );
    }
    unsigned int GetNumElements() const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            PottsMesh2,
            GetNumElements,
            );
    }
    ::boost::numeric::ublas::c_vector<double, 2> GetCentroidOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
            _boost_numeric_ublas_c_vector_lt_double_2_gt_,
            PottsMesh2,
            GetCentroidOfElement,
            index);
    }
    void Clear() override {
        PYBIND11_OVERLOAD(
            void,
            PottsMesh2,
            Clear,
            );
    }
    double GetVolumeOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
            double,
            PottsMesh2,
            GetVolumeOfElement,
            index);
    }
    double GetSurfaceAreaOfElement(unsigned int index) override {
        PYBIND11_OVERLOAD(
            double,
            PottsMesh2,
            GetSurfaceAreaOfElement,
            index);
    }
    unsigned int SolveNodeMapping(unsigned int index) const  override {
        PYBIND11_OVERLOAD(
            unsignedint,
            PottsMesh2,
            SolveNodeMapping,
            index);
    }

};
void register_PottsMesh2_class(py::module &m){
py::class_<PottsMesh2 , PottsMesh2_Overloads , boost::shared_ptr<PottsMesh2 >  , AbstractMesh<2, 2>  >(m, "PottsMesh2")
        .def(py::init<::std::vector<Node<2> *, std::allocator<Node<2> *> >, ::std::vector<PottsElement<2> *, std::allocator<PottsElement<2> *> >, ::std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > >, ::std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > > >(), py::arg("nodes"), py::arg("pottsElements"), py::arg("vonNeumannNeighbouringNodeIndices"), py::arg("mooreNeighbouringNodeIndices"))
        .def(py::init< >())
        .def(
            "GetElementIteratorBegin", 
            (::PottsMesh<2>::PottsElementIterator(PottsMesh2::*)(bool)) &PottsMesh2::GetElementIteratorBegin, 
            " " , py::arg("skipDeletedElements") = true )
        .def(
            "GetElementIteratorEnd", 
            (::PottsMesh<2>::PottsElementIterator(PottsMesh2::*)()) &PottsMesh2::GetElementIteratorEnd, 
            " "  )
        .def(
            "GetNumNodes", 
            (unsigned int(PottsMesh2::*)() const ) &PottsMesh2::GetNumNodes, 
            " "  )
        .def(
            "GetNumElements", 
            (unsigned int(PottsMesh2::*)() const ) &PottsMesh2::GetNumElements, 
            " "  )
        .def(
            "GetNumAllElements", 
            (unsigned int(PottsMesh2::*)() const ) &PottsMesh2::GetNumAllElements, 
            " "  )
        .def(
            "GetElement", 
            (::PottsElement<2> *(PottsMesh2::*)(unsigned int) const ) &PottsMesh2::GetElement, 
            " " , py::arg("index") , py::return_value_policy::reference)
        .def(
            "GetCentroidOfElement", 
            (::boost::numeric::ublas::c_vector<double, 2>(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetCentroidOfElement, 
            " " , py::arg("index") )
        .def(
            "ConstructFromMeshReader", 
            (void(PottsMesh2::*)(::AbstractMeshReader<2, 2> &)) &PottsMesh2::ConstructFromMeshReader, 
            " " , py::arg("rMeshReader") )
        .def(
            "Clear", 
            (void(PottsMesh2::*)()) &PottsMesh2::Clear, 
            " "  )
        .def(
            "GetVolumeOfElement", 
            (double(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetVolumeOfElement, 
            " " , py::arg("index") )
        .def(
            "GetSurfaceAreaOfElement", 
            (double(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetSurfaceAreaOfElement, 
            " " , py::arg("index") )
        .def(
            "GetMooreNeighbouringNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetMooreNeighbouringNodeIndices, 
            " " , py::arg("nodeIndex") )
        .def(
            "GetVonNeumannNeighbouringNodeIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetVonNeumannNeighbouringNodeIndices, 
            " " , py::arg("nodeIndex") )
        .def(
            "DeleteNode", 
            (void(PottsMesh2::*)(unsigned int)) &PottsMesh2::DeleteNode, 
            " " , py::arg("index") )
        .def(
            "DeleteElement", 
            (void(PottsMesh2::*)(unsigned int)) &PottsMesh2::DeleteElement, 
            " " , py::arg("index") )
        .def(
            "RemoveDeletedElements", 
            (void(PottsMesh2::*)()) &PottsMesh2::RemoveDeletedElements, 
            " "  )
        .def(
            "DivideElement", 
            (unsigned int(PottsMesh2::*)(::PottsElement<2> *, bool)) &PottsMesh2::DivideElement, 
            " " , py::arg("pElement"), py::arg("placeOriginalElementBelow") = false )
        .def(
            "AddElement", 
            (unsigned int(PottsMesh2::*)(::PottsElement<2> *)) &PottsMesh2::AddElement, 
            " " , py::arg("pNewElement") )
        .def(
            "GetNeighbouringElementIndices", 
            (::std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >(PottsMesh2::*)(unsigned int)) &PottsMesh2::GetNeighbouringElementIndices, 
            " " , py::arg("elementIndex") )
    ;
}
