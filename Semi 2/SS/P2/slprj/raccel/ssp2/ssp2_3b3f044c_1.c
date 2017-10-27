#include "__cf_ssp2.h"
#include "ne_std.h"
#include "ne_default_allocator.h"
#include "ne_dae_fwd.h"
#include "ne_profiler_fwd.h"
#include "ne_dae_construct.h"
#include "ssp2_3b3f044c_1_ds.h"
void ssp2_3b3f044c_1_dae ( NeDae * * dae , const NeModelParameters *
modelParams , const NeSolverParameters * solverParams , const NeLinearAlgebra
* linear_algebra_ptr ) { NeAllocator * ne_allocator ; ne_allocator =
ne_default_allocator ( ) ; ne_dae_create ( dae , ssp2_3b3f044c_1_dae_ds (
ne_allocator , NULL ) , * solverParams , * modelParams , linear_algebra_ptr ,
NULL , NULL , NULL , ne_allocator ) ; }
