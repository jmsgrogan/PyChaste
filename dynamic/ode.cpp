// This file has been generated by Py++.

#include "boost/python.hpp"

#include "boost/python/suite/indexing/vector_indexing_suite.hpp"

#include "/home/grogan/Chaste/projects/PyChaste/dynamic/wrapper_headers/ode_headers.hpp"

namespace bp = boost::python;

struct AbstractOdeSystem_wrapper : AbstractOdeSystem, bp::wrapper< AbstractOdeSystem > {

    AbstractOdeSystem_wrapper(unsigned int numberOfStateVariables )
    : AbstractOdeSystem( numberOfStateVariables )
      , bp::wrapper< AbstractOdeSystem >(){
        // constructor
    
    }

    virtual double CalculateRootFunction( double time, ::std::vector< double > const & rY ) {
        if( bp::override func_CalculateRootFunction = this->get_override( "CalculateRootFunction" ) )
            return func_CalculateRootFunction( time, boost::ref(rY) );
        else{
            return this->AbstractOdeSystem::CalculateRootFunction( time, boost::ref(rY) );
        }
    }
    
    double default_CalculateRootFunction( double time, ::std::vector< double > const & rY ) {
        return AbstractOdeSystem::CalculateRootFunction( time, boost::ref(rY) );
    }

    virtual bool CalculateStoppingEvent( double time, ::std::vector< double > const & rY ) {
        if( bp::override func_CalculateStoppingEvent = this->get_override( "CalculateStoppingEvent" ) )
            return func_CalculateStoppingEvent( time, boost::ref(rY) );
        else{
            return this->AbstractOdeSystem::CalculateStoppingEvent( time, boost::ref(rY) );
        }
    }
    
    bool default_CalculateStoppingEvent( double time, ::std::vector< double > const & rY ) {
        return AbstractOdeSystem::CalculateStoppingEvent( time, boost::ref(rY) );
    }

    virtual void EvaluateYDerivatives( double time, ::std::vector< double > const & rY, ::std::vector< double > & rDY ){
        bp::override func_EvaluateYDerivatives = this->get_override( "EvaluateYDerivatives" );
        func_EvaluateYDerivatives( time, boost::ref(rY), boost::ref(rDY) );
    }

};

struct AbstractOdeSystemInformation_wrapper : AbstractOdeSystemInformation, bp::wrapper< AbstractOdeSystemInformation > {

    AbstractOdeSystemInformation_wrapper( )
    : AbstractOdeSystemInformation( )
      , bp::wrapper< AbstractOdeSystemInformation >(){
        // null constructor
    
    }

    virtual void Initialise(  ){
        bp::override func_Initialise = this->get_override( "Initialise" );
        func_Initialise(  );
    }

};

struct AbstractPythonOdeSystemInformation_wrapper : AbstractPythonOdeSystemInformation, bp::wrapper< AbstractPythonOdeSystemInformation > {

    AbstractPythonOdeSystemInformation_wrapper( )
    : AbstractPythonOdeSystemInformation( )
      , bp::wrapper< AbstractPythonOdeSystemInformation >(){
        // null constructor
    
    }

    virtual void Initialise(  ){
        bp::override func_Initialise = this->get_override( "Initialise" );
        func_Initialise(  );
    }

};

BOOST_PYTHON_MODULE(_chaste_project_PyChaste_ode){
    { //::std::vector< std::string >
        typedef bp::class_< std::vector< std::string > > vector_less__std_scope_string__greater__exposer_t;
        vector_less__std_scope_string__greater__exposer_t vector_less__std_scope_string__greater__exposer = vector_less__std_scope_string__greater__exposer_t( "vector_less__std_scope_string__greater_" );
        bp::scope vector_less__std_scope_string__greater__scope( vector_less__std_scope_string__greater__exposer );
        vector_less__std_scope_string__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< std::string >, true >() );
    }

    { //::std::vector< double >
        typedef bp::class_< std::vector< double > > vector_less__double__greater__exposer_t;
        vector_less__double__greater__exposer_t vector_less__double__greater__exposer = vector_less__double__greater__exposer_t( "vector_less__double__greater_" );
        bp::scope vector_less__double__greater__scope( vector_less__double__greater__exposer );
        vector_less__double__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< double >, true >() );
    }

    bp::class_< AbstractOdeSystem_wrapper, boost::noncopyable >( "AbstractOdeSystem", bp::init< unsigned int >(( bp::arg("numberOfStateVariables") )) )    
        .def( 
            "CalculateRootFunction"
            , (double ( ::AbstractOdeSystem::* )( double,::std::vector< double > const & ))(&::AbstractOdeSystem::CalculateRootFunction)
            , (double ( AbstractOdeSystem_wrapper::* )( double,::std::vector< double > const & ))(&AbstractOdeSystem_wrapper::default_CalculateRootFunction)
            , ( bp::arg("time"), bp::arg("rY") ) )    
        .def( 
            "CalculateStoppingEvent"
            , (bool ( ::AbstractOdeSystem::* )( double,::std::vector< double > const & ))(&::AbstractOdeSystem::CalculateStoppingEvent)
            , (bool ( AbstractOdeSystem_wrapper::* )( double,::std::vector< double > const & ))(&AbstractOdeSystem_wrapper::default_CalculateStoppingEvent)
            , ( bp::arg("time"), bp::arg("rY") ) )    
        .def( 
            "EvaluateYDerivatives"
            , bp::pure_virtual( (void ( ::AbstractOdeSystem::* )( double,::std::vector< double > const &,::std::vector< double > & ))(&::AbstractOdeSystem::EvaluateYDerivatives) )
            , ( bp::arg("time"), bp::arg("rY"), bp::arg("rDY") ) )    
        .def( 
            "GetUseAnalyticJacobian"
            , (bool ( ::AbstractOdeSystem::* )(  ))( &::AbstractOdeSystem::GetUseAnalyticJacobian ) )    
        .def( 
            "rGetConstStateVariables"
            , (::std::vector< double > const & ( ::AbstractOdeSystem::* )(  )const)( &::AbstractOdeSystem::rGetConstStateVariables )
            , bp::return_value_policy< bp::copy_const_reference >() );

    bp::class_< AbstractOdeSystemInformation_wrapper, boost::noncopyable >( "AbstractOdeSystemInformation", bp::init< >() )    
        .def( 
            "GetAnyVariableIndex"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::GetAnyVariableIndex )
            , ( bp::arg("rName") ) )    
        .def( 
            "GetAnyVariableUnits"
            , (::std::string ( ::AbstractOdeSystemInformation::* )( unsigned int )const)( &::AbstractOdeSystemInformation::GetAnyVariableUnits )
            , ( bp::arg("index") ) )    
        .def( 
            "GetAttribute"
            , (double ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::GetAttribute )
            , ( bp::arg("rName") ) )    
        .def( 
            "GetDerivedQuantityIndex"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::GetDerivedQuantityIndex )
            , ( bp::arg("rName") ) )    
        .def( 
            "GetDerivedQuantityUnits"
            , (::std::string ( ::AbstractOdeSystemInformation::* )( unsigned int )const)( &::AbstractOdeSystemInformation::GetDerivedQuantityUnits )
            , ( bp::arg("index") ) )    
        .def( 
            "GetFreeVariableName"
            , (::std::string ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetFreeVariableName ) )    
        .def( 
            "GetFreeVariableUnits"
            , (::std::string ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetFreeVariableUnits ) )    
        .def( 
            "GetInitialConditions"
            , (::std::vector< double > ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetInitialConditions ) )    
        .def( 
            "GetNumberOfAttributes"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetNumberOfAttributes ) )    
        .def( 
            "GetNumberOfDerivedQuantities"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetNumberOfDerivedQuantities ) )    
        .def( 
            "GetNumberOfParameters"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetNumberOfParameters ) )    
        .def( 
            "GetParameterIndex"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::GetParameterIndex )
            , ( bp::arg("rName") ) )    
        .def( 
            "GetParameterUnits"
            , (::std::string ( ::AbstractOdeSystemInformation::* )( unsigned int )const)( &::AbstractOdeSystemInformation::GetParameterUnits )
            , ( bp::arg("index") ) )    
        .def( 
            "GetStateVariableIndex"
            , (unsigned int ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::GetStateVariableIndex )
            , ( bp::arg("rName") ) )    
        .def( 
            "GetStateVariableUnits"
            , (::std::string ( ::AbstractOdeSystemInformation::* )( unsigned int )const)( &::AbstractOdeSystemInformation::GetStateVariableUnits )
            , ( bp::arg("index") ) )    
        .def( 
            "GetSystemName"
            , (::std::string ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::GetSystemName ) )    
        .def( 
            "HasAnyVariable"
            , (bool ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::HasAnyVariable )
            , ( bp::arg("rName") ) )    
        .def( 
            "HasAttribute"
            , (bool ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::HasAttribute )
            , ( bp::arg("rName") ) )    
        .def( 
            "HasDerivedQuantity"
            , (bool ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::HasDerivedQuantity )
            , ( bp::arg("rName") ) )    
        .def( 
            "HasParameter"
            , (bool ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::HasParameter )
            , ( bp::arg("rName") ) )    
        .def( 
            "HasStateVariable"
            , (bool ( ::AbstractOdeSystemInformation::* )( ::std::string const & )const)( &::AbstractOdeSystemInformation::HasStateVariable )
            , ( bp::arg("rName") ) )    
        .def( 
            "Initialise"
            , (void ( AbstractOdeSystemInformation_wrapper::* )(  ))(&AbstractOdeSystemInformation_wrapper::Initialise) )    
        .def( 
            "SetDefaultInitialCondition"
            , (void ( ::AbstractOdeSystemInformation::* )( unsigned int,double ))( &::AbstractOdeSystemInformation::SetDefaultInitialCondition )
            , ( bp::arg("index"), bp::arg("initialCondition") ) )    
        .def( 
            "SetDefaultInitialConditions"
            , (void ( ::AbstractOdeSystemInformation::* )( ::std::vector< double > const & ))( &::AbstractOdeSystemInformation::SetDefaultInitialConditions )
            , ( bp::arg("rInitialConditions") ) )    
        .def( 
            "rGetDerivedQuantityNames"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetDerivedQuantityNames )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "rGetDerivedQuantityUnits"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetDerivedQuantityUnits )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "rGetParameterNames"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetParameterNames )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "rGetParameterUnits"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetParameterUnits )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "rGetStateVariableNames"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetStateVariableNames )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "rGetStateVariableUnits"
            , (::std::vector< std::string > const & ( ::AbstractOdeSystemInformation::* )(  )const)( &::AbstractOdeSystemInformation::rGetStateVariableUnits )
            , bp::return_value_policy< bp::copy_const_reference >() );

    bp::class_< AbstractPythonOdeSystemInformation_wrapper, bp::bases< AbstractOdeSystemInformation >, boost::noncopyable >( "AbstractPythonOdeSystemInformation", bp::init< >() )    
        .def( 
            "AddVariableName"
            , (void ( ::AbstractPythonOdeSystemInformation::* )( ::std::string const & ))( &::AbstractPythonOdeSystemInformation::AddVariableName )
            , ( bp::arg("rName") ) )    
        .def( 
            "AddVariableUnit"
            , (void ( ::AbstractPythonOdeSystemInformation::* )( ::std::string const & ))( &::AbstractPythonOdeSystemInformation::AddVariableUnit )
            , ( bp::arg("rUnit") ) )    
        .def( 
            "Initialise"
            , (void ( AbstractPythonOdeSystemInformation_wrapper::* )(  ))(&AbstractPythonOdeSystemInformation_wrapper::Initialise) )    
        .def( 
            "SetIsInitialised"
            , (void ( ::AbstractPythonOdeSystemInformation::* )( bool ))( &::AbstractPythonOdeSystemInformation::SetIsInitialised )
            , ( bp::arg("isInitialized")=(bool)(true) ) );
}
