/*
 * Codility - Find an index of an array such that its value occurs at more than
 *            half of indices in the array.
 *
 * Lesson: 8 (Leader)
 * Problem code: Dominator
 */

#include <cassert>
#include <leader.h>
#include <vector>

int main(int argc, char* argv[]) {
  vector<int> v = {3, 4, 3, 2, 3, -1, 3, 3};
  assert(v[find_leader(v)] == 3);
  return 0;
}
