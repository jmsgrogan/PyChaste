/*

Copyright (c) 2005-2012, University of Oxford.
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

#ifndef HELLO_HPP_
#define HELLO_HPP_

#include <string>
#include <vector>

/**
 * This is a demo class for demonstrating Python wrapping
 */
class Hello
{
private:

    /**
     * A message to be returned
     */
    std::string mMessage;

    /**
     * A vector of doubles
     */
    std::vector<double> mVector;

public:

    /**
     * Constructor
     * @param rMessage an input message
     */
    Hello(const std::string& rMessage);
    
    /**
     * Return the message
     * @return return the input message
     */
    std::string GetMessage();

    /**
     * Throw and exception with the complaint message
     * @param rComplaint the input message
     */
    void Complain(const std::string& rComplaint);

    /**
     * Set a vector of doubles
     * @param vectorInput the input vector
     */
    void SetVector(std::vector<double> vectorInput);

    /**
     * Return the vector of doubles
     * @return the vector of doubles
     */
    std::vector<double> GetVector();
};

#endif /*HELLO_HPP_*/
