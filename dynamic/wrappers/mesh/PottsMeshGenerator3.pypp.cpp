#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "PottsMeshGenerator3.pypp.hpp"

namespace py = pybind11;
typedef SharedPottsMeshGenerator<3 > PottsMeshGenerator3;
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
typedef ::boost::shared_ptr<PottsMesh<3> > _boost_shared_ptrPottsMesh3;

class PottsMeshGenerator3_Overloads : public PottsMeshGenerator3{
    public:
    using PottsMeshGenerator3::SharedPottsMeshGenerator;
    ::boost::shared_ptr<PottsMesh<3> > GetMesh() override {
        PYBIND11_OVERLOAD(
            _boost_shared_ptrPottsMesh3,
            PottsMeshGenerator3,
            GetMesh,
            );
    }

};
void register_PottsMeshGenerator3_class(py::module &m){
py::class_<PottsMeshGenerator3 , PottsMeshGenerator3_Overloads , boost::shared_ptr<PottsMeshGenerator3 >   >(m, "PottsMeshGenerator3")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool, bool, bool >())
        .def(py::init< >())
        .def(
            "GetMesh", 
            (::boost::shared_ptr<PottsMesh<3> >(PottsMeshGenerator3::*)()) &PottsMeshGenerator3::GetMesh, 
            " " )
    ;
}
