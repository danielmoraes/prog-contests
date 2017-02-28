/*
 *
 * EPI
 * Compute the Next Permutation (6.10)
 *
 */

#include <utils.h>
#include <vector>
#include <algorithm>

using namespace std;

// O(n)
vector<int> next_permutation_linear(vector<int> p) {
  int n = p.size();

  // finds element `e` that appears just before the longest decreasing suffix
  int e = n - 2;
  while (e >= 0 && p[e] >= p[e + 1]) --e;

  // if the entire permutation is in decreasing order, there is no next
  if (e < 0) return {};

  // finds `s` and swap with `e`; it must be the smallest element within the
  // decreasing suffix that is greater than `e`
  int s = n - 1;
  while (p[e] >= p[s]) --s;
  swap(p[e], p[s]);

  // turn the suffix to increasing order, which is its smallest possible
  // permutation under dictionary ordering
  reverse(p.begin() + e + 1, p.end());

  return p;
}

// O(n^2)
vector<int> next_permutation(vector<int> p) {
  int n = p.size();
  for (int i = n - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (p[i] > p[j]) {
        swap(p[i], p[j]);
        reverse(p.begin() + j + 1, p.end());
        return p;
      }
    }
  }
  return {};
}

int main() {
  vector<int> p = {6, 2, 1, 5, 4, 3, 0};
  print_vector(p);
  print_vector(next_permutation(p));
  print_vector(next_permutation_linear(p));
  return 0;
}
