#ifndef POINT_CLOUD_INTERPOLATION_GRID_H
#define POINT_CLOUD_INTERPOLATION_GRID_H
#pragma once
#include <vector>
#include "../include/point.h"
using namespace std;
struct GridNode {
    double x, y, z;
    double weight = 0.0;
    bool isExtrapolated = false;
};//grid node structure

vector<GridNode> generateGrid(
        double cx, double cy, double cz,
        double step,
        double r
);
#endif //POINT_CLOUD_INTERPOLATION_GRID_H
