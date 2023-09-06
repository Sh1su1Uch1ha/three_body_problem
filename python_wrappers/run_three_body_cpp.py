import subprocess
import numpy as np
import matplotlib.pyplot as plt
import os

# Step 1: Compile the C++ code
cpp_files_path = "numerical_solvers_cpp/"
executable_path = "numerical_solvers_cpp/main_executable"
output_file_path = "three_body_data/euler_output.txt"
file_path = "three_body_data/euler_output.txt"

subprocess.run(["g++", "-o", executable_path, cpp_files_path + "main.cpp", cpp_files_path + "three_body_euler.cpp"])

# Step 2: Run the C++ program
initial_values = [
    "1", # Euler
    "0.01",  # dt
    "20"     # t_final
]

process = subprocess.Popen([executable_path, file_path], stdin=subprocess.PIPE, text=True)
process.communicate(input='\n'.join(initial_values))

# Step 3: Load the data from the output file
data = np.loadtxt(output_file_path, skiprows=1)

# Extract positions for each body
timesteps, x1, y1, z1, x2, y2, z2, x3, y3, z3 = data.T

# Step 4: Plot the results
plt.figure(figsize=(10, 6))

plt.plot(x1, y1, label="Body 1", marker='o', markersize=2, linestyle='-')
plt.plot(x2, y2, label="Body 2", marker='o', markersize=2, linestyle='-')
plt.plot(x3, y3, label="Body 3", marker='o', markersize=2, linestyle='-')

plt.xlabel("X Position")
plt.ylabel("Y Position")
plt.title("Three Body Euler Simulation in C++")
plt.legend()
plt.grid(True)
plt.show()
