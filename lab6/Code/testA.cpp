#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <functional>



struct Coord {
    double x;
    double y;
};


std::vector<Coord> transform(std::vector<Coord> a, std::function<Coord(Coord)> f){

    std::vector<Coord> out;
    for(size_t i = 0; i < a.size(); i++){
        out.push_back(f(a[i]));
    }
    return(out);
}


bool isclose(std::vector<Coord> a, std::vector<Coord> b, double toleranz){

    int count = 0;
    for(size_t i = 0; i < a.size(); i++){

        if ( std::abs(a[i].x - b[i].x) < toleranz && std::abs(a[i].y - b[i].y) < toleranz ) count++;
    
    }
    if(count == a.size()) return true;
    else return false;
}







int main() {

    std::vector<Coord> a = {
        Coord{1.0, 1.0},
        Coord{2.0, 2.0},
        Coord{3.0, 3.0},
    };

    auto plus1 = [](const Coord& c) { return Coord{c.x + 1.0, c.y + 1.0}; };
    auto minus1 = [](const Coord& c) { return Coord{c.x - 1.0, c.y - 1.0}; };

    std::vector<Coord> b = transform(a, plus1);
    std::vector<Coord> c = transform(b, minus1);

    double abs_tol = 1e-3;
    assert(!isclose(a, b, abs_tol));
    assert(isclose(a, c, abs_tol));

    return 0;
}