#ifndef CODILITY_LEADER_H_
#define CODILITY_LEADER_H_

#include <vector>

using std::vector;

// @include
// O(n) time, O(1) space
int find_leader(const vector<int> &v) {
  int candidate = 0, count = 1;
  for (unsigned int i = 1; i < v.size(); ++i) {
    if (v[i] == v[candidate]) {
      count++;
    } else {
      if (count == 0) {
        candidate = i;
        count = 1;
      } else {
        count--;
      }
    }
  }
  count = 0;
  for (unsigned int i = 0; i < v.size(); ++i) {
    if (v[i] == v[candidate]) {
      count++;
    }
  }
  return (count > (v.size() / 2.0)) ? candidate : -1;
}
// @exclude

#endif  // CODILITY_LEADER_H_
