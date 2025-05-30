#include <iostream>
#include "../include/point.h"
#include "../include/grid.h"
#include "../include/utils.h"
#include "../include/idw.h"
#include <vector>
#include <ctime>

using namespace std;

int main(){
    unsigned int seed = clock();
    int countPoints;
    int countCl;
    int k;
    double minCoord, maxCoord;
    double minWeight, maxWeight;
    double xCenter, yCenter, zCenter, step, radius;
    cout << "Enter count clouds: ";
    cin >> countCl;
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

    cout << "Interpolation by k nearest points \n k(<=10)=" << endl;
    cin >> k;
    if(k > 10 || k < 1) k = 10;
//    cout << "Enter weighing level:" << endl;
//    cin >> power;

    vector<GridNode> grid = generateGrid(xCenter, yCenter, zCenter, step, radius);
    cout << grid.size() << endl;

//    vector<Point> cloud = generateRandomPointCloud(countPoints,
//                                                   minCoord,
//                                                   maxCoord,
//                                                   minWeight,
//                                                   maxWeight);//point cloud

    vector<vector<Point>> clouds;
    clouds.reserve(countCl);
        for(int i = 0; i < countCl; ++i){
            vector<Point> cloud = generateRandomPointCloud(countPoints,
                                                           minCoord,
                                                           maxCoord,
                                                           minWeight,
                                                           maxWeight);//point cloud
            clouds.push_back(cloud);
        }
        IDWInterpolator interpolator(k);
        interpolator.interpolate(clouds, grid);



      //for(int i = 0; i < grid.size(); i++){
//        cout << cloud[i].x << " " << cloud[i].y << " " << cloud[i].z << " " << cloud[i].weight << endl;
//        cout << cloud[i].x << ";" << cloud[i].y << ";" << cloud[i].z << "," << endl;
//        cout << cloud[i].x << "," << cloud[i].y << "," << cloud[i].z << endl;
          //cout << grid[i].x << "," << grid[i].y << "," << grid[i].z << " " << grid[i].weight << " " << grid[i].isExtrapolated << endl;
      //}
    unsigned int end_time = clock();
    cout << "Time: " << end_time - seed << endl;
    return 0;
}