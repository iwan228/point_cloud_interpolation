# IDW Interpolation Library
## Overview
This library provides an implementation of Inverse Distance Weighting (IDW) interpolation over a regular 3D grid using KD-trees for efficient nearest-neighbor search. It supports interpolation over one or more point clouds, configurable number of nearest neighbors, and automatic grid filling with interpolated values.

---

## Class: `IDWInterpolator`

### Declaration (`idw.h`)

```cpp
class IDWInterpolator {
public:
    IDWInterpolator(int k);
    void interpolate(const std::vector<std::vector<Point>>& clouds,
                     std::vector<GridNode>& grid);

private:
    int k_;
    double squaredDistance(const Point& p, const GridNode& g) const;
};
```

### Description
* **Constructor:** Initializes the interpolator with a number of nearest neighbors k.
* **interpolate():** Performs IDW interpolation on the given grid using the provided point clouds.
* **squaredDistance():** Computes squared Euclidean distance between a point p and a grid node g.
---
## Method: `interpolate()`
### Description
The `interpolate()` method takes multiple point clouds and performs interpolation on a 3D grid. For each grid node, the method finds the `k` nearest neighbors using the KD-tree and computes a weighted average using the inverse of the squared distances.

### Parameters
* **clouds:** A vector of point clouds (`std::vector<std::vector<Point>>`). Each point cloud is a collection of points to be interpolated.
* **grid:** A reference to the grid (`std::vector<GridNode>`), which will be updated with interpolated weights for each node.

## Method: `squaredDistance()`
### Description
The `squaredDistance()` method calculates the squared distance between two points: a `Point` and a `GridNode` . This function is used to compute the weight of each point based on its proximity to the grid node.

## Usage
To use this library, create an instance of `IDWInterpolator`, specify the number of nearest neighbors `k`, and then call the `interpolate()` method with your clouds and grid.

#### Example:
```cpp
int main() {
    // Define point clouds and grid
    std::vector<std::vector<Point>> clouds = ...;
    std::vector<GridNode> grid = ...;

    // Initialize the IDW interpolator with k = 5
    IDWInterpolator interpolator(5);

    // Perform interpolation
    interpolator.interpolate(clouds, grid);

    // Grid nodes will now have interpolated values
}
```