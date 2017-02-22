/*
 *
 * EPI
 * Multiply Two Arbitrary-Precision Integers (6.3)
 *
 */

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void remove_leading_zeros(vector<int>& v) {
  int pos = v.size() - 1, leading_zeros = 0;
  while (pos >= 0 && v[pos] == 0) {
    leading_zeros++, pos--;
  }
  v.resize(v.size() - leading_zeros);
}

vector<int> multiply(vector<int>& v1, vector<int>& v2) {
  // store the signal of the resulting integer
  short sign = (v1.front() < 0 ^ v2.front() < 0) ? -1 : 1;

  v1.front() = abs(v1.front());
  v2.front() = abs(v2.front());

  // multiply the two integers
  vector<int> result(v1.size() + v2.size(), 0);
  for (int i = v1.size() - 1; i >= 0; i--) {
    for (int j = v2.size() - 1; j >= 0; j--) {
      int index = (v1.size() - 1 - i) + (v2.size() - 1 - j);
      result[index] += v1[i] * v2[j];
      result[index + 1] += result[index] / 10;
      result[index] %= 10;
    }
  }

  remove_leading_zeros(result);

  if (result.empty()) {
    return {0};
  }

  reverse(result.begin(), result.end());
  result.front() *= sign;

  return result;
}

int main() {
  vector<int> v1 = {1, 2, 9};
  vector<int> v2 = {9, 9, 9};
  print_vector(multiply(v1, v2));  // 128871

  vector<int> v3 = { 1, 0, 0};
  vector<int> v4 = {-1, 0, 0};
  print_vector(multiply(v3, v4));  // -10000

  vector<int> v5 = {9, 9, 9, 9};
  vector<int> v6 = {0, 0, 0};
  print_vector(multiply(v5, v6));  // 0
  return 0;
}
