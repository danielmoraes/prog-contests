/*
 *
 * CodeJam 2017 - Qualification Round
 * Problem 4
 *
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Model {
  char model;
  int row, col;
};

bool can_be_x(int row, int col, const vector<vector<char>>& grid) {
  int n = grid.size();
  // check if only share row with + models
  for (int c = 0; c < n; ++c) {
    if (c == col) continue;
    if (grid[row][c] == 'x' || grid[row][c] == 'o') {
      return false;
    }
  }

  // check if only share col with + models
  for (int r = 0; r < n; ++r) {
    if (r == row) continue;
    if (grid[r][col] == 'x' || grid[r][col] == 'o') {
      return false;
    }
  }

  return true;
}

bool can_be_p(int row, int col, const vector<vector<char>>& grid) {
  int n = grid.size();
  // check if only share diagonal with x models
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (r + c != row + col && r - c != row - col) continue;
      if (r == row && c == col) continue;
      if (grid[r][c] == '+' || grid[r][c] == 'o') {
        return false;
      }
    }
  }

  return true;
}

vector<Model> optimize(vector<vector<char>>& grid) {
  int n = grid.size();
  vector<Model> models;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      int cr, cc;
      if (r % 2 == 0) { cr = r / 2; } else { cr = n - ceil(r / 2.0); }
      if (c % 2 == 0) { cc = c / 2; } else { cc = n - ceil(c / 2.0); }
      switch (grid[cr][cc]) {
        case '.': {
          bool x = can_be_x(cr, cc, grid);
          bool p = can_be_p(cr, cc, grid);
          if (x && p) {
            grid[cr][cc] = 'o';
            models.push_back({'o', cr, cc});
          } else if (x) {
            grid[cr][cc] = 'x';
            models.push_back({'x', cr, cc});
          } else if (p) {
            grid[cr][cc] = '+';
            models.push_back({'+', cr, cc});
          }
          break;
        }
        case 'x': {
          bool p = can_be_p(cr, cc, grid);
          if (p) {
            grid[cr][cc] = 'o';
            models.push_back({'o', cr, cc});
          }
          break;
        }
        case '+': {
          bool x = can_be_x(cr, cc, grid);
          if (x) {
            grid[cr][cc] = 'o';
            models.push_back({'o', cr, cc});
          }
          break;
        }
      }
    }
  }
  return models;
}

int count_points(const vector<vector<char>>& grid) {
  int points = 0;
  for (int r = 0; r < grid.size(); ++r) {
    for (int c = 0; c < grid.size(); ++c) {
      if (grid[r][c] == 'o') {
        points += 2;
      } else if (grid[r][c] == 'x' || grid[r][c] == '+') {
        points += 1;
      }
    }
  }
  return points;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(n, '.'));

    // fill grid with initial models
    for (int j = 0; j < m; ++j) {
      char model;
      cin >> model;
      int row, col;
      cin >> row >> col;
      grid[row - 1][col - 1] = model;
    }

    // the new added models
    vector<Model> models = optimize(grid);

    // score of the grid
    int points = count_points(grid);

    printf("Case #%d: %d %d\n", i, points, models.size());

    for (int j = 0; j < models.size(); ++j) {
      cout << models[j].model << " "
           << models[j].row + 1 << " "
           << models[j].col + 1 << endl;
    }
  }

  return 0;
}
