/*
 *
 * EPI
 * Computing the Parity of a Word (5.1)
 *
 */

#include <math.h>
#include <ctime>
#include <iostream>

using namespace std;

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

int main() {
  unsigned long min = pow(2, 63) + 1;
  unsigned long max = min + pow(2, 20);

  clock_t begin;

  begin = clock();
  for (unsigned long i = min; i <= max; i++) {
    parity_a(i);
  }
  cout << clock() - begin << endl;

  begin = clock();
  for (unsigned long i = min; i <= max; i++) {
    parity_b(i);
  }
  cout << clock() - begin << endl;

  begin = clock();
  short cache[65536];
  for (int i = 0; i < 65536; i++) cache[i] = parity_b(i);
  for (unsigned long i = min; i <= max; i++) {
    parity_c(i, 16, 0xFFFF, cache);
  }
  cout << clock() - begin << endl;
}
