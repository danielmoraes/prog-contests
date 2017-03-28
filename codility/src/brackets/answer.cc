/*
 * Codility - Determine whether a given string of parentheses is properly nested.
 *
 * Lesson: 7 (Stacks and Queues)
 * Problem code: Brackets
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unordered_map;

// @include
char is_open_bracket(char c) {
  return c == '{' || c == '[' || c == '(';
}

int is_string_properly_nested(const string &S) {
  unordered_map<char, char> m = {{'}', '{'}, {']', '['}, {')', '('}};
  stack<char> st;
  for (unsigned int i = 0; i < S.size(); ++i) {
    if (is_open_bracket(S[i])) {
      st.push(S[i]);
    } else {
      if (st.empty() || m[S[i]] != st.top()) {
        return 0;
      }
      st.pop();
    }
  }
  return st.empty() ? 1 : 0;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << is_string_properly_nested("{[()()]}") << endl;
  cout << is_string_properly_nested("{[()()]") << endl;
  return 0;
}
