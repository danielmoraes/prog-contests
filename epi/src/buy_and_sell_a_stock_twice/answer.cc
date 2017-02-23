/*
 *
 * EPI
 * Buy and Sell a Stock Twice (6.7)
 *
 */

#include <vector>
#include <iostream>

using namespace std;

int maximum_profit(const vector<int>& stock) {
  int buy_one_profit = 0, buy_two_profit = 0;
  int current_buy_start = 0, current_buy_profit = 0;

  for ( int i = 1; i <= stock.size(); i++ ) {
    // closes current buy
    if ( i == stock.size() or stock[i] < stock[current_buy_start] ) {
      // check if current buy is higher than the highest buy found so far
      if ( current_buy_profit > buy_one_profit ) {
        buy_two_profit = buy_one_profit;
        buy_one_profit = current_buy_profit;
      // check if current buy is higher than the second highest buy found so far
      } else if ( current_buy_profit > buy_two_profit ) {
        buy_two_profit = current_buy_profit;
      }
      current_buy_start = i, current_buy_profit = 0;
    // update current buy profit
    } else {
      current_buy_profit = max(current_buy_profit,
                               stock[i] - stock[current_buy_start]);
    }
  }
  // returns the maximum total profit
  return buy_one_profit + buy_two_profit;
}

int main() {
  vector<int> v1 {12, 11, 13, 9, 12, 8, 14, 13, 15};
  cout << maximum_profit(v1) << endl;
  return 0;
}
