#include <iostream>
#include "../include/point.h"
#include "../include/grid.h"
#include "../include/utils.h"
#include <vector>
using namespace std;

int main(){
    int countPoints;
    double minCoord, maxCoord;
    double minWeight, maxWeight;
    double xCenter, yCenter, zCenter, step, radius;
    cout << "Enter count points: ";
    cin >> countPoints;
    cout << "Enter min coord: ";
    cin >> minCoord;
    cout << "Enter max coord: ";
    cin >> maxCoord;
    cout << "Enter min weight: " << endl;
    cin >> minWeight;
    cout << "Enter max weight: " << endl;
    cin >> maxWeight;
    cout << "Center of grid(x,y,z): " << endl;
    cin >> xCenter >> yCenter >> zCenter;
    cout << "Grid step: " << endl;
    cin >> step;
    cout << "Grid radius: " << endl;
    cin >> radius;

    vector<Point> cloud = generateRandomPointCloud(countPoints, minCoord, maxCoord,0,10);//point cloud
    vector<GridNode> grid = generateGrid(xCenter, yCenter, zCenter, step, radius);

    for(int i = 0; i < cloud.size(); i++){
        //cout << cloud[i].x << " " << cloud[i].y << " " << cloud[i].z << " " << cloud[i].weight << endl;
        //cout << cloud[i].x << ";" << cloud[i].y << ";" << cloud[i].z << "," << endl;
        cout << cloud[i].x << "," << cloud[i].y << "," << cloud[i].z << endl;
    }
    // Строим дерево
    KDTree tree(cloud);

    // Точка, для которой ищем соседей
    Point query = {2.5, 3.5, 4.5, 0.0};

    // Один ближайший сосед
    Point nearest = tree.nearestNeighbor(query);
    std::cout << "Nearest neighbor: ("
              << nearest.x << ", " << nearest.y << ", " << nearest.z
              << "), weight = " << nearest.weight << "\n";

    // K ближайших соседей
    int k = 3;
    std::vector<Point> neighbors = tree.kNearestNeighbors(query, k);
    std::cout << k << " nearest neighbors:\n";
    for (const Point& p : neighbors) {
        std::cout << "  (" << p.x << ", " << p.y << ", " << p.z
                  << "), weight = " << p.weight << "\n";
    }


    return 0;
}