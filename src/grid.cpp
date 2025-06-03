/**
 * @file grid.cpp
 * @brief Implementation of the 3D grid generation function for GridNode.
 */
#include "../include/grid.h"
#include <vector>

//generate grid with center (cx, cy, cz), radius (r) and step(step)
vector<GridNode> generateGrid(double cx, double cy, double cz, double step, double r) {
    vector<GridNode> grid;

    int steps = static_cast<int>(r / step);

    for (int i = -steps; i <= steps; ++i) {
        for (int j = -steps; j <= steps; ++j) {
            for (int k = -steps; k <= steps; ++k) {
                double x = cx + i * step;
                double y = cy + j * step;
                double z = cz + k * step;
                grid.push_back(GridNode{x, y, z});
            }
        }
    }

    return grid;//vector<GridNode>
}





