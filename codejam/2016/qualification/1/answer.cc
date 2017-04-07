/*
 *
 * CodeJam 2016 - Qualification Round
 * Problem 1
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int new_digits(int m, vector<bool>& digits) {
  int count = 0;
  while (m) {
    int d = m % 10;
    if (!digits[d]) {
      digits[d] = true;
      count++;
    }
    m /= 10;
  }
  return count;
}

int counting_ship(int n) {
  if (n == 0) return -1;
  vector<bool> digits(10, false);
  int cur = 0, seen = 0;
  while (seen < 10) {
    cur += n;
    seen += new_digits(cur, digits);
  }
  return cur;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int n;
    cin >> n;

    printf("Case #%d: ", i);

    int seen = counting_ship(n);

    if (seen < 0) {
      cout << "INSOMNIA" << endl;
    } else {
      cout << seen << endl;
    }
  }

  return 0;
}
