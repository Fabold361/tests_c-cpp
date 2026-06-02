#include <array>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <numbers>
#include <vector>

struct Point
{
  double x;
  double y;
};

double distance(Point p1, Point p2)
{
  return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

class Circle
{

private:
  double radius;
  Point center;

public:
  Circle(double r, Point c)
  {
    assert(r > 0 && "Radius must be positive");
    radius = r;
    center = c;
  };

  double area()
  {
    double A;

    A = std::pow(radius, 2) * std::numbers::pi;

    return (A);
  }

  double center_distance(Circle circle2)
  {
    return distance(center, circle2.center);
  }

  bool contains(Point p2)
  {
    double d = distance(center, p2);

    if (d < radius)
      return true;
    else
      return false;
  }
};

int main()
{

  auto circle1 = Circle(0.5, Point{0, 0});
  auto circle2 = Circle(1.0, Point{1, 1});
  auto point = Point{0.5, 0.5};

  std::cout << "Area circle 1: " << circle1.area()
            << "   Area circle 2: " << circle2.area()
            << "\nDistance of 2 pts: " << distance(Point{0,0}, point)
            << "\nCenter distance: " << circle1.center_distance(circle2);

  if (circle1.contains(point) == true)
    std::cout << "\nPoint is inside the circle!";
  else
    std::cout << "\nPoint is outside the circle!";

  return (0);
}
