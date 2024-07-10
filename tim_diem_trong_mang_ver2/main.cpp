#include <iostream>
#include <vector>

struct Point {
    float x, y, z;

    Point(float xCoord, float yCoord, float zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

int findPoint(const std::vector<Point>& points, const Point& target) {
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1; 
}

int main() {
    int n, m;
    std::cin >> n;
    
    std::vector<Point> points;
    points.reserve(n);

    for (int i = 0; i < n; ++i) {
        float x, y, z;
        std::cin >> x >> y >> z;
        points.emplace_back(x, y, z);
    }
    
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        float x, y, z;
        std::cin >> x >> y >> z;
        int index = findPoint(points, Point(x, y, z));
        if (index != -1) {
            std::cout << index << "\n";
        } else {
            std::cout << "KHONG\n";
        }
    }
    
    return 0;
}
