/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include "../include/pendulum.h"

/* default data job */
int pendulum_default_data( PENDULUM* P ) {

    P->omega0 = 0.0;
    P->theta0 = M_PI / 4.0;
    P->length0 = 2.5;

    P->alpha = 0.0;
    P->omega = P->omega0;
    P->theta = P->theta0;
    P->length = P->length0;

    P->time = 0.0;

    P->direction_swapped = 0;
    P->impactTime = 0.0;

    return 0;
}

/* initialization job */
int pendulum_init( PENDULUM* P) {

    // P->theta0 = fmod(P->theta0, 2.0 * M_PI);

    // P->omega0 = 0.0;
    // P->length0 = 2.5;

    P->omega = P->omega0;
    P->theta = P->theta0;
    P->length = P->length0;

    P->pos[0] = P->length * sin(P->theta);
    P->pos[1] = -P->length * cos(P->theta);

    P->impactTime = 0.0;
    P->direction_swapped = 0;

    return 0; 
}