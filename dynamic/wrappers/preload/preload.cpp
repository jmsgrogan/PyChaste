/*

Copyright (c) 2005-2017, University of Oxford.
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
#include <memory>
#include <fstream>
#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#define _BACKWARD_BACKWARD_WARNING_H 1 //Cut out the vtk deprecated warning
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkRenderer.h>
#include <vtkColorTransferFunction.h>
#include <vtkScalarBarActor.h>
#include <vtkTextProperty.h>
#include "UblasIncludes.hpp"
#include "Exception.hpp"
//#include "PythonObjectConverters.hpp"

namespace py = pybind11;

/**
 *  This is the preload Chaste module. It contains functionality that should be loaded/registered when the Chaste Python
 *  package is first imported. This includes a collection of C++-Python converters.
 */

namespace pybind11 { namespace detail {
  template <typename T> struct type_caster<c_vector<T, 2> >
  {
    public:

      typedef c_vector<T, 2> CVec;
      PYBIND11_TYPE_CASTER(CVec, _("CVector_2"));

      // Conversion part 1 (Python -> C++)
      bool load(py::handle src, bool convert)
      {
        if (!convert && !py::array_t<T>::check_(src))
        {
            return false;
        }

        auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);
        if (!buf)
        {
            return false;
        }
        if (buf.ndim() != 1  or buf.shape()[0] != 2 )
        {
            return false;
        }
        CVec vec;
        for ( int i=0 ; i<2 ; i++ )
        {
            vec[i] = buf.data()[i];
        }
        value = vec;
        return true;
      }

      //Conversion part 2 (C++ -> Python)
      static py::handle cast(const c_vector<T, 2>& src, py::return_value_policy policy, py::handle parent)
      {
        std::vector<size_t> shape (1, 2);
        std::vector<size_t> strides(1, sizeof(T));
        double* data = src.size() ? const_cast<double *>(&src[0]) : static_cast<double *>(NULL);
        py::array a(std::move(shape), std::move(strides), data);
        return a.release();
      }
  };

  template <typename T> struct type_caster<c_vector<T, 3> >
  {
    public:

      typedef c_vector<T, 3> CVec;
      PYBIND11_TYPE_CASTER(CVec, _("CVector_3"));

      // Conversion part 1 (Python -> C++)
      bool load(py::handle src, bool convert)
      {
        if (!convert && !py::array_t<T>::check_(src))
        {
            return false;
        }

        auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);
        if (!buf)
        {
            return false;
        }
        if (buf.ndim() != 1  or buf.shape()[0] != 3 )
        {
            return false;
        }
        CVec vec;
        for ( int i=0 ; i<3 ; i++ )
        {
            vec[i] = buf.data()[i];
        }
        value = vec;
        return true;
      }

      //Conversion part 2 (C++ -> Python)
      static py::handle cast(const c_vector<T, 3>& src, py::return_value_policy policy, py::handle parent)
      {
        std::vector<size_t> shape (1, 3);
        std::vector<size_t> strides(1, sizeof(T));
        double* data = src.size() ? const_cast<double *>(&src[0]) : static_cast<double *>(NULL);
        py::array a(std::move(shape), std::move(strides), data);
        return a.release();
      }
  };
}} // namespace pybind11::detail

//PYBIND11_VTK_TYPECASTER(vtkPolyData)

class simple
{
    private:

    vtkSmartPointer<vtkPolyData> mpoly;

    public:

    simple() :
        mpoly(vtkSmartPointer<vtkPolyData>::New())
    {

    }

    vtkSmartPointer<vtkPolyData> get_poly()
    {
        return mpoly;
    }

    void set_poly(vtkSmartPointer<vtkPolyData> poly)
    {
        mpoly = poly;
        std::cout << mpoly->GetNumberOfPoints() << std::endl;
    }
};

// Make the module
PYBIND11_MODULE(_chaste_project_PyChaste_preload, m)
{

    // Register Exception
    py::register_exception_translator([](std::exception_ptr p) {
        try {
            if (p) std::rethrow_exception(p);
//        } catch (const Exception &e) {
//            exc(e.GetShortMessage());
        } catch (const Exception &e) {
            PyErr_SetString(PyExc_RuntimeError, e.GetMessage().c_str());
        }
    });


    py::class_<simple>(m, "simple")
        .def(py::init<>())
        .def("get_poly", &simple::get_poly)
        .def("set_poly", &simple::set_poly);


//    // To Python converters
//    bp::to_python_converter<vtkSmartPointer<vtkScalarBarActor>, VtkSmartPointerToPython<vtkScalarBarActor> >();
//    bp::to_python_converter<vtkSmartPointer<vtkColorTransferFunction>, VtkSmartPointerToPython<vtkColorTransferFunction> >();
//    bp::to_python_converter<vtkSmartPointer<vtkRenderer>, VtkSmartPointerToPython<vtkRenderer> >();
//    bp::to_python_converter<vtkSmartPointer<vtkUnsignedCharArray>, VtkSmartPointerToPython<vtkUnsignedCharArray> >();
//    bp::to_python_converter<vtkSmartPointer<vtkImageData>, VtkSmartPointerToPython<vtkImageData> >();
//    bp::to_python_converter<vtkSmartPointer<vtkPolyData>, VtkSmartPointerToPython<vtkPolyData> >();
//    bp::to_python_converter<c_vector<double, 2>, CVectorToNumpyArray<c_vector<double, 2> > >();
//    bp::to_python_converter<c_vector<double, 3>, CVectorToNumpyArray<c_vector<double, 3> > >();
//    bp::to_python_converter<boost::numeric::ublas::c_vector<double, 3ul>, CVectorToNumpyArray<boost::numeric::ublas::c_vector<double, 3ul> > >();
//    bp::to_python_converter<boost::numeric::ublas::c_vector<double, 2ul>, CVectorToNumpyArray<boost::numeric::ublas::c_vector<double, 2ul> > >();
//    bp::to_python_converter<c_vector<double, 6>, CVectorToNumpyArray<c_vector<double, 6> > >();
//    bp::to_python_converter<std::vector<double>, StdVectorToNumpyArray<std::vector<double> > >();
//
//    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkImageData>());
//    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkPoints>());
//    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkSmartPointer<vtkImageData> >());
//    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkSmartPointer<vtkPolyData> >());
//    bp::converter::registry::insert(&ExtractVtkWrappedPointer, type_id<vtkSmartPointer<vtkPoints> >());

//    bp::class_<std::basic_ofstream<char, std::char_traits<char> >, std::auto_ptr<std::basic_ofstream<char, std::char_traits<char> > >, boost::noncopyable > ("StdOutputFileStream", bp::no_init);
//
}
