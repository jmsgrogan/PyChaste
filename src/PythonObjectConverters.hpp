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

#ifndef PYTHONOBJECTCONVERTERS_HPP_
#define PYTHONOBJECTCONVERTERS_HPP_

#include <typeinfo>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include "UblasIncludes.hpp"
//#include <vtkSmartPointer.h>

namespace py = pybind11;

#define PYBIND11_CVECTOR_TYPECASTER3()                                  \
namespace pybind11 { namespace detail {                                 \
  template <> struct type_caster<c_vector<double, 3> >                  \
  {                                                                     \
    public:                                                             \
      typedef c_vector<double, 3> CVec3;                                \
      PYBIND11_TYPE_CASTER(CVec3, _("CVector_3"));                      \
      bool load(py::handle src, bool convert)                           \
      {                                                                 \
        if (!convert && !py::array_t<double>::check_(src))              \
        {                                                               \
            return false;                                               \
        }                                                               \
        auto buf = py::array_t<T, py::array::c_style |                  \
                py::array::forcecast>::ensure(src);                     \
        if (!buf){return false;}                                        \
        if (buf.ndim() != 1  or buf.shape()[0] != 3 )                   \
        {                                                               \
            return false;                                               \
        }                                                               \
        CVec vec;                                                       \
        for ( int i=0 ; i<3 ; i++ )                                     \
        {                                                               \
            vec[i] = buf.data()[i];                                     \
        }                                                               \
        value = vec;                                                    \
        return true;                                                    \
      }                                                                 \
      static py::handle cast(const c_vector<T, 3>& src,                 \
              py::return_value_policy policy, py::handle parent)        \
      {                                                                 \
        std::vector<size_t> shape (1, 3);                               \
        std::vector<size_t> strides(1, sizeof(T));                      \
        double* data = src.size() ?                                     \
                const_cast<double *>(&src[0]) :                         \
                static_cast<double *>(NULL);                            \
        py::array a(std::move(shape), std::move(strides), data);        \
        return a.release();                                             \
      }                                                                 \
  };                                                                    \
}}                                                                      \

#define PYBIND11_CVECTOR_TYPECASTER2()                                  \
namespace pybind11 { namespace detail {                                 \
  template <> struct type_caster<c_vector<double, 2> >                  \
  {                                                                     \
    public:                                                             \
      typedef c_vector<double, 2> CVec2;                                \
      PYBIND11_TYPE_CASTER(CVec2, _("CVector_2"));                      \
      bool load(py::handle src, bool convert)                           \
      {                                                                 \
        std::cout << "started conv" << std::endl;                       \
        if (!convert && !py::array_t<double>::check_(src))              \
        {                                                               \
            return false;                                               \
        }                                                               \
        auto buf = py::array_t<double, py::array::c_style |             \
                py::array::forcecast>::ensure(src);                     \
        if (!buf){return false;}                                        \
        if (buf.ndim() != 1  or buf.shape()[0] != 2 )                   \
        {                                                               \
            return false;                                               \
        }                                                               \
        value.resize(2, false);                                         \
        std::cout << value.size() << std::endl;                         \
        for ( int i=0 ; i<2 ; i++ )                                     \
        {                                                               \
            std::cout << i << std::endl;                                \
            value[i] = buf.data()[i];                                   \
        }                                                               \
        return true;                                                    \
      }                                                                 \
      static py::handle cast(const c_vector<double, 2>& src,            \
              py::return_value_policy policy, py::handle parent)        \
      {                                                                 \
        std::vector<size_t> shape (1, 2);                               \
        std::vector<size_t> strides(1, sizeof(double));                 \
        double* data = src.size() ?                                     \
                const_cast<double *>(&src[0]) :                         \
                static_cast<double *>(NULL);                            \
        py::array a(std::move(shape), std::move(strides), data);        \
        return a.release();                                             \
      }                                                                 \
  };                                                                    \
}}

/**
 *  VTK Conversion, from SMTK Source with copyright
//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
*/

#include <vtkObjectBase.h>
#include <vtkPythonUtil.h>

#define PYBIND11_VTK_TYPECASTER(VTK_OBJ)                                \
  namespace pybind11 {                                                  \
    namespace detail {                                                  \
    template <>                                                         \
  struct type_caster<vtkSmartPointer<VTK_OBJ> > {                       \
  protected:                                                            \
VTK_OBJ *value;                                                         \
public:                                                                 \
static PYBIND11_DESCR name() { return type_descr(_(#VTK_OBJ)); }        \
operator VTK_OBJ *() { return value; }                                  \
operator VTK_OBJ &() { return *value; }                                 \
template <typename _T> using cast_op_type =                             \
  pybind11::detail::cast_op_type<_T>;                                   \
bool load(handle src, bool) {                                           \
    value = dynamic_cast< VTK_OBJ *>(                                   \
    vtkPythonUtil::GetPointerFromObject(src.ptr(), #VTK_OBJ));          \
  if (!value) {                                                         \
    PyErr_Clear();                                                      \
    throw reference_cast_error();                                       \
  }                                                                     \
  return value != nullptr;                                              \
}                                                                       \
static handle cast(const vtkSmartPointer<VTK_OBJ>& src,                 \
        return_value_policy, handle) {                                  \
  return vtkPythonUtil::GetObjectFromPointer(                           \
const_cast< VTK_OBJ *>(src.GetPointer()));                             \
}                                                                       \
};                                                                      \
}}


// **
// *  Convert VTK pointers to Python VTK objects, templated over vtk object type
// *  Source: http://www.vtk.org/Wiki/Example_from_and_to_python_converters
// */
//template<class T>
//struct VtkSmartPointerToPython
//{
//    /**
//     *  Do the conversion
//     *  @param rVtkSmartPointerToObject a vtk smart pointer
//     *  @return A pointer to the Python object. Can be a None object if the smart pointer is empty.
//     */
//    static PyObject* convert(const vtkSmartPointer<T> &rVtkSmartPointer)
//    {
//        // Make sure something is being pointed to, otherwise return python None type
//        if(rVtkSmartPointer.GetPointer() == NULL)
//        {
//            return incref(Py_None);
//        }
//
//        // Get the address string of the vtk object
//        std::ostringstream oss;
//        oss << (void*) rVtkSmartPointer.GetPointer();
//        std::string address_str = oss.str();
//
//        // Can get vtk object type from address string using vtk tricks
//        boost::python::object obj = import("vtk").attr("vtkObjectBase")(address_str);
//
//        // Important to increment object reference
//        return incref(obj.ptr());
//    }
//};
//
///**
// *  Convert a Python VTK object to a pointer to the VTK object.
// *  Care is needed in suitably casting the returned void pointer to the desired
// *  vtk type. No checking is done here.
// *  Source: http://www.vtk.org/Wiki/Example_from_and_to_python_converters
// *  @param pPythonObject pointer to the python object
// *  @return void pointer to the vtk object
// */
//void* ExtractVtkWrappedPointer(PyObject* pPythonObject)
//{
//    //Get the __this__ attribute from the Python Object
//    char thisStr[] = "__this__";
//
//    // Several checks to make sure it is a valid vtk type, otherwise return a null pointer
//    if (!PyObject_HasAttrString(pPythonObject, thisStr))
//    {
//        return NULL;
//    }
//
//    PyObject* thisAttr = PyObject_GetAttrString(pPythonObject, thisStr);
//    if (thisAttr == NULL)
//    {
//        return NULL;
//    }
//
//    const char* str = PyString_AsString(thisAttr);
//    if(str == 0 || strlen(str) < 1)
//    {
//        return NULL;
//    }
//
//    char hex_address[32], *pEnd;
//    const char *_p_ = strstr(str, "_p_vtk");
//    if(_p_ == NULL)
//    {
//        return NULL;
//    }
//
//    const char *class_name = strstr(_p_, "vtk");
//    if(class_name == NULL)
//    {
//        return NULL;
//
//    }
//
//    // Create a generic vtk object pointer and assign the address of the python object to it
//    strcpy(hex_address, str+1);
//    hex_address[_p_-str-1] = '\0';
//    long address = strtol(hex_address, &pEnd, 16);
//
//    vtkObjectBase* vtk_object = (vtkObjectBase*)((void*)address);
//    if(vtk_object->IsA(class_name))
//    {
//        vtk_object->Register(NULL);
//        return vtk_object;
//    }
//
//    // Catch all in case something goes wrong
//    return NULL;
//};


#endif /*PYTHONOBJECTCONVERTERS_HPP_*/
