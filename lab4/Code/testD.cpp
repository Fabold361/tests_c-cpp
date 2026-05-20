#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

template <typename T> class Matrix {
public:
  Matrix(std::array<T, 3> row1_in, std::array<T, 3> row2_in,
         std::array<T, 3> row3_in) {

    row1 = row1_in;
    row2 = row2_in;
    row3 = row3_in;
  }

  T at(T x, T y) {

    T number_at;

    if (x == 0)
      number_at = row1[y];
    if (x == 1)
      number_at = row2[y];
    if (x == 2)
      number_at = row3[y];
    return number_at;
  }

  T diagonal_sum() {
    T summ;

    summ = row1[0] + row2[1] + row3[2];

    return summ;
  }

  T sum() { return row1[0] + row1[1] + row1[2] + row2[0] + row2[1] + row2[2] + row3[0] + row3[1] + row3[2];}

  void print() {
    std::cout << at(0, 0) << "\n"
              << at(2, 2) << "\n"
              << diagonal_sum() << "\n"
              << sum() << "\n";
  }

private:
  std::array<T, 3> row1;
  std::array<T, 3> row2;
  std::array<T, 3> row3;
};

int main() {
  { // usage for type 'int'
    std::array<int, 3> row1 = {1, 2, 3};
    std::array<int, 3> row2 = {4, 5, 6};
    std::array<int, 3> row3 = {7, 8, 9};
    Matrix<int> mat(row1, row2, row3); // constructor
    assert(mat.at(0, 0) == 1);
    assert(mat.at(2, 2) == 9);
    assert(mat.diagonal_sum() == 15);
    assert(mat.sum() == 45);
    mat.print();
  }
  { // usage for type 'float'
    std::array<float, 3> row1 = {1, 2, 3};
    std::array<float, 3> row2 = {4, 5, 6};
    std::array<float, 3> row3 = {7, 8, 9};
    Matrix<float> mat(row1, row2, row3); // constructor
    assert(std::abs(mat.at(0, 0) - 1) < 1e-5);
    assert(std::abs(mat.at(2, 2) - 9) < 1e-5);
    assert(std::abs(mat.diagonal_sum() - 15) < 1e-5);
    assert(std::abs(mat.sum() - 45) < 1e-5);
    mat.print();
  }
}
