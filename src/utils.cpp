/**
 * @file utils.cpp
 * @brief Implementation of KDTree class and utility functions for interpolation.
 */
#include "../include/utils.h"
#include <algorithm>//sort, make_heap, push_heap, pop_heap

using namespace std;

KDTree::KDTree(const vector<Point>& pts) {
    points = pts;
    root = build(points, 0, points.size(), 0);
}//constructor

KDTree::~KDTree() {
    //destroy(root); // Optional: Implement a destroy() method to clean up memory.
}//destructor

//recursively build kdtree
KDTree::Node* KDTree::build(vector<Point>& pts, int begin, int end, int depth) {
    if (begin >= end) return nullptr;

    int axis = depth % 3;//define partition axis
    int mid = (begin + end) / 2;//define middle point(parental node)

    auto compare = [axis](const Point& a, const Point& b) {
        if (axis == 0) return a.x < b.x;
        if (axis == 1) return a.y < b.y;
        return a.z < b.z;
    };//Comparison of points on selected axis(lambda function)

    sort(pts.begin() + begin, pts.begin() + end, compare);//sort by compare(pts.begin() - iterator)

    Node* node = new Node;//create new node
    node->point = pts[mid];//point of this node(middle)
    node->axis = axis;//axis of this node
    node->left = build(pts, begin, mid, depth + 1);//build left subtree
    node->right = build(pts, mid + 1, end, depth + 1);//build right subtree
    return node;
}

//void KDTree::destroy(Node* node) {
//    if (!node) return;
//    destroy(node->left);
//    destroy(node->right);
//    delete node;
//}//delete kdtree

double KDTree::squaredDistance(const Point& a, const Point& b) const {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}//calculating square root takes longer

void KDTree::nearest(Node* node, const Point& target, Point& best, double& bestDist) const {
    if (!node) return;

    double d = squaredDistance(node->point, target);
    if (d < bestDist) {
        bestDist = d;
        best = node->point;
    }

    int axis = node->axis;
    double delta = (axis == 0) ? (target.x - node->point.x)
                               : (axis == 1) ? (target.y - node->point.y)
                                             : (target.z - node->point.z);

    Node* first = (delta < 0) ? node->left : node->right;
    Node* second = (delta < 0) ? node->right : node->left;

    nearest(first, target, best, bestDist);
    if (delta * delta < bestDist) {
        nearest(second, target, best, bestDist);
    }
}//recursive function to find nearest neighbor(private)

Point KDTree::nearestNeighbor(const Point& target) const {
    Point best;
    double bestDist = 1e12;
    nearest(root, target, best, bestDist);
    return best;
}//external interface(searching nearest neighbor)

void KDTree::kNearest(Node* node, const Point& target, int k, vector<pair<double, Point>>& heap) const {
    if (!node) return;

    double d = squaredDistance(node->point, target);
    auto comp = [](const pair<double, Point>& a, const pair<double, Point>& b) {
        return a.first < b.first;
    };//If a.first is less than b.first, then a is considered to be less than b(lambda function)

    if ((int)heap.size() < k) {
        heap.emplace_back(d, node->point);
        push_heap(heap.begin(), heap.end(), comp);
    } else if (d < heap.front().first) {
        pop_heap(heap.begin(), heap.end(), comp);
        heap.back() = {d, node->point};
        push_heap(heap.begin(), heap.end(), comp);
    }//find and delete the farthest current closest point if a closer point appears

    int axis = node->axis;
    double delta = (axis == 0) ? (target.x - node->point.x)
                               : (axis == 1) ? (target.y - node->point.y)
                                             : (target.z - node->point.z);

    Node* first = (delta < 0) ? node->left : node->right;
    Node* second = (delta < 0) ? node->right : node->left;

    kNearest(first, target, k, heap);
    if ((int)heap.size() < k || delta * delta < heap.front().first) {
        kNearest(second, target, k, heap);
    }
}//recursive function to find k nearest neighbors(private)

vector<Point> KDTree::kNearestNeighbors(const Point& target, int k) const {
    vector<pair<double, Point>> heap;
    auto comp = [](const pair<double, Point>& a, const pair<double, Point>& b) {
        return a.first < b.first;
    };
    make_heap(heap.begin(), heap.end(), comp);
    kNearest(root, target, k, heap);

    vector<Point> result;
    for (auto& p : heap) result.push_back(p.second);
    return result;
}//external interface(searching nearest k neighbor)

Point convertToPoint(GridNode& node){
    return Point{node.x, node.y, node.z, node.weight};
}
double sumVector(vector<double> w){
    double sum = 0;
    for(auto& i : w)
        sum +=i;
    return sum;
}
