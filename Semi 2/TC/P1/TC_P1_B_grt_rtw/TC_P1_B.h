/*
 * TC_P1_B.h
 *
 * Code generation for model "TC_P1_B".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Sep  8 23:44:21 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_TC_P1_B_h_
#define RTW_HEADER_TC_P1_B_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef TC_P1_B_COMMON_INCLUDES_
# define TC_P1_B_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* TC_P1_B_COMMON_INCLUDES_ */

#include "TC_P1_B_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Buffer;                       /* '<S1>/Buffer' */
  real_T Add;                          /* '<Root>/Add' */
  real_T AnalogFilterDesign;           /* '<Root>/Analog Filter Design' */
  real_T AnalogFilterDesign1;          /* '<Root>/Analog Filter Design1' */
  real_T AnalogFilterDesign2;          /* '<Root>/Analog Filter Design2' */
} B_TC_P1_B_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<S1>/Random Number' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  uint32_T RandSeed;                   /* '<S1>/Random Number' */
} DW_TC_P1_B_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T AnalogFilterDesign_CSTATE[10];/* '<Root>/Analog Filter Design' */
  real_T AnalogFilterDesign1_CSTATE[20];/* '<Root>/Analog Filter Design1' */
  real_T AnalogFilterDesign2_CSTATE[20];/* '<Root>/Analog Filter Design2' */
} X_TC_P1_B_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T AnalogFilterDesign_CSTATE[10];/* '<Root>/Analog Filter Design' */
  real_T AnalogFilterDesign1_CSTATE[20];/* '<Root>/Analog Filter Design1' */
  real_T AnalogFilterDesign2_CSTATE[20];/* '<Root>/Analog Filter Design2' */
} XDot_TC_P1_B_T;

/* State disabled  */
typedef struct {
  boolean_T AnalogFilterDesign_CSTATE[10];/* '<Root>/Analog Filter Design' */
  boolean_T AnalogFilterDesign1_CSTATE[20];/* '<Root>/Analog Filter Design1' */
  boolean_T AnalogFilterDesign2_CSTATE[20];/* '<Root>/Analog Filter Design2' */
} XDis_TC_P1_B_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_TC_P1_B_T_ {
  real_T GaussianNoiseGenerator_m;     /* Mask Parameter: GaussianNoiseGenerator_m
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T GaussianNoiseGenerator_s;     /* Mask Parameter: GaussianNoiseGenerator_s
                                        * Referenced by: '<S1>/Random Number'
                                        */
  real_T SineWave1_Amp;                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 200
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T RandomNumber_Mean;            /* Expression: 0
                                        * Referenced by: '<S1>/Random Number'
                                        */
  real_T RandomNumber_StdDev;          /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S1>/Random Number'
                                        */
  real_T MatrixGain_Gain;              /* Expression: d
                                        * Referenced by: '<S1>/Matrix Gain'
                                        */
  real_T Buffer_ic;                    /* Expression: 0
                                        * Referenced by: '<S1>/Buffer'
                                        */
  real_T AnalogFilterDesign_A[19];     /* Computed Parameter: AnalogFilterDesign_A
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_B;         /* Computed Parameter: AnalogFilterDesign_B
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_C;         /* Computed Parameter: AnalogFilterDesign_C
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_X0;        /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign1_A[39];    /* Computed Parameter: AnalogFilterDesign1_A
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_B;        /* Computed Parameter: AnalogFilterDesign1_B
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_C;        /* Computed Parameter: AnalogFilterDesign1_C
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_X0;       /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign2_A[59];    /* Computed Parameter: AnalogFilterDesign2_A
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
  real_T AnalogFilterDesign2_B[5];     /* Computed Parameter: AnalogFilterDesign2_B
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
  real_T AnalogFilterDesign2_C[10];    /* Computed Parameter: AnalogFilterDesign2_C
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
  real_T AnalogFilterDesign2_D;        /* Computed Parameter: AnalogFilterDesign2_D
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
  real_T AnalogFilterDesign2_X0;       /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TC_P1_B_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_TC_P1_B_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[50];
    real_T odeF[3][50];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_TC_P1_B_T TC_P1_B_P;

/* Block signals (auto storage) */
extern B_TC_P1_B_T TC_P1_B_B;

/* Continuous states (auto storage) */
extern X_TC_P1_B_T TC_P1_B_X;

/* Block states (auto storage) */
extern DW_TC_P1_B_T TC_P1_B_DW;

/* Model entry point functions */
extern void TC_P1_B_initialize(void);
extern void TC_P1_B_step(void);
extern void TC_P1_B_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TC_P1_B_T *const TC_P1_B_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TC_P1_B'
 * '<S1>'   : 'TC_P1_B/Gaussian Noise Generator'
 * '<S2>'   : 'TC_P1_B/dB Conversion'
 * '<S3>'   : 'TC_P1_B/dB Conversion1'
 * '<S4>'   : 'TC_P1_B/dB Conversion/Err if non-flt'
 * '<S5>'   : 'TC_P1_B/dB Conversion/Error if Cplx'
 * '<S6>'   : 'TC_P1_B/dB Conversion1/Err if non-flt'
 * '<S7>'   : 'TC_P1_B/dB Conversion1/Error if Cplx'
 */
#endif                                 /* RTW_HEADER_TC_P1_B_h_ */
