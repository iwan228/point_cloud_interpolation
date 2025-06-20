/**
 * @file point.h
 * @brief Declaration of the Point structure and random point cloud generation function.
 *
 * Defines the `Point` structure used in point cloud interpolation and
 * declares the function to generate synthetic point clouds with configurable parameters.
 */
#ifndef POINT_CLOUD_INTERPOLATION_POINT_H
#define POINT_CLOUD_INTERPOLATION_POINT_H
#pragma once

#include <vector>
#include <random>
#include <cmath>

/**
 * @struct Point
 * @brief Represents a 3D point with an associated weight.
 *
 * The structure holds the spatial coordinates (x, y, z) of a point
 * and a corresponding weight value used in interpolation.
 */
struct Point {
    double x, y, z;
    double weight;
};

/**
 * @brief Generates a random point cloud within the given coordinate and weight ranges.
 *
 * This function creates a vector of randomly distributed points in 3D space,
 * using a basic noise filter to introduce sparsity and holes in the distribution.
 *
 * @param N Number of points to generate.
 * @param minC Minimum coordinate value (for x, y, and z).
 * @param maxC Maximum coordinate value (for x, y, and z).
 * @param minW Minimum weight value.
 * @param maxW Maximum weight value.
 * @return A vector of randomly generated points.
 */
std::vector<Point> generateRandomPointCloud(
        int N,
        double minC, double maxC,
        double minW, double maxW
);

#endif