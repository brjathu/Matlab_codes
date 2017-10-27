#include "__cf_ssp2.h"
#include "rt_logging_mmi.h"
#include "ssp2_capi.h"
#include <math.h>
#include "ssp2.h"
#include "ssp2_private.h"
#include "ssp2_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 2 ;
const char_T * gbl_raccel_Version = "8.6 (R2014a) 27-Dec-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//ssp2//ssp2_Jpattern.mat" ; const int_T gblNumRootInportBlks =
0 ; const int_T gblNumModelInputs = 0 ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtw_diagnostics_reset ( ) ;
rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset ( ) ; } void MdlStart (
void ) { NeuDiagnosticManager * diagnosticManager ; NeBoolVector fimtsVector
; real_T modelParameters_mSolverTolerance ; real_T
modelParameters_mFixedStepSize ; boolean_T
modelParameters_mVariableStepSolver ; NeslSimulator * simulator ;
NeuDiagnosticTree * diagnosticTree ; int32_T tmp ; char * msg ;
NeslSimulationData * simulationData ; real_T time ; NeBoolVector
fimtsVector_p ; boolean_T fimts ; real_T time_p ; NeBoolVector fimtsVector_e
; boolean_T fimts_p ; real_T time_e ; NeModelParameters expl_temp ;
NeModelParameters expl_temp_p ; NeModelParameters expl_temp_e ; simulator =
nesl_lease_simulator ( "ssp2/Solver Configuration" , 0 , 0 ) ; rtDW .
fxhaak0xjw = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . fxhaak0xjw ) ; if (
modelParameters_mVariableStepSolver ) { ssp2_3b3f044c_gateway ( ) ; simulator
= nesl_lease_simulator ( "ssp2/Solver Configuration" , 0 , 0 ) ; rtDW .
fxhaak0xjw = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . kvkxmdygmb = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
kgzjtvmrvt = ( void * ) diagnosticManager ; fimtsVector . mN = 0 ;
fimtsVector . mX = NULL ; modelParameters_mSolverTolerance = ( - 1.0 ) ;
modelParameters_mFixedStepSize = 0.0 ; modelParameters_mVariableStepSolver =
true ; simulator = ( NeslSimulator * ) rtDW . fxhaak0xjw ; diagnosticManager
= ( NeuDiagnosticManager * ) rtDW . kgzjtvmrvt ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp .
mUseSimState = false ; expl_temp . mStartTime = 0.0 ; expl_temp . mSolverType
= NE_SOLVER_TYPE_ODE ; expl_temp . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp . mLoadInitialState = false ; expl_temp .
mLinTrimCompile = false ; expl_temp . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp , & fimtsVector , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . kvkxmdygmb ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 4 ; simulationData -> mData -> mDiscStates . mX = (
real_T * ) & rtDW . aawmqhvsde ; simulationData -> mData -> mModeVector . mN
= 10 ; simulationData -> mData -> mModeVector . mX = ( int32_T * ) & rtDW .
aovldzv0y5 ; modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS
) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData ->
mData -> mFoundZcEvents = modelParameters_mVariableStepSolver ;
simulationData -> mData -> mIsMajorTimeStep = true ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
fxhaak0xjw ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . kgzjtvmrvt
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator ( "ssp2/Solver Configuration" , 3 , 0 ) ;
rtDW . gehqqvu5gv = ( void * ) simulator ;
modelParameters_mVariableStepSolver = pointer_is_null ( rtDW . gehqqvu5gv ) ;
if ( modelParameters_mVariableStepSolver ) { ssp2_3b3f044c_gateway ( ) ;
simulator = nesl_lease_simulator ( "ssp2/Solver Configuration" , 3 , 0 ) ;
rtDW . gehqqvu5gv = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . ipxtwqhjkn = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
h0xsttajpc = ( void * ) diagnosticManager ; fimts = true ; fimtsVector_p . mN
= 1 ; fimtsVector_p . mX = & fimts ; modelParameters_mSolverTolerance = ( -
1.0 ) ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . gehqqvu5gv ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
h0xsttajpc ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_p . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_p . mUseSimState = false ;
expl_temp_p . mStartTime = 0.0 ; expl_temp_p . mSolverType =
NE_SOLVER_TYPE_ODE ; expl_temp_p . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_p . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_p . mLoadInitialState = false ; expl_temp_p .
mLinTrimCompile = false ; expl_temp_p . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_p , & fimtsVector_p , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . ipxtwqhjkn ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
gehqqvu5gv ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . h0xsttajpc
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator ( "ssp2/Solver Configuration" , 1 , 0 ) ;
rtDW . gi3cxvn0ws = ( void * ) simulator ;
modelParameters_mVariableStepSolver = pointer_is_null ( rtDW . gi3cxvn0ws ) ;
if ( modelParameters_mVariableStepSolver ) { ssp2_3b3f044c_gateway ( ) ;
simulator = nesl_lease_simulator ( "ssp2/Solver Configuration" , 1 , 0 ) ;
rtDW . gi3cxvn0ws = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . kkrkpatst5 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
hrf3w0emgj = ( void * ) diagnosticManager ; fimts_p = true ; fimtsVector_e .
mN = 1 ; fimtsVector_e . mX = & fimts_p ; modelParameters_mSolverTolerance =
( - 1.0 ) ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . gi3cxvn0ws ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
hrf3w0emgj ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_e . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_e . mUseSimState = false ;
expl_temp_e . mStartTime = 0.0 ; expl_temp_e . mSolverType =
NE_SOLVER_TYPE_ODE ; expl_temp_e . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_e . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_e . mLoadInitialState = false ; expl_temp_e .
mLinTrimCompile = false ; expl_temp_e . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_e , & fimtsVector_e , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . kkrkpatst5 ; time_e = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_e ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
gi3cxvn0ws ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . hrf3w0emgj
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; int_T tmp_p ; NeslSimulator *
simulator ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; int32_T tmp_e ; char * msg ; NeslSimulationData *
simulationData_p ; real_T time_p ; real_T tmp_i [ 14 ] ; int_T tmp_m [ 2 ] ;
NeslSimulator * simulator_p ; NeuDiagnosticManager * diagnosticManager_p ;
NeuDiagnosticTree * diagnosticTree_p ; char * msg_p ; NeslSimulationData *
simulationData_e ; real_T time_e ; real_T tmp_g [ 14 ] ; int_T tmp_j [ 2 ] ;
NeslSimulator * simulator_e ; NeuDiagnosticManager * diagnosticManager_e ;
NeuDiagnosticTree * diagnosticTree_e ; char * msg_e ; real_T dfk1glsw3o ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { simulationData = ( NeslSimulationData * )
rtDW . kvkxmdygmb ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time ; simulationData ->
mData -> mContStates . mN = 0 ; simulationData -> mData -> mContStates . mX =
NULL ; simulationData -> mData -> mDiscStates . mN = 4 ; simulationData ->
mData -> mDiscStates . mX = ( real_T * ) & rtDW . aawmqhvsde ; simulationData
-> mData -> mModeVector . mN = 10 ; simulationData -> mData -> mModeVector .
mX = ( int32_T * ) & rtDW . aovldzv0y5 ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_p = 0 ; simulationData -> mData ->
mInputValues . mN = 0 ; simulationData -> mData -> mInputOffsets . mN = 1 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_p ; simulationData ->
mData -> mOutputs . mN = 14 ; simulationData -> mData -> mOutputs . mX = &
rtB . arplhcksad [ 0U ] ; simulationData -> mData -> mSampleHits . mN = 0 ;
simulationData -> mData -> mSampleHits . mX = NULL ; tmp = ssIsSampleHit (
rtS , 1 , 0 ) ; simulationData -> mData -> mIsFundamentalSampleHit = tmp ;
simulator = ( NeslSimulator * ) rtDW . fxhaak0xjw ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . kgzjtvmrvt ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_e =
ne_simulator_method ( simulator , NESL_SIM_OUTPUTS , simulationData ,
diagnosticManager ) ; if ( tmp_e != 0 ) { tmp_e =
rtw_diagnostics_message_count ( ) ; if ( tmp_e == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData_p = ( NeslSimulationData * ) rtDW . ipxtwqhjkn ; time_p =
ssGetT ( rtS ) ; simulationData_p -> mData -> mTime . mN = 1 ;
simulationData_p -> mData -> mTime . mX = & time_p ; simulationData_p ->
mData -> mContStates . mN = 0 ; simulationData_p -> mData -> mContStates . mX
= NULL ; simulationData_p -> mData -> mDiscStates . mN = 0 ; simulationData_p
-> mData -> mDiscStates . mX = NULL ; simulationData_p -> mData ->
mModeVector . mN = 0 ; simulationData_p -> mData -> mModeVector . mX = NULL ;
tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData_p -> mData -> mFoundZcEvents = tmp ;
simulationData_p -> mData -> mIsMajorTimeStep = true ; tmp = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData_p -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData_p -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData_p -> mData ->
mIsComputingJacobian = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData_p -> mData -> mIsSolverRequestingReset = tmp ; tmp_m [ 0U ] =
0 ; tmp_i [ 0U ] = rtB . arplhcksad [ 0 ] ; tmp_i [ 1U ] = rtB . arplhcksad [
1 ] ; tmp_i [ 2U ] = rtB . arplhcksad [ 2 ] ; tmp_i [ 3U ] = rtB . arplhcksad
[ 3 ] ; tmp_i [ 4U ] = rtB . arplhcksad [ 4 ] ; tmp_i [ 5U ] = rtB .
arplhcksad [ 5 ] ; tmp_i [ 6U ] = rtB . arplhcksad [ 6 ] ; tmp_i [ 7U ] = rtB
. arplhcksad [ 7 ] ; tmp_i [ 8U ] = rtB . arplhcksad [ 8 ] ; tmp_i [ 9U ] =
rtB . arplhcksad [ 9 ] ; tmp_i [ 10U ] = rtB . arplhcksad [ 10 ] ; tmp_i [
11U ] = rtB . arplhcksad [ 11 ] ; tmp_i [ 12U ] = rtB . arplhcksad [ 12 ] ;
tmp_i [ 13U ] = rtB . arplhcksad [ 13 ] ; tmp_m [ 1U ] = 14 ;
simulationData_p -> mData -> mInputValues . mN = 14 ; simulationData_p ->
mData -> mInputValues . mX = & tmp_i [ 0U ] ; simulationData_p -> mData ->
mInputOffsets . mN = 2 ; simulationData_p -> mData -> mInputOffsets . mX = &
tmp_m [ 0U ] ; simulationData_p -> mData -> mOutputs . mN = 1 ;
simulationData_p -> mData -> mOutputs . mX = & dfk1glsw3o ; simulationData_p
-> mData -> mSampleHits . mN = 0 ; simulationData_p -> mData -> mSampleHits .
mX = NULL ; tmp = ssIsSampleHit ( rtS , 1 , 0 ) ; simulationData_p -> mData
-> mIsFundamentalSampleHit = tmp ; simulator_p = ( NeslSimulator * ) rtDW .
gehqqvu5gv ; diagnosticManager_p = ( NeuDiagnosticManager * ) rtDW .
h0xsttajpc ; diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager_p ) ; tmp_e = ne_simulator_method ( simulator_p ,
NESL_SIM_OUTPUTS , simulationData_p , diagnosticManager_p ) ; if ( tmp_e != 0
) { tmp_e = rtw_diagnostics_message_count ( ) ; if ( tmp_e == 0 ) { msg_p =
rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS , msg_p ) ;
} } rtB . lhk35iqe3v = dfk1glsw3o ; simulationData_e = ( NeslSimulationData *
) rtDW . kkrkpatst5 ; time_e = ssGetT ( rtS ) ; simulationData_e -> mData ->
mTime . mN = 1 ; simulationData_e -> mData -> mTime . mX = & time_e ;
simulationData_e -> mData -> mContStates . mN = 0 ; simulationData_e -> mData
-> mContStates . mX = NULL ; simulationData_e -> mData -> mDiscStates . mN =
0 ; simulationData_e -> mData -> mDiscStates . mX = NULL ; simulationData_e
-> mData -> mModeVector . mN = 0 ; simulationData_e -> mData -> mModeVector .
mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS )
-> foundContZcEvents ) ; simulationData_e -> mData -> mFoundZcEvents = tmp ;
simulationData_e -> mData -> mIsMajorTimeStep = true ; tmp = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData_e -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData_e -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData_e -> mData ->
mIsComputingJacobian = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData_e -> mData -> mIsSolverRequestingReset = tmp ; tmp_j [ 0U ] =
0 ; tmp_g [ 0U ] = rtB . arplhcksad [ 0 ] ; tmp_g [ 1U ] = rtB . arplhcksad [
1 ] ; tmp_g [ 2U ] = rtB . arplhcksad [ 2 ] ; tmp_g [ 3U ] = rtB . arplhcksad
[ 3 ] ; tmp_g [ 4U ] = rtB . arplhcksad [ 4 ] ; tmp_g [ 5U ] = rtB .
arplhcksad [ 5 ] ; tmp_g [ 6U ] = rtB . arplhcksad [ 6 ] ; tmp_g [ 7U ] = rtB
. arplhcksad [ 7 ] ; tmp_g [ 8U ] = rtB . arplhcksad [ 8 ] ; tmp_g [ 9U ] =
rtB . arplhcksad [ 9 ] ; tmp_g [ 10U ] = rtB . arplhcksad [ 10 ] ; tmp_g [
11U ] = rtB . arplhcksad [ 11 ] ; tmp_g [ 12U ] = rtB . arplhcksad [ 12 ] ;
tmp_g [ 13U ] = rtB . arplhcksad [ 13 ] ; tmp_j [ 1U ] = 14 ;
simulationData_e -> mData -> mInputValues . mN = 14 ; simulationData_e ->
mData -> mInputValues . mX = & tmp_g [ 0U ] ; simulationData_e -> mData ->
mInputOffsets . mN = 2 ; simulationData_e -> mData -> mInputOffsets . mX = &
tmp_j [ 0U ] ; simulationData_e -> mData -> mOutputs . mN = 0 ;
simulationData_e -> mData -> mOutputs . mX = NULL ; simulationData_e -> mData
-> mSampleHits . mN = 0 ; simulationData_e -> mData -> mSampleHits . mX =
NULL ; tmp = ssIsSampleHit ( rtS , 1 , 0 ) ; simulationData_e -> mData ->
mIsFundamentalSampleHit = tmp ; simulator_e = ( NeslSimulator * ) rtDW .
gi3cxvn0ws ; diagnosticManager_e = ( NeuDiagnosticManager * ) rtDW .
hrf3w0emgj ; diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager_e ) ; tmp_e = ne_simulator_method ( simulator_e ,
NESL_SIM_OUTPUTS , simulationData_e , diagnosticManager_e ) ; if ( tmp_e != 0
) { tmp_e = rtw_diagnostics_message_count ( ) ; if ( tmp_e == 0 ) { msg_e =
rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus ( rtS , msg_e ) ;
} } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
NeslSimulationData * simulationData ; real_T time ; boolean_T tmp ; int_T
tmp_p ; NeslSimulator * simulator ; NeuDiagnosticManager * diagnosticManager
; NeuDiagnosticTree * diagnosticTree ; int32_T tmp_e ; char * msg ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { simulationData = ( NeslSimulationData * )
rtDW . kvkxmdygmb ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time ; simulationData ->
mData -> mContStates . mN = 0 ; simulationData -> mData -> mContStates . mX =
NULL ; simulationData -> mData -> mDiscStates . mN = 4 ; simulationData ->
mData -> mDiscStates . mX = ( real_T * ) & rtDW . aawmqhvsde ; simulationData
-> mData -> mModeVector . mN = 10 ; simulationData -> mData -> mModeVector .
mX = ( int32_T * ) & rtDW . aovldzv0y5 ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_p = 0 ; simulationData -> mData ->
mInputValues . mN = 0 ; simulationData -> mData -> mInputOffsets . mN = 1 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_p ; simulator = (
NeslSimulator * ) rtDW . fxhaak0xjw ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . kgzjtvmrvt ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_e =
ne_simulator_method ( simulator , NESL_SIM_UPDATE , simulationData ,
diagnosticManager ) ; if ( tmp_e != 0 ) { tmp_e =
rtw_diagnostics_message_count ( ) ; if ( tmp_e == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
} UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . kgzjtvmrvt
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . kvkxmdygmb
) ; nesl_erase_simulator ( "ssp2/Solver Configuration" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . h0xsttajpc
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . ipxtwqhjkn
) ; nesl_erase_simulator ( "ssp2/Solver Configuration" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . hrf3w0emgj
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . kkrkpatst5
) ; nesl_erase_simulator ( "ssp2/Solver Configuration" ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 13 ) ;
ssSetNumBlockIO ( rtS , 2 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.001 ) ;
ssSetOffsetTime ( rtS , 0 , 1.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
2481924848U ) ; ssSetChecksumVal ( rtS , 1 , 2135995762U ) ; ssSetChecksumVal
( rtS , 2 , 2902043217U ) ; ssSetChecksumVal ( rtS , 3 , 1682473226U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = & rtBTransTable ; }
ssp2_InitializeDataMapInfo ( rtS ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ssp2" ) ; ssSetPath (
rtS , "ssp2" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 2000.0 ) ; {
static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 4 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 4 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "DiscStates" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"ssp2/Solver\nConfiguration/EVAL_KEY/EXEC_STATE_1" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" } ; static boolean_T rt_LoggedStateCrossMdlRef
[ ] = { 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { {
0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 1 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 1 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) rtDW . aawmqhvsde ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.001 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.001 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepDiscrete" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid
( rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2481924848U ) ; ssSetChecksumVal ( rtS , 1 , 2135995762U ) ; ssSetChecksumVal
( rtS , 2 , 2902043217U ) ; ssSetChecksumVal ( rtS , 3 , 1682473226U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
