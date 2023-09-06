#include "three_body_euler.hpp"
#include <iostream>
#include <cmath>
using namespace std;


void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt);

void setInitialConditions(double (&r)[3][3], double (&v)[3][3], const double &pi);

void calculateAccelerations(double (&r)[3][3], double (&a)[3][3]);

void resetAccelerations(double (&a)[3][3]);

// implements entire euler method: 
// sets initial conditions, calculates accelerations,
// performs euler step, and writes to file
void eulerMethod() {

    double r[3][3], v[3][3], a[3][3];
    // first entry is which body, second is which dimension
    const double m = 1;
    double dt, t_final;
    const double pi = 2 * asin(1);

    //takes the user input for the timestep and final time
    cout << "Enter timestep: ";
    cin >> dt;
    cout << "Enter final time: ";
    cin >> t_final;

    setInitialConditions(r, v, pi);

    for (double t = 0; t < t_final; t += dt) {
        calculateAccelerations(r, a);
        eulerStep(r, v, a, dt);
    }

}


//sets the initial conditions (locations) of the bodies
void setInitialConditions(double (&r)[3][3], double (&v)[3][3], double &pi) { 
    for (int i = 0; i < 3; i++) {
        double phi = 2 * pi * i / 3;
        r[i][0] = cos(phi);
        r[i][1] = sin(phi);
        r[i][2] = 0;
    }
}

// performs a single euler step
void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            r[i][j] += v[i][j] * dt;
            v[i][j] += a[i][j] * dt;
        }
    }
}

//given the positions of the bodies, calculates the accelerations
void calculateAccelerations(const double (&r)[3][3], double (&a)[3][3]) {
    resetAccelerations(a);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j){
                double r_ij[3];
                for(int k = 0; k < 3; k++){
                    r_ij[k] = r[i][k] - r[j][k];
                }
                double r_ij_mag = sqrt(r_ij[0] * r_ij[0] + r_ij[1] * r_ij[1] + r_ij[2] * r_ij[2]);
                for(int k = 0; k < 3; k++){
                    a[i][k] += -r_ij[k] / (r_ij_mag * r_ij_mag * r_ij_mag);
                }
            }
        }
    }
}

//resets the accelerations to zero
void resetAccelerations(double (&a)[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = 0;
        }
    }
}

