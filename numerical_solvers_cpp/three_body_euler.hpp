#pragma once


void eulerMethod(const char* filePath);

void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt);
