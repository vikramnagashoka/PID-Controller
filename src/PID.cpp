#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/


PID::PID() {
    p_error = 0.0;
    d_error = 0.0;
    i_error = 0.0;

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    sum = 0;


}

void PID::UpdateError(double cte, double delta) {
    d_error = (cte - p_error) / delta;
    p_error = cte;
    sum = sum + (cte*delta) ;
    i_error = sum;


}

double PID::TotalError(double speed) {
    return - Kp * p_error - Ki * i_error - Kd * d_error;
}

