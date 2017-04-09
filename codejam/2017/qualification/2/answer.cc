/*
 *
 * CodeJam 2017 - Qualification Round
 * Problem 2
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void tidy(string& s) {
  bool modified;
  do {
    modified = false;
    for (int i = 0; i < s.size() - 1; ++i) {
      int curr = s[i] - '0', next = s[i + 1] - '0';
      if (curr > next) {
        modified = true;
        s[i] = '0' + (curr - 1);
        for (int j = i + 1; j < s.size(); ++j) {
          s[j] = '9';
        }
        break;
      }
    }
  } while (modified);
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    string s;
    cin >> s;
    tidy(s);
    cout << "Case #" << i << ": " << stoll(s) << endl;
  }

  return 0;
}
