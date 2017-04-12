/*
 *
 * EPI
 * Compute the Intersection of Two Sorted Arrays (14.1)
 *
 */

#include <algorithm>
#include <utils.h>
#include <vector>

using std::binary_search;
using std::vector;

// @include
// O(n + m)
vector<int> intersect_two_sorted_arrays_a(const vector<int>& a,
                                          const vector<int>& b) {
  vector<int> result;
  auto it_a = a.begin(), it_b = b.begin();
  while (it_a != a.end() && it_b != b.end()) {
    if (*it_a < *it_b) {
      it_a++;
    } else if (*it_b < *it_a) {
      it_b++;
    } else {
      int v = *it_a;
      result.push_back(v);
      do {
        it_a++;
      } while (it_a != a.end() && *it_a == v);
      do {
        it_b++;
      } while (it_b != b.end() && *it_b == v);
    }
  }
  return result;
}

// O(n lg m)
vector<int> intersect_two_sorted_arrays_b(const vector<int>& a,
                                          const vector<int>& b) {
  vector<int> result;
  for (unsigned int i = 0; i < a.size(); ++i) {
    if ((i == 0 || a[i] > a[i - 1]) &&
        binary_search(b.begin(), b.end(), a[i])) {
      result.push_back(a[i]);
    }
  }
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> b = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  print_vector(intersect_two_sorted_arrays_a(a, b));
  print_vector(intersect_two_sorted_arrays_b(a, b));
  return 0;
}
