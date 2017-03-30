/*
 * Codility - Given a log of stock prices compute the maximum possible earning.
 *
 * Lesson: 9 (Maximum Slice Problem)
 * Problem code: MaxProfit
 */

#include <cassert>
#include <math.h>
#include <vector>

using std::max;
using std::vector;

// @include
int max_profit(const vector<int>& v) {
  int result = 0, buy_idx = 0;
  for (unsigned int i = 1; i < v.size(); ++i) {
    if (v[i] <= v[buy_idx]) {
      buy_idx = i;
    } else {
      int profit = v[i] - v[buy_idx];
      if (profit > result) {
        result = profit;
      }
    }
  }
  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  assert(max_profit({23171, 21011, 21123, 21366, 21013, 21367}) == 356);
  return 0;
}
