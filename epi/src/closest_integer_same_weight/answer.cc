/*
 *
 * EPI
 * Find a Closest Integer with the Same Weight (5.4)
 *
 */

#include <iostream>
#include <primitive_types.h>

using namespace std;

int main() {
  for ( int i = 0; i < 10; i++ ) {
    unsigned long long word = rand64bits();
    unsigned long long word_closest = closest_integer_same_weight(word, 64);
    cout << word << "/" << parity_b(word) << "\t" << word_closest << "/"
         << parity_b(word_closest) << endl;
  }
}
