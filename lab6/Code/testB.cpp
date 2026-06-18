#include <cassert>
#include <cstddef>
#include <iostream>
#include <cmath>
#include <vector>


using Pixel = unsigned char;

class Image {
private:
  std::vector<Pixel> data;
  std::size_t width;
  std::size_t height;

public:
  Image(const std::vector<Pixel> &data, std::size_t width, std::size_t height) : data(data), width(width), height(height){}
  
  std::tuple<Pixel, Pixel> range() const {
    unsigned char min = data[0];
    unsigned char max = data[0];
    for(size_t i = 0; i < data.size(); i++){
        if(data[i] < min) min = data[i];
        if(data[i] > max) max = data[i];
    }
    return {min, max};
  }


  void print() const {
    for(size_t i = 0; i < data.size(); i++){
        std::cout << (int)data[i] << "\n";
    }
  }


  Image invert() const {

    
    std::vector<Pixel> data_inv;
    for(size_t i = 0; i < data.size(); i++){
        data_inv.push_back(255 - data[i]);
    }

    return{data_inv, width, height};
  }
};



int main() {
  std::size_t width = 3;
  std::size_t height = 3;
  std::vector<Pixel> pixels = {10, 20, 20, 110, 120, 130, 210, 220, 230};
  auto a = Image{pixels, width, height};
  a.print();
  assert((a.range() == std::tuple<Pixel, Pixel>{10, 230}));
  auto b = a.invert();
  b.print();
  assert((b.range() == std::tuple<Pixel, Pixel>{25, 245}));
  auto c = b.invert();
  c.print();
  assert((c.range() == std::tuple<Pixel, Pixel>{10, 230}));
}