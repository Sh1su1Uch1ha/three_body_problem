#include "three_body_euler.hpp"
#include "three_body_calculations.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <random> 

using namespace std;

// implements entire euler method: 
// sets initial conditions, calculates accelerations,
// performs euler step, and writes to file
void eulerMethod(const char* filePath) {

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

    setInitialConditions(r, v, a, pi, m);


    // Opening the file for writing
    ofstream outFile(filePath);
    if (!outFile) {
        cerr << "Unable to open file for writing!" << endl;
        return;
    }
    // Write the headers for our data columns
    outFile << "Time\tX1\tY1\tZ1\t"
        << "X2\tY2\tZ2\t"
        << "X3\tY3\tZ3\n";

    for (double t = 0; t < t_final; t += dt) {
        eulerStep(r, v, a, dt);
        calculateAccelerations(r, a, m);

        // Write the current state to the file
        outFile << t << '\t';
        for (int i = 0; i < 3; i++) {
            outFile << r[i][0] << '\t' << r[i][1] << '\t' << r[i][2] << '\t';
        }
        outFile << '\n';  // End of the line for this timestep
    }

    // Close the file after writing
    outFile.close();
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

