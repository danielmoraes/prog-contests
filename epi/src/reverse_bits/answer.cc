/*
 *
 * EPI
 * Reverse Bits (5.3)
 *
 */

#include <bitset>
#include <iostream>
#include <random64.h>
#include <reverse_bits.h>

using namespace std;

int main() {
  for ( int i = 0; i < 10; i++ ) {
    unsigned long long word = rand64bits();
    unsigned long long word_reversed = reverse_bits(word, 63);
    bitset<64> word_binary(word), word_reversed_binary(word_reversed);
    cout << word_binary << ":" << word_reversed_binary << endl;
  }
}
