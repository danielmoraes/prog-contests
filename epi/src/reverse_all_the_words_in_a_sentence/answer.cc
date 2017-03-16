/*
 *
 * EPI
 * Reverse All the Words in a Sentence (7.6)
 *
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// @include
void reverse_words(string& s) {
  reverse(s.begin(), s.end());
  int j = s.size();
  for (int i = j; i >= 0; --i) {
    if (i == 0 || s[i - 1] == ' ') {
      if (j - i >= 2) reverse(s.begin() + i, s.begin() + j);
      j = i - 1;
    }
  }
}
// @exclude

int main(int argc, char* argv[]) {
  string s = "Bob likes Alice";
  reverse_words(s);
  cout << s << endl;
  return 0;
}
