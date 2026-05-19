#include <array>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>

using Point = std::array<double, 2>;

class PointCloud {
private:
    std::vector<Point> points;

public:
    PointCloud() = default;

    std::vector<double> distance(const Point &p) const {
        std::vector<double> d;
        d.reserve(points.size());

        for (const auto &pt : points) {
            double dx = pt[0] - p[0];
            double dy = pt[1] - p[1];
            d.push_back(std::sqrt(dx * dx + dy * dy));
        }

        return d;
    }

    void add(const Point &p) {
        points.push_back(p);
    }

    void print(const Point &p, double r) const {
        auto d = distance(p);
        std::cout << "Distances from point (" << p[0] << ", " << p[1] << "): ";
        for (size_t i = 0; i < d.size(); ++i) {
            std::cout << std::fixed << std::setprecision(3) << d[i];
            if (i + 1 < d.size()) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";

        auto n = neighbourhood(p, r);
        std::cout << "Neighbour points within radius " << r << ": ";
        if (n.empty()) {
            std::cout << "none";
        } else {
            for (size_t i = 0; i < n.size(); ++i) {
                std::cout << "(" << n[i][0] << ", " << n[i][1] << ")";
                if (i + 1 < n.size()) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << "\n";
    }

    std::vector<Point> neighbourhood(const Point &pref, double radius) const {
        std::vector<Point> n;
        auto d = distance(pref);

        for (size_t i = 0; i < points.size(); ++i) {
            if (d[i] <= radius) {
                n.push_back(points[i]);
            }
        }

        return n;
    }
};

int main() {
    PointCloud cloud;
    for (unsigned int n = 0; n != 5; ++n) {
        cloud.add(Point{0.1 * n, 0.1 * n});
    }

    Point p1{0.5, 0.5};
    double radius = 0.35;
    cloud.print(p1, radius);

    return 0;
}
