# Escape-the-Labyrinth
CS 211 Class Project

Author
Jai Batra

Project Title
Escape the Labyrinth

Project Goal
The goal of this project is to implement and explore pointer-based mazes in C++, mastering dynamic memory management, linked structures, and debugging with gdb. Tasks include creating a templated Grid<T> class, validating escape paths, and solving custom labyrinths.

Implementation Instructions
Step 1: Build the Grid<T> Class
Create a templated Grid<T> class to represent a dynamic 2D grid.
Manage memory using heap-allocated arrays of pointers.
Overload the parentheses operator for accessing grid elements.
Step 2: Implement isPathToFreedom()
Write a function in EscapeTheLabyrinth.h to validate a path through a labyrinth.
Ensure the path collects all required items (Spellbook, Potion, Wand) and follows valid maze directions.
Step 3: Explore and Solve the Regular Labyrinth
Use gdb to navigate a maze represented by MazeCell structures.
Map out the maze, identify items, and construct an escape path.
Save the escape path in EscapeTheLabyrinth.h as kPathOutOfRegularMaze.
Step 4: Explore and Solve the Twisty Labyrinth
Repeat the process for a more complex maze without geometric constraints.
Use memory addresses to navigate and map the twisty labyrinth.
Save the escape path in EscapeTheLabyrinth.h as kPathOutOfTwistyMaze.
Submission
diagram_regular_[netID].pdf: Map of the regular maze.
diagram_twisty_[netID].pdf: Map of the twisty maze.
gdblog_regular_[netID].txt: Debug log for the regular maze.
gdblog_twisty_[netID].txt: Debug log for the twisty maze.
Update escape paths in EscapeTheLabyrinth.h.
