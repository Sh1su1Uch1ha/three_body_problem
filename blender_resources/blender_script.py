import bpy
import csv

output_file_path = "path_to_your_repo/three_body_data/euler_output.txt"  # Adjust the path accordingly

positions = []
with open(output_file_path, 'r') as file:
    reader = csv.reader(file, delimiter='\t')  # assuming tab-separated values
    next(reader)  # skip header
    for row in reader:
        positions.append([[float(row[1]), float(row[2]), float(row[3])],  # Body 1
                          [float(row[4]), float(row[5]), float(row[6])],  # Body 2
                          [float(row[7]), float(row[8]), float(row[9])]])  # Body 3

# Assuming three spheres named 'Body1', 'Body2', 'Body3'
bodies = [bpy.data.objects["Body1"], bpy.data.objects["Body2"], bpy.data.objects["Body3"]]

for frame_num, position in enumerate(positions, start=1):
    for i, body in enumerate(bodies):
        body.location = position[i]
        body.keyframe_insert(data_path="location", frame=frame_num)
