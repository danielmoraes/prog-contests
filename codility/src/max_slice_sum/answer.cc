/*
 * Codility - Find a maximum sum of a compact subsequence of array elements.
 *
 * Lesson: 9 (Maximum Slice Problem)
 * Problem code: MaxSliceSum
 */

#include <cassert>
#include <math.h>
#include <vector>

using std::max;
using std::vector;

// @include
int maximum_slice_sum(const vector<int>& v) {
  int max_slice_sum = v[0], max_slice_sum_ending = v[0];
  for (unsigned int i = 1; i < v.size(); ++i) {
    max_slice_sum_ending = max(max_slice_sum_ending + v[i], v[i]);
    max_slice_sum = max(max_slice_sum, max_slice_sum_ending);
  }
  return max_slice_sum;
}
// @exclude

int main(int argc, char* argv[]) {
  assert(maximum_slice_sum({3, 2, -6, 4, 0}) == 5);
  return 0;
}
