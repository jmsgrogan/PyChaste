#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"
#include "OutputFileHandler.pypp.hpp"

namespace py = pybind11;

typedef OutputFileHandler OutputFileHandler;
void register_OutputFileHandler_class(py::module &m){
    py::class_<OutputFileHandler, std::shared_ptr<OutputFileHandler >  >(m, "OutputFileHandler")
        .def(py::init<::std::string const &, bool >())
        .def(py::init<::FileFinder const &, bool >())
        .def_static("GetChasteTestOutputDirectory", (::std::string (*)()) &OutputFileHandler::GetChasteTestOutputDirectory, "" )
        .def("GetOutputDirectoryFullPath", (::std::string (OutputFileHandler::*)()) &OutputFileHandler::GetOutputDirectoryFullPath, "" )
        .def("GetRelativePath", (::std::string (OutputFileHandler::*)()) &OutputFileHandler::GetRelativePath, "" )
        .def("SetArchiveDirectory", (void (OutputFileHandler::*)()) &OutputFileHandler::SetArchiveDirectory, "" )
        .def("CopyFileTo", (::FileFinder (OutputFileHandler::*)(::FileFinder const &)) &OutputFileHandler::CopyFileTo, "" , py::arg("rSourceFile"))
        .def("FindFile", (::FileFinder (OutputFileHandler::*)(::std::string)) &OutputFileHandler::FindFile, "" , py::arg("leafName"))
    ;
}
