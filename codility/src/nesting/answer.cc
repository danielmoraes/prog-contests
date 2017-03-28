/*
 * Codility - Determine whether given string of parentheses is properly nested.
 *
 * Lesson: 7 (Stacks and Queues)
 * Problem code: Nesting
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// @include
int is_string_properly_nested(const string &S) {
  int level = 0;
  for (unsigned int i = 0; i < S.size(); ++i) {
    if (S[i] == '(') {
      level++;
    } else {
      level--;
      if (level < 0) return 0;
    }
  }
  return level == 0;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << is_string_properly_nested("(()())") << endl;
  cout << is_string_properly_nested("(()()") << endl;
  return 0;
}
