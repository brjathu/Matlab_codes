#include "__cf_ssp2.h"
#include "nesl_rtw.h"
#include "ssp2_3b3f044c_1.h"
void ssp2_3b3f044c_gateway ( void ) { NeModelParameters modelparams = { (
NeSolverType ) 1 , 0.001 , 1 , 0.001 , 0 , 0 , 0 , 0 , ( SscLoggingSetting )
0 , } ; NeSolverParameters solverparams = { 0 , 0 , 1 , 0 , 0 , 0.001 , 1e-06
, 1e-09 , 0 , 0 , 1e-09 , 1 , ( NeAdvancerChoice ) 1 , 0.001 , 1 , 3 , 2 , (
NeLinearAlgebraChoice ) 0 , 1024 , 1 , 0.001 , } ; const NeInputParameters *
inputparameters = NULL ; const NeOutputParameters * outputparameters = NULL ;
const NeLinearAlgebra * linear_algebra_ptr = ( ( solverparams .
mLinearAlgebra == NE_FULL_LA ) ? get_rtw_linear_algebra ( ) :
neu_get_csparse_linear_algebra ( ) ) ; NeDae * dae [ 1 ] ; size_t numInputs =
0 ; size_t numOutputs = 0 ; { static const NeOutputParameters
outputparameters_init [ ] = { { 0 , 0 , "ssp2/Solver\nConfiguration" , } , }
; outputparameters = outputparameters_init ; numOutputs = sizeof (
outputparameters_init ) / sizeof ( outputparameters_init [ 0 ] ) ; }
ssp2_3b3f044c_1_dae ( & dae [ 0 ] , & modelparams , & solverparams ,
linear_algebra_ptr ) ; nesl_register_simulator_group (
"ssp2/Solver Configuration" , 1 , dae , solverparams , modelparams ,
numInputs , inputparameters , numOutputs , outputparameters ) ; }
