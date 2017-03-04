/*
 *
 * EPI
 * Generate NonUniform Random values (6.15)
 *
 */

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

// @include

// O(lg n)
int nonuniform_random_binary_search(const vector<int>& values,
                                    const vector<double>& cum_probs,
                                    default_random_engine seed) {
  double r = generate_canonical<double, numeric_limits<double>::digits>(seed);
  return values[distance(cum_probs.cbegin(),
                         upper_bound(cum_probs.cbegin(), cum_probs.cend(), r))];
}

// O(n)
vector<double> compute_cumulative_probabilities(const vector<float>& pd) {
  vector<double> cp;
  partial_sum(pd.cbegin(), pd.cend(), back_inserter(cp));
  return cp;
}

// O(n)
int nonuniform_random(const vector<int>& values,
                      const vector<float>& prob_dist,
                      default_random_engine seed) {
  double r = generate_canonical<double, numeric_limits<double>::digits>(seed);
  double acc = 0;
  for (int i = 0; i < values.size(); i++) {
    acc += prob_dist[i];
    if (r < acc) return values[i];
  }
}

// @exclude

int main(int argc, char* argv[]) {
  // random number generator
  default_random_engine seed((random_device())());

  // values
  vector<int> v = {3, 5, 7, 11};

  // probability distribution of v
  vector<float> v_prob_dist = {0.5, 0.25, 0.15, 0.10};

  cout << nonuniform_random(v, v_prob_dist, seed) << endl;

  // commulative probabilities of v_prob_dist
  vector<double> v_cum_probs = compute_cumulative_probabilities(v_prob_dist);

  cout << nonuniform_random_binary_search(v, v_cum_probs, seed) << endl;

  return 0;
}
