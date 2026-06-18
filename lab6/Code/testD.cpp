#include <cstddef>
#include <vector>
#include <cmath>
#include <functional>
#include <cassert>


struct Coord {
    double x;
    double y;
};

class Track {
private:
  std::vector<Coord> coords;

public:
  Track(const std::vector<Coord>& coords) : coords(coords){};
  Track(std::function<Coord(double)> path, double start, double step, unsigned int n){
    for(size_t i = 0; i < n; i++){
        coords.push_back(path(start)); //strecke
        start = start + step;
    }
  }
  double length() const{

    double d = 0;
    for(size_t i = 1; i < coords.size(); i++){
        d = d + (std::sqrt( std::pow((coords[i-1].x - coords[i].x),2) + std::pow((coords[i-1].y - coords[i].y),2) ));
    }

    return(d);
  };
};


int main() {
  auto coords = std::vector<Coord>{Coord{0, 0}, Coord{1, 1}};
  auto track1 = Track(coords);
  assert(std::fabs(track1.length() - std::sqrt(2)) < 1e-7);

  auto linear_path = [](double t) { return Coord{t, t}; };
  double start = 1.0;
  double step = 0.1;
  unsigned int n = 11;
  auto track2 = Track(linear_path, start, step, n);
  assert(std::fabs(track2.length() - std::sqrt(2)) < 1e-7);
}