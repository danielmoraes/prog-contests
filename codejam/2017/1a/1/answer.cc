/*
 *
 * CodeJam 2017 - Round 1A
 * Problem 1
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Letter {
  char l;
  int r, c;
};

void solve_recursive_subproblem(int s_row, int e_row, int s_col, int e_col,
                                vector<string>& cake) {
  vector<Letter> letters;
  for (int i = s_row; i < e_row; ++i) {
    for (int j = s_col; j < e_col; ++j) {
      if (cake[i][j] != '?') {
        letters.push_back({cake[i][j], i, j});
      }
    }
  }

  if (letters.size() == 1) {
    for (int i = s_row; i < e_row; ++i) {
      for (int j = s_col; j < e_col; ++j) {
        cake[i][j] = letters.front().l;
      }
    }
  } else {
    int lm = (letters.size() - 1) / 2;
    if (letters[lm].r == letters[lm + 1].r) {
      solve_recursive_subproblem(s_row, e_row, s_col, letters[lm].c + 1, cake);
      solve_recursive_subproblem(s_row, e_row, letters[lm].c + 1, e_col, cake);
    } else {
      solve_recursive_subproblem(s_row, letters[lm].r + 1, s_col, e_col, cake);
      solve_recursive_subproblem(letters[lm].r + 1, e_row, s_col, e_col, cake);
    }
  }
}

void solve_recursive() {
  int r, c;
  cin >> r >> c;

  vector<string> cake(r);
  for (int i = 0; i < r; ++i) {
    cin >> cake[i];
  }

  solve_recursive_subproblem(0, r, 0, c, cake);

  for (int i = 0; i < r; ++i) {
    cout << cake[i] << endl;
  }
}

void solve_greedy() {
  int r, c;
  cin >> r >> c;

  vector<string> cake(r);
  for (int i = 0; i < r; ++i) {
    cin >> cake[i];
  }

  for (int i = 1; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (cake[i][j] == '?') {
        cake[i][j] = cake[i - 1][j];
      }
    }
  }

  for (int i = r - 2; i >= 0; --i) {
    for (int j = 0; j < c; ++j) {
      if (cake[i][j] == '?') {
        cake[i][j] = cake[i + 1][j];
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 1; j < c; ++j) {
      if (cake[i][j] == '?') {
        cake[i][j] = cake[i][j - 1];
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = c - 2; j >= 0; --j) {
      if (cake[i][j] == '?') {
        cake[i][j] = cake[i][j + 1];
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    cout << cake[i] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d:\n", i);
    solve_recursive();
  }
  return 0;
}
