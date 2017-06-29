#include <pybind11/pybind11.h>
#include "RelativeTo.pypp.hpp"
#include "FileFinder.pypp.hpp"
#include "OutputFileHandler.pypp.hpp"
#include "ProgressReporter.pypp.hpp"
#include "RandomNumberGenerator.pypp.hpp"
#include "TimeStepper.pypp.hpp"
#include "ChasteBuildInfo.pypp.hpp"
#include "Identifiable.pypp.hpp"
#include "PetscTools.pypp.hpp"
#include "ReplicatableVector.pypp.hpp"
#include "Timer.pypp.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_core, m)
{
register_RelativeTo_class(m);
register_FileFinder_class(m);
register_OutputFileHandler_class(m);
register_ProgressReporter_class(m);
register_RandomNumberGenerator_class(m);
register_TimeStepper_class(m);
register_ChasteBuildInfo_class(m);
register_Identifiable_class(m);
register_PetscTools_class(m);
register_ReplicatableVector_class(m);
register_Timer_class(m);
}
