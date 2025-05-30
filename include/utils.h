#ifndef POINT_CLOUD_INTERPOLATION_UTILS_H
#define POINT_CLOUD_INTERPOLATION_UTILS_H
#pragma once

#include "../include/point.h"
#include "../include/grid.h"

using namespace std;

class KDTree {
public:
    KDTree(const vector<Point>& points);//constructor
    ~KDTree();//destructor

    Point nearestNeighbor(const Point& target) const;//external interface(searching nearest neighbor)
    vector<Point> kNearestNeighbors(const Point& target, int k) const;//external interface(searching nearest k neighbor)

private:
    //internal structure of kdtree node
    struct Node {
        Point point;//point of this node
        int axis;//axis of this node(0 — x, 1 — y, 2 — z)
        Node* left;//left subtree
        Node* right;//right subtree
    };

    Node* root;//root of kdtree
    vector<Point> points;

    Node* build(vector<Point>& pts, int begin, int end, int depth);//recursive function to build kdtree
    void destroy(Node* node);//recursive function to destroy kdtree

    void nearest(Node* node, const Point& target, Point& best, double& bestDist) const;//recursive function to find nearest neighbor(private)
    void kNearest(Node* node, const Point& target, int k, vector<pair<double, Point>>& heap) const;//recursive function to find k nearest neighbors(private)

    double squaredDistance(const Point& a, const Point& b) const;//calculate squared distance
};

Point convertToPoint(GridNode& node);
double sumVector(vector<double> w);
#endif
