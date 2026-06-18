#include <cmath>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <tuple>



template <typename T>
std::vector<T> equidistant_range(T start, T step,  T n){
    std::vector<T> data;
    for(size_t i = 0; i < n; i++) {
        data.push_back(start);
        start = start + step;
    }
    return(data);
}


template <typename T>
auto stats (std::vector<T> data){
    T sum = 0;
    T abssum = 0;
    T sqsum = 0;
    for(size_t i = 0; i < data.size(); i++) sum = data[i] + sum;
    for(size_t i = 0; i < data.size(); i++) abssum = std::abs(data[i]) + abssum;
    for(size_t i = 0; i < data.size(); i++) sqsum = std::pow(data[i],2) + sqsum;
    return (std::tuple{sum, abssum, sqsum});
}



int main() {
  {
    float start = -1.0f;
    float step = +1.0f;
    unsigned int n = 4;
    std::vector<float> data = equidistant_range<float>(start, step, n); // (-1, 0, 1, 2)
    auto [sum, abssum, sqsum] = stats<float>(data);
    assert(std::fabs(sum - 2) < 1e-5);
    assert(std::fabs(abssum - 4) < 1e-5);
    assert(std::fabs(sqsum - 6) < 1e-5);
  }
  {
    double start = 0.0;
    double step = -2.0;
    unsigned int n = 3;
    std::vector<double> data = equidistant_range<double>(start, step, n); // (0, -2, -4)
    auto [sum, abssum, sqsum] = stats<double>(data);
    assert(std::fabs(sum - (-6)) < 1e-9);
    assert(std::fabs(abssum - 6) < 1e-9);
    assert(std::fabs(sqsum - 20) < 1e-9);
  }
}