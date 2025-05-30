#ifndef POINT_CLOUD_INTERPOLATION_IDW_H
#define POINT_CLOUD_INTERPOLATION_IDW_H
#pragma once

#include <vector>
#include <cmath>
#include "../include/point.h"
#include "../include/grid.h"
#include "../include/utils.h"

using namespace std;

class IDWInterpolator{
public:
    IDWInterpolator(int k);
    void interpolate(const vector<vector<Point>>& clouds, vector<GridNode>& grid);
private:
    int k_;

    double squaredDistance(const Point& p, const GridNode& g) const;
};

#endif
