/*
 *
 * EPI
 * Reverse Digits (5.8)
 *
 */

#include <iostream>
#include <primitive_types.h>

using namespace std;

int main() {
  // test with positive numbers
  for ( int i = 0; i < 10; i++ ) {
    int x = rand() % 1000 + 1;  // between 1 and 1000
    cout << x << ":" << reverse_digits(x) << endl;
  }

  // test with negative numbers
  for ( int i = 0; i < 10; i++ ) {
    int x = -(rand() % 1000 + 1);  // between -1 and -1000
    cout << x << ":" << reverse_digits(x) << endl;
  }
}
