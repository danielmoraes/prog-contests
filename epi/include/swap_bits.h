/*
 *
 * EPI
 * Swap Bits (5.2)
 *
 */

#ifndef EPI_SWAP_BITS_H_
#define EPI_SWAP_BITS_H_

unsigned long long swap_bits(unsigned long long word, int i, int j) {
  if ( ( ( word >> i ) & 1 ) ^ ( ( word >> j ) & 1) ) {  // if bits differ
    word ^= (1L << i) | (1L << j);
  }
  return word;
}

#endif  // EPI_SWAP_BITS_H_
