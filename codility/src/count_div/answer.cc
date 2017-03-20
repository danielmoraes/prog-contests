/*
 * Codility - Compute number of integers divisible by k in range [a..b].
 *
 * Lesson: 5 (PrefixSums)
 * Problem code: CountDiv
 */

#include <iostream>

using namespace std;

// @include
int count_div(int A, int B, int K) {
  int up_to_b = B / K + 1, up_to_a = (A - 1) / K + 1;
  return up_to_b - up_to_a;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << count_div(6, 11, 2) << endl;
  return 0;
}
