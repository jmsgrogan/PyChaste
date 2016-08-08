/*

Copyright (c) 2005-2015, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <vector>
#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h>
#define _BACKWARD_BACKWARD_WARNING_H 1 //Cut out the vtk deprecated warning for now (gcc4.3)
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include "UblasIncludes.hpp"
#include "Exception.hpp"
#include "ChastePoint.hpp"
#include "PythonObjectConverters.hpp"

namespace bp = boost::python;

/**
 *  This is the preload Chaste module. It contains functionality that should be loaded/registered when the Chaste Python
 *  package is first imported. This includes a collection of C++-Python converters.
 */

// Helper for wrapping Chaste Exceptions
PyObject *pChasteExceptionType = NULL;

void ExceptionToPython(Exception const &rChasteException)
{
  assert(pChasteExceptionType != NULL);
  boost::python::object pythonExceptionInstance(rChasteException);
  PyErr_SetObject(pChasteExceptionType, pythonExceptionInstance.ptr());
}

// Make the module
BOOST_PYTHON_MODULE(_chaste_project_PyChaste_preload)
{
    // Import numpy arrays for use in converters
    import_array();
    numeric::array::set_module_and_type("numpy", "ndarray");

    // Manage exceptions
    bp::class_<Exception> myCPPExceptionClass("ChasteException", init<std::string, std::string, unsigned>());
    myCPPExceptionClass.add_property("GetMessage", &Exception::GetMessage);
    myCPPExceptionClass.add_property("GetShortMessage", &Exception::GetShortMessage);

    pChasteExceptionType = myCPPExceptionClass.ptr();
    bp::register_exception_translator<Exception>(&ExceptionToPython);

    // To Python converters
    bp::to_python_converter<vtkSmartPointer<vtkImageData>, VtkSmartPointerToPython<vtkImageData> >();
    bp::to_python_converter<vtkSmartPointer<vtkPolyData>, VtkSmartPointerToPython<vtkPolyData> >();
    bp::to_python_converter<c_vector<double, 2>, CVectorToNumpyArray<c_vector<double, 2> > >();
    bp::to_python_converter<c_vector<double, 3>, CVectorToNumpyArray<c_vector<double, 3> > >();
    bp::to_python_converter<c_vector<double, 6>, CVectorToNumpyArray<c_vector<double, 6> > >();
    bp::to_python_converter<std::vector<double>, StdVectorToNumpyArray<std::vector<double> > >();

    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkImageData>());
    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkSmartPointer<vtkImageData> >());

    bp::class_<std::pair<double, double> > ("DblPair")
        .def_readwrite("first", &std::pair<double, double>::first)
        .def_readwrite("second", &std::pair<double, double>::second)
    ;

    bp::class_<std::vector<unsigned> > ("VecUnsigned")
         .def(vector_ptr_indexing_suite<std::vector<unsigned> >())
    ;

    bp::class_<std::vector<std::pair<double, double> > > ("VecPairDoubleDouble")
         .def(vector_ptr_indexing_suite<std::vector<std::pair<double, double> > >())
    ;

    bp::class_<std::vector<std::vector<unsigned> > > ("VecVecUnsigned")
         .def(vector_ptr_indexing_suite<std::vector<std::vector<unsigned> > >())
    ;

    bp::class_<std::vector<std::vector<double> > > ("VecVecDouble")
         .def(vector_ptr_indexing_suite<std::vector<std::vector<double> > >())
    ;

    bp::class_<std::map<unsigned, double> >("UnsignedDoubleMap")
        .def(map_indexing_suite<std::map<unsigned, double> >())
    ;

    // From Python converters
    TupleToCVector()
        .from_python<2>()
        .from_python<3>()
        ;

    NumpyArrayToCVector()
        .from_python<2>()
        .from_python<3>()
        ;

    // Iterators
    PythonIterableToStl()
      .from_python<std::vector<double> >()
      .from_python<std::vector<std::vector<double> > >()
      .from_python<std::vector<std::vector<double> > >()
      .from_python<std::vector<unsigned> >()
      .from_python<std::vector<c_vector<double, 3> > >()
      ;
}
