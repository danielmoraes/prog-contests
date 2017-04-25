/*
 *
 * EPI
 * The 3-Sum Problem (18.4)
 *
 */

#include <algorithm>
#include <cassert>
#include <vector>

using std::sort;
using std::vector;

// @include
bool has_two_sum(const vector<int>& v, int t) {
  int i = 0, j = v.size() - 1;
  while (i <= j) {
    int s = v[i] + v[j];
    if (s < t) {
      i++;
    } else if (s > t) {
      j--;
    } else {
      return true;
    }
  }
  return false;
}

bool has_three_sum(vector<int> v, int t) {
  sort(v.begin(), v.end());
  for (unsigned int i = 0; i < v.size(); ++i) {
    if (has_two_sum(v, t - v[i])) {
      return true;
    }
  }
  return false;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {11, 2, 5, 7, 3};
  assert(has_three_sum(v, 21) == true);
  assert(has_three_sum(v, 22) == false);
  return 0;
}
