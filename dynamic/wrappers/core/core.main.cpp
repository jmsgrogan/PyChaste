#include <pybind11/pybind11.h>
#include "Identifiable.cppwg.hpp"
#include "PetscTools.cppwg.hpp"
#include "ReplicatableVector.cppwg.hpp"
#include "Timer.cppwg.hpp"
#include "RelativeTo.cppwg.hpp"
#include "FileFinder.cppwg.hpp"
#include "OutputFileHandler.cppwg.hpp"
#include "ProgressReporter.cppwg.hpp"
#include "RandomNumberGenerator.cppwg.hpp"
#include "TimeStepper.cppwg.hpp"
#include "ChasteBuildInfo.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_core, m)
{
    register_Identifiable_class(m);
    register_PetscTools_class(m);
    register_ReplicatableVector_class(m);
    register_Timer_class(m);
    register_RelativeTo_class(m);
    register_FileFinder_class(m);
    register_OutputFileHandler_class(m);
    register_ProgressReporter_class(m);
    register_RandomNumberGenerator_class(m);
    register_TimeStepper_class(m);
    register_ChasteBuildInfo_class(m);
}
