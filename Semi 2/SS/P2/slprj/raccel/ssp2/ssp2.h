#include "__cf_ssp2.h"
#ifndef RTW_HEADER_ssp2_h_
#define RTW_HEADER_ssp2_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef ssp2_COMMON_INCLUDES_
#define ssp2_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "ssp2_3b3f044c_gateway.h"
#endif
#include "ssp2_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME ssp2
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (2) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
typedef struct { real_T arplhcksad [ 14 ] ; real_T lhk35iqe3v ; } B ; typedef
struct { real_T aawmqhvsde [ 4 ] ; void * fxhaak0xjw ; void * kvkxmdygmb ;
void * kgzjtvmrvt ; void * jdcwboebby ; void * pey0lyliit ; void * gehqqvu5gv
; void * ipxtwqhjkn ; void * h0xsttajpc ; void * ijoba4oino ; void *
l3snbelswk ; struct { void * LoggedData ; } buythqrmps ; void * gi3cxvn0ws ;
void * kkrkpatst5 ; void * hrf3w0emgj ; void * ffjhnerl1j ; void * mckerwfbul
; int_T aovldzv0y5 [ 10 ] ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern
B rtB ; extern DW rtDW ; extern const rtwCAPI_ModelMappingStaticInfo *
ssp2_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern const
int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
#endif
