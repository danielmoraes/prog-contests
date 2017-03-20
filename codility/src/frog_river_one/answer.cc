/*
 * Codility - Find the earliest time when a frog can jump to the other side of a river.
 *
 * Lesson: 4 (Time Complexity)
 * Problem code: FrogRiverOne
 */

#include <vector>
#include <iostream>

using namespace std;

// @include
int frog_river(const vector<int>& A, int x) {
  vector<bool> has_leave(x, false);
  int positions_with_leave = 0;
  for (unsigned int i = 0; i < A.size(); i++) {
    if (has_leave[A[i] - 1] == false) {
      has_leave[A[i] - 1] = true;
      if (++positions_with_leave == x) return i;
    }
  }
  return -1;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {1, 3, 1, 4, 2, 3, 5, 4};
  cout << frog_river(a, 5) << endl;
  return 0;
}
