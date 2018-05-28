#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	this->p_error = 0;
	this->i_error = 0;
	this->d_error = 0;
}

void PID::UpdateError(double cte) {

	double cte_pre = p_error;
	p_error = cte;
	i_error += cte;
	d_error = cte - cte_pre;
}

double PID::TotalError() {
	return -this->Kp * p_error - this->Ki * i_error - this->Kd * d_error;
}

