/*
 *
 * EPI
 * Rotate a Square Array (6.18)
 *
 */

#include <utils.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @include
void rotate_square_matrix_layer(vector<vector<int>>& matrix, int layer) {
  int layer_s = layer;
  int layer_e = matrix.size() - 1 - layer;
  for (int i = 0; i < layer_e - layer_s; ++i) {
    swap(matrix[layer_s][layer_s + i], matrix[layer_s + i][layer_e]);
    swap(matrix[layer_s][layer_s + i], matrix[layer_e][layer_e - i]);
    swap(matrix[layer_s][layer_s + i], matrix[layer_e - i][layer_s]);
  }
}

void rotate_square_matrix(vector<vector<int>>& matrix) {
  int layers = matrix.size() / 2;
  for (int i = 0; i < layers; ++i) {
    rotate_square_matrix_layer(matrix, i);
  }
}
// @exclude

vector<vector<int>> square_matrix(int n) {
  vector<vector<int>> m(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = (i * n) + j + 1;
    }
  }
  return m;
}

int main(int argc, char* argv[]) {
  vector<vector<int>> m = square_matrix(4);

  print_matrix(m);
  rotate_square_matrix(m);

  cout << endl;
  print_matrix(m);

  return 0;
}
