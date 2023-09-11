#include "three_body_calculations.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <random> 

using namespace std;

//sets the initial conditions (locations) of the bodies

// void setInitialConditions(double (&r)[3][3], double (&v)[3][3], double (&a)[3][3], const double &pi, const double &m) { 
    
//     for (int i = 0; i < 3; i++) {
//         double phi = 2 * pi * i / 3;
//         r[i][0] = cos(phi);
//         r[i][1] = sin(phi);
//         r[i][2] = 0;
//     }
//     calculateAccelerations(r, a, m);
//     double v_mag = sqrt(-a[0][0]);
//     for (int i = 0; i < 3; i++) {
//         double phi = 2 * pi * i / 3;
//         v[i][0] = - v_mag * sin(phi);
//         v[i][1] = v_mag * cos(phi);
//         v[i][2] = 0;
//     }
// }

void setInitialConditions(double (&r)[3][3], double (&v)[3][3], double (&a)[3][3], const double &pi, const double &m) { 
    
    // Seed for the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < 3; i++) {
        double phi = 2 * pi * i / 3;
        r[i][0] = cos(phi);
        r[i][1] = sin(phi);
        r[i][2] = 0;
    }

    // Calculate the accelerations based on the positions
    calculateAccelerations(r, a, m);
    
    double v_mag = sqrt(-a[0][0]);

    // Set velocities with random multiples of v_mag in each dimension
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[i][j] = dis(gen) * v_mag;
        }
    }
}

//given the positions of the bodies, calculates the accelerations
void calculateAccelerations(const double (&r)[3][3], double (&a)[3][3], const double &m) {
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
                    if (r_ij_mag == 0) {
                        cout << "Zero magnitude encountered between body " << i << " and body " << j << endl;
                    }

                    a[i][k] -= m * r_ij[k] / (r_ij_mag * r_ij_mag * r_ij_mag);
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