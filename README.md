# PID-Controller
Predicting steering using PID controller


A PID (Proportional, Integral, Derivative) controller is a control loop feedback controller which is widely used in different control systems.

The cross track error obtained from the simulator can be calculated as below:
cte = current_position - reference_trajectory

Using only the (P) component or the proportional component of the PID controller, output is proportional to the cte. It takes into account only the present value of cte. But since it only considers present value it overshoots after certain point of time.

Integral term (I) which is the sum of all cte over the entire time is used to reduce systematic bias. But one other thing here i tried is using the sum computed only over the last 10 frames and not complete past time. This seems to work little better partly and not for all regions of the track. It works better certain times because i feel certain errors that may have occurred earlier wouldn't affect the current computation and thus provides better results. Also for certain regions it does not work better and the reason i think is the complete integral over time does help the system in future predictions or measurements by tuning the error terms. 

With differential (D) part, the controller output is proportional to the rate of change of cte . The parameter is used to reduce overshooting caused by the P component.

## Tuning

Initially twiddle was used to compute the values but then I did not obtain values that worked perfectly without too many wobbles. So I had to tune it manually after certain point of time. Currently it doesn't drive perfectly smooth but lot better than just the values obtained using twiddle. 


