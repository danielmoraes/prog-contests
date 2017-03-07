/*
 *
 * EPI
 * Compute the Spiral Ordering of a Square Array (6.17)
 *
 */

#include <utils.h>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

// @include
void spiral_order_a_layer(const vector<vector<int>>& matrix, int layer,
                          vector<int>& spiral_ordering) {
  // corner case
  if (matrix.size() - (2 * layer) == 1) {
    spiral_ordering.push_back(matrix[layer][layer]);
    return;
  }

  int layer_s = layer;
  int layer_e = matrix.size() - 1 - layer;

  // add first n - 1 elements of the top row
  for (int j = layer_s; j < layer_e; ++j) {
    spiral_ordering.push_back(matrix[layer_s][j]);
  }

  // add first n - 1 elements of the last column
  for (int i = layer_s; i < layer_e; ++i) {
    spiral_ordering.push_back(matrix[i][layer_e]);
  }

  // add last n - 1 elements of the last row (in reverse order)
  for (int j = layer_e; j > layer_s; --j) {
    spiral_ordering.push_back(matrix[layer_e][j]);
  }

  // add last n - 1 elements of the first column (in reverse order)
  for (int i = layer_e; i > layer_s; --i) {
    spiral_ordering.push_back(matrix[i][layer_s]);
  }
}

vector<int> spiral_order_a(const vector<vector<int>>& matrix) {
  vector<int> spiral_ordering;
  int layers = ceil(matrix.size() / 2.0);
  for (int i = 0; i < layers; ++i) {
    spiral_order_a_layer(matrix, i, spiral_ordering);
  }
  return spiral_ordering;
}

vector<int> spiral_order_b(vector<vector<int>> matrix) {
  vector<int> spiral_ordering;
  int current_direction = 0, row = 0, col = 0;

  // directions offsets in (row, col) format
  array<array<int, 2>, 4> direction = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

  for (int i = 0; i < matrix.size() * matrix.size(); ++i) {
    spiral_ordering.push_back(matrix[row][col]);
    matrix[row][col] = 0;

    // finds the index of the next element
    int next_row = row + direction[current_direction][0];
    int next_col = col + direction[current_direction][1];
    if (next_row < 0 || next_row > matrix.size() - 1 ||
        next_col < 0 || next_col > matrix.size() - 1 ||
        matrix[next_row][next_col] == 0) {
      current_direction = (current_direction + 1) % 4;
      next_row = row + direction[current_direction][0];
      next_col = col + direction[current_direction][1];
    }

    row = next_row, col = next_col;
  }

  return spiral_ordering;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<vector<int>> a(3, vector<int>(3, 0));
  a[0] = {1, 2, 3};
  a[1] = {4, 5, 6};
  a[2] = {7, 8, 9};

  vector<vector<int>> b(4, vector<int>(4, 0));
  b[0] = {1, 2, 3, 4};
  b[1] = {5, 6, 7, 8};
  b[2] = {9, 10, 11, 12};
  b[3] = {13, 14, 15, 16};

  print_vector(spiral_order_a(a));
  print_vector(spiral_order_a(b));
  print_vector(spiral_order_b(a));
  print_vector(spiral_order_b(b));
  return 0;
}
