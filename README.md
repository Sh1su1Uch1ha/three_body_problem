# Three-Body Problem Simulation and Visualization

This project aims to simulate the three-body problem using C++ for computation and Blender for visualization. The motions of three celestial bodies under the influence of mutual gravitational attraction are computed using numerical methods and then visualized in a 3D animation using Blender.

## Quick Start

1. Ensure you have the required dependencies installed:
   - C++ compiler (e.g., `g++`)
   - Python 3
   - Blender (with the ability to execute scripts)
   - Necessary Python libraries (e.g., `numpy`)

2. Navigate to the project directory and run the following command to generate a text file with the computed trajectories of the three bodies:

python3 -m python_wrappers.run_three_body_cpp


3. This command will prompt you for parameters like the timestep and the final time for the simulation. Once provided, the C++ code will generate the positions of the three bodies at each timestep and save them in a text file.

4. The Python script provided can be executed within Blender to visualize the motion of these bodies.

## Adjusting the Simulation

The project, in its current state, offers a base setup for the three-body problem. However, it is designed to be flexible and allow adjustments:

1. **Initial Conditions**: You can set different initial positions and velocities for the bodies by adjusting the `setInitialConditions` function in the C++ files. Comments in the code provide guidance on how to do this.

2. **Visualization**: The Blender script can be adjusted to change the appearance of the bodies, camera movements, background, and other visual elements. Comments within the script guide you through the customization process.

3. **Background & Stars**: To enhance the realism of the animation, the background can be set to a starry night. Additionally, the bodies can be made to look like stars or suns with light emissions.

4. **Camera Animation**: Comments in the Blender script guide you through adjusting the camera's motion, allowing you to showcase the 3D nature of the simulation.

## Note

This project is not exhaustive and may require tweaks depending on the desired outcome. The provided comments in the codebase are designed to assist in making these adjustments. Feedback and contributions are welcome!
