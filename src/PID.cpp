#include "PID.h"
#include <limits>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    cte_prev = 0.0;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    d_error = cte - cte_prev;
    i_error += cte; // sum of errors
    cte_prev = cte;
}

double PID::TotalError() {
    return Kp * p_error + Ki * i_error + Kd * d_error;
}

