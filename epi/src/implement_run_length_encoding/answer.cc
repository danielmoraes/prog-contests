/*
 *
 * EPI
 * Implement Run-Length Encoding (7.12)
 *
 */

#include <string>
#include <cassert>

using std::string;
using std::to_string;

// @include
string encode(const string& s) {
  string result;
  for (int i = 0; i < s.length(); ++i) {
    int count = 1;
    while (i < s.length() && s[i] == s[i + 1]) {
      i++; count++;
    }
    result += to_string(count) + s[i];
  }
  return result;
}

string decode(const string& s) {
  string result;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isdigit(s[i])) {
      count = (count * 10) + s[i] - '0';
    } else {
      result.append(count, s[i]);
      count = 0;
    }
  }
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  string s1 = "aaaabcccaa";
  assert(decode(encode(s1)) == s1);
  string s2 = "3e4f2e";
  assert(encode(decode(s2)) == s2);
  return 0;
}
