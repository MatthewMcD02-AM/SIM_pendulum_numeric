# Pendulum Simulation
The simulation is of a simple pendulum. It uses the initial angle with respect to the vertical axis, the initial angular velocity, as well as the length of the pendulum. This simulation also uses that information to calculate the x and y position of the pendulum bob on the 2D plane.

Additionally, I used regula_falsi to determine whenever the bob's angular velocity changes direction. After the first two changes are stored, the time period of the pendulum is calculated by doubling the time difference between these stored values.

The assumptions made are that there is no friction or air resistance. One major limitation is that the force of gravity is constant and does not change with respect to the distance from the Earth.

Below is the result of a 7.5 real-time simulation. The length of the pendulum is 2.5 meters, starting at rest, and an angle of 45 degrees with respect to the y-axis. As shown in the plots below, the time period of the pendulum is approximately 3.3 seconds.

<div align="center">
    <img src=DP_Product/Plot_Images/Pendulum_Path.png width=500 />
    <p>
    The above shows the path of the simulation centered on the origin (0m, 0m)
    </p>
    <img src=DP_Product/Plot_Images/XPosition_v_Time.png width=500 />
    <img src=DP_Product/Plot_Images/YPosition_v_Time.png width=500 />
    <p>
    The above plots show the X and Y Positions as a function of time
    </p>
    <img src=DP_Product/Plot_Images/Theta_v_Time.png width=500 />
    <img src=DP_Product/Plot_Images/Omega_v_Time.png width=500 />
    <p>
    The above plots show the angle data as a function of time
    </p>
</div>
