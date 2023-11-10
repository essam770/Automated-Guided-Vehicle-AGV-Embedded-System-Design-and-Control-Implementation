# Automated-Guided-Vehicle-AGV-Embedded-System-Design-and-Control-Implementation
The system implemented for The AGV will be an Isolated 
System that will disregard all frictional effects, such as 
Aerodynamics effects, Internal Motor Friction, Wheel 
Friction, etc. on the AGV Dynamics. As stated earlier, The 
AGV loads and unloads certain packages into designated 
stations therefore, the loading and unloading process of The 
AGV in this project will be done using a robotic arm which 
will not be part of this project. Along with moving the 
packages the AGV will concurrently monitor its battery 
health and proceed to charge when requested by the FSM.
The AGV also monitors if a certain error occurs within it and 
notifies the FSM that an emergency occurred.
Using Simulink, The AGV’s system will use vision 
guidance. The inputs will be the movement calculated from 
the simulated FMS (Flexible Manufacturing System) and 
inserted into The AGV as follows (System input signals):
o Forward.
o Backward.
o Rotate clockwise.
o Rotate anti-clockwise.
o Wait for the package.
o Brake
o Dock.
o Id
The system states will therefore be defined as:
o On
➢ Battery Management(concurrent)
❖ Charging
❖ Discharging
➢ Active Task(concurrent)
❖ Motion
• Translation(concurrent)
o Forwards
o Backwards
o No translation
• Rotational(concurrent)
o Clockwise 
o Anticlockwise
o No rotation
❖ Waiting
❖ Going to Station
• Docking
• Docked
o Off
o Emergency
Whereas, The Translational and Rotational motions will be 
concurrent with each other. The AGV’s system will output:
o Position.
o Fault LED.
o Battery percentage
The continuous dynamics of the system will be modelled as 
the motion resulting from 2 electrical motors and will be 
controlled using raspberry pi. The raspberry pi we will be 
using is raspberry pi 4b 4 GB RAM.
