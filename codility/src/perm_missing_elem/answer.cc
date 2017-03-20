/*
 * Codility - Find the missing element in a given permutation
 *
 * Lesson: 3 (Time Complexity)
 * Problem code: PermMissingElem
 */

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

// @include
// O(n) time, O(1) space
int missing_element(vector<int> A) {
  int sum = accumulate(A.begin(), A.end(), 0);
  return ((A.size() + 1) * (A.size() + 2)) / 2 - sum;
}

// O(n) time, O(1) space
int missing_element_xor(vector<int> A) {
  int xor_input = A[0];
  for (unsigned int i = 1; i < A.size(); i++) xor_input = xor_input ^ A[i];
  int xor_all = 1;
  for (unsigned int i = 2; i <= A.size() + 1; i++) xor_all = xor_all ^ i;
  return xor_input ^ xor_all;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> A = {1, 2, 3, 4, 5, 7, 8, 9};
  cout << missing_element(A) << endl;
  cout << missing_element_xor(A) << endl;
  return 0;
}
