/*
 * Codility - Find the maximal sum of any double slice.
 *
 * Lesson: 9 (Maximum Slice Problem)
 * Problem code: MaxDoubleSliceSum
 */

#include <cassert>
#include <math.h>
#include <vector>

using std::max;
using std::vector;

// @include
int maximum_double_slice_sum(const vector<int>& v) {
  int n = v.size();

  vector<int> max_starting_i(n, 0);
  for (int i = n - 2; i > 0; i--) {
    max_starting_i[i] = max(max_starting_i[i + 1] + v[i], 0);
  }

  vector<int> max_ending_i(n, 0);
  for (int i = 1; i < n - 1; ++i) {
    max_ending_i[i] = max(max_ending_i[i - 1] + v[i], 0);
  }

  int max_sum = 0;
  for (int i = 1; i < n - 1; ++i) {
    max_sum = max(max_sum, max_ending_i[i - 1] + max_starting_i[i + 1]);
  }

  return max_sum;
}
// @exclude

int main(int argc, char* argv[]) {
  assert(maximum_double_slice_sum({3, 2, 6, -1, 4, 5, -1, 2}) == 17);
  return 0;
}
