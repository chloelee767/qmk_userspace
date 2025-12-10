#!/usr/bin/env python3

# Draw a keyboard layout showing the matrix positions and number of each key

import json
import sys

keyboard_json = json.load(open("/Users/chloelee/Code/qmk_firmware/keyboards/keebio/iris_ce/rev1/keyboard.json"))

layout = keyboard_json["layouts"]["LAYOUT"]["layout"]
print(layout)

# layout should be something like this:
# layout = [
#     {"matrix": [0, 0], "x": 0, "y": 0.5},
#     {"matrix": [0, 1], "x": 1, "y": 0.375},
#     {"matrix": [0, 2], "x": 2, "y": 0.125},
#     ...
# ]

def draw_with_matplotlib(layout):
    import matplotlib.pyplot as plt
    # Create the plot
    fig, ax = plt.subplots()

    for idx, key in enumerate(layout):
        x = key["x"]
        y = -key["y"] # Invert y-axis as the thumb keys are drawn at the top for some reason
        label = f'{key["matrix"]}\n{idx}'
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

def draw_ascii(layout):
    # Find the bounds of the layout
    max_x = max(key["x"] + 1 for key in layout)
    max_y = max(key["y"] + key.get("h", 1) for key in layout)

    # Create a grid with enough resolution
    # Each key unit is represented by a certain number of characters
    chars_per_unit_x = 8
    chars_per_unit_y = 3

    grid_width = int(max_x * chars_per_unit_x) + 1
    grid_height = int(max_y * chars_per_unit_y) + 1

    # Initialize grid with spaces
    grid = [[' ' for _ in range(grid_width)] for _ in range(grid_height)]

    def draw_box(grid, x, y, width, height, label):
        """Draw a box with a label in the grid"""
        x1 = int(x * chars_per_unit_x)
        y1 = int(y * chars_per_unit_y)
        x2 = int((x + width) * chars_per_unit_x)
        y2 = int((y + height) * chars_per_unit_y)

        # Draw top border
        grid[y1][x1] = '┌'
        for i in range(x1 + 1, x2):
            grid[y1][i] = '─'
        grid[y1][x2] = '┐'

        # Draw bottom border
        grid[y2][x1] = '└'
        for i in range(x1 + 1, x2):
            grid[y2][i] = '─'
        grid[y2][x2] = '┘'

        # Draw side borders
        for i in range(y1 + 1, y2):
            grid[i][x1] = '│'
            grid[i][x2] = '│'

        # Add label in the center
        label_lines = label.split('\n')
        center_y = (y1 + y2) // 2 - len(label_lines) // 2 + 1
        for idx, line in enumerate(label_lines):
            center_x = (x1 + x2) // 2 - len(line) // 2
            if center_y + idx < len(grid) and center_y + idx >= 0:
                for char_idx, char in enumerate(line):
                    if center_x + char_idx < len(grid[0]) and center_x + char_idx >= 0:
                        grid[center_y + idx][center_x + char_idx] = char

    # Draw each key
    for idx, key in enumerate(layout):
        x = key["x"]
        y = key["y"]
        height = key.get("h", 1)
        width = 1

        matrix_str = f"[{key['matrix'][0]},{key['matrix'][1]}]"
        label = f"{matrix_str}\n{idx}"

        draw_box(grid, x, y, width, height, label)

    # Print the grid
    for row in grid:
        print(''.join(row))

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("Usage: visualize_matrix.py [matplotlib|ascii]")
        sys.exit(1)
    mode = sys.argv[1]
    if mode == "matplotlib":
        draw_with_matplotlib(layout)
    elif mode == "ascii":
        draw_ascii(layout)
    else:
        print(f"Unknown mode {mode}. Use 'matplotlib' or 'ascii'.")
        sys.exit(1)
