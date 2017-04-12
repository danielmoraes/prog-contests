/*
 *
 * EPI
 * Is an Anonymous Letter Constructible? (13.2)
 *
 */

#include <cassert>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// @include
bool is_constructible(const string& letter, const string& magazine) {
  unordered_map<char, int> m;
  for (auto c : magazine) {
    m[c]++;
  }
  for (auto c : letter) {
    if (m[c] == 0) {
      return false;
    }
    m[c]--;
  }
  return true;
}
// @exclude

int main(int argc, char* argv[]) {
  assert(is_constructible("abcd", "badc") == true);
  assert(is_constructible("aabb", "aabc") == false);
  return 0;
}
