/*
 * TC_P1_B_data.c
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

/* Block parameters (auto storage) */
P_TC_P1_B_T TC_P1_B_P = {
  0.0,                                 /* Mask Parameter: GaussianNoiseGenerator_m
                                        * Referenced by: '<S1>/Constant'
                                        */
  41.0,                                /* Mask Parameter: GaussianNoiseGenerator_s
                                        * Referenced by: '<S1>/Random Number'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Random Number'
                                        */
  1.0,                                 /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S1>/Random Number'
                                        */
  1.4142135623730951,                  /* Expression: d
                                        * Referenced by: '<S1>/Matrix Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Buffer'
                                        */

  /*  Computed Parameter: AnalogFilterDesign_A
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { -1975.3766811902753, -1000.0, 999.99999999999977, 1000.0000000000002,
    -1782.0130483767355, -1000.0000000000002, 999.99999999999977,
    1000.0000000000002, -1414.2135623730949, -1000.0, 1000.0, 1000.0,
    -907.9809994790935, -1000.0, 1000.0, 1000.0, -312.86893008046161, -1000.0,
    1000.0 },
  1000.0,                              /* Computed Parameter: AnalogFilterDesign_B
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  0.99999999999999989,                 /* Computed Parameter: AnalogFilterDesign_C
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */

  /*  Computed Parameter: AnalogFilterDesign1_A
   * Referenced by: '<Root>/Analog Filter Design1'
   */
  { -19.753766811902754, -10.000000000000002, 199.93749023132204,
    9.9999999999999982, 199.93749023132204, 10.000000000000002,
    -17.820130483767358, -10.000000000000002, 199.93749023132204,
    9.9999999999999982, 199.93749023132204, 10.000000000000002,
    -14.142135623730949, -10.000000000000002, 199.93749023132204,
    10.000000000000002, 199.93749023132204, 10.000000000000002,
    -9.079809994790935, -10.000000000000002, 199.93749023132204,
    10.000000000000002, 199.93749023132204, 10.000000000000002,
    -3.1286893008046168, -10.000000000000002, 199.93749023132204,
    10.000000000000002, 199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204 },
  10.000000000000002,                  /* Computed Parameter: AnalogFilterDesign1_B
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  0.99999999999999989,                 /* Computed Parameter: AnalogFilterDesign1_C
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design1'
                                        */

  /*  Computed Parameter: AnalogFilterDesign2_A
   * Referenced by: '<Root>/Analog Filter Design2'
   */
  { 10.000000000000002, 1.1102230246251565E-15, -1.1102230246251565E-15,
    199.93749023132204, -10.0, -19.753766811902757, 2.2204460492503131E-15,
    199.93749023132204, 10.000000000000002, 199.93749023132204, -10.0,
    -19.753766811902757, -9.9999999999999982, -17.820130483767358,
    2.2204460492503131E-15, 199.93749023132204, 10.0, 199.93749023132204,
    -10.000000000000002, -19.753766811902761, -10.0, -17.820130483767361, -10.0,
    -14.142135623730949, 199.93749023132204, 10.0, 199.93749023132204,
    -10.000000000000002, -19.753766811902761, -10.0, -17.820130483767361, -10.0,
    -14.142135623730949, -10.0, -9.079809994790935, 199.93749023132204, 10.0,
    199.93749023132204, -10.000000000000002, -19.753766811902761, -10.0,
    -17.820130483767361, -10.0, -14.142135623730949, -10.0, -9.079809994790935,
    -10.0, -3.1286893008046164, 199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204,
    -199.93749023132204, -199.93749023132204, -199.93749023132204 },

  /*  Computed Parameter: AnalogFilterDesign2_B
   * Referenced by: '<Root>/Analog Filter Design2'
   */
  { 10.0, 10.0, 10.000000000000002, 10.000000000000002, 10.000000000000002 },

  /*  Computed Parameter: AnalogFilterDesign2_C
   * Referenced by: '<Root>/Analog Filter Design2'
   */
  { -1.0, -1.9753766811902758, -0.99999999999999989, -1.7820130483767358,
    -0.99999999999999989, -1.4142135623730947, -0.99999999999999989,
    -0.90798099947909339, -0.99999999999999989, -0.31286893008046157 },
  1.0,                                 /* Computed Parameter: AnalogFilterDesign2_D
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design2'
                                        */
};
