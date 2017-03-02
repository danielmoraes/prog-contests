/*
 *
 * EPI
 * Sample Offline Data (6.11)
 *
 */

#include <utils.h>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void sample(int sample_size, vector<int>& data) {
  int n = data.size();
  default_random_engine seed( ( random_device() )() );
  for (int i = 0; i < sample_size; i++) {
    int sorted_el = uniform_int_distribution<int>{i, n - 1}(seed);
    swap(data[i], data[sorted_el]);
  }
  data.resize(sample_size);
}

int main() {
  vector<int> data;

  data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  sample(5, data);
  print_vector(data);

  data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  sample(10, data);
  print_vector(data);

  data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  sample(15, data);
  print_vector(data);
  return 0;
}
