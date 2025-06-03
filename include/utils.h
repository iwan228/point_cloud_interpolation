/**
 * @file utils.h
 * @brief Declaration of the KDTree class and utility functions for point cloud processing.
 */
#ifndef POINT_CLOUD_INTERPOLATION_UTILS_H
#define POINT_CLOUD_INTERPOLATION_UTILS_H
#pragma once

#include "../include/point.h"
#include "../include/grid.h"

using namespace std;

/**
 * @class KDTree
 * @brief A 3D k-d tree for efficient nearest neighbor search in point clouds.
 */
class KDTree {
public:
    /**
    * @brief Constructs a KDTree from a set of points.
    * @param points Vector of input points to build the tree.
    */
    KDTree(const vector<Point>& points);
    /**
    * @brief Destructor.
    */
    ~KDTree();
    /**
    * @brief Finds the nearest neighbor to the given target point.
    * @param target Target point to search nearest neighbor for.
    * @return The closest point from the KDTree.
    */
    Point nearestNeighbor(const Point& target) const;//external interface(searching nearest neighbor)
    /**
     * @brief Finds the k nearest neighbors to the given target point.
     * @param target Target point.
     * @param k Number of nearest neighbors to find.
     * @return Vector of k nearest points.
     */
    vector<Point> kNearestNeighbors(const Point& target, int k) const;//external interface(searching nearest k neighbor)

private:
    /**
    * @struct Node
    * @brief Represents a node in the KDTree.
    */
    struct Node {
        Point point;    ///< Point stored at this node.
        int axis;       ///< Axis used for partitioning (0 = x, 1 = y, 2 = z).
        Node* left;     ///< Left child node.
        Node* right;    ///< Right child node.
    };

    Node* root;              ///< Root of the KDTree.
    vector<Point> points;    ///< Local copy of point data.

    /**
     * @brief Recursively builds a KDTree.
     * @param pts Vector of points.
     * @param begin Start index.
     * @param end End index.
     * @param depth Current tree depth.
     * @return Pointer to the root of the subtree.
     */
    Node* build(vector<Point>& pts, int begin, int end, int depth);

    /**
     * @brief Recursively finds the nearest neighbor.
     * @param node Current node in the tree.
     * @param target Target point.
     * @param best Current best match.
     * @param bestDist Distance to current best match.
     */
    void nearest(Node* node, const Point& target, Point& best, double& bestDist) const;

    /**
     * @brief Recursively finds k nearest neighbors.
     * @param node Current node.
     * @param target Target point.
     * @param k Number of neighbors.
     * @param heap Max-heap of (distance, point) pairs.
     */
    void kNearest(Node* node, const Point& target, int k, vector<pair<double, Point>>& heap) const;

    /**
     * @brief Computes squared Euclidean distance between two points.
     * @param a First point.
     * @param b Second point.
     * @return Squared distance.
     */
    double squaredDistance(const Point& a, const Point& b) const;//calculate squared distance
};

/**
 * @brief Converts a GridNode to a Point.
 * @param node Grid node to convert.
 * @return Point equivalent of the GridNode.
 */
Point convertToPoint(GridNode& node);

/**
 * @brief Computes the sum of a vector of doubles.
 * @param w Vector of weights.
 * @return Sum of the weights.
 */
double sumVector(vector<double> w);
#endif
