/**
 * @file idw.h
 * @brief Header file for IDWInterpolator class implementing Inverse Distance Weighting interpolation.
 */
#ifndef POINT_CLOUD_INTERPOLATION_IDW_H
#define POINT_CLOUD_INTERPOLATION_IDW_H
#pragma once

#include <vector>
#include <cmath>
#include "../include/point.h"
#include "../include/grid.h"
#include "../include/utils.h"

/**
 * @class IDWInterpolator
 * @brief Performs Inverse Distance Weighting (IDW) interpolation on a regular 3D grid using multiple point clouds.
 */

class IDWInterpolator{
public:
    /**
    * @brief Constructor for the IDWInterpolator.
    * @param k Number of nearest neighbors to consider during interpolation.
    */

    IDWInterpolator(int k);
    /**
    * @brief Performs IDW interpolation on the given grid using multiple point clouds.
    *
    * This function interpolates weights for each node in a regular grid by considering
    * the k nearest neighbors from each point cloud. It builds a KD-tree for each cloud
    * and computes the weighted average based on the inverse of the squared distances.
    *
    * @param clouds A vector of point clouds, where each point cloud is a vector of Point structures.
    * @param grid A reference to the vector of GridNode structures that will receive the interpolated values.
    */
    void interpolate(const std::vector<std::vector<Point>>& clouds, std::vector<GridNode>& grid);
private:
    int k_; ///< Number of nearest neighbors used in IDW interpolation.
    /**
    * @brief Computes squared Euclidean distance between a point and a grid node.
    * @param p A point from the cloud.
    * @param g A node of the grid.
    * @return The squared distance between p and g.
    */
    double squaredDistance(const Point& p, const GridNode& g) const;
};

#endif
