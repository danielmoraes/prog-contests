/*
 *
 * EPI
 * Compute a Random Subset (6.14)
 *
 */

#include <utils.h>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

// @include

// O(k)
vector<int> random_subset_hash(int n, int k, default_random_engine seed) {
  vector<int> sample(k);
  unordered_map<int, int> map;  // swapped elements
  for (int i = 0; i < k; ++i) {
    int j = uniform_int_distribution<int>{i, n - 1}(seed);
    if (i == j) {
      sample[i] = i;
    } else {
      sample[i] = (map.find(j) != map.end()) ? map[j] : j;
      map[j] = (map.find(i) != map.end()) ? map[i] : i;
    }
  }
  return sample;
}

// O(n)
vector<int> random_subset(int n, int k, default_random_engine seed) {
  vector<int> sample(n);
  iota(sample.begin(), sample.end(), 0);
  for (int i = 0; i < k; ++i) {
    int idx = uniform_int_distribution<int>{i, n - 1}(seed);
    swap(sample[i], sample[idx]);
  }
  sample.resize(k);
  return sample;
}

// @exclude

int main(int argc, char* argv[]) {
  int n = 1000, k = 10;
  default_random_engine seed((random_device())());  // random number generator
  print_vector(random_subset(n, k, seed));
  print_vector(random_subset_hash(n, k, seed));
  return 0;
}
