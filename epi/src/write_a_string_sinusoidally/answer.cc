/*
 *
 * EPI
 * Write a String Sinusoidally (7.11)
 *
 */

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// @include
string snakestring(const string& s) {
  string result;
  for (int i = 1; i < s.length(); i += 4) result += s[i];  // first row
  for (int i = 0; i < s.length(); i += 2) result += s[i];  // second row
  for (int i = 3; i < s.length(); i += 4) result += s[i];  // third row
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << snakestring("Hello World!") << endl;
  return 0;
}
