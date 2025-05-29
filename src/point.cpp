#include "../include/point.h"
using namespace std;
// generate random point cloud

// simple noise function: sin(x) + cos(y) + sin(z)
double noiseMask(double x, double y, double z) {
    return abs(sin(x * 0.5 + 332 + 0.1) + cos(y * 0.7 * (2 + 0.1)) + sin(z * 0.3));
}
vector<Point> generateRandomPointCloud(int N, double minC, double maxC, double minW, double maxW){
vector<Point> cloud;
cloud.reserve(N);

default_random_engine gen(random_device{}());
uniform_real_distribution<double> dist(minC, maxC);
uniform_real_distribution<double> distW(minW, maxW);

while (cloud.size() < N) {
    Point p = {dist(gen), dist(gen), dist(gen), distW(gen)};

    if (noiseMask(p.x, p.y, p.z) < 0.9)//lower the value, the bigger holes.
        cloud.push_back(p);
}
return cloud;//vector<Point>
}
