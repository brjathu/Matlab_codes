/*
 * TC_P1_B.c
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
#include "TC_P1_B.h"
#include "TC_P1_B_private.h"

/* Block signals (auto storage) */
B_TC_P1_B_T TC_P1_B_B;

/* Continuous states */
X_TC_P1_B_T TC_P1_B_X;

/* Block states (auto storage) */
DW_TC_P1_B_T TC_P1_B_DW;

/* Real-time model */
RT_MODEL_TC_P1_B_T TC_P1_B_M_;
RT_MODEL_TC_P1_B_T *const TC_P1_B_M = &TC_P1_B_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 50;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TC_P1_B_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TC_P1_B_step();
  TC_P1_B_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TC_P1_B_step();
  TC_P1_B_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void TC_P1_B_step(void)
{
  int_T ci;
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
    /* set solver stop time */
    if (!(TC_P1_B_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TC_P1_B_M->solverInfo,
                            ((TC_P1_B_M->Timing.clockTickH0 + 1) *
        TC_P1_B_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TC_P1_B_M->solverInfo,
                            ((TC_P1_B_M->Timing.clockTick0 + 1) *
        TC_P1_B_M->Timing.stepSize0 + TC_P1_B_M->Timing.clockTickH0 *
        TC_P1_B_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TC_P1_B_M)) {
    TC_P1_B_M->Timing.t[0] = rtsiGetT(&TC_P1_B_M->solverInfo);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  TC_P1_B_B.Gain = (sin(TC_P1_B_P.SineWave1_Freq * TC_P1_B_M->Timing.t[0] +
                        TC_P1_B_P.SineWave1_Phase) * TC_P1_B_P.SineWave1_Amp +
                    TC_P1_B_P.SineWave1_Bias) * TC_P1_B_P.Gain_Gain;
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant'
     *  Gain: '<S1>/Matrix Gain'
     *  RandomNumber: '<S1>/Random Number'
     */
    TC_P1_B_B.Sum = TC_P1_B_P.MatrixGain_Gain * TC_P1_B_DW.NextOutput +
      TC_P1_B_P.GaussianNoiseGenerator_m;

    /* Buffer: '<S1>/Buffer' */
    TC_P1_B_B.Buffer = TC_P1_B_B.Sum;
  }

  /* Sum: '<Root>/Add' */
  TC_P1_B_B.Add = TC_P1_B_B.Gain + TC_P1_B_B.Buffer;
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
  }

  /* StateSpace: '<Root>/Analog Filter Design' */
  TC_P1_B_B.AnalogFilterDesign = 0.0;
  ci = 0;
  while (ci < 1) {
    TC_P1_B_B.AnalogFilterDesign += TC_P1_B_P.AnalogFilterDesign_C *
      TC_P1_B_X.AnalogFilterDesign_CSTATE[9];
    ci = 1;
  }

  /* End of StateSpace: '<Root>/Analog Filter Design' */
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
  }

  /* StateSpace: '<Root>/Analog Filter Design1' */
  TC_P1_B_B.AnalogFilterDesign1 = 0.0;
  ci = 0;
  while (ci < 1) {
    TC_P1_B_B.AnalogFilterDesign1 += TC_P1_B_P.AnalogFilterDesign1_C *
      TC_P1_B_X.AnalogFilterDesign1_CSTATE[9];
    ci = 1;
  }

  /* End of StateSpace: '<Root>/Analog Filter Design1' */
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
  }

  /* StateSpace: '<Root>/Analog Filter Design2' */
  TC_P1_B_B.AnalogFilterDesign2 = 0.0;
  for (ci = 0; ci < 10; ci++) {
    TC_P1_B_B.AnalogFilterDesign2 += TC_P1_B_P.AnalogFilterDesign2_C[ci] *
      TC_P1_B_X.AnalogFilterDesign2_CSTATE[ci];
  }

  TC_P1_B_B.AnalogFilterDesign2 += TC_P1_B_P.AnalogFilterDesign2_D *
    TC_P1_B_B.AnalogFilterDesign;

  /* End of StateSpace: '<Root>/Analog Filter Design2' */
  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
  }

  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(TC_P1_B_M->rtwLogInfo, (TC_P1_B_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
    if (rtmIsMajorTimeStep(TC_P1_B_M)) {
      /* Update for RandomNumber: '<S1>/Random Number' */
      TC_P1_B_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&TC_P1_B_DW.RandSeed) *
        TC_P1_B_P.RandomNumber_StdDev + TC_P1_B_P.RandomNumber_Mean;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TC_P1_B_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(TC_P1_B_M)!=-1) &&
          !((rtmGetTFinal(TC_P1_B_M)-(((TC_P1_B_M->Timing.clockTick1+
               TC_P1_B_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((TC_P1_B_M->Timing.clockTick1+TC_P1_B_M->Timing.clockTickH1*
               4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(TC_P1_B_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&TC_P1_B_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++TC_P1_B_M->Timing.clockTick0)) {
      ++TC_P1_B_M->Timing.clockTickH0;
    }

    TC_P1_B_M->Timing.t[0] = rtsiGetSolverStopTime(&TC_P1_B_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      TC_P1_B_M->Timing.clockTick1++;
      if (!TC_P1_B_M->Timing.clockTick1) {
        TC_P1_B_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TC_P1_B_derivatives(void)
{
  int_T is;
  int_T ci;
  static const int8_T ir[11] = { 0, 2, 3, 6, 7, 10, 11, 14, 15, 18, 19 };

  static const int8_T ir_0[11] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  static const int8_T ir_1[21] = { 0, 3, 5, 9, 11, 15, 17, 21, 23, 27, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39 };

  static const int8_T ir_2[21] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1 };

  static const int8_T ir_3[21] = { 0, 4, 8, 10, 16, 18, 25, 27, 36, 38, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59 };

  static const int8_T ir_4[21] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5 };

  static const int8_T jc[19] = { 0, 1, 0, 1, 2, 3, 2, 3, 4, 5, 4, 5, 6, 7, 6, 7,
    8, 9, 8 };

  static const int8_T jc_0[39] = { 0, 1, 10, 0, 11, 1, 2, 3, 12, 2, 13, 3, 4, 5,
    14, 4, 15, 5, 6, 7, 16, 6, 17, 7, 8, 9, 18, 8, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    9 };

  static const int8_T jc_1[59] = { 1, 3, 5, 10, 0, 1, 5, 11, 3, 12, 0, 1, 2, 3,
    5, 13, 5, 14, 0, 1, 2, 3, 4, 5, 15, 7, 16, 0, 1, 2, 3, 4, 5, 6, 7, 17, 9, 18,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  XDot_TC_P1_B_T *_rtXdot;
  _rtXdot = ((XDot_TC_P1_B_T *) TC_P1_B_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<Root>/Analog Filter Design' */
  memset(&_rtXdot->AnalogFilterDesign_CSTATE[0], 0, 10U * sizeof(real_T));
  for (is = 0; is < 10; is++) {
    for (ci = ir[is]; ci < ir[is + 1]; ci++) {
      _rtXdot->AnalogFilterDesign_CSTATE[is] +=
        TC_P1_B_P.AnalogFilterDesign_A[ci] *
        TC_P1_B_X.AnalogFilterDesign_CSTATE[jc[ci]];
    }
  }

  for (is = 0; is < 10; is++) {
    ci = ir_0[is];
    while (ci < ir_0[is + 1]) {
      _rtXdot->AnalogFilterDesign_CSTATE[is] += TC_P1_B_P.AnalogFilterDesign_B *
        TC_P1_B_B.Add;
      ci = 1;
    }
  }

  /* End of Derivatives for StateSpace: '<Root>/Analog Filter Design' */

  /* Derivatives for StateSpace: '<Root>/Analog Filter Design1' */
  memset(&_rtXdot->AnalogFilterDesign1_CSTATE[0], 0, 20U * sizeof(real_T));
  for (is = 0; is < 20; is++) {
    for (ci = ir_1[is]; ci < ir_1[is + 1]; ci++) {
      _rtXdot->AnalogFilterDesign1_CSTATE[is] +=
        TC_P1_B_P.AnalogFilterDesign1_A[ci] *
        TC_P1_B_X.AnalogFilterDesign1_CSTATE[jc_0[ci]];
    }
  }

  for (is = 0; is < 20; is++) {
    ci = ir_2[is];
    while (ci < ir_2[is + 1]) {
      _rtXdot->AnalogFilterDesign1_CSTATE[is] += TC_P1_B_P.AnalogFilterDesign1_B
        * TC_P1_B_B.AnalogFilterDesign;
      ci = 1;
    }
  }

  /* End of Derivatives for StateSpace: '<Root>/Analog Filter Design1' */

  /* Derivatives for StateSpace: '<Root>/Analog Filter Design2' */
  memset(&_rtXdot->AnalogFilterDesign2_CSTATE[0], 0, 20U * sizeof(real_T));
  for (is = 0; is < 20; is++) {
    for (ci = ir_3[is]; ci < ir_3[is + 1]; ci++) {
      _rtXdot->AnalogFilterDesign2_CSTATE[is] +=
        TC_P1_B_P.AnalogFilterDesign2_A[ci] *
        TC_P1_B_X.AnalogFilterDesign2_CSTATE[jc_1[ci]];
    }
  }

  for (is = 0; is < 20; is++) {
    for (ci = ir_4[is]; ci < ir_4[is + 1]; ci++) {
      _rtXdot->AnalogFilterDesign2_CSTATE[is] +=
        TC_P1_B_P.AnalogFilterDesign2_B[ci] * TC_P1_B_B.AnalogFilterDesign;
    }
  }

  /* End of Derivatives for StateSpace: '<Root>/Analog Filter Design2' */
}

/* Model initialize function */
void TC_P1_B_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TC_P1_B_M, 0,
                sizeof(RT_MODEL_TC_P1_B_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TC_P1_B_M->solverInfo, &TC_P1_B_M->Timing.simTimeStep);
    rtsiSetTPtr(&TC_P1_B_M->solverInfo, &rtmGetTPtr(TC_P1_B_M));
    rtsiSetStepSizePtr(&TC_P1_B_M->solverInfo, &TC_P1_B_M->Timing.stepSize0);
    rtsiSetdXPtr(&TC_P1_B_M->solverInfo, &TC_P1_B_M->ModelData.derivs);
    rtsiSetContStatesPtr(&TC_P1_B_M->solverInfo, (real_T **)
                         &TC_P1_B_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&TC_P1_B_M->solverInfo,
      &TC_P1_B_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&TC_P1_B_M->solverInfo, (&rtmGetErrorStatus(TC_P1_B_M)));
    rtsiSetRTModelPtr(&TC_P1_B_M->solverInfo, TC_P1_B_M);
  }

  rtsiSetSimTimeStep(&TC_P1_B_M->solverInfo, MAJOR_TIME_STEP);
  TC_P1_B_M->ModelData.intgData.y = TC_P1_B_M->ModelData.odeY;
  TC_P1_B_M->ModelData.intgData.f[0] = TC_P1_B_M->ModelData.odeF[0];
  TC_P1_B_M->ModelData.intgData.f[1] = TC_P1_B_M->ModelData.odeF[1];
  TC_P1_B_M->ModelData.intgData.f[2] = TC_P1_B_M->ModelData.odeF[2];
  TC_P1_B_M->ModelData.contStates = ((X_TC_P1_B_T *) &TC_P1_B_X);
  rtsiSetSolverData(&TC_P1_B_M->solverInfo, (void *)
                    &TC_P1_B_M->ModelData.intgData);
  rtsiSetSolverName(&TC_P1_B_M->solverInfo,"ode3");
  rtmSetTPtr(TC_P1_B_M, &TC_P1_B_M->Timing.tArray[0]);
  rtmSetTFinal(TC_P1_B_M, 20.0);
  TC_P1_B_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    TC_P1_B_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(TC_P1_B_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(TC_P1_B_M->rtwLogInfo, (NULL));
    rtliSetLogT(TC_P1_B_M->rtwLogInfo, "tout");
    rtliSetLogX(TC_P1_B_M->rtwLogInfo, "");
    rtliSetLogXFinal(TC_P1_B_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(TC_P1_B_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(TC_P1_B_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(TC_P1_B_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(TC_P1_B_M->rtwLogInfo, 1);
    rtliSetLogY(TC_P1_B_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(TC_P1_B_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(TC_P1_B_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &TC_P1_B_B), 0,
                sizeof(B_TC_P1_B_T));

  /* states (continuous) */
  {
    (void) memset((void *)&TC_P1_B_X, 0,
                  sizeof(X_TC_P1_B_T));
  }

  /* states (dwork) */
  (void) memset((void *)&TC_P1_B_DW, 0,
                sizeof(DW_TC_P1_B_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(TC_P1_B_M->rtwLogInfo, 0.0, rtmGetTFinal
    (TC_P1_B_M), TC_P1_B_M->Timing.stepSize0, (&rtmGetErrorStatus(TC_P1_B_M)));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for RandomNumber: '<S1>/Random Number' */
    tmp = floor(TC_P1_B_P.GaussianNoiseGenerator_s);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    TC_P1_B_DW.RandSeed = tseed;
    TC_P1_B_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&TC_P1_B_DW.RandSeed) *
      TC_P1_B_P.RandomNumber_StdDev + TC_P1_B_P.RandomNumber_Mean;

    /* End of Start for RandomNumber: '<S1>/Random Number' */
  }

  {
    int_T is;

    /* InitializeConditions for StateSpace: '<Root>/Analog Filter Design' */
    for (is = 0; is < 10; is++) {
      TC_P1_B_X.AnalogFilterDesign_CSTATE[is] = TC_P1_B_P.AnalogFilterDesign_X0;
    }

    for (is = 0; is < 20; is++) {
      /* InitializeConditions for StateSpace: '<Root>/Analog Filter Design1' */
      TC_P1_B_X.AnalogFilterDesign1_CSTATE[is] =
        TC_P1_B_P.AnalogFilterDesign1_X0;

      /* InitializeConditions for StateSpace: '<Root>/Analog Filter Design2' */
      TC_P1_B_X.AnalogFilterDesign2_CSTATE[is] =
        TC_P1_B_P.AnalogFilterDesign2_X0;
    }

    /* End of InitializeConditions for StateSpace: '<Root>/Analog Filter Design' */
  }
}

/* Model terminate function */
void TC_P1_B_terminate(void)
{
  /* (no terminate code required) */
}
