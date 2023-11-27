# Pendulum Simulation
The simulation is of a simple pendulum. It uses the initial angle with respect to the vertical axis, the initial angular velocity, as well as the length of the pendulum. This simulation also uses that information to calculate the x and y position of the pendulum bob on the 2D plane.

Additionally, I used regula_falsi to determine whenever the bob's angular velocity changes direction. After the first two changes are stored, the time period of the pendulum is calculated by doubling the time difference between these stored values.

The assumptions made are that there is no friction or air resistance. One major limitation is that the force of gravity is constant and does not change with respect to the distance from the Earth. 