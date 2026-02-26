Skyscraper Problem

The Skyscraper Problem is a logic-based constraint satisfaction puzzle in which the goal is to determine the height of buildings in a grid-based city while respecting a set of visibility constraints. Each cell represents a skyscraper, and its height must be unique within its row and column. Clues placed around the grid indicate how many skyscrapers are visible from a specific direction, considering that taller buildings block the view of shorter ones behind them.

This project provides an algorithmic solution to the Skyscraper Problem, focusing on correctness, efficiency, and clarity of implementation.

Problem Description

The grid is of size N × N.

Each row and each column must contain all values from 1 to N exactly once.

Numbers around the grid edges represent visibility clues:

A clue indicates how many skyscrapers are visible from that side.

A taller skyscraper hides any smaller ones behind it.

Example

If a row contains [2, 1, 4, 3] and is viewed from the left:

You can see 2 and 4 → visibility count = 2

⚙️ Solution Approach

The solution is based on constraint satisfaction and backtracking, enhanced by:

Row and column validation

Visibility checks from all four directions

Early pruning to reduce the search space

Optional heuristics to improve performance on larger grids

The algorithm systematically builds the grid, validating partial solutions at each step to ensure consistency with the rules and clues.
