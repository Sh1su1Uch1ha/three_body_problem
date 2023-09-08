#include <iostream>
#include "three_body_euler.hpp" 
#include "three_body_leapfrog.hpp" 

using namespace std;

int main(int argc, char* argv[]) {
    int choice;

    if (argc < 2) {
        cerr << "Please provide a file path as an argument." << endl;
        return 1;
    }

    const char* filePath = argv[1];

    cout << "Choose a numerical method for the three-body simulation:" << endl;
    cout << "1. Euler Method" << endl;
    cout << "2. Leapfrog Method" << endl;
    cout << "Enter your choice (number): ";
    cin >> choice;

    switch(choice) {
        case 1:
            eulerMethod(filePath);
            break;
        case 2:
            leapfrogMethod(filePath);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
    return 0;
}
