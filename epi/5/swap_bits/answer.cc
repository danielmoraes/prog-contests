/*
 *
 * EPI
 * Swap Bits (5.2)
 *
 */

#include <math.h>
#include <bitset>
#include <iostream>

using namespace std;

unsigned rand256() {
    static unsigned const limit = RAND_MAX - RAND_MAX % 256;
    unsigned result = rand();
    while ( result >= limit ) {
        result = rand();
    }
    return result % 256;
}

unsigned long long rand64bits() {
    unsigned long long results = 0ULL;
    for ( int count = 8; count > 0; -- count ) {
        results = 256U * results + rand256();
    }
    return results;
}

unsigned long long swap_bits(unsigned long long word, int i, int j) {
  if ( ( ( word >> i ) & 1 ) ^ ( ( word >> j ) & 1) ) {  // if bits differ
    word ^= (1L << i) | (1L << j);
  }
  return word;
}

int main() {
  for ( int i = 0; i < 10; i++ ) {
    unsigned long long word = rand64bits();
    unsigned long long word_swapped = swap_bits(word, 0, 63);
    bitset<64> word_binary(word), word_swapped_binary(word_swapped);
    cout << word_binary << ":" << word_swapped_binary << endl;
  }
}
