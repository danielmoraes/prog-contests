/*
 *
 * EPI
 * The Look-And-Say Problem (7.8)
 *
 */

#include <string>
#include <iostream>

using namespace std;

// @include
string next_number(const string& s) {
  string res;
  for (int i = 0; i < s.size(); i++) {
    int count = 1;
    while (i + 1 < s.size() && s[i] == s[i + 1]) {
      ++i, ++count;
    }
    res += to_string(count) + s[i];
  }
  return res;
}

string look_and_say(int n) {
  string number = "1";
  for (int i = 1; i < n; ++i) {
    number = next_number(number);
  }
  return number;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << look_and_say(8) << endl;
  return 0;
}
