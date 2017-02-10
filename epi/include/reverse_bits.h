/*
 *
 * EPI
 * Reverse Bits (5.3)
 *
 */

#ifndef EPI_REVERSE_BITS_H_
#define EPI_REVERSE_BITS_H_

#include "swap_bits.h"

// @include
unsigned long long reverse_bits(unsigned long long word, int n) {
  for ( int i = 0, j = n; i < j; i++, j-- ) {
    word = swap_bits(word, j, 63 - j);
  }
  return word;
}
// @exclude
#endif  // EPI_REVERSE_BITS_H_
