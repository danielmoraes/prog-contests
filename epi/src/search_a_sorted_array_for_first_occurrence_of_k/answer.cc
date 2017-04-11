/*
 *
 * EPI
 * Search a Sorted Array for First Occurrence of K (12.1)
 *
 */

#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// @include
int find_first(const vector<int>& v, int k) {
  int result = -1;
  int l = 0, u = v.size() - 1;
  while (l <= u) {
    int m = l + (u - l) / 2;
    if (v[m] > k) {
      u = m - 1;
    } else if (v[m] == k) {
      result = m;
      u = m - 1;
    } else if (v[m] < k) {
      l = m + 1;
    }
  }
  return result;
}

int find_first_stl(const vector<int>& v, int k) {
  auto lower = lower_bound(v.begin(), v.end(), k);
  if (lower == v.end() || *lower != k) return -1;
  return lower - v.begin();
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {1, 1, 1, 2, 3, 4, 5};

  assert(find_first(a, 3) == find_first_stl(a, 3));
  assert(find_first(a, 0) == find_first_stl(a, 0));
  assert(find_first(a, 6) == find_first_stl(a, 6));

  return 0;
}
