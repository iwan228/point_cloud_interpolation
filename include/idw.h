#ifndef POINT_CLOUD_INTERPOLATION_IDW_H
#define POINT_CLOUD_INTERPOLATION_IDW_H
#pragma once
using namespace std;

#include <vector>
#include <memory>
#include <queue>
#include <limits>
#include <cmath>

#include "point.h"

class KDTree {
public:
    KDTree(const vector<Point> &points);
    Point NearestPoint(const Point &target) const;
    vector<Point> KNearestPoint(const Point &target, int k) const;

private:
    struct Node {
        Point point;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        int axis;// 0 for x, 1 for y, 2 for z
    };
    unique_ptr<Node> root;// root of the KD tree
    std::unique_ptr<Node> build(std::vector<Point>& points, int depth);
    void searchNearest(const Node* node, const Point& target, int depth, Point& best, double& bestDist) const;
    void searchKNearest(const Node* node, const Point& target, int k, int depth, priority_queue<pair<double, Point>>& heap) const;
};

#endif
