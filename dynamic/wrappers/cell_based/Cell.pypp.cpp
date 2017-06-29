#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "Cell.pypp.hpp"

namespace py = pybind11;

typedef Cell Cell;

void register_Cell_class(py::module &m){
    py::class_<Cell, std::shared_ptr<Cell >  >(m, "Cell")
        .def(py::init<::boost::shared_ptr<AbstractCellProperty>, ::AbstractCellCycleModel *, ::AbstractSrnModel *, bool, ::CellPropertyCollection >())
        .def("GetCellProliferativeType", (::boost::shared_ptr<AbstractCellProliferativeType> (Cell::*)() const ) &Cell::GetCellProliferativeType, "" )
        .def("SetCellProliferativeType", (void (Cell::*)(::boost::shared_ptr<AbstractCellProperty>)) &Cell::SetCellProliferativeType, "" , py::arg("pProliferativeType"))
        .def("SetBirthTime", (void (Cell::*)(double)) &Cell::SetBirthTime, "" , py::arg("birthTime"))
        .def("SetCellCycleModel", (void (Cell::*)(::AbstractCellCycleModel *)) &Cell::SetCellCycleModel, "" , py::arg("pCellCycleModel"))
        .def("GetCellCycleModel", (::AbstractCellCycleModel * (Cell::*)() const ) &Cell::GetCellCycleModel, "" )
        .def("InitialiseCellCycleModel", (void (Cell::*)()) &Cell::InitialiseCellCycleModel, "" )
        .def("SetSrnModel", (void (Cell::*)(::AbstractSrnModel *)) &Cell::SetSrnModel, "" , py::arg("pSrnModel"))
        .def("InitialiseSrnModel", (void (Cell::*)()) &Cell::InitialiseSrnModel, "" )
        .def("GetAge", (double (Cell::*)() const ) &Cell::GetAge, "" )
        .def("GetBirthTime", (double (Cell::*)() const ) &Cell::GetBirthTime, "" )
        .def("GetStartOfApoptosisTime", (double (Cell::*)() const ) &Cell::GetStartOfApoptosisTime, "" )
        .def("GetApoptosisTime", (double (Cell::*)() const ) &Cell::GetApoptosisTime, "" )
        .def("SetApoptosisTime", (void (Cell::*)(double)) &Cell::SetApoptosisTime, "" , py::arg("apoptosisTime"))
        .def("GetMutationState", (::boost::shared_ptr<AbstractCellMutationState> (Cell::*)() const ) &Cell::GetMutationState, "" )
        .def("GetCellData", (::boost::shared_ptr<CellData> (Cell::*)() const ) &Cell::GetCellData, "" )
        .def("HasCellVecData", (bool (Cell::*)() const ) &Cell::HasCellVecData, "" )
        .def("GetCellVecData", (::boost::shared_ptr<CellVecData> (Cell::*)() const ) &Cell::GetCellVecData, "" )
        .def("SetMutationState", (void (Cell::*)(::boost::shared_ptr<AbstractCellProperty>)) &Cell::SetMutationState, "" , py::arg("pMutationState"))
        .def("AddCellProperty", (void (Cell::*)(::boost::shared_ptr<AbstractCellProperty> const &)) &Cell::AddCellProperty, "" , py::arg("rProperty"))
        .def("ReadyToDivide", (bool (Cell::*)()) &Cell::ReadyToDivide, "" )
        .def("Divide", (::CellPtr (Cell::*)()) &Cell::Divide, "" )
        .def("StartApoptosis", (void (Cell::*)(bool)) &Cell::StartApoptosis, "" , py::arg("setDeathTime") = true)
        .def("Kill", (void (Cell::*)()) &Cell::Kill, "" )
        .def("HasApoptosisBegun", (bool (Cell::*)() const ) &Cell::HasApoptosisBegun, "" )
        .def("GetTimeUntilDeath", (double (Cell::*)() const ) &Cell::GetTimeUntilDeath, "" )
        .def("IsDead", (bool (Cell::*)()) &Cell::IsDead, "" )
        .def("SetLogged", (void (Cell::*)()) &Cell::SetLogged, "" )
        .def("IsLogged", (bool (Cell::*)()) &Cell::IsLogged, "" )
        .def("SetAncestor", (void (Cell::*)(::boost::shared_ptr<AbstractCellProperty>)) &Cell::SetAncestor, "" , py::arg("pCellAncestor"))
        .def("GetAncestor", (unsigned int (Cell::*)() const ) &Cell::GetAncestor, "" )
        .def("GetCellId", (unsigned int (Cell::*)() const ) &Cell::GetCellId, "" )
    ;
}
