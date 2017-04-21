find_package(Chaste COMPONENTS cell_based)

# PyChaste needs some additional VTK libraries, take them all for now.
find_package(VTK REQUIRED)
list(APPEND Chaste_THIRD_PARTY_LIBRARIES ${VTK_LIBRARIES})
chaste_do_project(PyChaste)

# Include the Python wrapping build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/WrapPython.cmake)