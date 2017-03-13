/*
 *
 * EPI
 * Spreadsheet Column Encoding (7.3)
 *
 */

#include <math.h>
#include <string>
#include <iostream>

using namespace std;

// @include
int spreadsheet_column_encoding(string c) {
  int base = 26;
  int encoding = 0;
  for (int i = 0; i < c.size(); i++) {
    encoding *= base;
    encoding += c[i] - 'A' + 1;
  }
  return encoding;
}
// @exclude

int main(int argc, char* argv[]) {
  cout << spreadsheet_column_encoding("D") << endl;
  cout << spreadsheet_column_encoding("AA") << endl;
  cout << spreadsheet_column_encoding("ZZ") << endl;
  return 0;
}
