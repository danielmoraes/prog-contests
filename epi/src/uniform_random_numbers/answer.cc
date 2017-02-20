/*
 *
 * EPI
 * Generate Uniform Random Numbers (5.10)
 *
 */

#include <iostream>
#include <primitive_types.h>

using namespace std;

int main() {
  for ( int i = 1; i < 10; i++ ) {
    cout << 0 << ":" << i << " " << uniform_random(0, i) << endl;
  }
}
