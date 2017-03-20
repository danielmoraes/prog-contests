/*
 * Codility - Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
 *
 * Lesson: 3 (Time Complexity)
 * Problem code: TapeEquilibrium
 */

#include <math.h>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// @include
int tape_equilibrium(vector<int> &v) {
  int lsum = v[0];
  int rsum = accumulate(v.begin() + 1, v.end(), 0);
  int min_diff = abs(lsum - rsum);
  for (unsigned int i = 1; i < v.size() - 1; i++) {
    lsum += v[i];
    rsum -= v[i];
    min_diff = min(min_diff, abs(lsum - rsum));
  }
  return min_diff;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {-10, -20, -30, -40, 100};
  cout << tape_equilibrium(a) << endl;
  return 0;
}
