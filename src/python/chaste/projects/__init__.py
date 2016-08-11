import sys
import importlib
import pkgutil

def import_submodules(package_name):
    """ Import all submodules of a module, recursively

    :param package_name: Package name
    :type package_name: str
    :rtype: dict[types.ModuleType]
    """
    
    package = sys.modules[package_name]
    return {
        name: importlib.import_module(package_name + '.' + name)
        for _, name, _ in pkgutil.walk_packages(package.__path__)
    }
   
# Auto import any packages that are places in this directory 
#__all__ = import_submodules(__name__).keys()
import angiogenesis