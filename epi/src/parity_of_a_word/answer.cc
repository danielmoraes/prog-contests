/*
 *
 * EPI
 * Computing the Parity of a Word (5.1)
 *
 */

#include <ctime>
#include <iostream>
#include <random64.h>
#include <parity.h>

using namespace std;

int main() {
  int n = 1 << 20;  // ~1M
  clock_t begin;

  begin = clock();
  for (int i = 0; i < n; i++) {
    parity_a(rand64bits());
  }
  cout << clock() - begin << endl;

  begin = clock();
  for (int i = 0; i < n; i++) {
    parity_b(rand64bits());
  }
  cout << clock() - begin << endl;

  begin = clock();
  short cache[65536];
  for (int i = 0; i < 65536; i++) cache[i] = parity_b(i);
  for (int i = 0; i < n; i++) {
    parity_c(rand64bits(), 16, 0xFFFF, cache);
  }
  cout << clock() - begin << endl;
}
