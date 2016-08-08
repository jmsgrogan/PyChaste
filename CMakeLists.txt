find_package(Chaste COMPONENTS cell_based)
chaste_do_project(PyChaste)

# Include the Python wrapping build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/WrapPython.cmake)