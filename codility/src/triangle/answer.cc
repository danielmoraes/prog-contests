/*
 * Codility: Determine whether a triangle can be built from a given set of edges.
 *
 * Lesson: 6 (Sorting)
 * Problem code: Triangle
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// @include
int has_triangle(vector<int>& v) {
  if (v.size() < 3u) return 0;
  sort(v.begin(), v.end());
  for (int i = 2; i < v.size(); ++i) {
    const long sum = v[i - 2] + v[i - 1];
    if (sum > v[i]) {
      return 1;
    }
  }
  return 0;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v1 = {10, 2, 5, 1, 8, 20};
  cout << has_triangle(v1) << endl;

  vector<int> v2 = {10, 50, 5, 1};
  cout << has_triangle(v2) << endl;
  return 0;
}
