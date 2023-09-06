#include "three_body_euler.hpp"
#include <iostream>
#include <cmath>
using namespace std;



void eulerMethod() {
    double r[3][3], v[3][3], a[3][3];
    // first entry is which body, second is which dimension
    const double m = 1;
    double dt, t_final;
    const double pi = 2 * asin(1);

}


//sets the initial configuration and calculates the initial accelerations
void setInitialConditions(double (&r)[3][3], double (&v)[3][3]) { 
    
}

void eulerStep(double (&r)[3][3], double (&v)[3][3], const double (&a)[3][3], double dt) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            r[i][j] += v[i][j] * dt;
            v[i][j] += a[i][j] * dt;
        }
    }
}

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

void resetAccelerations(double (&a)[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = 0;
        }
    }
}

