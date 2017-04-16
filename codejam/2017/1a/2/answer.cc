/*
 *
 * CodeJam 2017 - Round 1A
 * Problem 3
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    printf("Case #%d:\n", i);

    int hd, ad, hk, ak, b, d;
    cin >> hd >> ad >> hk >> ak >> b >> d;

    int c_hd = hd, c_hk = hk;

    int rounds = 0;
    while (c_hk > 0) {
      cout << c_hk << " " << c_hd << endl;
      if (c_hd <= 0) break;

      int rounds_to_lose = ceil(c_hd / (double) ak);
      int rounds_to_lose_d = ceil(c_hd / (double) max(ak - d, 0) - 1);
      int rounds_to_lose_h = ceil(hd / (double) ak);
      int rounds_to_win = ceil(c_hk / (double) ad);
      int rounds_to_win_b = ceil(c_hk / (double) (ad + b)) + 1;

      cout << rounds_to_lose << endl;
      cout << rounds_to_lose_d << endl;
      cout << rounds_to_lose_h << endl;
      cout << rounds_to_win << endl;
      cout << rounds_to_win_b << endl;

      if (rounds_to_lose < rounds_to_win) {
        exit(0);
        if (rounds_to_lose_d >= rounds_to_lose_h) {
          cout << "D" << endl;
          rounds_to_lose = rounds_to_lose_d;
          ak = max(ak - d, 0);
          rounds++;
          continue;
        } else {
          cout << "HEAL" << endl;
          rounds_to_lose = rounds_to_lose_h;
          c_hd = hd;
          rounds++;
          continue;
        }
      }

      if (rounds_to_win_b < rounds_to_win) {
        cout << "B" << endl;
        ad += b;
        rounds++;
        continue;
      }

      cout << "ATTACK" << endl;

      c_hk -= ad;
      c_hd -= ak;
      rounds++;
    }

    if (c_hk <= 0) {
      cout << rounds << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  return 0;
}
