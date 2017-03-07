/*
 *
 * EPI
 * Compute Rows in Pascal's Triangle (6.19)
 *
 */

#include <utils.h>
#include <vector>

using namespace std;

// @include
vector<vector<int>> pascal_triangle(int rows) {
  vector<vector<int>> t;
  for (int i = 0; i < rows; ++i) {
    vector<int> row(i + 1);
    for (int j = 0; j < i + 1; ++j) {
      row[j] = (j == 0 || j == i) ? 1 : t.back()[j - 1] + t.back()[j];
    }
    t.push_back(row);
  }
  return t;
}
// @exclude

int main(int argc, char* argv[]) {
  print_matrix(pascal_triangle(10));
  return 0;
}
