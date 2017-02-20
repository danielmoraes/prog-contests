/*
 *
 * EPI
 * Check if a Decimal Integer is a Palindrome (5.9)
 *
 */

#include <bitset>
#include <iostream>
#include <primitive_types.h>

using namespace std;

int main() {
  // test with positive numbers
  for ( int i = 0; i < 25; i++ ) {
    int x = rand() % 100 + 1;  // between 1 and 100
    cout << x << ":" << is_palindrome(x) << endl;
  }

  // test with negative numbers
  for ( int i = 0; i < 25; i++ ) {
    int x = -(rand() % 100 + 1);  // between -1 and -100
    cout << x << ":" << is_palindrome(x) << endl;
  }
}
