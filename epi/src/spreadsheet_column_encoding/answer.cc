/*
 *
 * EPI
 * Compute Spreadsheet Column Encoding (7.3)
 *
 */

#include <math.h>
#include <string>
#include <iostream>

using namespace std;

// @include
int decode_column_code(const string& c) {
  int base = 26;
  int id = 0;
  for (unsigned int i = 0; i < c.size(); i++) {
    id = id * base + (c[i] - 'A' + 1);
  }
  return id;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << decode_column_code("D") << endl;
  cout << decode_column_code("AA") << endl;
  cout << decode_column_code("ZZ") << endl;
  return 0;
}
