"""
This file contains a list of classes that are to be wrapped.

Each class includes metadata such as template arguments, excluded methods,
methods with special pointer management requirements, and any special
declaration code needed for wrapping. A minimal, and typical, case is just to
specify the class name.
"""

from wrapper_utilities.class_info import CppClassInfo

# CORE
global_checkpointing_classes = [CppClassInfo('Identifiable'), ]

global_parallel_classes = [
    CppClassInfo('PetscTools', excluded_methods=["GetWorld"],
                 excluded_variables=["MASTER_RANK"]),  # MPI not wrapped
    CppClassInfo('ReplicatableVector'), ]

global_timing_classes = [CppClassInfo('Timer'), ]

global_classes = [
    CppClassInfo('BoostFilesystem', include_file_only=True),
    CppClassInfo('RelativeTo', component="core",
                 needs_include_file=False),  # in FileFinder
    CppClassInfo('FileFinder'),
    CppClassInfo('OutputFileHandler',
                 excluded_methods=["OpenOutputFile"]),  # no auto_ptr
    CppClassInfo('ProgressReporter'),
    CppClassInfo('RandomNumberGenerator'),
    CppClassInfo('SmartPointers', include_file_only=True),
    CppClassInfo('TimeStepper'),
    CppClassInfo('Version', include_file_only=True),
    CppClassInfo('ChasteBuildInfo', component="core", needs_include_file=False,), ]

global_classes += global_checkpointing_classes + global_parallel_classes
global_classes += global_timing_classes

linalg_classes = [
                CppClassInfo('UblasIncludes', include_file_only = True),
                ]

core_classes = global_classes + linalg_classes

################################## ODE ##########################################
ode_classes = [
               CppClassInfo('AbstractOdeSystemInformation'), CppClassInfo('AbstractPythonOdeSystemInformation'),
               CppClassInfo('AbstractOdeSystem')
               ]

################################## PDE ##########################################
pde_classes = [CppClassInfo('AbstractLinearPde'), CppClassInfo('AbstractLinearParabolicPde'),
               CppClassInfo('AbstractLinearEllipticPde'), CppClassInfo('AbstractNonlinearEllipticPde'),
               CppClassInfo('AbstractBoundaryCondition'), CppClassInfo('ConstBoundaryCondition'),
               CppClassInfo('PdeSimulationTime'),
               ]

################################## MESH ##########################################
mesh_classes = [CppClassInfo('ChastePoint', pointer_return_methods=[["rGetLocation", "copy_const_reference"]],), 
                CppClassInfo('NodeAttributes'), 
                CppClassInfo('Node', include_vec_ptr_self=True),
                CppClassInfo('Element', excluded_methods = ["CalculateCircumsphereVolume"],
                         include_vec_ptr_self=True), # method not found
                CppClassInfo('NodesOnlyMesh'),
                CppClassInfo('MutableMesh', excluded_methods = ["SplitLongEdges", # can't work with vec<c_vec>
                                                            "RescaleMeshFromBoundaryNode"]), # method not found
                CppClassInfo('PottsMesh'),
                CppClassInfo('SharedPottsMeshGenerator', component = "mesh",
                         name_override = "PottsMeshGenerator"), # manual override component and name
                CppClassInfo('PottsElement', include_vec_ptr_self=True),
                CppClassInfo('TetrahedralMesh', excluded_methods = ["FreeTriangulateIo", "InitialiseTriangulateIo"]),
                CppClassInfo('AbstractTetrahedralMesh'),
                CppClassInfo('AbstractMesh'),
                CppClassInfo('VertexMesh', excluded_methods = ["GetFace"]), # dont have mixed dim elements yet             
                CppClassInfo('MutableVertexMesh'),
                CppClassInfo('Cylindrical2dVertexMesh'),
                CppClassInfo('SharedHoneycombMeshGenerator', component = "mesh", 
                         name_override = "HoneycombMeshGenerator"),
                CppClassInfo('SharedHoneycombVertexMeshGenerator', component = "mesh", 
                         name_override = "HoneycombVertexMeshGenerator"),
                CppClassInfo('SharedCylindricalHoneycombVertexMeshGenerator', component = "mesh", 
                         name_override = "CylindricalHoneycombVertexMeshGenerator"),
#                 CppClassInfo('std::pair', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
#                           template_args=[["Node3Ptr, Node3Ptr"], ["Node2Ptr, Node2Ptr"]]),
#                 CppClassInfo('std::vector', skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
#                           template_args=[["PairNode3PtrNode3Ptr"], ["PairNode2PtrNode2Ptr"],
#                                          ["VertexElement<1,2>*"], ["VertexElement<2,2>*"],
#                                          ["VertexElement<2,3>*"], ["VertexElement<3,3>*"],
#                                          ]),
                ]

################################## CELL_BASED ##########################################
cell_based_cell_cycle_classes = [CppClassInfo('AbstractCellCycleModel'),
                      CppClassInfo('AbstractPhaseBasedCellCycleModel'), 
                      CppClassInfo('AbstractSimpleCellCycleModel'),
                      CppClassInfo('AbstractSimplePhaseBasedCellCycleModel'),
                      CppClassInfo('AbstractSimpleGenerationalCellCycleModel'),
                      CppClassInfo('UniformCellCycleModel'),
                      CppClassInfo('SimpleOxygenBasedCellCycleModel'),
                      CppClassInfo('UniformG1GenerationalCellCycleModel'), 
                      CppClassInfo('NoCellCycleModel'),]

cell_based_cell_property_classes = [
                    CppClassInfo('AbstractCellProperty', excluded_methods=["IsType"], include_vec_ptr_self=True),
                      CppClassInfo('CellPropertyCollection', excluded_methods=["GetCellPropertyRegistry"]),
                      CppClassInfo('AbstractCellProliferativeType'), 
                      CppClassInfo('StemCellProliferativeType'),
                      CppClassInfo('DefaultCellProliferativeType'), 
                      CppClassInfo('TransitCellProliferativeType'),
                      CppClassInfo('DifferentiatedCellProliferativeType'), 
                      CppClassInfo('AbstractCellMutationState'),
                      CppClassInfo('ApcOneHitCellMutationState'), 
                      CppClassInfo('ApcTwoHitCellMutationState'),
                      CppClassInfo('BetaCateninOneHitCellMutationState'), 
                      CppClassInfo('WildTypeCellMutationState'),
                      CppClassInfo('ApoptoticCellProperty'), 
                      CppClassInfo('CellData'),
                      CppClassInfo('CellLabel'), 
                      CppClassInfo('CellAncestor'),
                      CppClassInfo('CellId'), 
                      CppClassInfo('CellPropertyRegistry', excluded_methods=["rGetAllCellProperties",
                                                                    "TakeOwnership",
                                                                    "Get"]),]

cell_based_cell_srn_classes = [CppClassInfo('AbstractSrnModel'), 
                               CppClassInfo('NullSrnModel', pointer_return_methods=[["CreateSrnModel", "reference_existing_object"]]),
                               ]

cell_based_cell_classes = [CppClassInfo('Cell', excluded_methods=["rGetCellPropertyCollection",
                                                                        "GetSrnModel"], 
                                    include_vec_ptr_self=True),
                      CppClassInfo('CellsGenerator')
                           ]

cell_based_cell_classes += cell_based_cell_cycle_classes + cell_based_cell_property_classes + cell_based_cell_srn_classes

cell_based_cell_based_pde_classes = [
                      CppClassInfo('AbstractLinearPde', component = "cell_based", needs_include_file=False, needs_instantiation = False), 
                      CppClassInfo('AbstractLinearParabolicPde',component = "cell_based", needs_include_file=False, needs_instantiation = False),
                      CppClassInfo('AbstractLinearEllipticPde', component = "cell_based", needs_include_file=False, needs_instantiation = False), 
                      CppClassInfo('CellwiseSourceEllipticPde'), CppClassInfo('AveragedSourceEllipticPde'),
                      CppClassInfo('AveragedSourceParabolicPde'), CppClassInfo('CellwiseSourceParabolicPde'),
                      CppClassInfo('AbstractPdeModifier', excluded_methods = ["GetSolution, GetFeMesh"]),
                      CppClassInfo('AbstractGrowingDomainPdeModifier'),
                      CppClassInfo('EllipticGrowingDomainPdeModifier', excluded_methods = ["ConstructBoundaryConditionsContainer"]),]

cell_based_population_writers_classes = [
                      CppClassInfo('VoronoiDataWriter'), CppClassInfo('CellLabelWriter'),
                    ]

cell_based_population_update_rules_classes = [
                      CppClassInfo('AbstractCaUpdateRule'), 
                      CppClassInfo('AbstractUpdateRule', include_vec_ptr_self=True),
                      CppClassInfo('DiffusionCaUpdateRule'), CppClassInfo('AbstractPottsUpdateRule'),
                      CppClassInfo('VolumeConstraintPottsUpdateRule'), CppClassInfo('SurfaceAreaConstraintPottsUpdateRule'),
                      CppClassInfo('DifferentialAdhesionPottsUpdateRule'), CppClassInfo('AdhesionPottsUpdateRule')
                    ]

cell_based_population_division_rules_classes = [
    CppClassInfo('AbstractVertexBasedDivisionRule'),
    ]

cell_based_population_forces_classes = [
                    CppClassInfo('AbstractForce', include_vec_ptr_self=True), 
                    CppClassInfo('AbstractTwoBodyInteractionForce'),
                    CppClassInfo('GeneralisedLinearSpringForce'), 
                    CppClassInfo('NagaiHondaForce'),
                    ]

cell_based_population_killer_classes = [
                      CppClassInfo('AbstractCellKiller'), CppClassInfo('PlaneBasedCellKiller'),
                      CppClassInfo('ApoptoticCellKiller'),
                    ]

cell_based_population_boundary_conditions_classes = [
                      CppClassInfo('AbstractCellPopulationBoundaryCondition'), 
                      CppClassInfo('PlaneBoundaryCondition'),
                      CppClassInfo('AttractingPlaneBoundaryCondition', pointer_return_methods=[["rGetNormalToPlane", "copy_const_reference"],
                                                                                           ["rGetPointOnPlane", "copy_const_reference"]]), 
                      CppClassInfo('SphereGeometryBoundaryCondition'),
                    ]

cell_based_population_classes = [
                      CppClassInfo('AbstractCellPopulation', excluded_methods=["rGetCells"]),
                      CppClassInfo('AbstractOnLatticeCellPopulation'),
                      CppClassInfo('AbstractCentreBasedCellPopulation', excluded_methods=["GetNodeCorrespondingToCell",
                                                                                          "MarkSpring",
                                                                                          "UnmarkSpring"]),
                      CppClassInfo('AbstractOffLatticeCellPopulation'),
                      CppClassInfo('CaBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier"
                                                  "GetNodeCorrespondingToCell", "rGetAvailableSpaces"]),
                      CppClassInfo('MeshBasedCellPopulation',
                                excluded_methods=["GetVoronoiTessellation, rGetNodePairs, GetTetrahedralMeshForPdeModifier","rGetMesh"]),
                      CppClassInfo('MeshBasedCellPopulationWithGhostNodes'),
                      CppClassInfo('VertexBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell"]),
                      CppClassInfo('PottsBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier",
                                                  "GetElement", "GetElementCorrespondingToCell",
                                                  "GetElementTessellation", "GetMutableMesh"]),
                      CppClassInfo('NodeBasedCellPopulation', excluded_methods=["rGetMesh", "GetTetrahedralMeshForPdeModifier","rGetNodePairs"]),
                                ]

cell_based_population_classes += cell_based_population_writers_classes + cell_based_population_boundary_conditions_classes
cell_based_population_classes += cell_based_population_killer_classes + cell_based_population_forces_classes
cell_based_population_classes += cell_based_population_division_rules_classes + cell_based_population_update_rules_classes

cell_based_simulation_modifier_classes = [
                    CppClassInfo('AbstractTargetAreaModifier'), CppClassInfo('SimpleTargetAreaModifier'),
                      CppClassInfo('VtkSceneModifier', component="cell_based"), 
                      CppClassInfo('AbstractCellBasedSimulationModifier'),
                      ]

cell_based_simulation_classes = [
                    CppClassInfo('AbstractCellBasedSimulation', excluded_methods = ["GetSimulationModifiers"]),
                      CppClassInfo('SimulationTime'), CppClassInfo('OnLatticeSimulation'), CppClassInfo('OffLatticeSimulation'),
                        ]

# cell_based_classes = [
#                       CppClassInfo('std::set', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
#                           template_args=[["CellPtr"],]),
#                       CppClassInfo('std::map', "cell_based", skip_wrapping=True, needs_include_file=False, needs_instantiation = False,
#                           template_args=[["Node2Ptr, c_vector<double, 2> "], 
#                                          ["Node3Ptr, c_vector<double, 3> "],
#                                          ["CellPtr, unsigned"]]),
#                       ]

cell_based_classes = []

cell_based_classes += cell_based_simulation_classes + cell_based_population_classes + cell_based_cell_based_pde_classes
cell_based_classes += cell_based_cell_classes + cell_based_simulation_modifier_classes

################################## TUTORIAL ##########################################
tutorial_classes = [CppClassInfo('Hello'),]

################################## VISUALIZATION ##########################################
visualization_classes = [CppClassInfo('VtkScene'), CppClassInfo('AbstractPyChasteActorGenerator'),
                         CppClassInfo('CellPopulationPyChasteActorGenerator'),]

################################## EXTRA #################################################
extra_classes = [
                 CppClassInfo("std::string", "extra", skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClassInfo("std::map","extra",  [["std::string", "std::string"]], skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClassInfo("std::set","extra",  [["unsigned"]], skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClassInfo("std::vector","extra", [["double"], 
                                          ["unsigned"], 
                                          ["bool"],
                                          ["std::string"],
                                          ["c_vector<double,3>"],
                                          ["c_vector<double,2>"],
                                          ["c_vector<unsigned,5>"],
                                          ["std::set<unsigned int>"],
                                          ["std::vector<unsigned int>"]], 
                          skip_wrapping=True, needs_include_file=False, needs_instantiation = False),
                 CppClassInfo("c_vector","extra", [["double", 2], ["double", 3], ["unsigned", 5]], 
                          skip_wrapping=True, needs_include_file=False, needs_instantiation = False)]

# This final list will be pulled in by the autowrapper code by name...i.e. don't change the name.
classes = core_classes  + ode_classes + pde_classes + mesh_classes + cell_based_classes + tutorial_classes + visualization_classes