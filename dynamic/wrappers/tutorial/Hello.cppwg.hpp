#ifndef Hello_hpp__pyplusplus_wrapper
#define Hello_hpp__pyplusplus_wrapper

namespace py = pybind11;
void register_Hello_class(py::module &m);
#endif // Hello_hpp__pyplusplus_wrapper
