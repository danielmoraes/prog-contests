/*
 *
 * EPI
 * Interconvert Strings and Integers (7.1)
 *
 */

#include <string>
#include <iostream>

using namespace std;

// @include
int string_to_integer(const string& s) {
  int n = 0;
  for (unsigned int i = s.front() == '-' ? 1 : 0; i < s.size(); ++i) {
    n = n * 10 + (s[i] - '0');
  }
  return s.front() == '-' ? -n : n;
}

string integer_to_string(int n) {
  bool is_negative = n < 0;

  string s;
  do {
    s.push_back('0' + abs(n % 10));
    n /= 10;
  } while (n);

  if (is_negative) {
    s.push_back('-');
  }

  return {s.rbegin(), s.rend()};
}
// @exclude

int main(int argc, char* argv[]) {
  cout << integer_to_string(0) << endl;
  cout << integer_to_string(-10) << endl;
  cout << integer_to_string(100) << endl;

  cout << string_to_integer("0") << endl;
  cout << string_to_integer("-10") << endl;
  cout << string_to_integer("100") << endl;
  return 0;
}
