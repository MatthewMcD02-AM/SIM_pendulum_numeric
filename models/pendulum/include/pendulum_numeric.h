/*************************************************************************
PURPOSE: ( Pendulum Numeric Model )
**************************************************************************/

#ifndef PENDULUM_NUMERIC_H
#define PENDULUM_NUMERIC_H

#include "pendulum.h"

#ifdef __cplusplus
extern "C" {
#endif
int pendulum_integ(PENDULUM*) ;
int pendulum_deriv(PENDULUM*) ;
double pendulum_direction_change(PENDULUM*) ;
#ifdef __cplusplus
}
#endif
#endif