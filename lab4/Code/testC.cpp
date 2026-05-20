#include <cmath>
#include <iostream>
#include <cassert>


struct Point{
    public:
    Point(double xin, double yin){
        x = xin;
        y = yin;
    }
    double x;
    double y;
};

class Coord{
    public:
    Coord(double xin, double yin){
        x = xin;
        y = yin;
    }
    double x;
    double y;
};


template<typename T>
void print(T value){

    std::cout << value.x << " " << value.y << "\n";

}

template<typename T1>
T1 add(T1 point1, T1 point2){

    T1 result(point1.x + point2.x, point1.y + point2.y);
    return result;
}


template <typename T, typename Tpoint>
double dot (Tpoint point1, Tpoint point2){

    return point1.x*point2.x + point1.y * point2.y;
}

template<typename Tpoint>
double norm(Tpoint point){
    return std::sqrt(pow(point.x, 2) + pow(point.y, 2));
}

template<typename T, typename Tpoint>
bool almost_equal(Tpoint point1, Tpoint point2){

    if(point1.x == point2.x && point1.y == point2.y) return true;
    else return false;

}




int main() {
    { // usage for type 'Point'
        Point p1 = Point(1, 0);
        Point p2 = Point(0, 1);
        Point p3 = add<Point>(p1, p2);
        print<Point>(p3);
        assert(almost_equal<Point>(p3, Point(1, 1)));
        assert(std::abs(norm<Point>(p3) - std::sqrt(2.0)) < 1e-5);
        assert(std::abs(dot<Point>(Point(1, 2), Point(3, 4)) - 11.0) < 1e-5);
    }
    { // usage for type 'Coord'
        Coord c1 = Coord(2, 0);
        Coord c2 = Coord(0, 2);
        Coord c3 = add<Coord>(c1, c2);
        print<Coord>(c3);
        assert(almost_equal<Coord>(c3, Coord(2, 2)));
        assert(std::abs(norm<Coord>(c3) - 2 * std::sqrt(2.0)) < 1e-5);
        assert(std::abs(dot<Coord>(Coord(1, 2), Coord(3, 4)) - 11.0) < 1e-5);
    }
}






