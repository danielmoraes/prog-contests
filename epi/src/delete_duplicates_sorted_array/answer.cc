/*
 *
 * EPI
 * Delete Duplicates From a Sorted Array (6.5)
 *
 */

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

void print_vector(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int delete_duplicates(vector<int>& vec) {
  int last_empty_index = 1;
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i] != vec[i - 1]) {
      vec[last_empty_index++] = vec[i];
    }
  }
  for (int i = last_empty_index; i < vec.size(); i++) {
    vec[i] = 0;
  }
  return last_empty_index;
}

int main() {
  vector<int> v1 {2, 3, 5, 5, 7, 11, 11, 11, 13};
  delete_duplicates(v1);
  print_vector(v1);
  return 0;
}
