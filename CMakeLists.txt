find_package(Chaste COMPONENTS cell_based)

# PyChaste needs some additional VTK libraries, take them all for now.
find_package(VTK REQUIRED)
set(Chaste_THIRD_PARTY_LIBRARIES_LOCAL ${Chaste_THIRD_PARTY_LIBRARIES} ${VTK_LIBRARIES})
set_property(GLOBAL PROPERTY lib_overwrite_property ${Chaste_THIRD_PARTY_LIBRARIES_LOCAL})
GET_PROPERTY(Chaste_THIRD_PARTY_LIBRARIES GLOBAL PROPERTY lib_overwrite_property)

chaste_do_project(PyChaste)

# Include the Python wrapping build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/WrapPython.cmake)