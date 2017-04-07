/*
 *
 * CodeJam 2016 - Qualification Round
 * Problem 2
 *
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int flip(int end, string& s) {
  for (int i = 0; i < end; ++i) {
    s[i] = (s[i] == '-') ? '+' : '-';
  }
}

int num_flips(string s) {
  int n = s.size(), count = 0;
  while (true) {
    int e;
    if (s[0] == '+') {
      e = s.find('-');
      if (e == string::npos) break;
    } else {
      e = s.find('+');
      if (e == string::npos) e = n;
    }
    flip(e, s);
    count++;
  }
  return count;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    string s;
    cin >> s;
    printf("Case #%d: ", i);
    cout << num_flips(s) << endl;
  }

  return 0;
}
