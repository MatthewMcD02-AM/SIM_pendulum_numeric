/************************************************************************
PURPOSE: (Print the final pendulum state.)
*************************************************************************/
#include <stdio.h>
#include "../include/pendulum.h"
#include "trick/exec_proto.h"
#include <math.h>

int pendulum_shutdown( PENDULUM* P) {
    double t = exec_get_sim_time();
    printf( "========================================\n");
    printf( "      Pendulum State at Shutdown     \n");
    printf( "t = %g\n", t);
    printf( "Angle (rad) = %.9f\n", P->theta);
    printf( "Angular vel (rad/s) = %.9f\n", P->omega);
    printf( "2D position (x, y): (%.9f, %.9f)\n", P->pos[0], P->pos[1]);
    printf( "========================================\n");
    return 0 ;
}