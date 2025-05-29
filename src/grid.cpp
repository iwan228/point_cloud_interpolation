#include "../include/grid.h"
#include <vector>

//generate grid with center (cx, cy, cz), radius (r) and step(step)
vector<GridNode> generateGrid(double cx, double cy, double cz, double r, double step) {
    vector<GridNode> grid;

    double minX = cx - r;
    double maxX = cx + r;
    double minY = cy - r;
    double maxY = cy + r;
    double minZ = cz - r;
    double maxZ = cz + r;

    for (double z = minZ; z <= maxZ; z += step) {
        for (double y = minY; y <= maxY; y += step) {
            for (double x = minX; x <= maxX; x += step) {
                grid.push_back(GridNode{x, y, z});
            }
        }
    }

    return grid;//vector<GridNode>
}





