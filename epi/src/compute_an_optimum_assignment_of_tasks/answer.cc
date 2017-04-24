/*
 *
 * EPI
 * Compute an Optimum Assignment of Tasks (18.1)
 *
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <utils.h>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::sort;
using std::vector;

// @include
vector<pair<int, int>> optimum_assignment(vector<int> tasks) {
  vector<pair<int, int>> assignment;
  sort(tasks.begin(), tasks.end());
  for (int i = 0, j = tasks.size() - 1; i < j; ++i, --j) {
    assignment.push_back({tasks[i], tasks[j]});
  }
  return assignment;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<pair<int, int>> assignment = optimum_assignment({5, 2, 1, 6, 4, 4});
  for (unsigned int i = 0; i < assignment.size(); ++i) {
    cout << assignment[i].first << " " << assignment[i].second << endl;
  }
  return 0;
}
