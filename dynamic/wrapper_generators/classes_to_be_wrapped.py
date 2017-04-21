"""
This file contains a list of classes that are to be wrapped. 

Each class includes metadata such as template arguments, excluded methods,
methods with special pointer management requirements, and any special
declaration code needed for wrapping. A minimal, and typical, case is just to
specify the class name.
"""

from wrapper_utilities.class_data import CppClass

################################## CORE ##########################################
global_checkpointing_classes = [CppClass('Identifiable', include_file_only = True),]

global_parallel_classes = [
    CppClass('PetscTools', excluded_methods=["GetWorld"], excluded_variables = ["MASTER_RANK"]), # MPI not wrapped
    CppClass('ReplicatableVector'),]

global_timing_classes = [CppClass('Timer'),]

global_classes = [
    CppClass('BoostFilesystem', include_file_only = True),
    CppClass('RelativeTo', component = "core", needs_include_file = False), # in FileFinder
    CppClass('FileFinder'),
    CppClass('OutputFileHandler', excluded_methods = ["OpenOutputFile"]), # can't work with auto_ptr
    CppClass('ProgressReporter'),
    CppClass('RandomNumberGenerator'),
    CppClass('SmartPointers', include_file_only = True),
    CppClass('TimeStepper'),
    CppClass('Version', include_file_only = True),
                  ]

global_classes += global_checkpointing_classes + global_parallel_classes + global_timing_classes

linalg_classes = [
                CppClass('UblasIncludes', include_file_only = True),
                ]

core_classes = global_classes + linalg_classes

################################## ODE ##########################################
ode_classes = [
               CppClass('AbstractOdeSystemInformation'), CppClass('AbstractPythonOdeSystemInformation'),
               CppClass('AbstractOdeSystem')
               ]

################################## PDE ##########################################
pde_classes = [CppClass('AbstractLinearPde'), CppClass('AbstractLinearParabolicPde'),
               CppClass('AbstractLinearEllipticPde'), CppClass('AbstractNonlinearEllipticPde'),
               CppClass('AbstractBoundaryCondition'), CppClass('ConstBoundaryCondition'),
               CppClass('PdeSimulationTime'),
               ]

################################## MESH ##########################################
mesh_classes = [CppClass('ChastePoint'), CppClass('NodeAttributes'), CppClass('Node'),
                CppClass('Element', excluded_methods = ["CalculateCircumsphereVolume"]), # method not found
                CppClass('NodesOnlyMesh'),
                CppClass('MutableMesh', excluded_methods = ["SplitLongEdges", # can't work with vec<c_vec>
                                                            "RescaleMeshFromBoundaryNode"]), # method not found
                CppClass('PottsMesh'),
                CppClass('SharedPottsMeshGenerator', component = "mesh",
                         name_override = "PottsMeshGenerator"), # manual override component and name
                CppClass('PottsElement'),
                CppClass('TetrahedralMesh', excluded_methods = ["FreeTriangulateIo", "InitialiseTriangulateIo"]),
                CppClass('AbstractTetrahedralMesh'),
                CppClass('AbstractMesh'),
                CppClass('VertexMesh', excluded_methods = ["GetFace"]), # dont have mixed dim elements yet             
                CppClass('MutableVertexMesh'),
                CppClass('Cylindrical2dVertexMesh'),
                CppClass('SharedHoneycombMeshGenerator', component = "mesh", 
                         name_override = "HoneycombMeshGenerator"),
                CppClass('SharedHoneycombVertexMeshGenerator', component = "mesh", 
                         name_override = "HoneycombVertexMeshGenerator"),
                CppClass('SharedCylindricalHoneycombVertexMeshGenerator', component = "mesh", 
                         name_override = "CylindricalHoneycombVertexMeshGenerator"),
                CppClass('std::vector', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["std::pair<Node<3>*, Node<3>* >"], ["std::pair<Node<2>*, Node<2>* >"],
                                         ["PottsElement<3>*"], ["PottsElement<2>*"],
                                         ["VertexElement<1, 2>*"], ["VertexElement<2, 2>*"],
                                         ["VertexElement<2, 3>*"], ["VertexElement<3, 3>*"], ["VertexElement<3, 3>*"],
                                         ["Element<3, 3>*"], ["Element<2, 2>*"],
                                         ["Node<3>*"], ["Node<2>*"],
                                         ["boost::shared_ptr<Node<3> >"], ["boost::shared_ptr<Node<2> >"],
                                         ]),
                CppClass('boost::shared_ptr', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>"], ["Node<2>"]]),
                CppClass('std::pair', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>*, Node<3>*"], ["Node<2>*, Node<2>*"]]),
                ]

################################## CELL_BASED ##########################################
cell_based_cell_cycle_classes = [CppClass('AbstractCellCycleModel'),
                      CppClass('AbstractPhaseBasedCellCycleModel'), CppClass('AbstractSimpleCellCycleModel'),
                      CppClass('AbstractSimplePhaseBasedCellCycleModel'),CppClass('AbstractSimpleGenerationalCellCycleModel'),
                      CppClass('UniformCellCycleModel'),CppClass('SimpleOxygenBasedCellCycleModel'),
                      CppClass('UniformG1GenerationalCellCycleModel'), CppClass('NoCellCycleModel'),]

cell_based_cell_property_classes = [
                    CppClass('AbstractCellProperty', excluded_methods=["IsType"]),
                      CppClass('CellPropertyCollection', excluded_methods=["GetCellPropertyRegistry"]),
                      CppClass('AbstractCellProliferativeType'), CppClass('StemCellProliferativeType'),
                      CppClass('DefaultCellProliferativeType'), CppClass('TransitCellProliferativeType'),
                      CppClass('DifferentiatedCellProliferativeType'), CppClass('AbstractCellMutationState'),
                      CppClass('ApcOneHitCellMutationState'), CppClass('ApcTwoHitCellMutationState'),
                      CppClass('BetaCateninOneHitCellMutationState'), CppClass('WildTypeCellMutationState'),
                      CppClass('ApoptoticCellProperty'), CppClass('CellData'),
                      CppClass('CellLabel'), CppClass('CellAncestor'),
                      CppClass('CellId'), CppClass('CellPropertyRegistry', excluded_methods=["rGetAllCellProperties",
                                                                    "TakeOwnership",
                                                                    "Get"]),]

cell_based_cell_srn_classes = [CppClass('AbstractSrnModel'), CppClass('NullSrnModel'),]

cell_based_cell_classes = [CppClass('Cell', excluded_methods=["rGetCellPropertyCollection",
                                                                        "GetSrnModel"]),
                      CppClass('CellsGenerator')
                           ]

cell_based_cell_classes += cell_based_cell_cycle_classes + cell_based_cell_property_classes + cell_based_cell_srn_classes

cell_based_cell_based_pde_classes = [
                      CppClass('CellwiseSourceEllipticPde'), CppClass('AveragedSourceEllipticPde'),
                      CppClass('AveragedSourceParabolicPde'), CppClass('CellwiseSourceParabolicPde'),
                      CppClass('AbstractPdeModifier', excluded_methods = ["GetSolution, GetFeMesh"]),
                      CppClass('AbstractGrowingDomainPdeModifier'),
                      CppClass('EllipticGrowingDomainPdeModifier', excluded_methods = ["ConstructBoundaryConditionsContainer"]),]

cell_based_population_writers_classes = [
                      CppClass('VoronoiDataWriter'), CppClass('CellLabelWriter'),
                    ]

cell_based_population_update_rules_classes = [
                      CppClass('AbstractCaUpdateRule'), CppClass('AbstractUpdateRule'),
                      CppClass('DiffusionCaUpdateRule'), CppClass('AbstractPottsUpdateRule'),
                      CppClass('VolumeConstraintPottsUpdateRule'), CppClass('SurfaceAreaConstraintPottsUpdateRule'),
                      CppClass('DifferentialAdhesionPottsUpdateRule'), CppClass('AdhesionPottsUpdateRule')
                    ]

cell_based_population_division_rules_classes = [
    CppClass('AbstractVertexBasedDivisionRule'),
    ]

cell_based_population_forces_classes = [
                    CppClass('AbstractForce'), CppClass('AbstractTwoBodyInteractionForce'),
                    CppClass('GeneralisedLinearSpringForce'), CppClass('NagaiHondaForce'),
                    ]

cell_based_population_killer_classes = [
                      CppClass('AbstractCellKiller'), CppClass('PlaneBasedCellKiller'),
                      CppClass('ApoptoticCellKiller'),
                    ]

cell_based_population_boundary_conditions_classes = [
                      CppClass('AbstractCellPopulationBoundaryCondition'), CppClass('PlaneBoundaryCondition'),
                      CppClass('AttractingPlaneBoundaryCondition'), CppClass('SphereGeometryBoundaryCondition'),
                    ]

cell_based_population_classes = [
                      CppClass('AbstractCellPopulation', excluded_methods=["rGetCells"]),
                      CppClass('AbstractOnLatticeCellPopulation'),
                      CppClass('AbstractCentreBasedCellPopulation', excluded_methods=["GetNodeCorrespondingToCell"]),
                      CppClass('AbstractOffLatticeCellPopulation'),
                      CppClass('CaBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier"
                                                  "GetNodeCorrespondingToCell", "rGetAvailableSpaces"]),
                      CppClass('MeshBasedCellPopulation',
                                excluded_methods=["GetVoronoiTessellation, rGetNodePairs, GetTetrahedralMeshForPdeModifier","rGetMesh"]),
                      CppClass('MeshBasedCellPopulationWithGhostNodes'),
                      CppClass('VertexBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell"]),
                      CppClass('PottsBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell",
                                                  "GetElementTessellation", "GetMutableMesh"]),
                      CppClass('NodeBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier","rGetNodePairs"]),
                                ]

cell_based_population_classes += cell_based_population_writers_classes + cell_based_population_boundary_conditions_classes
cell_based_population_classes += cell_based_population_killer_classes + cell_based_population_forces_classes
cell_based_population_classes += cell_based_population_division_rules_classes + cell_based_population_update_rules_classes

cell_based_simulation_modifier_classes = [
                    CppClass('AbstractTargetAreaModifier'), CppClass('SimpleTargetAreaModifier'),
                      CppClass('VtkSceneModifier', component="cell_based"), CppClass('AbstractCellBasedSimulationModifier'),
                      ]

cell_based_simulation_classes = [
                    CppClass('AbstractCellBasedSimulation', excluded_methods = ["GetSimulationModifiers"]),
                      CppClass('SimulationTime'), CppClass('OnLatticeSimulation'), CppClass('OffLatticeSimulation'),
                        ]

cell_based_classes = [
                      CppClass('std::vector', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["CellPtr"],
                                         ["boost::shared_ptr<AbstractCellProperty> "],
                                         ["boost::shared_ptr<AbstractUpdateRule<2> >"],
                                         ["boost::shared_ptr<AbstractUpdateRule<3> >"],
                                         ["boost::shared_ptr<AbstractForce<2> >"], ["boost::shared_ptr<AbstractForce<3> >"],
                                         ["std::pair<Node<3>*, Node<3>* >"], ["std::pair<Node<2>*, Node<2>* >"],]),
                      CppClass('std::set', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["CellPtr"],]),
                      CppClass('std::pair', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<3>*, Node<3>*"], ["Node<2>*, Node<2>*"]]),
                      CppClass('std::map', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node<2>*, c_vector<double, 2> "], 
                                         ["Node<3>*, c_vector<double, 3> "],
                                         ["boost::shared_ptr<Cell>, unsigned"]]),
                      ]

cell_based_classes += cell_based_simulation_classes + cell_based_population_classes + cell_based_cell_based_pde_classes
cell_based_classes += cell_based_cell_classes

################################## TUTORIAL ##########################################
tutorial_classes = [CppClass('Hello'),]

################################## VISUALIZATION ##########################################
visualization_classes = [CppClass('VtkScene'), CppClass('AbstractPyChasteActorGenerator'),
                         CppClass('CellPopulationPyChasteActorGenerator'),]

# This final list will be pulled in by the autowrapper code by name...i.e. don't change the name.
classes = core_classes + ode_classes + pde_classes + mesh_classes + cell_based_classes + tutorial_classes + visualization_classes