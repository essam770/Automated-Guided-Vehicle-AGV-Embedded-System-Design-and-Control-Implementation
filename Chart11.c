/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart11.c
 *
 * Code generated for Simulink model 'Chart11'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Dec 25 19:14:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Chart11.h"
#include "rtwtypes.h"
#include <math.h>
#include "Chart11_private.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define Chart11_IN_Anti_CLCKWISE       ((uint8_T)1U)
#define Chart11_IN_Backward            ((uint8_T)1U)
#define Chart11_IN_CLCK_WISE           ((uint8_T)2U)
#define Chart11_IN_Charging            ((uint8_T)1U)
#define Chart11_IN_Charging_station    ((uint8_T)1U)
#define Chart11_IN_Discharging         ((uint8_T)2U)
#define Chart11_IN_Docked              ((uint8_T)1U)
#define Chart11_IN_Docking             ((uint8_T)2U)
#define Chart11_IN_Emergency           ((uint8_T)1U)
#define Chart11_IN_Forward             ((uint8_T)2U)
#define Chart11_IN_Motion              ((uint8_T)2U)
#define Chart11_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define Chart11_IN_OFF                 ((uint8_T)2U)
#define Chart11_IN_ON                  ((uint8_T)3U)
#define Chart11_IN_Waiting             ((uint8_T)3U)
#define Chart11_IN_none                ((uint8_T)3U)

/* Forward declaration for local functions */
static void Chart11_exit_internal_ON(DW_Chart11_f_T *localDW);
static void Chart11_ON(const real_T *rtu_Emergency, const real_T *rtu_off, const
  real_T *rtu_waitPA, const real_T *rtu_forwardt, const real_T *rtu_Backwardt,
  const real_T *rtu_Brake, const real_T *rtu_ACW, const real_T *rtu_CW, const
  real_T *rtu_Dockingfinish, real_T *rty_FaultLED, real_T *rty_Batteryp, real_T *
  rty_thetadota, real_T *rty_thetadotb, real_T *rty_X, real_T *rty_Y, real_T
  *rty_Rotation, DW_Chart11_f_T *localDW);
static void Chart11_enter_internal_ON(real_T *rty_thetadota, real_T
  *rty_thetadotb, DW_Chart11_f_T *localDW);

/* Function for Chart: '<Root>/Chart1' */
static void Chart11_exit_internal_ON(DW_Chart11_f_T *localDW)
{
  localDW->is_Battery_management = Chart11_IN_NO_ACTIVE_CHILD;
  switch (localDW->is_Active_task) {
   case Chart11_IN_Charging_station:
    switch (localDW->is_Charging_station) {
     case Chart11_IN_Docked:
      localDW->d = 0.0;
      localDW->is_Charging_station = Chart11_IN_NO_ACTIVE_CHILD;
      break;

     case Chart11_IN_Docking:
      localDW->d = 1.0;
      localDW->is_Charging_station = Chart11_IN_NO_ACTIVE_CHILD;
      break;
    }

    localDW->is_Active_task = Chart11_IN_NO_ACTIVE_CHILD;
    break;

   case Chart11_IN_Motion:
    localDW->is_Rotational = Chart11_IN_NO_ACTIVE_CHILD;
    localDW->r = 0.0;
    localDW->is_Translational = Chart11_IN_NO_ACTIVE_CHILD;
    localDW->t = 0.0;
    localDW->is_Active_task = Chart11_IN_NO_ACTIVE_CHILD;
    break;

   case Chart11_IN_Waiting:
    localDW->g = 0.0;
    localDW->is_Active_task = Chart11_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Chart11_ON(const real_T *rtu_Emergency, const real_T *rtu_off, const
  real_T *rtu_waitPA, const real_T *rtu_forwardt, const real_T *rtu_Backwardt,
  const real_T *rtu_Brake, const real_T *rtu_ACW, const real_T *rtu_CW, const
  real_T *rtu_Dockingfinish, real_T *rty_FaultLED, real_T *rty_Batteryp, real_T *
  rty_thetadota, real_T *rty_thetadotb, real_T *rty_X, real_T *rty_Y, real_T
  *rty_Rotation, DW_Chart11_f_T *localDW)
{
  real_T Vb;
  real_T Vt;
  real_T thetadoubledota;

  /* Chart: '<Root>/Chart1' */
  if (*rtu_off == 1.0) {
    Chart11_exit_internal_ON(localDW);
    localDW->is_c1_Chart11 = Chart11_IN_OFF;
    localDW->r = 0.0;
    localDW->t = 0.0;
    *rty_thetadota = 0.0;
    *rty_thetadotb = 0.0;
  } else if (*rtu_Emergency == 1.0) {
    Chart11_exit_internal_ON(localDW);
    localDW->is_c1_Chart11 = Chart11_IN_Emergency;
    *rty_FaultLED = 1.0;
    localDW->r = 0.0;
    localDW->t = 0.0;
    *rty_thetadota = 0.0;
    *rty_thetadotb = 0.0;
  } else {
    switch (localDW->is_Active_task) {
     case Chart11_IN_Charging_station:
      if (*rty_Batteryp == 100.0) {
        switch (localDW->is_Charging_station) {
         case Chart11_IN_Docked:
          localDW->d = 0.0;
          localDW->is_Charging_station = Chart11_IN_NO_ACTIVE_CHILD;
          break;

         case Chart11_IN_Docking:
          localDW->d = 1.0;
          localDW->is_Charging_station = Chart11_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Active_task = Chart11_IN_Motion;
        localDW->is_Translational = Chart11_IN_none;
        localDW->t = 0.0;
        localDW->is_Rotational = Chart11_IN_none;
        localDW->r = 0.0;
      } else {
        switch (localDW->is_Charging_station) {
         case Chart11_IN_Docked:
          break;

         default:
          /* case IN_Docking: */
          if (*rtu_Dockingfinish == 1.0) {
            localDW->d = 1.0;
            localDW->is_Charging_station = Chart11_IN_Docked;
          }
          break;
        }
      }
      break;

     case Chart11_IN_Motion:
      if (*rtu_waitPA == 1.0) {
        localDW->is_Rotational = Chart11_IN_NO_ACTIVE_CHILD;
        localDW->is_Translational = Chart11_IN_NO_ACTIVE_CHILD;
        localDW->is_Active_task = Chart11_IN_Waiting;
        localDW->r = 0.0;
        localDW->t = 0.0;
      } else if (*rty_Batteryp <= 30.0) {
        localDW->is_Rotational = Chart11_IN_NO_ACTIVE_CHILD;
        localDW->r = 0.0;
        localDW->is_Translational = Chart11_IN_NO_ACTIVE_CHILD;
        localDW->t = 0.0;
        localDW->is_Active_task = Chart11_IN_Charging_station;
        localDW->is_Charging_station = Chart11_IN_Docking;
      } else {
        switch (localDW->is_Translational) {
         case Chart11_IN_Backward:
          if (*rtu_forwardt == 1.0) {
            localDW->is_Translational = Chart11_IN_Forward;
            localDW->t = 1.0;
          } else if (*rtu_Brake == 1.0) {
            localDW->is_Translational = Chart11_IN_none;
            localDW->t = 0.0;
          }
          break;

         case Chart11_IN_Forward:
          if (*rtu_Brake == 1.0) {
            localDW->is_Translational = Chart11_IN_none;
            localDW->t = 0.0;
          } else if (*rtu_Backwardt == 1.0) {
            localDW->is_Translational = Chart11_IN_Backward;
            localDW->t = -1.0;
          }
          break;

         default:
          /* case IN_none: */
          if (*rtu_Backwardt == 1.0) {
            localDW->is_Translational = Chart11_IN_Backward;
            localDW->t = -1.0;
          } else if (*rtu_forwardt == 1.0) {
            localDW->is_Translational = Chart11_IN_Forward;
            localDW->t = 1.0;
          } else if (*rtu_Brake == 1.0) {
            localDW->is_Translational = Chart11_IN_none;
            localDW->t = 0.0;
          }
          break;
        }

        switch (localDW->is_Rotational) {
         case Chart11_IN_Anti_CLCKWISE:
          if (*rtu_Brake == 1.0) {
            localDW->is_Rotational = Chart11_IN_none;
            localDW->r = 0.0;
          } else if (*rtu_CW == 1.0) {
            localDW->is_Rotational = Chart11_IN_CLCK_WISE;
            localDW->r = -1.0;
          }
          break;

         case Chart11_IN_CLCK_WISE:
          if (*rtu_ACW == 1.0) {
            localDW->is_Rotational = Chart11_IN_Anti_CLCKWISE;
            localDW->r = 1.0;
          } else if (*rtu_Brake == 1.0) {
            localDW->is_Rotational = Chart11_IN_none;
            localDW->r = 0.0;
          }
          break;

         default:
          /* case IN_none: */
          if (*rtu_ACW == 1.0) {
            localDW->is_Rotational = Chart11_IN_Anti_CLCKWISE;
            localDW->r = 1.0;
          } else if (*rtu_CW == 1.0) {
            localDW->is_Rotational = Chart11_IN_CLCK_WISE;
            localDW->r = -1.0;
          } else if (*rtu_Brake == 1.0) {
            localDW->is_Rotational = Chart11_IN_none;
            localDW->r = 0.0;
          }
          break;
        }
      }
      break;

     default:
      /* case IN_Waiting: */
      if ((localDW->g == 1.0) && (*rtu_waitPA == 0.0)) {
        localDW->g = 0.0;
        localDW->is_Active_task = Chart11_IN_Motion;
        localDW->is_Translational = Chart11_IN_none;
        localDW->t = 0.0;
        localDW->is_Rotational = Chart11_IN_none;
        localDW->r = 0.0;
      } else if ((*rtu_forwardt != 0.0) || (*rtu_Backwardt != 0.0) || (*rtu_CW
                  != 0.0) || (*rtu_ACW == 1.0)) {
        localDW->g = 1.0;
      }
      break;
    }

    if (localDW->is_Battery_management == Chart11_IN_Charging) {
      if (localDW->d == 0.0) {
        localDW->is_Battery_management = Chart11_IN_Discharging;
      } else {
        localDW->SOC += localDW->I * localDW->Ts;
        if (localDW->SOC >= 100000.0) {
          localDW->SOC = 100000.0;
        }

        *rty_Batteryp = localDW->SOC / 100000.0 * 100.0;
      }

      /* case IN_Discharging: */
    } else if (localDW->d == 1.0) {
      localDW->is_Battery_management = Chart11_IN_Charging;
    } else {
      localDW->SOC -= fabs(localDW->Id) * localDW->Ts;
      if (localDW->SOC >= 100000.0) {
        localDW->SOC = 100000.0;
      }

      *rty_Batteryp = localDW->SOC / 100000.0 * 100.0;
    }

    localDW->Va_Desired = (0.2 * localDW->r + localDW->t) * 5.0;
    localDW->Vb_Desired = (localDW->t - 0.2 * localDW->r) * 5.0;
    thetadoubledota = (localDW->Kt * localDW->ia - localDW->b * *rty_thetadota) *
      (1.0 / localDW->J);
    localDW->ia += ((-localDW->R * localDW->ia + localDW->input_MotorA) -
                    localDW->Ke * *rty_thetadota) * (1.0 / localDW->L) *
      localDW->Ts;
    *rty_thetadota += thetadoubledota * localDW->Ts;
    thetadoubledota = (localDW->Kt * localDW->ib - localDW->b * *rty_thetadotb) *
      (1.0 / localDW->J);
    localDW->ib += ((-localDW->ib + localDW->input_MotorB) - localDW->Ke *
                    *rty_thetadotb) * (1.0 / localDW->L) * localDW->Ts;
    *rty_thetadotb += thetadoubledota * localDW->Ts;
    localDW->Id = localDW->ia + localDW->ib;
    thetadoubledota = *rty_thetadota * localDW->wheelradius;
    Vb = *rty_thetadotb * localDW->wheelradius;
    Vt = (thetadoubledota + Vb) / 2.0;
    *rty_Rotation += (thetadoubledota - Vb) / localDW->radius * localDW->Ts;
    *rty_X += Vt * cos(*rty_Rotation) * localDW->Ts;
    *rty_Y += Vt * sin(*rty_Rotation) * localDW->Ts;
    thetadoubledota = localDW->Error_MotorA;
    localDW->Error_MotorA = localDW->Va_Desired / localDW->wheelradius -
      *rty_thetadota;
    localDW->inte_MotorA += localDW->Error_MotorA * localDW->Ts;
    localDW->input_MotorA = (localDW->Error_MotorA - thetadoubledota) /
      localDW->Ts * 0.01 + (40.0 * localDW->Error_MotorA + 100.0 *
      localDW->inte_MotorA);
    thetadoubledota = localDW->Error_MotorB;
    localDW->Error_MotorB = localDW->Vb_Desired / localDW->wheelradius -
      *rty_thetadotb;
    localDW->inte_MotorB += localDW->Error_MotorB * localDW->Ts;
    localDW->input_MotorB = (localDW->Error_MotorB - thetadoubledota) /
      localDW->Ts * 0.01 + (40.0 * localDW->Error_MotorB + 100.0 *
      localDW->inte_MotorB);
  }

  /* End of Chart: '<Root>/Chart1' */
}

/* Function for Chart: '<Root>/Chart1' */
static void Chart11_enter_internal_ON(real_T *rty_thetadota, real_T
  *rty_thetadotb, DW_Chart11_f_T *localDW)
{
  real_T Error_old_MotorA;
  localDW->is_Active_task = Chart11_IN_Motion;
  localDW->is_Translational = Chart11_IN_none;
  localDW->t = 0.0;
  localDW->is_Rotational = Chart11_IN_none;
  localDW->r = 0.0;
  localDW->is_Battery_management = Chart11_IN_Discharging;
  localDW->J = 0.01;
  localDW->b = 0.1;
  localDW->Ke = 0.01;
  localDW->Kt = 0.01;
  localDW->R = 1.0;
  localDW->L = 0.5;
  localDW->Ts = 0.01;
  localDW->radius = 1.0;
  localDW->wheelradius = 0.1;
  Error_old_MotorA = localDW->Error_MotorA;

  /* Chart: '<Root>/Chart1' */
  localDW->Error_MotorA = localDW->Va_Desired / 0.1 - *rty_thetadota;
  localDW->inte_MotorA += localDW->Error_MotorA * 0.01;
  localDW->input_MotorA = (localDW->Error_MotorA - Error_old_MotorA) / 0.01 *
    0.01 + (40.0 * localDW->Error_MotorA + 100.0 * localDW->inte_MotorA);
  Error_old_MotorA = localDW->Error_MotorB;

  /* Chart: '<Root>/Chart1' */
  localDW->Error_MotorB = localDW->Vb_Desired / 0.1 - *rty_thetadotb;
  localDW->inte_MotorB += localDW->Error_MotorB * 0.01;
  localDW->input_MotorB = (localDW->Error_MotorB - Error_old_MotorA) / 0.01 *
    0.01 + (40.0 * localDW->Error_MotorB + 100.0 * localDW->inte_MotorB);
}

/* System initialize for referenced model: 'Chart11' */
void Chart11_Init(real_T *rty_Batteryp, DW_Chart11_f_T *localDW)
{
  /* SystemInitialize for Chart: '<Root>/Chart1' */
  localDW->I = 100.0;
  localDW->SOC = 100000.0;
  *rty_Batteryp = 100.0;
}

/* Output and update for referenced model: 'Chart11' */
void Chart11(const real_T *rtu_Emergency, const real_T *rtu_start, const real_T *
             rtu_off, const real_T *rtu_waitPA, const real_T *rtu_forwardt,
             const real_T *rtu_Backwardt, const real_T *rtu_Brake, const real_T *
             rtu_ACW, const real_T *rtu_CW, const real_T *rtu_Dockingfinish,
             real_T *rty_FaultLED, real_T *rty_Batteryp, real_T *rty_thetadota,
             real_T *rty_thetadotb, real_T *rty_X, real_T *rty_Y, real_T
             *rty_Rotation, DW_Chart11_f_T *localDW)
{
  boolean_T out;

  /* Chart: '<Root>/Chart1' */
  if (localDW->is_active_c1_Chart11 == 0U) {
    localDW->is_active_c1_Chart11 = 1U;
    localDW->is_c1_Chart11 = Chart11_IN_OFF;
    localDW->r = 0.0;
    localDW->t = 0.0;
    *rty_thetadota = 0.0;
    *rty_thetadotb = 0.0;
  } else {
    switch (localDW->is_c1_Chart11) {
     case Chart11_IN_Emergency:
      out = ((*rtu_start == 1.0) && (*rtu_Emergency == 0.0));
      if (out) {
        *rty_FaultLED = 0.0;
        localDW->is_c1_Chart11 = Chart11_IN_ON;
        Chart11_enter_internal_ON(rty_thetadota, rty_thetadotb, localDW);
      }
      break;

     case Chart11_IN_OFF:
      if (*rtu_start == 1.0) {
        localDW->is_c1_Chart11 = Chart11_IN_ON;
        Chart11_enter_internal_ON(rty_thetadota, rty_thetadotb, localDW);
      }
      break;

     default:
      /* case IN_ON: */
      Chart11_ON(rtu_Emergency, rtu_off, rtu_waitPA, rtu_forwardt, rtu_Backwardt,
                 rtu_Brake, rtu_ACW, rtu_CW, rtu_Dockingfinish, rty_FaultLED,
                 rty_Batteryp, rty_thetadota, rty_thetadotb, rty_X, rty_Y,
                 rty_Rotation, localDW);
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */
}

/* Model initialize function */
void Chart11_initialize(const char_T **rt_errorStatus, RT_MODEL_Chart11_T *const
  Chart11_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Chart11_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
