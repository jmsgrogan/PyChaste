"""
This file contains a list of classes that are to be wrapped.

Each class includes metadata such as template arguments, excluded methods,
methods with special pointer management requirements, and any special
declaration code needed for wrapping. A minimal, and typical, case is just to
specify the class name.
"""

from wrapper_utilities.class_info import CppClassInfo

# CORE
# global
global_classes = [CppClassInfo('Identifiable'),  # checkpointing
                  CppClassInfo('PetscTools',  # parallel
                               excluded_methods=["GetWorld"],  # MPI not wrapped here
                               excluded_variables=["MASTER_RANK"]),
                  CppClassInfo('ReplicatableVector'),
                  CppClassInfo('Timer'),
                  CppClassInfo('BoostFilesystem'),
                  CppClassInfo('RelativeTo', component="core"),  # structs/enums need manual module addition
                  CppClassInfo('FileFinder'),
                  CppClassInfo('OutputFileHandler',
                               excluded_methods=["OpenOutputFile"]),
                  CppClassInfo('ProgressReporter'),
                  CppClassInfo('RandomNumberGenerator'),
                  CppClassInfo('SmartPointers'),
                  CppClassInfo('TimeStepper'),
                  CppClassInfo('Version'), ]  # timing

# linalg
linalg_classes = [CppClassInfo('UblasIncludes'), ]

# core
core_classes = global_classes + linalg_classes

# ode
ode_classes = [CppClassInfo('AbstractOdeSystemInformation'),
               CppClassInfo('AbstractPythonOdeSystemInformation'),
               CppClassInfo('AbstractOdeSystem'), ]

# pde
pde_classes = [CppClassInfo('AbstractLinearPde'),
               CppClassInfo('AbstractLinearParabolicPde'),
               CppClassInfo('AbstractLinearEllipticPde'),
               CppClassInfo('AbstractNonlinearEllipticPde'),
               CppClassInfo('AbstractBoundaryCondition'),
               CppClassInfo('ConstBoundaryCondition'),
               CppClassInfo('PdeSimulationTime'), ]

# mesh
mesh_classes = [CppClassInfo('ChastePoint'),
                CppClassInfo('NodeAttributes'),
                CppClassInfo('Node'),
                CppClassInfo('Element',
                             excluded_methods=["CalculateCircumsphereVolume"], ),  # method not found!
                CppClassInfo('NodesOnlyMesh'),
                CppClassInfo('MutableMesh',
                             excluded_methods=["SplitLongEdges", # can't work with vec<c_vec>
                                                 "RescaleMeshFromBoundaryNode"]), # method not found!
                CppClassInfo('PottsMesh'),
                CppClassInfo('SharedPottsMeshGenerator',
                             component="mesh",
                             name_override="PottsMeshGenerator"), # manual override component and name
                CppClassInfo('PottsElement'),
                CppClassInfo('TetrahedralMesh',
                             excluded_methods=["FreeTriangulateIo", 
                                               "InitialiseTriangulateIo"]),
                CppClassInfo('AbstractTetrahedralMesh'),
                CppClassInfo('AbstractMesh'),
                CppClassInfo('VertexMesh',
                             excluded_methods=["GetFace"], # dont have mixed dim elements
                             constructor_arg_type_excludes=["TetrahedralMesh<3, 3>",
                                                            "TetrahedralMesh<2, 2>"]), # not found!
                CppClassInfo('MutableVertexMesh'),
                CppClassInfo('Cylindrical2dVertexMesh'),
                CppClassInfo('SharedHoneycombMeshGenerator',
                             component="mesh",
                             name_override="HoneycombMeshGenerator"),
                CppClassInfo('SharedHoneycombVertexMeshGenerator',
                             component="mesh",
                             name_override="HoneycombVertexMeshGenerator"),
                CppClassInfo('SharedCylindricalHoneycombVertexMeshGenerator',
                             component="mesh",
                             name_override="CylindricalHoneycombVertexMeshGenerator"), ]

# cell based
cell_based_classes = [CppClassInfo('AbstractCellCycleModel'),
                      CppClassInfo('AbstractPhaseBasedCellCycleModel'),
                      CppClassInfo('AbstractSimpleCellCycleModel'),
                      CppClassInfo('AbstractSimplePhaseBasedCellCycleModel'),
                      CppClassInfo('AbstractSimpleGenerationalCellCycleModel'),
                      CppClassInfo('UniformCellCycleModel'),
                      CppClassInfo('SimpleOxygenBasedCellCycleModel'),
                      CppClassInfo('UniformG1GenerationalCellCycleModel'),
                      CppClassInfo('NoCellCycleModel'),
                      CppClassInfo('AbstractCellProperty',
                                   excluded_methods=["IsType"]), # exclude templated method
                      CppClassInfo('AbstractCellProperty', 
                                   excluded_methods=["IsType"]),
                      CppClassInfo('CellPropertyCollection', 
                                   excluded_methods=["GetCellPropertyRegistry"]),
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
                      CppClassInfo('CellPropertyRegistry', 
                                   excluded_methods=["rGetAllCellProperties",
                                                     "TakeOwnership",
                                                     "Get"]),
                      CppClassInfo('AbstractSrnModel'), 
                      CppClassInfo('NullSrnModel', 
                                   pointer_return_methods=[["CreateSrnModel", 
                                                            "reference_existing_object"]]),
                      CppClassInfo('Cell', 
                                   excluded_methods=["rGetCellPropertyCollection",
                                                     "GetSrnModel"]),
                      CppClassInfo('CellsGenerator'),
                      CppClassInfo('AbstractLinearPde',
                                   component="cell_based",
                                   needs_include_file=False,
                                   needs_instantiation=False),
                      CppClassInfo('AbstractLinearParabolicPde',
                                   component="cell_based",
                                   needs_include_file=False,
                                   needs_instantiation=False),
                      CppClassInfo('AbstractLinearEllipticPde',
                                   component="cell_based", 
                                   needs_include_file=False, 
                                   needs_instantiation=False), 
                      CppClassInfo('CellwiseSourceEllipticPde'), 
                      CppClassInfo('AveragedSourceEllipticPde'),
                      CppClassInfo('AveragedSourceParabolicPde'), 
                      CppClassInfo('CellwiseSourceParabolicPde'),
                      CppClassInfo('AbstractPdeModifier', 
                                   excluded_methods = ["GetSolution",
                                                       "GetFeMesh"]),
                      CppClassInfo('AbstractGrowingDomainPdeModifier'),
                      CppClassInfo('EllipticGrowingDomainPdeModifier', 
                                   excluded_methods=["ConstructBoundaryConditionsContainer"]),
                      CppClassInfo('VoronoiDataWriter'), 
                      CppClassInfo('CellLabelWriter'),
                      CppClassInfo('AbstractCaUpdateRule'), 
                      CppClassInfo('AbstractUpdateRule'),
                      CppClassInfo('DiffusionCaUpdateRule'), 
                      CppClassInfo('AbstractPottsUpdateRule'),
                      CppClassInfo('VolumeConstraintPottsUpdateRule'), 
                      CppClassInfo('SurfaceAreaConstraintPottsUpdateRule'),
                      CppClassInfo('DifferentialAdhesionPottsUpdateRule'), 
                      CppClassInfo('AdhesionPottsUpdateRule'),
                      CppClassInfo('AbstractVertexBasedDivisionRule'),
                      CppClassInfo('AbstractForce'), 
                      CppClassInfo('AbstractTwoBodyInteractionForce'),
                      CppClassInfo('GeneralisedLinearSpringForce'), 
                      CppClassInfo('NagaiHondaForce'),
                      CppClassInfo('AbstractCellKiller'), 
                      CppClassInfo('PlaneBasedCellKiller'),
                      CppClassInfo('ApoptoticCellKiller'),
                      CppClassInfo('AbstractCellPopulationBoundaryCondition'), 
                      CppClassInfo('PlaneBoundaryCondition'),
                      CppClassInfo('AttractingPlaneBoundaryCondition', 
                                   pointer_return_methods=[["rGetNormalToPlane", "copy_const_reference"],
                                                           ["rGetPointOnPlane", "copy_const_reference"]]), 
                      CppClassInfo('SphereGeometryBoundaryCondition'),
                      CppClassInfo('AbstractCellPopulation', 
                                   excluded_methods=["rGetCells"]),
                      CppClassInfo('AbstractOnLatticeCellPopulation'),
                      CppClassInfo('AbstractCentreBasedCellPopulation', 
                                   excluded_methods=["GetNodeCorrespondingToCell",
                                                     "MarkSpring",
                                                     "UnmarkSpring"]),
                      CppClassInfo('AbstractOffLatticeCellPopulation'),
                      CppClassInfo('CaBasedCellPopulation', 
                                   excluded_methods=["rGetMesh", 
                                                     "GetTetrahedralMeshForPdeModifier",
                                                     "GetNodeCorrespondingToCell", 
                                                     "rGetAvailableSpaces"]),
                      CppClassInfo('MeshBasedCellPopulation',
                                excluded_methods=["GetVoronoiTessellation", 
                                                  "rGetNodePairs", 
                                                  "GetTetrahedralMeshForPdeModifier",
                                                  "rGetMesh"]),
                      CppClassInfo('MeshBasedCellPopulationWithGhostNodes'),
                      CppClassInfo('VertexBasedCellPopulation', 
                                   excluded_methods=["rGetMesh", 
                                                     "GetTetrahedralMeshForPdeModifier",
                                                     "GetElement", 
                                                     "GetElementCorrespondingToCell"]),
                      CppClassInfo('PottsBasedCellPopulation', 
                                   excluded_methods=["rGetMesh", 
                                                     "GetTetrahedralMeshForPdeModifier",
                                                     "GetElement", 
                                                     "GetElementCorrespondingToCell",
                                                     "GetElementTessellation", 
                                                     "GetMutableMesh"]),
                      CppClassInfo('NodeBasedCellPopulation', 
                                   excluded_methods=["rGetMesh", 
                                                     "GetTetrahedralMeshForPdeModifier",
                                                     "rGetNodePairs"]),
                      CppClassInfo('AbstractTargetAreaModifier'), 
                      CppClassInfo('SimpleTargetAreaModifier'),
                      CppClassInfo('VtkSceneModifier', component="cell_based"), 
                      CppClassInfo('AbstractCellBasedSimulationModifier'),
                      CppClassInfo('AbstractCellBasedSimulation', 
                                   excluded_methods = ["GetSimulationModifiers"]),
                      CppClassInfo('SimulationTime'), 
                      CppClassInfo('OnLatticeSimulation'), 
                      CppClassInfo('OffLatticeSimulation'),
                      ]

# tutorial
tutorial_classes = [CppClassInfo('Hello'), ]

# visualization
visualization_classes = [CppClassInfo('VtkScene'), 
                         CppClassInfo('AbstractPyChasteActorGenerator'),
                         CppClassInfo('CellPopulationPyChasteActorGenerator'), ]

classes = core_classes  + ode_classes + pde_classes + mesh_classes
classes += cell_based_classes + tutorial_classes + visualization_classes