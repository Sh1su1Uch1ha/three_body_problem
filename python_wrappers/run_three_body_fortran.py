import subprocess
import numpy as np
import matplotlib.pyplot as plt
import os

# Step 1: Compile the Fortran code
fortran_file_path = "numerical_solvers_fortran/three_body_leapfrog.f"
executable_path = "numerical_solvers_fortran/three_body_leapfrog"
output_file_path = "numerical_solvers_fortran/leapfrog_output.txt"

subprocess.run(["gfortran", "-o", executable_path, fortran_file_path])

# Step 2: Input reasonable values and run the Fortran program
initial_values = [
    "0 0 0 1 0 0",  # Body 1
    "1 0 0 0 1 0",  # Body 2
    "0 1 0 0 0 1"   # Body 3
]

# Change the current working directory
os.chdir("numerical_solvers_fortran")

# Run the executable with inputs
process = subprocess.Popen(["./three_body_leapfrog"], stdin=subprocess.PIPE, text=True)
process.communicate(input='\n'.join(initial_values))

# Change back to the main directory
os.chdir("..")

# Step 3: Parse the output file
data = np.loadtxt(output_file_path)

# Extract positions for each body
timesteps, x1, y1, z1, x2, y2, z2, x3, y3, z3 = data.T

# Step 4: Plot the results
plt.figure(figsize=(10, 6))

plt.plot(x1, y1, label="Body 1", marker='o', markersize=2, linestyle='-')
plt.plot(x2, y2, label="Body 2", marker='o', markersize=2, linestyle='-')
plt.plot(x3, y3, label="Body 3", marker='o', markersize=2, linestyle='-')

plt.xlabel("X Position")
plt.ylabel("Y Position")
plt.title("Three Body Leapfrog Simulation")
plt.legend()
plt.grid(True)
plt.show()

