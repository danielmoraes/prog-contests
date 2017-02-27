/*
 *
 * EPI
 * Permute the Elements of an Array (6.9)
 *
 */

#include <utils.h>
#include <iostream>
#include <algorithm>

using namespace std;

void apply_permutation(vector<int>& v, vector<int>& p) {
  for (int i = 0; i < (v.size() - 1); i++) {
    while (i != p[i]) {
      swap(v[i], v[p[i]]);
      swap(p[i], p[p[i]]);
    }
  }
}

int main() {
  vector<int> v = {1, 2, 3, 4};
  vector<int> p = {3, 1, 2, 0};
  apply_permutation(v, p);
  print_vector(v);
  return 0;
}
