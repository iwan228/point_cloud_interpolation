#include <iostream>
#include "../include/point.h"
#include "../include/grid.h"
#include <vector>
using namespace std;

int main(){
    int countPoints;
    double minCoord, maxCoord;
    double xCenter, yCenter, zCenter, step, radius;
    cout << "Enter count points: ";
    cin >> countPoints;
    cout << "Enter min coord: ";
    cin >> minCoord;
    cout << "Enter max coord: ";
    cin >> maxCoord;
    cout << "Center of grid(x,y,z): " << endl;
    cin >> xCenter >> yCenter >> zCenter;
    cout << "Grid step: " << endl;
    cin >> step;
    cout << "Grid radius: " << endl;
    cin >> radius;

    vector<Point> cloud = generateRandomPointCloud(countPoints, minCoord, maxCoord,0,10);

    for(int i = 0; i < cloud.size(); i++){
        cout << cloud[i].x << " " << cloud[i].y << " " << cloud[i].z << " " << cloud[i].weight << endl;
    }

    vector<GridNode> grid = generateGrid(xCenter, yCenter, zCenter, step, radius);

    return 0;
}