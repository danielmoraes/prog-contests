/*
 * Codility - Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
 *
 * Lesson: 6 (Sorting)
 * Problem code: MaxProductOfThree
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::vector;

// @include
int max_product_of_three(vector<int> v) {
  int n = v.size();
  sort(v.begin(), v.end());
  return max(v[n - 1] * v[n - 2] * v[n - 3], v[0] * v[1] * v[n - 1]);
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {-3, 1, 2, -2, 5, 6};
  cout << max_product_of_three(v) << endl;
  return 0;
}
