/*
 *
 * EPI
 * Implement a Stack with Max API (9.1)
 *
 */

#include <iostream>
#include <stack.h>
#include <stdexcept>

using std::cout;
using std::endl;
using std::length_error;

int main(int argc, char* argv[]) {
  Stack s;

  try {
    s.max();
  } catch (const length_error& e) {
    cout << e.what() << endl;
  }

  for (int i = 5; i < 10; ++i) s.push(i);
  cout << s.max() << endl;

  for (int i = 0; i < 5; ++i) s.push(i);
  cout << s.max() << endl;

  while (!s.empty()) {
    cout << s.max() << endl;
    s.pop();
  }

  try {
    s.pop();
  } catch (const length_error& e) {
    cout << e.what() << endl;
  }

  return 0;
}
