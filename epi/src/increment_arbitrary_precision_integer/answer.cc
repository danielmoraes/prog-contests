/*
 *
 * EPI
 * Increment an Arbitrary Precision Integer (6.2)
 *
 */

#include <iostream>
#include <vector>
#include <utils.h>

using namespace std;

void increment(vector<int>& v) {
  v.back()++;
  for (int i = v.size() - 1; i > 0 && v[i] == 10; i--) {
    v[i - 1]++;
    v[i] = 0;
  }
  if (v[0] == 10) {
    v[0] = 0;
    v.insert(v.begin(), 1);
  }
}

int main() {
  vector<int> v1 = {1, 2, 9};
  vector<int> v2 = {9, 9, 9};
  increment(v1);
  print_vector(v1);
  increment(v2);
  print_vector(v2);
  return 0;
}
