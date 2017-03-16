/*
 *
 * EPI
 * Replace and Remove (7.4)
 *
 */

#include <vector>
#include <stack>
#include <utils.h>

using namespace std;

// @include

// O(n) time; O(1) space
int replace_and_remove_a(vector<char>& v, int n) {
  int read_idx = 0, write_idx = 0, a_count = 0;
  while (read_idx < n) {
    if (v[read_idx] != 'b') {
      v[write_idx++] = v[read_idx];
      if (v[read_idx] == 'a') a_count++;
    }
    read_idx++;
  }
  int size = write_idx + a_count;
  read_idx = write_idx - 1;
  write_idx = size - 1;
  while (read_idx >= 0) {
    if (v[read_idx] == 'a') {
      v[write_idx--] = 'd';
      v[write_idx--] = 'd';
    } else {
      v[write_idx--] = v[read_idx];
    }
    read_idx--;
  }
  return size;
}

// O(n) time; O(n) space
int replace_and_remove_b(vector<char>& v, int n) {
  int size = n;

  // find b's
  stack<int> empty_indexes;
  for (int i = n - 1; i >= 0; --i) {
    if (v[i] == 'b') empty_indexes.emplace(i);
  }

  // replace a's by two d's; use b's spots or push to the end of the array
  for (int i = 0; i < n; ++i) {
    if (v[i] == 'a') {
      v[i] = 'd';
      if (empty_indexes.empty()) {
        v[size++] = 'd';
      } else {
        v[empty_indexes.top()] = 'd';
        empty_indexes.pop();
      }
    }
  }

  // replace remaining b's empty spots with the elements at the back
  while (!empty_indexes.empty()) {
    v[empty_indexes.top()] = v[--size];
    empty_indexes.pop();
  }

  return size;
}

// @exclude

int main(int argc, char* argv[]) {
  vector<char> a = {'a', 'c', 'd', 'b', 'b', 'c', 'a'};
  replace_and_remove_a(a, 7);
  print_vector(a);

  vector<char> b = {'a', 'b', 'a', 'c', '*'};
  replace_and_remove_a(b, 4);
  print_vector(b);

  vector<char> c = {'a', 'c', 'a', 'a', '*', '*', '*'};
  replace_and_remove_a(c, 4);
  print_vector(c);
  return 0;
}
