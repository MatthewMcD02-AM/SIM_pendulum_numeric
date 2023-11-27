/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a pendulum)
**************************************************************************/
#ifndef PENDULUM_H
#define PENDULUM_H

#include "trick/regula_falsi.h"

typedef struct {

    double omega0 ;     /* *i rad/s Init angular velocity of pendulum*/
    double theta0 ;     /* *i rad Init angle of pendulum */
    double length0 ;    /* *i m Init length of pendulum */

    double alpha ;      /* rad/s2 angular acceleration */
    double omega ;      /* rad/s angular acceleration */
    double theta ;      /* rad angle in radians */
    double length ;     /* m Length*/

    double pos[2] ;     /* m xy-position */

    double time;        /* s Model time */

    int direction_swapped ;     /* -- Has impact occured? */
    double impactTime;  /* s Time of Impact */
    double times[2];    /* s Times to calculate period*/

    REGULA_FALSI rf ;

} PENDULUM ;

#ifdef __cplusplus
extern "C" {
#endif
    int pendulum_default_data(PENDULUM*) ;
    int pendulum_init(PENDULUM*) ;
    int pendulum_shutdown(PENDULUM*) ;
#ifdef __cplusplus
}
#endif

#endif