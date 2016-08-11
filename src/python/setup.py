from setuptools import setup, Distribution,find_packages

class BinaryDistribution(Distribution):
    def is_pure(self):
        return False

setup(
    name = "chaste",
    version = "0.1.dev0",
    packages = find_packages(),
    install_requires = ['matplotlib', 'pandas', 'numpy'],
    package_data={
        'chaste': ['_chaste_project_PyChaste_preload.so', 
                   'core/_chaste_project_PyChaste_core.so', 
                  'tutorial/_chaste_project_PyChaste_hello_auto.so',],},
      
    include_package_data=True,

    # Project Metadata
    author = "Chaste Team, University of Oxford",
    author_email = "chaste-users@maillist.ox.ac.uk",
    description = "Python bindings for the Chaste project",
    license = "BSD",
    keywords = "cancer developmental biology electrophysiology scientific",

    classifiers=[
        'Development Status :: 1 - Planning',
        'Intended Audience :: Science/Research',
        'Topic :: Scientific/Engineering',
        'Operating System :: Unix',  
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python :: 2.7',
    ],

    distclass=BinaryDistribution
)
