/*
 * Codility - Find the index S such that the leaders of the sequences v[0],
 *            v[1], ..., v[S] and v[S + 1], v[S + 2], ..., v[N - 1] are the
 *            same.
 *
 * Lesson: 8 (Leader)
 * Problem code: EquiLeader
 */

#include <cassert>
#include <leader.h>
#include <vector>

using std::vector;

// @include
int equi_leaders_count(vector<int> &v) {
  int equi_leaders = 0;

  // O(n) time, O(1) space
  int leader = find_leader(v);

  int leader_count = 0;
  for (unsigned int i = 0; i < v.size(); ++i) {
    if (v[i] == v[leader]) {
      leader_count++;
    }
  }

  int total_l = 1, total_r = v.size() - 1;
  int leaders_l = 0, leaders_r = leader_count;

  for (unsigned int i = 0; i < v.size() - 1; ++i) {
    if (v[i] == v[leader]) {
      leaders_l++, leaders_r--;
    }
    if (leaders_l > (total_l  / 2.0) && leaders_r > (total_r / 2.0)) {
      equi_leaders++;
    }
    total_l++, total_r--;
  }
  return equi_leaders;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {4, 3, 4, 4, 4, 2};
  assert(equi_leaders_count(v) == 2);
  return 0;
}
