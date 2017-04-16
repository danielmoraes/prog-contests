/*
 *
 * CodeJam 2017 - Round 1A
 * Problem 2
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Range {
  bool operator<(const Range& that) const {
    if (l == that.l) {
      return u < that.u;
    } else {
      return l < that.l;
    }
  }
  int l, u;
  bool used = false;
};

int solve_greedy() {
  int n, p;
  cin >> n >> p;

  vector<int> ingredients(n);
  for (int i = 0; i < n; ++i) {
    cin >> ingredients[i];
  }

  vector<vector<Range>> ranges(n);
  for (int i = 0; i < n; ++i) {
    int r = ingredients[i];
    for (int j = 0; j < p; ++j) {
      int q;
      cin >> q;

      int dd = 10 * q, ds;  // dividend and divisor

      ds = 11 * r;
      int l = (dd + ds - 1) / ds;  // integer ceiling
      ds = 9 * r;
      int u = dd / ds;  // integer floor

      if (l <= u) {
        ranges[i].push_back({l, u});
      }
    }
    sort(ranges[i].begin(), ranges[i].end());
  }

  int result = 0;

  for (int i = 0; i < ranges[0].size(); ++i) {
    vector<int> kit(n, -1);

    kit[0] = i;

    bool valid_kit = false;;
    for (int m = ranges[0][i].l; m <= ranges[0][i].u && !valid_kit; ++m) {
      valid_kit = true;
      for (int j = 1; j < ranges.size() && valid_kit; ++j) {
        for (int k = 0; k < ranges[j].size() && ranges[j][k].l <= m; ++k) {
          if (ranges[j][k].u < m || ranges[j][k].used) continue;
          if (kit[j] == -1 || ranges[j][k].u < ranges[j][kit[j]].u) {
            kit[j] = k;
          }
        }
        if (kit[j] == -1) {
          valid_kit = false;
        }
      }
    }

    if (valid_kit) {
      result++;
      for (int j = 0; j < ranges.size(); ++j) {
        ranges[j][kit[j]].used = true;
      }
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: %d\n", i, solve_greedy());
  }

  return 0;
}
