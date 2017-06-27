#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PottsMeshGenerator2.pypp.hpp"

namespace py = pybind11;

typedef SharedPottsMeshGenerator<2 > PottsMeshGenerator2;
class PottsMeshGenerator2_Overloads : public PottsMeshGenerator2{
    public:
    using PottsMeshGenerator2::SharedPottsMeshGenerator<2>;

        ::boost::shared_ptr<PottsMesh<2> > GetMesh() override {
        PYBIND11_OVERLOAD(
        ::boost::shared_ptr<PottsMesh<2> >,
        PottsMeshGenerator2,
        GetMesh,
        
        );
        }

};
void register_PottsMeshGenerator2_class(py::module &m){
    py::class_<PottsMeshGenerator2, PottsMeshGenerator2_Overloads, std::shared_ptr<PottsMeshGenerator2 >  >(m, "PottsMeshGenerator2")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool, bool, bool >())
        .def(py::init< >())
        .def("GetMesh", (::boost::shared_ptr<PottsMesh<2> > (PottsMeshGenerator2::*)()) &PottsMeshGenerator2::GetMesh, "" )
    ;
}
