/*
 *
 * EPI
 * Compute All Mnemonics for a Phone Number (7.7)
 *
 */

#include <array>
#include <vector>
#include <string>
#include <utils.h>
#include <iostream>

using namespace std;

// @include
const int keypad_num_digits = 10;
const array<string, keypad_num_digits> keypad = {
    {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}};

void compute_mnemonics_helper(const string& phone_number, unsigned int digit,
    const string& current_mnemonic, vector<string>& mnemonics) {
  if (digit == phone_number.size()) {
    mnemonics.push_back(current_mnemonic);
    return;
  }
  for (auto c : keypad[phone_number[digit] - '0']) {
    compute_mnemonics_helper(phone_number, digit + 1, current_mnemonic + c,
                             mnemonics);
  }
}

vector<string> compute_mnemonics(const string& phone_number) {
  vector<string> mnemonics;
  compute_mnemonics_helper(phone_number, 0, "", mnemonics);
  return mnemonics;
}
// @exclude

int main(int argc, char* argv[]) {
  string phone_number = "227";
  print_vector(compute_mnemonics(phone_number));
  return 0;
}
