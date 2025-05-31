# Point Cloud Interpolation with IDW and KD-Tree

This program module implements the IDW (Inverse Distance Weighting) interpolation algorithm in three-dimensional space on a regular grid. The main purpose is to restore (estimate) values in grid nodes on the basis of spatially distributed measured data represented as one or several point clouds.

Each point cloud contains coordinates and a numerical weight. The IDW algorithm assumes that the contribution of each point to the interpolated value is inversely proportional to the degree (in this case, the square of the distance to the grid node in question).

To speed up the nearest neighbor search, the KD-tree structure is used, which allows efficient processing of large amounts of data. Interpolation is performed by k nearest points for each grid node. The processing of edge cases (e.g., zero distance) is provided.

---

## Features

- Supports multiple point clouds
- Configurable number of nearest neighbors (`k`)
- Fast nearest neighbor queries using KD-tree
- Flexible generation of a regular 3D grid
- Handles near-zero distance cases robustly
- Computes averaged values from all clouds at each grid node

---

## Project Structure

```text
include/
├── grid.h       // Regular grid node structure
├── idw.h        // IDWInterpolator class declaration
├── point.h      // Point structure with coordinates and weight
└── utils.h      // Grid generation, random point cloud utilities

src/
├── grid.cpp     // GridNode implementation
├── idw.cpp      // Core interpolation logic
├── main.cpp     // Demo entry point (can be removed)
├── point.cpp    // Point implementation
└── utils.cpp    // Utility implementations

CMakeLists.txt   // Build instructions using CMake
README.md        //
