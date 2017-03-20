/*
 * Codility - Calculate the values of counters after applying all alternating operations:
 *   increase counter by 1;
 *   set value of all counters to current maximum.
 *
 * Lesson: 4 (Counting Elements)
 * Problem code: MaxCounters
 */

#include <vector>
#include <iostream>

using namespace std;

// @include
vector<int> max_counters(const vector<int>& A, int n) {
  int max_counter = 0, min_counter = 0;
  vector<int> counters(n, 0);
  for (unsigned int i = 0; i < A.size(); ++i) {
    if (A[i] > 0 && A[i] <= n) {  // increase
      counters[A[i] - 1] = max(min_counter, counters[A[i] - 1]) + 1;
      max_counter = max(max_counter, counters[A[i] - 1]);
    } else { // max_counter
      min_counter = max_counter;
    }
  }
  for (int i = 0; i < n; ++i) {
    counters[i] = max(min_counter, counters[i]);
  }
  return counters;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {3, 4, 4, 6, 1, 4, 4};
  vector<int> counters = max_counters(a, 5);
  for (auto c: counters) cout << c << " ";
  cout << endl;
  return 0;
}
