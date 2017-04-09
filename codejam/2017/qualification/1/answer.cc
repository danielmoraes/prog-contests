/*
 *
 * CodeJam 2017 - Qualification Round
 * Problem 1
 *
 */

#include <iostream>
#include <string>

using namespace std;

void flip(int b, int e, string& s) {
  for (int i = b; i < e; ++i) {
    s[i] = (s[i] == '+') ? '-' : '+';
  }
}

int num_flips(string s, int k) {
  int n = s.size();
  int count = 0;
  for (int i = 0; i < n - k + 1; ++i) {
    if (s[i] == '-') {
      flip(i, i + k, s);
      count++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') {
      return -1;
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {

    string s;
    int k;
    cin >> s >> k;

    printf("Case #%d: ", i);

    int res = num_flips(s, k);

    if (res == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }

  return 0;
}
