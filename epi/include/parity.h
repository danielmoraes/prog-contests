#ifndef EPI_PARITY_H_
#define EPI_PARITY_H_

// @include

// O(n), where n is the number of bits
short parity_a(unsigned long word) {
  short result = 0;
  while (word) {
    result ^= (word & 1);
    word >>= 1;
  }
  return result;
}

// O(k), where k is then number of bits sets to 1
short parity_b(unsigned long word) {
  short result = 0;
  while (word) {
    result ^= 1;
    word &= (word - 1);  // drops lowest set bit
  }
  return result;
}

// O(n/l), where n is the number of bits and l the block size
short parity_c(unsigned long word, short bsize, unsigned short mask,
               short cache[]) {
    return cache[word & mask] ^
           cache[(word >> bsize) & mask] ^
           cache[(word >> (2 * bsize)) & mask] ^
           cache[word >> (3 * bsize)];
}

// @exclude

#endif  // EPI_PARITY_H_
