/*
 *
 * EPI
 * The Sudoku Checker Problem (6.16)
 *
 */

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

// @include
bool has_duplicate(vector<vector<int>>& game,
                   int row_s, int row_e, int col_s, int col_e) {
  vector<bool> is_present(game.size() + 1, false);
  for (int i = row_s; i < row_e; ++i) {
    for (int j = col_s; j < col_e; ++j) {
      if (game[i][j] != 0 && is_present[game[i][j]]) {
        return true;
      }
      is_present[game[i][j]] = true;
    }
  }
  return false;
}

bool is_valid_sudoku(vector<vector<int>>& game) {
  int rows = game.size();
  int cols = game[0].size();

  for (int i = 0; i < rows; ++i) {
    if (has_duplicate(game, i, i + 1, 0, cols)) {
      return false;
    }
  }

  for (int j = 0; j < cols; ++j) {
    if (has_duplicate(game, 0, rows, j, j + 1)) {
      return false;
    }
  }

  int region_rows = sqrt(rows);
  int region_cols = sqrt(cols);
  for (int i = 0; i < region_rows; ++i) {
    for (int j = 0; j < region_cols; ++j) {
      if (has_duplicate(game, i * region_rows, (i + 1) * region_rows,
                        j * region_cols, (j + 1) * region_cols)) {
        return false;
      }
    }
  }

  return true;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<vector<int>> game(9, vector<int>(9));
  game[0] = {0, 2, 6, 0, 0, 0, 8, 1, 0};
  game[1] = {3, 0, 0, 7, 0, 8, 0, 0, 6};
  game[2] = {4, 0, 0, 0, 5, 0, 0, 0, 7};
  game[3] = {0, 5, 0, 1, 0, 7, 0, 9, 0};
  game[4] = {0, 0, 3, 9, 0, 5, 1, 0, 0};
  game[5] = {0, 4, 0, 3, 0, 2, 0, 5, 0};
  game[6] = {1, 0, 0, 0, 3, 0, 0, 0, 2};
  game[7] = {5, 0, 0, 2, 0, 4, 0, 0, 9};
  game[8] = {0, 3, 8, 0, 0, 0, 4, 6, 0};
  cout << is_valid_sudoku(game) << endl;
  game[0] = {4, 2, 6, 0, 0, 0, 8, 1, 0};
  cout << is_valid_sudoku(game) << endl;
  return 0;
}
