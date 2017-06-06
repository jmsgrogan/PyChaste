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
    CppClass('ChasteBuildInfo', component = "core", needs_include_file = False,
             pointer_return_methods=[["GetBuildInformation", ""],
                                     ["GetBuildTime", ""],
                                     ["GetBuilderUnameInfo", ""],
                                     ["GetCompilerFlags", ""],
                                     ["GetCompilerType", ""],
                                     ["GetCompilerVersion", ""],
                                     ["GetCurrentTime", ""],
                                     ["GetRootDir", ""],
                                     ["GetXsdVersion", ""]],),]

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
mesh_classes = [CppClass('ChastePoint', pointer_return_methods=[["rGetLocation", "copy_const_reference"]],), 
                CppClass('NodeAttributes'), 
                CppClass('Node', include_vec_ptr_self=True),
                CppClass('Element', excluded_methods = ["CalculateCircumsphereVolume"],
                         include_vec_ptr_self=True), # method not found
                CppClass('NodesOnlyMesh'),
                CppClass('MutableMesh', excluded_methods = ["SplitLongEdges", # can't work with vec<c_vec>
                                                            "RescaleMeshFromBoundaryNode"]), # method not found
                CppClass('PottsMesh'),
                CppClass('SharedPottsMeshGenerator', component = "mesh",
                         name_override = "PottsMeshGenerator"), # manual override component and name
                CppClass('PottsElement', include_vec_ptr_self=True),
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
                CppClass('std::pair', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node3Ptr, Node3Ptr"], ["Node2Ptr, Node2Ptr"]]),
                CppClass('std::vector', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["PairNode3PtrNode3Ptr"], ["PairNode2PtrNode2Ptr"],
                                         ["VertexElement<1,2>*"], ["VertexElement<2,2>*"],
                                         ["VertexElement<2,3>*"], ["VertexElement<3,3>*"],
                                         ]),
                ]

################################## CELL_BASED ##########################################
cell_based_cell_cycle_classes = [CppClass('AbstractCellCycleModel'),
                      CppClass('AbstractPhaseBasedCellCycleModel'), 
                      CppClass('AbstractSimpleCellCycleModel'),
                      CppClass('AbstractSimplePhaseBasedCellCycleModel'),
                      CppClass('AbstractSimpleGenerationalCellCycleModel'),
                      CppClass('UniformCellCycleModel'),
                      CppClass('SimpleOxygenBasedCellCycleModel'),
                      CppClass('UniformG1GenerationalCellCycleModel'), 
                      CppClass('NoCellCycleModel'),]

cell_based_cell_property_classes = [
                    CppClass('AbstractCellProperty', excluded_methods=["IsType"], include_vec_ptr_self=True),
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

cell_based_cell_srn_classes = [CppClass('AbstractSrnModel'), 
                               CppClass('NullSrnModel', pointer_return_methods=[["CreateSrnModel", "reference_existing_object"]]),
                               ]

cell_based_cell_classes = [CppClass('Cell', excluded_methods=["rGetCellPropertyCollection",
                                                                        "GetSrnModel"], 
                                    include_vec_ptr_self=True),
                      CppClass('CellsGenerator')
                           ]

cell_based_cell_classes += cell_based_cell_cycle_classes + cell_based_cell_property_classes + cell_based_cell_srn_classes

cell_based_cell_based_pde_classes = [
                      CppClass('AbstractLinearPde', component = "cell_based", needs_include_file=False, needs_instantiation = False), 
                      CppClass('AbstractLinearParabolicPde',component = "cell_based", needs_include_file=False, needs_instantiation = False),
                      CppClass('AbstractLinearEllipticPde', component = "cell_based", needs_include_file=False, needs_instantiation = False), 
                      CppClass('CellwiseSourceEllipticPde'), CppClass('AveragedSourceEllipticPde'),
                      CppClass('AveragedSourceParabolicPde'), CppClass('CellwiseSourceParabolicPde'),
                      CppClass('AbstractPdeModifier', excluded_methods = ["GetSolution, GetFeMesh"]),
                      CppClass('AbstractGrowingDomainPdeModifier'),
                      CppClass('EllipticGrowingDomainPdeModifier', excluded_methods = ["ConstructBoundaryConditionsContainer"]),]

cell_based_population_writers_classes = [
                      CppClass('VoronoiDataWriter'), CppClass('CellLabelWriter'),
                    ]

cell_based_population_update_rules_classes = [
                      CppClass('AbstractCaUpdateRule'), 
                      CppClass('AbstractUpdateRule', include_vec_ptr_self=True),
                      CppClass('DiffusionCaUpdateRule'), CppClass('AbstractPottsUpdateRule'),
                      CppClass('VolumeConstraintPottsUpdateRule'), CppClass('SurfaceAreaConstraintPottsUpdateRule'),
                      CppClass('DifferentialAdhesionPottsUpdateRule'), CppClass('AdhesionPottsUpdateRule')
                    ]

cell_based_population_division_rules_classes = [
    CppClass('AbstractVertexBasedDivisionRule'),
    ]

cell_based_population_forces_classes = [
                    CppClass('AbstractForce', include_vec_ptr_self=True), 
                    CppClass('AbstractTwoBodyInteractionForce'),
                    CppClass('GeneralisedLinearSpringForce'), 
                    CppClass('NagaiHondaForce'),
                    ]

cell_based_population_killer_classes = [
                      CppClass('AbstractCellKiller'), CppClass('PlaneBasedCellKiller'),
                      CppClass('ApoptoticCellKiller'),
                    ]

cell_based_population_boundary_conditions_classes = [
                      CppClass('AbstractCellPopulationBoundaryCondition'), 
                      CppClass('PlaneBoundaryCondition'),
                      CppClass('AttractingPlaneBoundaryCondition', pointer_return_methods=[["rGetNormalToPlane", "copy_const_reference"],
                                                                                           ["rGetPointOnPlane", "copy_const_reference"]]), 
                      CppClass('SphereGeometryBoundaryCondition'),
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
                      CppClass('VtkSceneModifier', component="cell_based"), 
                      CppClass('AbstractCellBasedSimulationModifier'),
                      ]

cell_based_simulation_classes = [
                    CppClass('AbstractCellBasedSimulation', excluded_methods = ["GetSimulationModifiers"]),
                      CppClass('SimulationTime'), CppClass('OnLatticeSimulation'), CppClass('OffLatticeSimulation'),
                        ]

cell_based_classes = [
                      CppClass('std::set', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["CellPtr"],]),
                      CppClass('std::map', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
                          template_args=[["Node2Ptr, c_vector<double, 2> "], 
                                         ["Node3Ptr, c_vector<double, 3> "],
                                         ["CellPtr, unsigned"]]),
                      ]

cell_based_classes += cell_based_simulation_classes + cell_based_population_classes + cell_based_cell_based_pde_classes
cell_based_classes += cell_based_cell_classes + cell_based_simulation_modifier_classes

################################## TUTORIAL ##########################################
tutorial_classes = [CppClass('Hello'),]

################################## VISUALIZATION ##########################################
visualization_classes = [CppClass('VtkScene'), CppClass('AbstractPyChasteActorGenerator'),
                         CppClass('CellPopulationPyChasteActorGenerator'),]

################################## EXTRA #################################################
extra_classes = [
                 CppClass("std::string", "extra", skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClass("std::map","extra",  [["std::string", "std::string"]], skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClass("std::set","extra",  [["unsigned"]], skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClass("std::vector","extra", [["double"], 
                                          ["unsigned"], 
                                          ["bool"],
                                          ["std::string"],
                                          ["c_vector<double,3>"],
                                          ["c_vector<double,2>"],
                                          ["c_vector<unsigned,5>"],
                                          ["std::set<unsigned int>"],
                                          ["std::vector<unsigned int>"]], 
                          skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClass("c_vector","extra", [["double", 2], ["double", 3], ["unsigned", 5]], 
                          skip_wrapping=True, needs_include_file=False, needs_instantiation = False)]

# This final list will be pulled in by the autowrapper code by name...i.e. don't change the name.
classes = extra_classes + core_classes + ode_classes + pde_classes + mesh_classes + cell_based_classes + tutorial_classes + visualization_classes