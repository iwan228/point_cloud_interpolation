/**
 * @file idw.cpp
 * @brief Implementation of the IDWInterpolator class.
 */

#include "../include/idw.h"

IDWInterpolator::IDWInterpolator( int k): k_(k) {}

double IDWInterpolator::squaredDistance(const Point& p, const GridNode& g) const {
    double dx = p.x - g.x;
    double dy = p.y - g.y;
    double dz = p.z - g.z;
    return dx * dx + dy * dy + dz * dz;
}

void IDWInterpolator::interpolate(const std::vector<std::vector<Point>>& clouds, std::vector<GridNode>& grid) {
    std::vector<KDTree> trees;
    for (const auto& cloud : clouds)
        trees.emplace_back(cloud);//creating one kd tree for each point cloud, and storing these trees in vector<KDTree> trees

    for (auto& node : grid) {
        const Point target = convertToPoint(node);
        std::vector<double> weights;

        for (const auto& tree : trees) {
            if (k_ == 1) {
                Point nearest = tree.nearestNeighbor(target);
                weights.push_back(nearest.weight);
            } else
            {
                std::vector<Point> knearest = tree.kNearestNeighbors(target, k_);
                double sumWeighted = 0, sumWeight = 0;
                for (const auto& pt : knearest) {
                    double dist2 = squaredDistance(pt, node);
//                    if (dist2 < ZERO) {
//                        sumWeighted = pt.weight;
//                        sumWeight = 1.0;
//                        break;
//                    }
                    sumWeighted += pt.weight / dist2;
                    sumWeight += 1.0 / dist2;
                }
                weights.push_back(sumWeighted / sumWeight);
            }
        }

        node.weight = sumVector(weights) / static_cast<double>(weights.size());
        node.isExtrapolated = true;
    }
}