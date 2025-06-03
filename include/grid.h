/**
 * @file grid.h
 * @brief Header file for generating a regular 3D grid of GridNode.
 *
 * Contains the definition of the GridNode structure and the generateGrid function
 * for creating a three-dimensional regular grid around a given center with a specified step and radius.
 */
#ifndef POINT_CLOUD_INTERPOLATION_GRID_H
#define POINT_CLOUD_INTERPOLATION_GRID_H
#pragma once

#include <vector>
#include "../include/point.h"

using namespace std;

/**
 * @struct GridNode
 * @brief Represents a node in the regular 3D grid.
 *
 * Stores the coordinates of a point in space, a weight value, and an extrapolation flag.
 */
struct GridNode {
    double x;                       ///< X coordinate
    double y;                       ///< Y coordinate
    double z;                       ///< Z coordinate
    double weight = 0.0;            ///< Weight computed by interpolation method
    bool isExtrapolated = false;    ///< Flag indicating whether the point has been extrapolated
};

/**
 * @brief Generates a regular cubic 3D grid with a given step size and radius around the point (cx, cy, cz).
 *
 * Creates a three-dimensional grid within a cube of side length 2*r and step size `step`. The center of the grid is specified by the coordinates (cx, cy, cz).
 * This function is used to define a regular grid, which is then used for interpolation of values.
 *
 * @param cx X-coordinate of the grid center
 * @param cy Y-coordinate of the grid center
 * @param cz Z-coordinate of the grid center
 * @param step Step size between grid nodes
 * @param r Radius (relative to the center) within which the grid is created
 * @return A vector of GridNode objects representing the grid nodes
 */
vector<GridNode> generateGrid(
        double cx, double cy, double cz,
        double step,
        double r
);
#endif //POINT_CLOUD_INTERPOLATION_GRID_H
