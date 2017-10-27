#include "__cf_TC_P1_C.h"
#include <math.h>
#include "TC_P1_C_acc.h"
#include "TC_P1_C_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo
; uint32_T hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if
( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ; real_T
si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void RandSrcInitState_U_64 ( const uint32_T seed [ ] ,
real_T state [ ] , int32_T nChans ) { int32_T i ; uint32_T j ; int32_T k ;
int32_T n ; real_T d ; for ( i = 0 ; i < nChans ; i ++ ) { j = seed [ i ] !=
0U ? seed [ i ] : 2147483648U ; state [ 35 * i + 34 ] = j ; for ( k = 0 ; k <
32 ; k ++ ) { d = 0.0 ; for ( n = 0 ; n < 53 ; n ++ ) { j ^= j << 13 ; j ^= j
>> 17 ; j ^= j << 5 ; d = ( real_T ) ( ( int32_T ) ( j >> 19 ) & 1 ) + ( d +
d ) ; } state [ 35 * i + k ] = ldexp ( d , - 53 ) ; } state [ 35 * i + 32 ] =
0.0 ; state [ 35 * i + 33 ] = 0.0 ; } } void RandSrc_U_D ( real_T y [ ] ,
const real_T minVec [ ] , int32_T minLen , const real_T maxVec [ ] , int32_T
maxLen , real_T state [ ] , int32_T nChans , int32_T nSamps ) { int32_T one ;
int32_T lsw ; int8_T * onePtr ; int32_T chan ; real_T min ; real_T max ;
int32_T samps ; real_T d ; int32_T i ; uint32_T j ; one = 1 ; onePtr = (
int8_T * ) & one ; lsw = ( onePtr [ 0U ] == 0 ) ; for ( chan = 0 ; chan <
nChans ; chan ++ ) { min = minVec [ minLen > 1 ? chan : 0 ] ; max = maxVec [
maxLen > 1 ? chan : 0 ] ; max -= min ; i = ( int32_T ) ( ( uint32_T ) state [
chan * 35 + 33 ] & 31U ) ; j = ( uint32_T ) state [ chan * 35 + 34 ] ; for (
samps = 0 ; samps < nSamps ; samps ++ ) { d = state [ ( ( i + 20 ) & 31 ) +
chan * 35 ] ; d -= state [ ( ( i + 5 ) & 31 ) + chan * 35 ] ; d -= state [
chan * 35 + 32 ] ; if ( d >= 0.0 ) { state [ chan * 35 + 32 ] = 0.0 ; } else
{ d ++ ; state [ chan * 35 + 32 ] = 1.1102230246251565E-16 ; } state [ chan *
35 + i ] = d ; i = ( i + 1 ) & 31 ; ( ( int32_T * ) & d ) [ lsw ] ^= j ; j ^=
j << 13 ; j ^= j >> 17 ; j ^= j << 5 ; ( ( int32_T * ) & d ) [ lsw ^ 1 ] ^= j
& 1048575U ; y [ chan * nSamps + samps ] = max * d + min ; } state [ chan *
35 + 33 ] = i ; state [ chan * 35 + 34 ] = j ; } } static void mdlOutputs (
SimStruct * S , int_T tid ) { int_T ci ; real_T taskTimeV ; real_T
tNextAdjusted ; real_T ratio ; uint32_T numCycles ; real_T v6 ; ZCEventType
zcEvent ; real_T jyodn4si1s ; real_T ojfq42nj2y ; real_T giimtiim3l ; real_T
doc3530mak ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; f1xhd02yjc * _rtX ;
o24blyp2sp * _rtZCE ; ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( o24blyp2sp * ) _ssGetPrevZCSigState ( S
) ) ; _rtX = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ; _rtP = ( (
loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * )
_ssGetBlockIO ( S ) ) ; _rtB -> fqlktzjcfy = 0.0 ; ci = 0 ; while ( ci < 1 )
{ _rtB -> fqlktzjcfy += _rtP -> P_3 * _rtX -> psnkwrmkrq [ 9 ] ; ci = 1 ; }
if ( ssIsSampleHit ( S , 4 , 0 ) ) { taskTimeV = ssGetTaskTime ( S , 4 ) ;
tNextAdjusted = ( real_T ) ssGetTNextWasAdjusted ( S , 4 ) ; if (
tNextAdjusted != 0.0 ) { _rtDW -> p3tx0z5vyf = _ssGetVarNextHitTime ( S , 0 )
; } if ( _rtDW -> j3uqtpp344 != 0 ) { _rtDW -> j3uqtpp344 = 0 ; if (
taskTimeV >= _rtP -> P_8 ) { ratio = ( taskTimeV - _rtP -> P_8 ) / _rtP ->
P_6 ; numCycles = ( uint32_T ) muDoubleScalarFloor ( ratio ) ; if (
muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON *
ratio ) { numCycles ++ ; } _rtDW -> hjcfxjmii3 = numCycles ; v6 = ( ( real_T
) numCycles * _rtP -> P_6 + _rtP -> P_8 ) + _rtP -> P_7 * _rtP -> P_6 / 100.0
; if ( taskTimeV < v6 ) { _rtDW -> acyh0z4v21 = 1 ; _rtDW -> p3tx0z5vyf = v6
; } else { _rtDW -> acyh0z4v21 = 0 ; _rtDW -> p3tx0z5vyf = ( real_T ) (
numCycles + 1U ) * _rtP -> P_6 + _rtP -> P_8 ; } } else { _rtDW -> hjcfxjmii3
= _rtP -> P_8 != 0.0 ? - 1 : 0 ; _rtDW -> acyh0z4v21 = 0 ; _rtDW ->
p3tx0z5vyf = _rtP -> P_8 ; } } else { if ( _rtDW -> p3tx0z5vyf <= taskTimeV )
{ if ( _rtDW -> acyh0z4v21 == 1 ) { _rtDW -> acyh0z4v21 = 0 ; _rtDW ->
p3tx0z5vyf = ( real_T ) ( _rtDW -> hjcfxjmii3 + 1L ) * _rtP -> P_6 + _rtP ->
P_8 ; } else { _rtDW -> hjcfxjmii3 ++ ; _rtDW -> acyh0z4v21 = 1 ; _rtDW ->
p3tx0z5vyf = ( _rtP -> P_7 * _rtP -> P_6 * 0.01 + ( real_T ) _rtDW ->
hjcfxjmii3 * _rtP -> P_6 ) + _rtP -> P_8 ; } } } _ssSetVarNextHitTime ( S , 0
, _rtDW -> p3tx0z5vyf ) ; if ( _rtDW -> acyh0z4v21 == 1 ) { _rtB ->
ig02n0wouk = _rtP -> P_5 ; } else { _rtB -> ig02n0wouk = 0.0 ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { tNextAdjusted = _rtB -> ig02n0wouk ; if (
ssIsMajorTimeStep ( S ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , &
_rtZCE -> mxmqab5xos , ( tNextAdjusted ) ) ; if ( zcEvent != NO_ZCEVENT ) {
_rtB -> hmdtk2pafz = _rtB -> fqlktzjcfy ; _rtDW -> iu4qayolme = 4 ; } } _rtB
-> cjkdnlo52s = muDoubleScalarSign ( _rtB -> hmdtk2pafz ) ; _rtB ->
i2agflvriw = look1_binlxpw ( _rtB -> cjkdnlo52s , _rtP -> P_10 , _rtP -> P_9
, 1U ) ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { doc3530mak = _rtB ->
i2agflvriw ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { jyodn4si1s = _rtP -> P_11
; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { RandSrc_U_D ( & ojfq42nj2y , & _rtP
-> P_12 , 1 , & _rtP -> P_13 , 1 , _rtDW -> pvvrmjios3 , 1 , 1 ) ; _rtB ->
hvralrmyh4 = ( real_T ) ( ojfq42nj2y > _rtP -> P_14 ) * _rtP -> P_15 ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> d5tml12fqj = jyodn4si1s + _rtB ->
hvralrmyh4 ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { tNextAdjusted = 0.0 ; v6
= 0.0 ; ratio = 0.0 ; _rtDW -> egbrg3i0ys [ _rtDW -> co5ubg0mij ] =
doc3530mak ; if ( _rtDW -> co5ubg0mij == 1 ) { _rtDW -> co5ubg0mij = 0 ; }
else { _rtDW -> co5ubg0mij ++ ; } if ( _rtDW -> e3hd2mckig < 1 ) { _rtDW ->
e3hd2mckig ++ ; } else { if ( _rtDW -> icjy3tzj0f ) { v6 = 1.0 ; if ( _rtDW
-> egbrg3i0ys [ _rtDW -> co5ubg0mij ] != _rtB -> d5tml12fqj ) { tNextAdjusted
= 1.0 ; } } } _rtDW -> gpwligbhga += v6 ; _rtDW -> axhdf0htii +=
tNextAdjusted ; if ( _rtDW -> gpwligbhga > 0.0 ) { ratio = _rtDW ->
axhdf0htii / _rtDW -> gpwligbhga ; } _rtB -> caxi42oesx [ 0U ] = ratio ; _rtB
-> caxi42oesx [ 1U ] = _rtDW -> axhdf0htii ; _rtB -> caxi42oesx [ 2U ] =
_rtDW -> gpwligbhga ; ssCallAccelRunBlock ( S , 1 , 14 , SS_CALL_MDL_OUTPUTS
) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 15 ,
SS_CALL_MDL_OUTPUTS ) ; giimtiim3l = _rtP -> P_16 * _rtB -> d5tml12fqj ; } if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> dutfukbarx = _rtP -> P_20 * _rtDW
-> dtkakm5txa + _rtP -> P_21 ; _rtB -> c502qqtujl = _rtB -> dutfukbarx ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bmrbs52lqb = giimtiim3l + _rtB ->
c502qqtujl ; ssCallAccelRunBlock ( S , 1 , 23 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 24 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 1 , 25 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 26 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 27 , SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { loikxjbxjg * _rtP ;
ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtP
= ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; if ( ssIsSampleHit ( S , 2 ,
0 ) ) { _rtDW -> dtkakm5txa = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
kdhgoh5qh1 ) * _rtP -> P_18 + _rtP -> P_17 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { int_T is ; int_T ci ; static
const int8_T ir [ 11 ] = { 0 , 2 , 3 , 6 , 7 , 10 , 11 , 14 , 15 , 18 , 19 }
; static const int8_T ir_p [ 11 ] = { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 } ; static const int8_T jc [ 19 ] = { 0 , 1 , 0 , 1 , 2 , 3 , 2 , 3 , 4 , 5
, 4 , 5 , 6 , 7 , 6 , 7 , 8 , 9 , 8 } ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP
; f1xhd02yjc * _rtX ; pqmvzr1kvu * _rtXdot ; _rtXdot = ( ( pqmvzr1kvu * )
ssGetdX ( S ) ) ; _rtX = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ; _rtP =
( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * )
_ssGetBlockIO ( S ) ) ; memset ( & _rtXdot -> psnkwrmkrq [ 0 ] , 0 , 10U *
sizeof ( real_T ) ) ; for ( is = 0 ; is < 10 ; is ++ ) { for ( ci = ir [ is ]
; ci < ir [ is + 1 ] ; ci ++ ) { _rtXdot -> psnkwrmkrq [ is ] += _rtP -> P_1
[ ci ] * _rtX -> psnkwrmkrq [ jc [ ci ] ] ; } } for ( is = 0 ; is < 10 ; is
++ ) { ci = ir_p [ is ] ; while ( ci < ir_p [ is + 1 ] ) { _rtXdot ->
psnkwrmkrq [ is ] += _rtP -> P_2 * _rtB -> bmrbs52lqb ; ci = 1 ; } } } static
void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
3188436164U ) ; ssSetChecksumVal ( S , 1 , 240806988U ) ; ssSetChecksumVal (
S , 2 , 2923832304U ) ; ssSetChecksumVal ( S , 3 , 2055507097U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.3" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( ew10rzwqr2 ) ) { ssSetErrorStatus ( S ,
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
