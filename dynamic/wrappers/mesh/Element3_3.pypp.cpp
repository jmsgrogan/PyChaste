// This file has been generated by Py++.


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

#include "boost/python.hpp"
#include "wrapper_header_collection.hpp"
#include "Element3_3.pypp.hpp"

namespace bp = boost::python;

struct Element_less__3_comma__3__greater__wrapper : Element< 3, 3 >, bp::wrapper< Element< 3, 3 > > {

    Element_less__3_comma__3__greater__wrapper(Element<3, 3> const & arg )
    : Element<3, 3>( arg )
      , bp::wrapper< Element< 3, 3 > >(){
        // copy constructor
        
    }

    Element_less__3_comma__3__greater__wrapper(unsigned int index, ::std::vector< Node<3> * > const & rNodes, bool registerWithNodes=true )
    : Element<3, 3>( index, boost::ref(rNodes), registerWithNodes )
      , bp::wrapper< Element< 3, 3 > >(){
        // constructor
    
    }

    Element_less__3_comma__3__greater__wrapper(::Element< 3, 3 > const & rElement, unsigned int const index )
    : Element<3, 3>( boost::ref(rElement), index )
      , bp::wrapper< Element< 3, 3 > >(){
        // constructor
    
    }

    virtual void MarkAsDeleted(  ) {
        if( bp::override func_MarkAsDeleted = this->get_override( "MarkAsDeleted" ) )
            func_MarkAsDeleted(  );
        else{
            this->Element< 3, 3 >::MarkAsDeleted(  );
        }
    }
    
    void default_MarkAsDeleted(  ) {
        Element< 3, 3 >::MarkAsDeleted( );
    }

    virtual void RegisterWithNodes(  ) {
        if( bp::override func_RegisterWithNodes = this->get_override( "RegisterWithNodes" ) )
            func_RegisterWithNodes(  );
        else{
            this->Element< 3, 3 >::RegisterWithNodes(  );
        }
    }
    
    void default_RegisterWithNodes(  ) {
        Element< 3, 3 >::RegisterWithNodes( );
    }

    virtual void UpdateNode( unsigned int const & rIndex, ::Node< 3 > * pNode ) {
        if( bp::override func_UpdateNode = this->get_override( "UpdateNode" ) )
            func_UpdateNode( rIndex, boost::python::ptr(pNode) );
        else{
            this->Element< 3, 3 >::UpdateNode( rIndex, boost::python::ptr(pNode) );
        }
    }
    
    void default_UpdateNode( unsigned int const & rIndex, ::Node< 3 > * pNode ) {
        Element< 3, 3 >::UpdateNode( rIndex, boost::python::ptr(pNode) );
    }

};

void register_Element3_3_class(){

    bp::class_< Element_less__3_comma__3__greater__wrapper >( "Element3_3", bp::init< unsigned int, std::vector< Node<3> * > const &, bp::optional< bool > >(( bp::arg("index"), bp::arg("rNodes"), bp::arg("registerWithNodes")=(bool)(true) )) )    
        .def( bp::init< Element< 3, 3 > const &, unsigned int >(( bp::arg("rElement"), bp::arg("index") )) )    
        .def( 
            "CalculateCircumsphere"
            , (::boost::numeric::ublas::c_vector< double, 4 > ( ::Element<3, 3>::* )( ::boost::numeric::ublas::c_matrix< double, 3, 3 > &,::boost::numeric::ublas::c_matrix< double, 3, 3 > & ))( &::Element< 3, 3 >::CalculateCircumsphere )
            , ( bp::arg("rJacobian"), bp::arg("rInverseJacobian") ) )    
        .def( 
            "CalculateInterpolationWeights"
            , (::boost::numeric::ublas::c_vector< double, 4 > ( ::Element<3, 3>::* )( ::ChastePoint< 3 > const & ))( &::Element< 3, 3 >::CalculateInterpolationWeights )
            , ( bp::arg("rTestPoint") ) )    
        .def( 
            "CalculateInterpolationWeightsWithProjection"
            , (::boost::numeric::ublas::c_vector< double, 4 > ( ::Element<3, 3>::* )( ::ChastePoint< 3 > const & ))( &::Element< 3, 3 >::CalculateInterpolationWeightsWithProjection )
            , ( bp::arg("rTestPoint") ) )    
        .def( 
            "CalculateMinMaxEdgeLengths"
            , (::boost::numeric::ublas::c_vector< double, 2 > ( ::Element<3, 3>::* )(  ))( &::Element< 3, 3 >::CalculateMinMaxEdgeLengths ) )    
        .def( 
            "CalculateQuality"
            , (double ( ::Element<3, 3>::* )(  ))( &::Element< 3, 3 >::CalculateQuality ) )    
        .def( 
            "CalculateXi"
            , (::boost::numeric::ublas::c_vector< double, 3 > ( ::Element<3, 3>::* )( ::ChastePoint< 3 > const & ))( &::Element< 3, 3 >::CalculateXi )
            , ( bp::arg("rTestPoint") ) )    
        .def( 
            "IncludesPoint"
            , (bool ( ::Element<3, 3>::* )( ::ChastePoint< 3 > const &,bool ))( &::Element< 3, 3 >::IncludesPoint )
            , ( bp::arg("rTestPoint"), bp::arg("strict")=(bool)(false) ) )    
        .def( 
            "MarkAsDeleted"
            , (void ( ::Element<3, 3>::* )(  ))(&::Element< 3, 3 >::MarkAsDeleted)
            , (void ( Element_less__3_comma__3__greater__wrapper::* )(  ))(&Element_less__3_comma__3__greater__wrapper::default_MarkAsDeleted) )    
        .def( 
            "RegisterWithNodes"
            , (void ( ::Element<3, 3>::* )(  ))(&::Element< 3, 3 >::RegisterWithNodes)
            , (void ( Element_less__3_comma__3__greater__wrapper::* )(  ))(&Element_less__3_comma__3__greater__wrapper::default_RegisterWithNodes) )    
        .def( 
            "ResetIndex"
            , (void ( ::Element<3, 3>::* )( unsigned int ))( &::Element< 3, 3 >::ResetIndex )
            , ( bp::arg("index") ) )    
        .def( 
            "UpdateNode"
            , (void ( ::Element<3, 3>::* )( unsigned int const &,::Node< 3 > * ))(&::Element< 3, 3 >::UpdateNode)
            , (void ( Element_less__3_comma__3__greater__wrapper::* )( unsigned int const &,::Node< 3 > * ))(&Element_less__3_comma__3__greater__wrapper::default_UpdateNode)
            , ( bp::arg("rIndex"), bp::arg("pNode") ) );

}