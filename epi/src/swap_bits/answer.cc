/*
 *
 * EPI
 * Swap Bits (5.2)
 *
 */

#include <math.h>
#include <bitset>
#include <iostream>
#include <random64.h>
#include <swap_bits.h>

using namespace std;

int main() {
  for ( int i = 0; i < 10; i++ ) {
    unsigned long long word = rand64bits();
    unsigned long long word_swapped = swap_bits(word, 0, 63);
    bitset<64> word_binary(word), word_swapped_binary(word_swapped);
    cout << word_binary << ":" << word_swapped_binary << endl;
  }
}
