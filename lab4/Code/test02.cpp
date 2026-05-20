#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>

template<typename T, typename func>
bool all_of (std::vector<T> values, func lambda){

    int count = 0;
    for (size_t i = 0; i < values.size(); i++)
    {
        if (lambda(values[i])){
            count++;
        }
    }
    if (count == values.size()) return true;
    else return false;

}


template<typename T, typename func>
T find_max(std::vector<T> values, func lambda){
    
    std::vector<T> out;
    T result = -100;
    for (size_t i = 0; i < values.size(); i++)
    {
        if (lambda(values[i])){
            out.push_back(values[i]);
        }

    }
    
    for (size_t i = 0; i < out.size(); i++)
    {
        if (out[i] > result) result = out[i];
    }
    return(result);

}

template<typename T, typename func01>
std::vector<T> replace_if(std::vector<T> values, func01 lambda01, T limit){

std::vector<T> out;

    for (size_t i = 0; i < values.size(); i++)
    {
        if (lambda01(values[i]))
        {
            values[i] = limit;
        }
    }
    return (values);
}




int main() {
  { // usage for type 'int'
    std::vector<int> values = {4, 7, 2, 9, 3, 6};
    auto is_odd = [](int v) { return v % 2 != 0; };
    assert(all_of<int>(values, is_odd) == false);
    assert(find_max<int>(values, is_odd) == 9);
    assert(replace_if<int>(values, is_odd, 0)
        == std::vector<int>({4, 0, 2, 0, 0, 6}));
  }
  { // usage for type 'double'
    std::vector<double> values = {1.2, 3.8, 2.5, 4.1, 0.9};
    double limit = 2.0;
    auto above_limit = [limit](double v) { return v > limit; };
    assert(all_of<double>(values, above_limit) == false);
    assert(std::abs(find_max<double>(values, above_limit) - 4.1) < 1e-5);
    assert(replace_if<double>(values, above_limit, -1.0)
        == std::vector<double>({1.2, -1.0, -1.0, -1.0, 0.9}));
  }
}