"""
This file contains a list of classes that are to be wrapped. 

Each class includes metadata such as template arguments, excluded methods,
methods with special pointer management requirements, and any special
declaration code needed for wrapping. A minimal case is just to
specify the class name and component it will belong to.
"""

class cpp_class():
    
    """
    A container for each class to be wrapped. Include the class name, component (e.g. ode,pde,cell_based) 
    template arguments and specify if any custom code is needed to
    complete the wrapping.
    
    Template arguments are specified in a list of lists. For example if a
    class is templated over a single dimension <DIM> then the template
    list might look like [[2], [3]]. If templated over two dimensions <ELEMENT, DIM>
    <SPACE, DIM> it might look like [[2,2], [3,3]]. If templated over type it might look
    like [[UniformCellCycleModel, 2], [SimpleOxygenBasedCellCycleModel, 2]]
    
    :param: name - the class name, for example AbstractCellPopulation
    :param: component - which module the class will be in, e.g. ode, pde, core, cell_based
    :param: template_args - a list of lists containing the template arguments
    :param: skip_wrapping - do not wrap the class if True. The class can still go in include files
    :param: excluded_methods - a list of methods not to be wrapped
    :param: excluded_variables - a list of public member variables not to be wrapped
    :param: pointer_return_methods - a list of lists of methods with special pointer
    or reference return requirements and the name of the Py++ method for managing them.
    :param: needs_include_file - should the class be added to the include file, mostly yes
    :param: include_file_only - should the class only be added to the include file and nothing else
    :param: declaration_code - a list of extra Boost Python wrapper codes to be added to the autowrapper
    :param: needs_instantiation - does the class need instantiation in the header, mostly True for templated
    classes
    """
    
    def __init__(self, name, component, template_args = None, skip_wrapping = False, 
                 excluded_methods = None, 
                 excluded_variables = None,
                 pointer_return_methods = None, 
                 needs_include_file = True,
                 include_file_only = False,
                 declaration_code = None,
                 needs_instantiation = True):
        
        self.name = name
        self.component = component
        self.template_args = template_args
        self.skip_wrapping = skip_wrapping
        self.excluded_methods = excluded_methods
        self.excluded_variables = excluded_variables
        self.needs_include_file = needs_include_file
        self.pointer_return_methods = pointer_return_methods
        self.include_file_only = include_file_only
        self.declaration_code = declaration_code
        self.needs_instantiation= needs_instantiation
        
    def get_short_names(self):
        
        """
        Return the name of the class as it will appear on the Python side. This
        collapses template arguements, separating them by underscores and removes
        special characters. The return type is a list, as a class can have multiple
        names if it is templated.
        """
        
        if self.template_args is None:
            return [self.name]
        
        names = []
        for eachTemplateArg in self.template_args:
            template_string=""
            for idx, eachTemplateEntry in enumerate(eachTemplateArg):
                cleaned_entry = str(eachTemplateEntry).translate(None, "<>:,*").replace(" ", "")
                if len(cleaned_entry)>1:
                    cleaned_entry = cleaned_entry[0].capitalize()+cleaned_entry[1:]
                template_string += str(cleaned_entry)
                if(idx!=len(eachTemplateArg)-1):
                    template_string+="_"
            cleaned_name = self.name.translate(None, "<>:*")
            if len(cleaned_name)>1:
                cleaned_name = cleaned_name[0].capitalize()+cleaned_name[1:]
            names.append(cleaned_name+template_string)
        return names
        
    def get_full_names(self):
        
        """
        Return the name (declaration) of the class as it appears on the C++ side.
        The return type is a list, as a class can have multiple
        names (declarations) if it is templated.
        """
        
        if self.template_args is None:
            return [self.name]
        
        names = []
        for eachTemplateArg in self.template_args:
            template_string = "<"
            for idx, eachTemplateEntry in enumerate(eachTemplateArg):
                template_string += str(eachTemplateEntry)
                if(idx==len(eachTemplateArg)-1):
                    template_string+=" >"
                else:
                    template_string+=","
            names.append(self.name + template_string)
        return names
            
    def needs_header_file_instantiation(self):
        
        """
        Does this class need to be instantiated in the header file
        """
        
        return (self.template_args is not None) and (not self.include_file_only) and (self.needs_instantiation)
    
    def needs_header_file_typdef(self):
        
        """
        Does this class need to be typdef'd with a nicer name in the header file.
        All template classes need this.
        """
        
        return (self.template_args is not None) and (not self.include_file_only)
    
    def needs_auto_wrapper_generation(self):
        
        """
        Does this class need a wrapper to be autogenerated.
        """
        
        return (not self.include_file_only) and (not self.skip_wrapping)
    
# Convenience vars for template args
same_dims_1 = [[2], [3]] # i.e. <DIM>
same_dims_2 = [[2, 2], [3, 3]] # i.e. <ELEMENT_DIM, SPACE_DIM>

# Classes which have methods taking or returning PETSc vec or mat need to add
# this custom wrapper code to allow wrapping of PETSc opaque pointers. Any 
# methods returning them also needs to set up opaque pointer management by
# choosing the Py++ 'return_opaque_pointer' option.
petsc_mat_custom_code = "BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Mat )"
petsc_vec_custom_code = "BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Vec )"

# Break into components just for easier reading
core_classes = [cpp_class('BoostFilesystem', 'core', include_file_only = True),
                cpp_class('Version', 'core', include_file_only = True),
                cpp_class('SmartPointers', 'core', include_file_only = True),
                cpp_class('Identifiable', 'core', include_file_only = True),
                cpp_class('UblasIncludes', 'core', include_file_only = True),
                cpp_class('OutputFileHandler', 'core', excluded_methods = ["OpenOutputFile"]), # can't work with auto_ptr
                cpp_class('RelativeTo', 'core', needs_include_file = False),
                cpp_class('FileFinder', 'core'),
                cpp_class('RandomNumberGenerator', 'core'),
                cpp_class('Timer', 'core'),
                cpp_class('PetscTools', 'core', excluded_methods=["GetWorld"], 
                          pointer_return_methods=[["CreateVec", "return_opaque_pointer"],
                                                  ["CreateAndSetVec", "return_opaque_pointer"]],
                          excluded_variables = ["MASTER_RANK"],
                          declaration_code = [petsc_mat_custom_code]),
                cpp_class('ReplicatableVector', 'core', declaration_code = [petsc_vec_custom_code,
                                                                            petsc_mat_custom_code]),
                ]

ode_classes = [cpp_class('AbstractOdeSystemInformation', 'ode'),
               cpp_class('AbstractPythonOdeSystemInformation', 'ode'),
               cpp_class('AbstractOdeSystem', 'ode')
               ]

pde_classes = [cpp_class('AbstractLinearPde', 'pde', template_args = same_dims_2),
               cpp_class('AbstractLinearEllipticPde', 'pde', template_args = same_dims_2),
               cpp_class('AbstractBoundaryCondition', 'pde', template_args = same_dims_1),
               cpp_class('ConstBoundaryCondition', 'pde', template_args = same_dims_1),
               ]

mesh_classes = [cpp_class('ChastePoint', 'mesh', template_args = same_dims_1),
                cpp_class('NodeAttributes', 'mesh', template_args = same_dims_1),
                cpp_class('Node', 'mesh', template_args = same_dims_1),
                cpp_class('Element', 'mesh', template_args = same_dims_2, excluded_methods = ["CalculateCircumsphereVolume"]), # method not found
                cpp_class('NodesOnlyMesh', 'mesh', template_args = same_dims_1),
                cpp_class('MutableMesh', 'mesh', template_args = same_dims_2, excluded_methods = ["SplitLongEdges", # can't work with vec<c_vec>
                                                                                                  "RescaleMeshFromBoundaryNode"]), # method not found
                cpp_class('PottsMesh', 'mesh', template_args = same_dims_1),
                cpp_class('SharedPottsMeshGenerator', 'mesh', template_args = same_dims_1),
                cpp_class('PottsElement', 'mesh', template_args = same_dims_1),
                cpp_class('TetrahedralMesh', 'mesh', template_args = same_dims_2,
                          excluded_methods = ["FreeTriangulateIo", "InitialiseTriangulateIo"]),
                cpp_class('AbstractTetrahedralMesh', 'mesh', template_args = same_dims_2),
                cpp_class('AbstractMesh', 'mesh', template_args = same_dims_2),
                cpp_class('VertexMesh', 'mesh', template_args = same_dims_2, excluded_methods = ["GetFace"]), # dont have mixed dim elements yet             
                cpp_class('MutableVertexMesh', 'mesh', template_args = same_dims_2),
                cpp_class('Cylindrical2dVertexMesh', 'mesh'),
                cpp_class('SharedHoneycombMeshGenerator', 'mesh'),
                cpp_class('SharedHoneycombVertexMeshGenerator', 'mesh'),
                cpp_class('SharedCylindricalHoneycombVertexMeshGenerator', 'mesh'),
                cpp_class('std::vector', "mesh", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["std::pair<Node<3>*, Node<3>* >"], ["std::pair<Node<2>*, Node<2>* >"],
                                         ["PottsElement<3>*"], ["PottsElement<2>*"],
                                         ["VertexElement<1, 2>*"], ["VertexElement<2, 2>*"],
                                         ["VertexElement<2, 3>*"], ["VertexElement<3, 3>*"], ["VertexElement<3, 3>*"],
                                         ["Element<3, 3>*"], ["Element<2, 2>*"],
                                         ["Node<3>*"], ["Node<2>*"],
                                         ["boost::shared_ptr<Node<3> >"], ["boost::shared_ptr<Node<2> >"],
                                         ]),
                cpp_class('boost::shared_ptr', "mesh", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>"], ["Node<2>"]]),
                cpp_class('std::pair', "mesh", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>*, Node<3>*"], ["Node<2>*, Node<2>*"]]),
                ]

cell_based_classes = [cpp_class('Cell', 'cell_based', excluded_methods=["rGetCellPropertyCollection",
                                                                        "GetSrnModel"]),
                      cpp_class('CellsGenerator', 'cell_based', template_args=
                                [["NoCellCycleModel", 2],
                                 ["NoCellCycleModel", 3],
                                 ["UniformCellCycleModel", 2],
                                 ["UniformCellCycleModel", 3],
                                 ["SimpleOxygenBasedCellCycleModel", 2],
                                 ["SimpleOxygenBasedCellCycleModel", 3],
                                 ["UniformG1GenerationalCellCycleModel", 2],
                                 ["UniformG1GenerationalCellCycleModel", 3],]),
                      cpp_class('CellId', 'cell_based'),
                      cpp_class('CellPropertyRegistry', 'cell_based', excluded_methods=["rGetAllCellProperties",
                                                                                        "TakeOwnership",
                                                                                        "Get"]),
                      cpp_class('CellData', 'cell_based'),
                      cpp_class('CellLabel', 'cell_based'),
                      cpp_class('CellAncestor', 'cell_based'),
                      cpp_class('AbstractCellPopulation', 'cell_based', template_args = same_dims_2,
                                excluded_methods=["rGetCells"]),
                      cpp_class('AbstractOnLatticeCellPopulation', 'cell_based', template_args = same_dims_1),
                      cpp_class('CaBasedCellPopulation', 'cell_based', template_args = same_dims_1,
                                excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier"
                                                  "GetNodeCorrespondingToCell", "rGetAvailableSpaces"]),
                      cpp_class('AbstractCentreBasedCellPopulation', 'cell_based', template_args = same_dims_2,
                                excluded_methods=["GetNodeCorrespondingToCell"]),
                      cpp_class('AbstractOffLatticeCellPopulation', 'cell_based', template_args = same_dims_2),
                      cpp_class('MeshBasedCellPopulation', 'cell_based', template_args = same_dims_2,
                                excluded_methods=["GetVoronoiTessellation, rGetNodePairs, GetTetrahedralMeshForPdeModifier","rGetMesh"]),
                      cpp_class('MeshBasedCellPopulationWithGhostNodes', 'cell_based', template_args = same_dims_1),
                      cpp_class('VertexBasedCellPopulation', 'cell_based', template_args = same_dims_1,
                                excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell"]),
                      cpp_class('PottsBasedCellPopulation', 'cell_based', template_args = same_dims_1,
                                excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell",
                                                  "GetElementTessellation", "GetMutableMesh"]),
                      cpp_class('NodeBasedCellPopulation', 'cell_based', template_args = same_dims_1,
                                excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier","rGetNodePairs"]),
                      cpp_class('VoronoiDataWriter', 'cell_based', template_args = same_dims_2),
                      cpp_class('CellLabelWriter', 'cell_based', template_args = same_dims_2),
                      cpp_class('AbstractCellProperty', 'cell_based', excluded_methods=["IsType"]),
                      cpp_class('CellPropertyCollection', 'cell_based', excluded_methods=["GetCellPropertyRegistry"]),
                      cpp_class('AbstractCellProliferativeType', 'cell_based'),
                      cpp_class('StemCellProliferativeType', 'cell_based'),
                      cpp_class('DefaultCellProliferativeType', 'cell_based'),
                      cpp_class('TransitCellProliferativeType', 'cell_based'),
                      cpp_class('DifferentiatedCellProliferativeType', 'cell_based'),
                      cpp_class('AbstractCellMutationState', 'cell_based'),
                      cpp_class('ApcOneHitCellMutationState', 'cell_based'),
                      cpp_class('ApcTwoHitCellMutationState', 'cell_based'),
                      cpp_class('BetaCateninOneHitCellMutationState', 'cell_based'),
                      cpp_class('WildTypeCellMutationState', 'cell_based'),
                      cpp_class('AbstractCellCycleModel', 'cell_based'),
                      cpp_class('AbstractPhaseBasedCellCycleModel', 'cell_based'),
                      cpp_class('AbstractSimpleCellCycleModel', 'cell_based'),
                      cpp_class('AbstractSimplePhaseBasedCellCycleModel', 'cell_based'),
                      cpp_class('AbstractSimpleGenerationalCellCycleModel', 'cell_based'),
                      cpp_class('UniformCellCycleModel', 'cell_based'),
                      cpp_class('SimpleOxygenBasedCellCycleModel', 'cell_based'),
                      cpp_class('UniformG1GenerationalCellCycleModel', 'cell_based'),
                      cpp_class('NoCellCycleModel', 'cell_based'),
                      cpp_class('AbstractCaUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('DiffusionCaUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractPottsUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('VolumeConstraintPottsUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('SurfaceAreaConstraintPottsUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('DifferentialAdhesionPottsUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('AdhesionPottsUpdateRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractVertexBasedDivisionRule', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractForce', 'cell_based', template_args = same_dims_2),
                      cpp_class('AbstractTwoBodyInteractionForce', 'cell_based', template_args = same_dims_2),
                      cpp_class('GeneralisedLinearSpringForce', 'cell_based', template_args = same_dims_2),
                      cpp_class('NagaiHondaForce', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractCellBasedSimulation', 'cell_based', template_args = same_dims_2,
                                excluded_methods = ["GetSimulationModifiers"]),
                      cpp_class('SimulationTime', 'cell_based'),
                      cpp_class('OnLatticeSimulation', 'cell_based', template_args = same_dims_1),
                      cpp_class('OffLatticeSimulation', 'cell_based', template_args = same_dims_2),
                      cpp_class('AbstractCellBasedSimulationModifier', 'cell_based', template_args = same_dims_2),
                      cpp_class('AbstractTargetAreaModifier', 'cell_based', template_args = same_dims_1),
                      cpp_class('SimpleTargetAreaModifier', 'cell_based', template_args = same_dims_1),
                      cpp_class('VtkSceneModifier', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractCellPopulationBoundaryCondition', 'cell_based', template_args = same_dims_2),
                      cpp_class('PlaneBoundaryCondition', 'cell_based', template_args = same_dims_2),
                      cpp_class('AttractingPlaneBoundaryCondition', 'cell_based', template_args = same_dims_2),
                      cpp_class('SphereGeometryBoundaryCondition', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractCellKiller', 'cell_based', template_args = same_dims_1),
                      cpp_class('PlaneBasedCellKiller', 'cell_based', template_args = same_dims_1),
                      cpp_class('ApoptoticCellKiller', 'cell_based', template_args = same_dims_1),
                      cpp_class('CellwiseSourceEllipticPde', 'cell_based', template_args = same_dims_1),
                      cpp_class('AbstractPdeModifier', 'cell_based', template_args = same_dims_1,
                                excluded_methods = ["GetSolution, GetFeMesh"]),
                      cpp_class('AbstractGrowingDomainPdeModifier', 'cell_based', template_args = same_dims_1),
                      cpp_class('EllipticGrowingDomainPdeModifier', 'cell_based', template_args = same_dims_1,
                                excluded_methods = ["ConstructBoundaryConditionsContainer"]),
                      cpp_class('std::vector', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["CellPtr"],
                                         ["boost::shared_ptr<AbstractCellProperty> "],
                                         ["boost::shared_ptr<AbstractUpdateRule<2> >"],
                                         ["boost::shared_ptr<AbstractUpdateRule<3> >"],
                                         ["boost::shared_ptr<AbstractForce<2> >"], ["boost::shared_ptr<AbstractForce<3> >"],
                                         ["std::pair<Node<3>*, Node<3>* >"], ["std::pair<Node<2>*, Node<2>* >"],]),
                      cpp_class('std::set', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["CellPtr"],]),
                      cpp_class('std::pair', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>*, Node<3>*"], ["Node<2>*, Node<2>*"]]),
                      cpp_class('std::map', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<2>*, c_vector<double, 2> "], 
                                         ["Node<3>*, c_vector<double, 3> "],
                                         ["boost::shared_ptr<Cell>, unsigned"]]),
                      ]

tutorial_classes = [cpp_class('Hello', 'tutorial'),]

visualization_classes = [cpp_class('VtkScene', 'visualization', template_args = same_dims_1),
                         cpp_class('AbstractPyChasteActorGenerator', 'visualization', template_args = same_dims_1),
                         cpp_class('CellPopulationPyChasteActorGenerator', 'visualization', template_args = same_dims_1),]

# This final list will be pulled in by the autowrapper code by name...i.e. don't change the name.
classes = core_classes + ode_classes + pde_classes + mesh_classes + cell_based_classes + tutorial_classes + visualization_classes

