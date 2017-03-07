#ifndef EPI_UTILS_H_
#define EPI_UTILS_H_

#include <vector>
#include <iostream>

// @include

/*
 * I/O
 */

void print_array(int arr[], unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    if (i > 0) std::cout << " ";
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

template<typename T>
void print_vector(const std::vector<T>& v) {
  for (unsigned int i = 0; i < v.size(); i++) {
    if (i > 0) std::cout << " ";
    std::cout << v[i];
  }
  std::cout << std::endl;
}

template<typename T>
void print_matrix(const std::vector<std::vector<T>>& v) {
  for (unsigned int i = 0; i < v.size(); i++) {
    for (unsigned int j = 0; j < v[i].size(); j++) {
      if (j > 0) std::cout << "\t";
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }
}

// @exclude

#endif  // EPI_UTILS_H_
