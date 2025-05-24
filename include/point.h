#ifndef POINT_CLOUD_INTERPOLATION_POINT_H
#define POINT_CLOUD_INTERPOLATION_POINT_H
#pragma once
#include <vector>
#include <random>
using namespace std;

struct Point {
    double x, y, z;
    double weight;
};//point structure
vector<Point> generateRandomPointCloud(
        int N,
        double minC, double maxC,
        double minW = 0.0, double maxW = 10.0
);

#endif
