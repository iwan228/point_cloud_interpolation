#include "../include/point.h"
using namespace std;
// generate random point cloud
vector<Point> generateRandomPointCloud(int N, double minC, double maxC, double minW, double maxW){
vector<Point> cloud;
cloud.reserve(N);

random_device rd;
mt19937 gen(rd());

uniform_real_distribution<double> distCoord(minC, maxC);
uniform_real_distribution<double> distW(minW, maxW);

for (int i = 0; i < N; ++i) {
    cloud.push_back({
        distCoord(gen),
        distCoord(gen),
        distCoord(gen),
        distW(gen)
    });
}

return cloud;//vector<Point>
}
