#ifndef EPI_PRIMITIVE_TYPES_H_
#define EPI_PRIMITIVE_TYPES_H_

// @include

typedef unsigned long long ULONG;

/*
 * Random 64bit numbers
 */

unsigned rand256() {
    static unsigned const limit = RAND_MAX - RAND_MAX % 256;
    unsigned result = rand();
    while ( result >= limit ) {
        result = rand();
    }
    return result % 256;
}

ULONG rand64bits() {
    ULONG results = 0ULL;
    for ( int count = 8; count > 0; -- count ) {
        results = 256U * results + rand256();
    }
    return results;
}

/*
 * Bit manipulation
 */

// O(n), where n is the number of bits
short parity_a(ULONG word) {
  short result = 0;
  while (word) {
    result ^= (word & 1);
    word >>= 1;
  }
  return result;
}

// O(k), where k is then number of bits sets to 1
short parity_b(ULONG word) {
  short result = 0;
  while (word) {
    result ^= 1;
    word &= (word - 1);  // drops lowest set bit
  }
  return result;
}

// O(n/l), where n is the number of bits and l the block size
short parity_c(ULONG word, short bsize, unsigned short mask, short cache[]) {
    return cache[word & mask] ^
           cache[(word >> bsize) & mask] ^
           cache[(word >> (2 * bsize)) & mask] ^
           cache[word >> (3 * bsize)];
}

ULONG swap_bits(ULONG word, int i, int j) {
  if ( ( ( word >> i ) & 1 ) ^ ( ( word >> j ) & 1) ) {  // if bits differ
    word ^= (1L << i) | (1L << j);
  }
  return word;
}

ULONG reverse_bits(ULONG word, int n) {
  for ( int i = 0, j = n; i < j; i++, j-- ) {
    word = swap_bits(word, j, 63 - j);
  }
  return word;
}

ULONG reverse_bits_cache(ULONG word, int n, short bsize, short cache[]) {
  for ( int i = 0, j = n; i < j; i++, j-- ) {
    word = swap_bits(word, j, 63 - j);
  }
  return word;
}

ULONG closest_integer_same_weight(ULONG word, int bitsize) {
  for (int i = 0; i < bitsize - 1; i++) {
    if ( ( ( word >> i ) & 1 ) ^ ( ( word >> i + 1 ) & 1) ) {  // if bits differ
      word = swap_bits(word, i, i + 1);
      return word;
    }
  }
}

/*
 * Operations on decimal numbers
 */

long reverse_digits(int x) {
  long x_reversed = 0;
  short x_sign = (x < 0) ? -1 : 1;
  for (; x > 0; x /= 10)
    x_reversed = (x_reversed * 10) + (x % 10);
  return x_reversed * x_sign;
}

// @exclude

#endif  // EPI_PRIMITIVE_TYPES_H_
