/*
 * Codility - Compute the number of intersections in a sequence of discs.
 *
 * Lesson: 6 (Sorting)
 * Problem code: NumberOfDiscIntersections
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::upper_bound;

// @include
const int LIMIT = 10000000;

struct Interval { long s; long e; };

int disk_intersections(vector<int> &v) {
  vector<Interval> intervals;
  for (int i = 0; i < v.size(); ++i) {
    intervals.push_back({i - (long) v[i], i + (long) v[i]});
  }

  sort(intervals.begin(), intervals.end(),
       [](Interval& a, Interval& b) { return a.s < b.s; });

  int result = 0;
  for (int i = 0; i < v.size(); ++i) {
    auto it = upper_bound(
        intervals.begin() + i, intervals.end(), intervals[i].e,
        [](long a, Interval& b) { return a < b.s; });
    result += (it - intervals.begin()) - 1 - i;
    if (result > LIMIT) return -1;
  }

  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {1, 5, 2, 1, 4, 0};
  cout << disk_intersections(v) << endl;
  return 0;
}
