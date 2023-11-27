/*********************************************************************
  PURPOSE: ( Trick numeric for pendulum )
*********************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "trick/integrator_c_intf.h"
#include "../include/pendulum_numeric.h"

int pendulum_deriv(PENDULUM* P) {
        P->alpha = -9.81 / P->length * sin(P->theta) ;
        P->pos[0] = P->length * sin(P->theta);
        P->pos[1] = -P->length * cos(P->theta);
    return 0;
}

int pendulum_integ(PENDULUM* P) {
    int ipass;

    load_state(
        &P->theta,
        &P->omega,
        &P->pos[0],
        &P->pos[1],
        NULL);

    load_deriv(
        &P->omega,
        &P->alpha,
        NULL);

    ipass = integrate();

    unload_state(
        &P->theta,
        &P->omega,
        &P->pos[0],
        &P->pos[1],
        NULL );

    return(ipass);
}

double pendulum_direction_change( PENDULUM* P ) {
    double tgo ; /* time-to-go */
    double now ; /* current integration time. */
    double time_diff ; /* half of a period*/
    
    P->rf.error = P->omega ;              /* Specify the event boundary. */
    now = get_integ_time() ;               /* Get the current integration time */
    tgo = regula_falsi( now, &(P->rf) ) ;  /* Estimate remaining integration time. */ 
    if (tgo == 0.0) {                      /* If we are at the event, it's action time! */
        now = get_integ_time() ;
        reset_regula_falsi( now, &(P->rf) ) ; 
        P->direction_swapped += 1 ;
        P->times[P->direction_swapped % 2] = now ;

        if ( P->direction_swapped >= 2 & P->omega0 == 0.0 ) {
            time_diff = fabs(P->times[1] - P->times[0]) ;

            fprintf(stderr, "\nTime Period = %.9f\n", time_diff * 2 ) ;
        } else if ( P->direction_swapped >= 3 ) {
            time_diff = fabs(P->times[1] - P->times[0]) ;

            fprintf(stderr, "\nTime Period = %.9f\n", time_diff * 2 ) ;
        }
    }
    return (tgo) ;
}