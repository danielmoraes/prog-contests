/*
 *
 * EPI
 * Buy and Sell a Stock Once (6.6)
 *
 */

#include <vector>
#include <iostream>

using namespace std;

int maximum_profit(const vector<int>& stock) {
  int max_profit = 0, current_min = 0;
  for (int i = 1; i < stock.size(); i++) {
    if (stock[i] < stock[current_min]) {
      current_min = i;
    } else {
      max_profit = max(max_profit, stock[i] - stock[current_min]);
    }
  }
  return max_profit;
}

int main() {
  vector<int> v1 {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
  cout << maximum_profit(v1) << endl;
  return 0;
}
