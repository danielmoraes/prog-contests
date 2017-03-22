/*
 * Codility - Compute number of distinct values in an array.
 *
 * Lesson: 6 (Sorting)
 * Problem code: Distinct
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// @include
int distinct_count(vector<int> &v) {
  if (v.size() < 2) return v.size();
  sort(v.begin(), v.end());
  int result = 1;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] != v[i - 1]) result++;
  }
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {2, 1, 1, 2, 3, 1};
  cout << distinct_count(v) << endl;
  return 0;
}
