/*
 *
 * EPI
 * Test Palindromicity (7.5)
 *
 */

#include <string>
#include <locale>
#include <cctype>
#include <iostream>

using namespace std;

// @include
// O(n) time; O(1) space
bool is_palindromic_a(const string& s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    while (!isalnum(s[i]) && i < j) ++i;
    while (!isalnum(s[j]) && i < j) --j;
    if (tolower(s[i]) != tolower(s[j])) {
      return false;
    }
    ++i;
    --j;
  }
  return true;
}

// O(n) time; O(n) space
bool is_palindromic_b(string s) {
  int write_idx = 0;
  for (unsigned int i = 0; i < s.size(); ++i) {
    if (isalnum(s[i])) s[write_idx++] = tolower(s[i]);
  }
  for (int i = 0; i < write_idx / 2; ++i) {
    if (s[i] != s[write_idx - 1 - i]) {
      return false;
    }
  }
  return true;
}
// @exclude

int main(int argc, char* argv[]) {
  string s1 = "A man, a plan, a canal, Panama.";
  string s2 = "Able was I, ere I saw Elba!";
  string s3 = "Ray a Ray";

  cout << is_palindromic_a(s1) << endl;
  cout << is_palindromic_a(s2) << endl;
  cout << is_palindromic_a(s3) << endl;

  cout << is_palindromic_b(s1) << endl;
  cout << is_palindromic_b(s2) << endl;
  cout << is_palindromic_b(s3) << endl;
  return 0;
}
