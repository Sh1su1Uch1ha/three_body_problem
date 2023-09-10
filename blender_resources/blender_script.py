import bpy
import numpy as np

# Clear all existing mesh objects (optional)
bpy.ops.object.select_all(action='DESELECT')
bpy.ops.object.select_by_type(type='MESH')
bpy.ops.object.delete()

# Load data from the txt file
data = np.loadtxt('/Users/quinnmcintyre/GitHub/three_body_problem/three_body_data/euler_output.txt', skiprows=1)
timesteps, x1, y1, z1, x2, y2, z2, x3, y3, z3 = data.T

# Create or update bodies
body_names = ['Body1', 'Body2', 'Body3']
positions = [(x1, y1, z1), (x2, y2, z2), (x3, y3, z3)]

for idx, body_name in enumerate(body_names):
    # If the body already exists, use it; otherwise, create a new one
    body = bpy.data.objects.get(body_name)
    if not body:
        bpy.ops.mesh.primitive_uv_sphere_add(radius=0.05, location=(0, 0, 0))
        body = bpy.context.active_object
        body.name = body_name
    
    # Now, animate the body based on the data
    x, y, z = positions[idx]
    for frame_idx, (x_pos, y_pos, z_pos) in enumerate(zip(x, y, z)):
        body.location = (x_pos, y_pos, z_pos)
        body.keyframe_insert(data_path="location", frame=frame_idx)