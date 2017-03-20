/*
 *
 * EPI
 * Convert from Roman to Decimal (7.9)
 *
 */

#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                {'C', 100}, {'D', 500}, {'M', 1000}};

// @include
int roman_to_decimal(const string& roman) {
  int decimal = map[roman.back()];
  for (int i = roman.length() - 2; i >= 0; --i) {
    if (map[roman[i]] >= map[roman[i + 1]]) {
      decimal += map[roman[i]];
    } else {
      decimal -= map[roman[i]];
    }
  }
  return decimal;
}
// @exclude

int main(int argc, char* argv[]) {
  assert(59 == roman_to_decimal("XXXXXIIIIIIIII"));
  assert(59 == roman_to_decimal("LVIIII"));
  assert(59 == roman_to_decimal("LIX"));
  return 0;
}
