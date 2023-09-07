#pragma once


void eulerMethod(const char* filePath);

void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt);

void setInitialConditions(double (&r)[3][3], double (&v)[3][3], double (&a)[3][3], const double &pi, const double &m);

void calculateAccelerations(const double (&r)[3][3], double (&a)[3][3], const double &m);

void resetAccelerations(double (&a)[3][3]);