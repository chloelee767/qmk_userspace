#!/usr/bin/env python3

import matplotlib.pyplot as plt
import json

keyboard_json = json.load(open("/Users/chloelee/Code/github/qmk_firmware/keyboards/keebio/iris_ce/rev1/keyboard.json"))

layout = keyboard_json["layouts"]["LAYOUT"]["layout"]
print(layout)

# layout should be something like this:
# layout = [
#     {"matrix": [0, 0], "x": 0, "y": 0.5},
#     {"matrix": [0, 1], "x": 1, "y": 0.375},
#     {"matrix": [0, 2], "x": 2, "y": 0.125},
#     ...
# ]

# Create the plot
fig, ax = plt.subplots()

for key in layout:
    x = key["x"]
    y = -key["y"] # Invert y-axis as the thumb keys are drawn at the top for some reason
    label = f'{key["matrix"]}'
    height = key.get("h", 1)
    width = 1  # Assume width of 1 for simplicity

    rect = plt.Rectangle((x, y), width, height, fill=True, edgecolor='black', facecolor='skyblue')
    ax.add_patch(rect)
    plt.text(x + width / 2, y + height / 2, label, ha='center', va='center')

# Set the limits and aspect ratio
ax.set_xlim(-1, 18)
ax.set_ylim(-6, 1)
ax.set_aspect('equal')

# Hide axes
ax.axis('off')

plt.show()
