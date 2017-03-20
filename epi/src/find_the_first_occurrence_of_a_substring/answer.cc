/*
 *
 * EPI
 * Find the First Occurrence of a Substring (7.13)
 *
 */

#include <cassert>
#include <string>

using std::string;

// @include
// O(n^2) time, in which n is the length of t
size_t find_substr(const string& s, const string& t) {
  if (s.size() > t.size()) {
    return -1;
  }
  for (unsigned int i = 0; i < t.length() - s.length() + 1; ++i) {
    if (t.compare(i, s.length(), s) == 0) {
      return i;
    }
  }
  return -1;
}

// O(n) time, in which n is the length of t
size_t rabin_karp(const string& s, const string& t) {
  if (s.length() > t.length()) {
    return -1;
  }

  const int k_base = 26;
  int t_hash = 0, s_hash = 0;
  int power_s = 1;  // k_base^|s|
  for (int i = 0; i < s.length(); ++i) {
    power_s = i ? power_s * k_base : 1;
    t_hash = t_hash * k_base + t[i];
    s_hash = s_hash * k_base + s[i];
  }

  for (int i = s.length(); i < t.length(); ++i) {
    if (t_hash == s_hash && t.compare(i - s.length(), s.length(), s) == 0) {
      return i - s.length();
    }

    t_hash -= t[i - s.length()] * power_s;
    t_hash = t_hash * k_base + t[i];
  }

  if (t_hash == s_hash &&
      t.compare(t.length() - s.length(), s.length(), s) == 0) {
    return t.length() - s.length();
  }

  return -1;
}
// @exclude

int main(int argc, char* argv[]) {
  string t = "Hello World!";
  string s_present = "World", s_not_present = "Worlds";

  assert(find_substr(s_present, t) == t.find(s_present));
  assert(find_substr(s_not_present, t) == t.find(s_not_present));

  assert(rabin_karp(s_present, t) == t.find(s_present));
  assert(rabin_karp(s_not_present, t) == t.find(s_not_present));
  return 0;
}
