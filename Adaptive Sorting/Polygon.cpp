#include "Polygon.hpp"
#include <algorithm>

void Polygon::sortPoints(std::vector<std::pair<double, double>>& points) {
    // Sort points based on X coordinate
    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
}
