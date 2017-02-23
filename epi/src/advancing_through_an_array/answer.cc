/*
 *
 * EPI
 * Advancing Through an Array (6.4)
 *
 */

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

bool is_valid_game(const vector<int>& board) {
  int reachable_pos = 0;
  for (int i = 0; i < board.size(); i++) {
    if ( reachable_pos < i ) {
      return false;
    }
    reachable_pos = max(reachable_pos, i + board[i]);
  }
  return true;
}

int main() {
  vector<int> v1 {3, 3, 1, 0, 2, 0, 1};
  cout << is_valid_game(v1) << endl;

  vector<int> v2 {3, 2, 0, 0, 2, 0, 1};
  cout << is_valid_game(v2) << endl;

  vector<int> v3 {2, 4, 1, 1, 0, 2, 3};
  cout << is_valid_game(v3) << endl;

  vector<int> v4 {3, 0, 0, 2, 0, 0, 0};
  cout << is_valid_game(v4) << endl;

  vector<int> v5 {3, 0, 0, 3, 0, 0, 0};
  cout << is_valid_game(v5) << endl;
  return 0;
}
