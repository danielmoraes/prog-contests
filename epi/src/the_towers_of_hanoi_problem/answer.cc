/*
 *
 * EPI
 * The Towers of Hanoi Problem (16.1)
 *
 */

#include <array>
#include <iostream>
#include <stack>

using std::array;
using std::cout;
using std::endl;
using std::stack;

// @include
const int NUM_PEGS = 3;

void move(int num_rings_to_move, array<stack<int>, NUM_PEGS>& pegs,
          int from, int to, int use) {
  if (num_rings_to_move == 0) return;

  move(num_rings_to_move - 1, pegs, from, use, to);

  pegs[to].push(pegs[from].top());
  pegs[from].pop();

  cout << "from " << from << " to " << to << endl;

  move(num_rings_to_move - 1, pegs, use, to, from);
}

void hanoi_moves(int num_rings) {
  array<stack<int>, NUM_PEGS> pegs;
  for (int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }
  move(num_rings, pegs, 0, 1, 2);
}
// @exclude

int main(int argc, char* argv[]) {
  hanoi_moves(3);
  return 0;
}
