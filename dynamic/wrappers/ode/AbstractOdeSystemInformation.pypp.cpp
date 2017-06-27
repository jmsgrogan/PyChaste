#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "AbstractOdeSystemInformation.pypp.hpp"

namespace py = pybind11;

typedef AbstractOdeSystemInformation AbstractOdeSystemInformation;
class AbstractOdeSystemInformation_Overloads : public AbstractOdeSystemInformation{
    public:
    using AbstractOdeSystemInformation::AbstractOdeSystemInformation;

        void Initialise() override {
        PYBIND11_OVERLOAD_PURE(
        void,
        AbstractOdeSystemInformation,
        Initialise,
        
        );
        }

};
void register_AbstractOdeSystemInformation_class(py::module &m){
    py::class_<AbstractOdeSystemInformation, AbstractOdeSystemInformation_Overloads, std::shared_ptr<AbstractOdeSystemInformation >  >(m, "AbstractOdeSystemInformation")
        .def("GetSystemName", (::std::string (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetSystemName, "" )
        .def("GetFreeVariableName", (::std::string (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetFreeVariableName, "" )
        .def("GetFreeVariableUnits", (::std::string (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetFreeVariableUnits, "" )
        .def("SetDefaultInitialConditions", (void (AbstractOdeSystemInformation::*)(::std::vector<double, std::allocator<double> > const &)) &AbstractOdeSystemInformation::SetDefaultInitialConditions, "" , py::arg("rInitialConditions"))
        .def("SetDefaultInitialCondition", (void (AbstractOdeSystemInformation::*)(unsigned int, double)) &AbstractOdeSystemInformation::SetDefaultInitialCondition, "" , py::arg("index"), py::arg("initialCondition"))
        .def("GetInitialConditions", (::std::vector<double, std::allocator<double> > (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetInitialConditions, "" )
        .def("rGetStateVariableNames", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetStateVariableNames, "" )
        .def("rGetStateVariableUnits", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetStateVariableUnits, "" )
        .def("GetStateVariableIndex", (unsigned int (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::GetStateVariableIndex, "" , py::arg("rName"))
        .def("HasStateVariable", (bool (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::HasStateVariable, "" , py::arg("rName"))
        .def("GetStateVariableUnits", (::std::string (AbstractOdeSystemInformation::*)(unsigned int)) &AbstractOdeSystemInformation::GetStateVariableUnits, "" , py::arg("index"))
        .def("rGetParameterNames", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetParameterNames, "" )
        .def("rGetParameterUnits", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetParameterUnits, "" )
        .def("GetParameterIndex", (unsigned int (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::GetParameterIndex, "" , py::arg("rName"))
        .def("HasParameter", (bool (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::HasParameter, "" , py::arg("rName"))
        .def("GetParameterUnits", (::std::string (AbstractOdeSystemInformation::*)(unsigned int)) &AbstractOdeSystemInformation::GetParameterUnits, "" , py::arg("index"))
        .def("GetNumberOfParameters", (unsigned int (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetNumberOfParameters, "" )
        .def("GetAnyVariableIndex", (unsigned int (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::GetAnyVariableIndex, "" , py::arg("rName"))
        .def("HasAnyVariable", (bool (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::HasAnyVariable, "" , py::arg("rName"))
        .def("GetAnyVariableUnits", (::std::string (AbstractOdeSystemInformation::*)(unsigned int)) &AbstractOdeSystemInformation::GetAnyVariableUnits, "" , py::arg("index"))
        .def("rGetDerivedQuantityNames", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetDerivedQuantityNames, "" )
        .def("rGetDerivedQuantityUnits", (::std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > const & (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::rGetDerivedQuantityUnits, "" )
        .def("GetDerivedQuantityIndex", (unsigned int (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::GetDerivedQuantityIndex, "" , py::arg("rName"))
        .def("HasDerivedQuantity", (bool (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::HasDerivedQuantity, "" , py::arg("rName"))
        .def("GetDerivedQuantityUnits", (::std::string (AbstractOdeSystemInformation::*)(unsigned int)) &AbstractOdeSystemInformation::GetDerivedQuantityUnits, "" , py::arg("index"))
        .def("GetNumberOfDerivedQuantities", (unsigned int (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetNumberOfDerivedQuantities, "" )
        .def("GetNumberOfAttributes", (unsigned int (AbstractOdeSystemInformation::*)()) &AbstractOdeSystemInformation::GetNumberOfAttributes, "" )
        .def("HasAttribute", (bool (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::HasAttribute, "" , py::arg("rName"))
        .def("GetAttribute", (double (AbstractOdeSystemInformation::*)(::std::string const &)) &AbstractOdeSystemInformation::GetAttribute, "" , py::arg("rName"))
    ;
}
