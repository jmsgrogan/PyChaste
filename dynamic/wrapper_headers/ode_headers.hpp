#include "AbstractOdeSystemInformation.hpp"
#include "AbstractPythonOdeSystemInformation.hpp"
#include "AbstractOdeSystem.hpp"

//// Typdef in this namespace so that pyplusplus uses the nicer typedef'd name for the class
namespace pyplusplus{
namespace aliases{
typedef std::vector<std::string, std::allocator<std::string> >  VecString;
typedef std::vector<double> VecDouble;
}
}

