// This file has been generated by Py++.

#include "boost/python.hpp"

#include "boost/python/suite/indexing/vector_indexing_suite.hpp"

#include "/home/grogan/Chaste/projects/PyChaste/dynamic/wrapper_headers/mesh_headers.hpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_chaste_project_PyChaste_mesh){
    { //::std::vector< double >
        typedef bp::class_< std::vector< double > > vector_less__double__greater__exposer_t;
        vector_less__double__greater__exposer_t vector_less__double__greater__exposer = vector_less__double__greater__exposer_t( "vector_less__double__greater_" );
        bp::scope vector_less__double__greater__scope( vector_less__double__greater__exposer );
        vector_less__double__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< double >, true >() );
    }

    { //::ChastePoint< 3 >
        typedef bp::class_< ChastePoint< 3 > > ChastePoint3_exposer_t;
        ChastePoint3_exposer_t ChastePoint3_exposer = ChastePoint3_exposer_t( "ChastePoint3", bp::init< bp::optional< double, double, double > >(( bp::arg("v1")=0, bp::arg("v2")=0, bp::arg("v3")=0 )) );
        bp::scope ChastePoint3_scope( ChastePoint3_exposer );
        bp::implicitly_convertible< double, ChastePoint< 3 > >();
        ChastePoint3_exposer.def( bp::init< std::vector< double > >(( bp::arg("coords") )) );
        bp::implicitly_convertible< std::vector< double >, ChastePoint< 3 > >();
        ChastePoint3_exposer.def( bp::init< boost::numeric::ublas::c_vector< double, 3 > >(( bp::arg("location") )) );
        bp::implicitly_convertible< boost::numeric::ublas::c_vector< double, 3 >, ChastePoint< 3 > >();
        { //::ChastePoint< 3 >::GetWithDefault
        
            typedef ChastePoint< 3 > exported_class_t;
            typedef double ( exported_class_t::*GetWithDefault_function_type)( unsigned int,double ) const;
            
            ChastePoint3_exposer.def( 
                "GetWithDefault"
                , GetWithDefault_function_type( &::ChastePoint< 3 >::GetWithDefault )
                , ( bp::arg("i"), bp::arg("def")=0. ) );
        
        }
        { //::ChastePoint< 3 >::IsSamePoint
        
            typedef ChastePoint< 3 > exported_class_t;
            typedef bool ( exported_class_t::*IsSamePoint_function_type)( ::ChastePoint< 3 > const & ) const;
            
            ChastePoint3_exposer.def( 
                "IsSamePoint"
                , IsSamePoint_function_type( &::ChastePoint< 3 >::IsSamePoint )
                , ( bp::arg("rPoint") ) );
        
        }
        { //::ChastePoint< 3 >::SetCoordinate
        
            typedef ChastePoint< 3 > exported_class_t;
            typedef void ( exported_class_t::*SetCoordinate_function_type)( unsigned int,double ) ;
            
            ChastePoint3_exposer.def( 
                "SetCoordinate"
                , SetCoordinate_function_type( &::ChastePoint< 3 >::SetCoordinate )
                , ( bp::arg("i"), bp::arg("value") ) );
        
        }
        { //::ChastePoint< 3 >::operator[]
        
            typedef ChastePoint< 3 > exported_class_t;
            typedef double ( exported_class_t::*__getitem___function_type)( unsigned int ) const;
            
            ChastePoint3_exposer.def( 
                "__getitem__"
                , __getitem___function_type( &::ChastePoint< 3 >::operator[] )
                , ( bp::arg("i") ) );
        
        }
        { //::ChastePoint< 3 >::rGetLocation
        
            typedef ChastePoint< 3 > exported_class_t;
            typedef ::boost::numeric::ublas::c_vector< double, 3 > const & ( exported_class_t::*rGetLocation_function_type)(  ) const;
            
            ChastePoint3_exposer.def( 
                "rGetLocation"
                , rGetLocation_function_type( &::ChastePoint< 3 >::rGetLocation )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
    }

    { //::Instantiation
    
        typedef int ( *Instantiation_function_type )(  );
        
        bp::def( 
            "Instantiation"
            , Instantiation_function_type( &::Instantiation ) );
    
    }
}