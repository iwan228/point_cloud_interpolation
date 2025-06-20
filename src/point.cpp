/**
 * @file point.cpp
 * @brief Implementation of random point cloud generation.
 *
 * Contains the implementation of a utility to generate a noisy and sparse
 * 3D point cloud using a basic sinusoidal noise mask.
 */

#include "../include/point.h"

/**
 * @brief Simple deterministic noise mask to add spatial sparsity.
 *
 * Computes a noise-based mask value using sine and cosine functions.
 * Points with noise values above a threshold are skipped during generation.
 *
 * @param x X-coordinate
 * @param y Y-coordinate
 * @param z Z-coordinate
 * @return A value between 0 and ~3 representing the noise mask.
 */
double noiseMask(double x, double y, double z) {
    return abs(sin(x * 0.5 + 332 + 0.1) + cos(y * 0.7 * (2 + 0.1)) + sin(z * 0.3));
}

std::vector<Point> generateRandomPointCloud(int N, double minC, double maxC, double minW, double maxW){
std::vector<Point> cloud;
cloud.reserve(N);

std::default_random_engine gen(std::random_device{}());
std::uniform_real_distribution<double> dist(minC, maxC);
std::uniform_real_distribution<double> distW(minW, maxW);

while (cloud.size() < N) {
    Point p = {dist(gen), dist(gen), dist(gen), distW(gen)};

    if (noiseMask(p.x, p.y, p.z) < NOISE_FILTER)//lower the value, the bigger holes.
        cloud.push_back(p);
}
return cloud;//vector<Point>
}
