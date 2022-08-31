[Mesh]
  type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
  dim = 2 # Dimensions of the mesh
  nx = 100 # Number of elements in the x-direction
  ny = 10 # Number of elements in y-direction
  xmax = 0.304 # length of test chamber
  ymax = 0.0257 # Test chamber radius
[]

[Problem]
  type = FEProblem # This is the normal type of finite element problem in MOOSE
  coord_type = RZ # Axisymmetric RZ
  rz_coord_axis = X # Which axis the symmetry is around
[]

[Variables]
  [pressure]
     # Adds a linear Lagrange variable by default
  []
[]

[Kernels]
  [diffusion]
     type = DarcyPressure # ADDiffusion # Laplacian opeartor
     variable = pressure # Operate on the pressure variable from above
     permeability = 0.8451e-09 # # (m^s) assumed permeability of the porous medium
  []
[]

[BCs]
  [inlet]
    type = ADDirichletBC # Simple u=value BC
    variable = pressure # Variable to be set
    boundary = left # Name of a sideset in the mesh
    value = 4000 # (Pa) first dat point for 1 mm spheres.
  []
  [outlet]
    type = ADDirichletBC
    variable = pressure
    boundary = right
    value = 0 # (Pa) Gives the correct pressure drop form Figure 2 for 1 mm spheres.
  []
[]

[Executioner]
  type = Steady # Steady state problem
  solve_type = NEWTON # Perform a Newton solve
  # Set PETSc parameters to optimize solver efficiency
  petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
  exodus = true # Output Exodus format
[]


