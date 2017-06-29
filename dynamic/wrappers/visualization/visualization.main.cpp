#include <pybind11/pybind11.h>
#include "VtkScene2.pypp.hpp"
#include "VtkScene3.pypp.hpp"
#include "AbstractPyChasteActorGenerator2.pypp.hpp"
#include "AbstractPyChasteActorGenerator3.pypp.hpp"
#include "CellPopulationPyChasteActorGenerator2.pypp.hpp"
#include "CellPopulationPyChasteActorGenerator3.pypp.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_chaste_project_PyChaste_visualization, m)
{
register_VtkScene2_class(m);
register_VtkScene3_class(m);
register_AbstractPyChasteActorGenerator2_class(m);
register_AbstractPyChasteActorGenerator3_class(m);
register_CellPopulationPyChasteActorGenerator2_class(m);
register_CellPopulationPyChasteActorGenerator3_class(m);
}
