/*
 *
 * EPI
 * Compute a Random Permutation (6.13)
 *
 */

#include <utils.h>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// @include
vector<int> random_permutation(int n) {
  vector<int> s(n);
  iota(s.begin(), s.end(), 0);
  default_random_engine seed((random_device())());  // random number generator
  for (int i = 0; i < n - 1; ++i) {
    int idx = uniform_int_distribution<int>{i, n - 1}(seed);
    swap(s[i], s[idx]);
  }
  return s;
}
// @exclude

int main(int argc, char* argv[]) {
  print_vector(random_sample(10));
  return 0;
}
