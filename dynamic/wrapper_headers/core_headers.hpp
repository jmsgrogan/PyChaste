/*

Copyright (c) 2005-2016, University of Oxford.
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

// Global
#ifndef PYCHASTECOREHEADERS_HPP_
#define PYCHASTECOREHEADERS_HPP_

#include <vector>
#include <set>
#include <map>
#include "PetscTools.hpp"
#include "OutputFileHandler.hpp"
#include "BoostFilesystem.hpp"
#include "FileFinder.hpp"
#include "RandomNumberGenerator.hpp"
#include "Timer.hpp"
#include "Version.hpp"
#include "Identifiable.hpp"
#include "ReplicatableVector.hpp"
#include "UblasIncludes.hpp"

typedef boost::filesystem::path boost_filesystem_path;

inline int Instantiation()
{
    return sizeof(Mat) + sizeof(Vec);
}

inline Mat GetPetscMatForWrapper()
{
    Mat A;

    PetscTools::SetupMat(A, 3, 3, 3);
    return A;
}

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class/
// include usual std types here so they ara available for other modules.
namespace pyplusplus{
namespace aliases{
typedef std::map<std::string, std::string> MapString;
typedef std::vector<double> VecDouble;
typedef std::vector<unsigned> VecUnsigned;
typedef std::vector<bool> VecBool;
typedef std::set<unsigned> SetUnsigned;
typedef c_vector<double, 2> CVectorDouble_2;
typedef c_vector<double, 3> CVectorDouble_3;
typedef c_vector<unsigned, 5> CVectorUnsigned_5;
typedef std::vector<std::string, std::allocator<std::string> >  VecString;
typedef std::vector<c_vector<unsigned, 5> > VecCVectorUnsigned_5;
typedef std::vector<c_vector<double, 3> > VecCVectorDouble_3;
typedef std::vector<c_vector<double, 2> > VecCVectorDouble_2;
typedef std::vector<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> >, std::allocator<std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > > > VecSetInt;
typedef std::vector<std::vector<unsigned int, std::allocator<unsigned int> >, std::allocator<std::vector<unsigned int, std::allocator<unsigned int> > > > VecVecInt;
}
}

#endif // PYCHASTECOREHEADERS_HPP_
