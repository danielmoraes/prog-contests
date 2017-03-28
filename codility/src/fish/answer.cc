/*
 * Codility - N voracious fish are moving along a river. Calculate how many fish are alive.
 *
 * Lesson: 7 (Stacks and Queues)
 * Problem code: Fish
 */

#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

// @include
int fishes_alive(const vector<int>& A, const vector<int>& B) {
  int result = 0;
  stack<int> downstream;
  for (int i = 0; i < A.size(); ++i) {
    if (B[i] == 1) {  // going downstream
      downstream.push(A[i]);
      result++;
    } else {  // going upstream
      while (!downstream.empty() && downstream.top() < A[i]) {
        downstream.pop(), result--;
      }
      if (downstream.empty()) {
        result++;
      }
    }
  }
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> A = {4, 3, 2, 1, 5};
  vector<int> B = {0, 1, 0, 0, 0};
  cout << fishes_alive(A, B) << endl;
  return 0;
}
