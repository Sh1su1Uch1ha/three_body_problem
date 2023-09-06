#pragma once


void eulerMethod();

void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt);

void setInitialConditions(double (&r)[3][3], double (&v)[3][3]);

void calculateAccelerations(double (&r)[3][3], double (&a)[3][3]);

void resetAccelerations(double (&a)[3][3]);