/*
 *
 * EPI
 * Sample Online Data (6.12)
 *
 */

#include <utils.h>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

string generate_online_data(int size) {
  vector<int> data(size);
  iota(data.begin(), data.end(), 0);
  std::stringstream ss;
  std::copy(data.begin(), data.end(), ostream_iterator<int>(ss, " "));
  return ss.str();
}

// @include
vector<int> online_sample(istringstream& sin, int k) {
  // if the sample size is zero, return an empty sample
  if (k < 1) return {};

  // random number generator
  default_random_engine seed((random_device())());

  int packet;

  // initialize the sample with the first k packets in the stream
  vector<int> sample(k);
  int num_packets_so_far = 0;
  while (num_packets_so_far < k && sin >> packet) {
    sample[num_packets_so_far++] = packet;
  }

  // the (m)th new packet is added to the sample with probability k/m
  while (sin >> packet) {
    ++num_packets_so_far;
    int idx = uniform_int_distribution<int>{0, num_packets_so_far - 1}(seed);
    if (idx < k) {
      sample[idx] = packet;
    }
  }

  sample.resize(min(num_packets_so_far, k));

  return sample;
}
// @exclude

int main(int argc, char* argv[]) {
  int n = 100, k = 10;
  istringstream data(generate_online_data(n));
  print_vector(online_sample(data, k));
  return 0;
}
