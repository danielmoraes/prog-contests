/*
 * Codility - Cover "Manhattan skyline" using the minimum number of rectangles.
 *
 * Lesson: 7 (Stacks and Queues)
 * Problem code: StoneWall
 */

#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

// @include
int blocks_needed(vector<int> &H) {
  int blocks = 0;
  stack<int> st;
  for (unsigned int i = 0; i < H.size(); ++i) {
    while (!st.empty() && st.top() > H[i]) {
      st.pop();
    }
    if (st.empty() || st.top() < H[i]) {
      st.push(H[i]);
      blocks++;
    }
  }
  return blocks;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> v = {8, 8, 5, 7, 9, 8, 7, 4, 8};
  cout << blocks_needed(v) << endl;
  return 0;
}
