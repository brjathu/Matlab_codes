#include "__cf_ssp4.h"
#include <math.h>
#include "ssp4_acc.h"
#include "ssp4_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { char_T * sErr ; void *
audio ; int16_T b4eyfaifxn ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP ;
ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtP
= ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * )
_ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { sErr =
GetErrorBuffer ( & _rtDW -> k3gxplsjys [ 0U ] ) ; audio = ( void * ) & _rtB
-> hpdgxncvqr ; LibOutputs_FromMMFile ( & _rtDW -> k3gxplsjys [ 0U ] ,
GetNullPointer ( ) , audio , GetNullPointer ( ) , GetNullPointer ( ) ,
GetNullPointer ( ) ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( S , sErr ) ;
ssSetStopRequested ( S , 1 ) ; } b4eyfaifxn = ( int16_T ) ( _rtP -> P_10 *
_rtB -> hpdgxncvqr >> 15 ) ; _rtB -> geyoptmzjv = ( int16_T ) ( ( ( ( ( (
_rtP -> P_11 * _rtDW -> op33dosocz [ 0 ] >> 17 ) + b4eyfaifxn ) + ( _rtP ->
P_13 * _rtDW -> b1s2fitqka [ 0 ] >> 16 ) ) + ( _rtP -> P_12 * _rtDW ->
dsgys0qsx1 [ 0 ] >> 17 ) ) + ( _rtP -> P_14 * _rtDW -> bjexdnbsxy [ 0 ] >> 18
) ) + ( _rtP -> P_15 * _rtDW -> k1onn5kscs [ 0 ] >> 19 ) ) ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { char_T * sErr ; void *
audio ; int32_T idxDelay ; n3qi1whofz * _rtB ; ew10rzwqr2 * _rtDW ; _rtDW = (
( ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtB = ( ( n3qi1whofz * )
_ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { sErr =
GetErrorBuffer ( & _rtDW -> bs5meiwhna [ 0U ] ) ; audio = ( void * ) & _rtB
-> geyoptmzjv ; LibUpdate_ToMMFile ( & _rtDW -> bs5meiwhna [ 0U ] , audio ,
GetNullPointer ( ) , GetNullPointer ( ) , GetNullPointer ( ) ) ; if ( * sErr
!= 0 ) { ssSetErrorStatus ( S , sErr ) ; } for ( idxDelay = 0 ; idxDelay <
9999 ; idxDelay ++ ) { _rtDW -> op33dosocz [ ( uint32_T ) idxDelay ] = _rtDW
-> op33dosocz [ idxDelay + 1U ] ; } _rtDW -> op33dosocz [ 9999 ] = _rtB ->
hpdgxncvqr ; for ( idxDelay = 0 ; idxDelay < 14999 ; idxDelay ++ ) { _rtDW ->
b1s2fitqka [ ( uint32_T ) idxDelay ] = _rtDW -> b1s2fitqka [ idxDelay + 1U ]
; } _rtDW -> b1s2fitqka [ 14999 ] = _rtB -> hpdgxncvqr ; for ( idxDelay = 0 ;
idxDelay < 19999 ; idxDelay ++ ) { _rtDW -> dsgys0qsx1 [ ( uint32_T )
idxDelay ] = _rtDW -> dsgys0qsx1 [ idxDelay + 1U ] ; } _rtDW -> dsgys0qsx1 [
19999 ] = _rtB -> hpdgxncvqr ; for ( idxDelay = 0 ; idxDelay < 24999 ;
idxDelay ++ ) { _rtDW -> bjexdnbsxy [ ( uint32_T ) idxDelay ] = _rtDW ->
bjexdnbsxy [ idxDelay + 1U ] ; } _rtDW -> bjexdnbsxy [ 24999 ] = _rtB ->
hpdgxncvqr ; for ( idxDelay = 0 ; idxDelay < 29999 ; idxDelay ++ ) { _rtDW ->
k1onn5kscs [ ( uint32_T ) idxDelay ] = _rtDW -> k1onn5kscs [ idxDelay + 1U ]
; } _rtDW -> k1onn5kscs [ 29999 ] = _rtB -> hpdgxncvqr ; } UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 765645096U ) ; ssSetChecksumVal ( S , 1 , 2032687057U ) ;
ssSetChecksumVal ( S , 2 , 3174502172U ) ; ssSetChecksumVal ( S , 3 ,
2688379731U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.3" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
ew10rzwqr2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( n3qi1whofz ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
loikxjbxjg ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & o2iu0a2jke ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
