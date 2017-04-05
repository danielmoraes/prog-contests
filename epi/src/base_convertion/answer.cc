/*
 *
 * EPI
 * Base Convertion (7.2)
 *
 */

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// @include
string base_convertion(const string& s, int b1, int b2) {
  bool is_negative = s.front() == '-';

  int decimal = 0;
  for (unsigned int i = (is_negative == true ? 1 : 0); i < s.size(); ++i) {
    decimal = decimal * b1 + (isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10);
  }

  string result;
  do {
    int digit = decimal % b2;
    result.push_back(digit < 10 ? digit + '0' : digit + 'A' - 10);
    decimal /= b2;
  } while (decimal);

  if (is_negative) result.push_back('-');

  return {result.rbegin(), result.rend()};
}
// @exclude

int main(int argc, char* argv[]) {
  cout << base_convertion("615", 7, 13) << endl;
  cout << base_convertion("1A7", 13, 7) << endl;
  return 0;
}
