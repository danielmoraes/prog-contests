/*
 *
 * EPI
 * Count the Number of Score Combinations (17.1)
 *
 */

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// @include
int solve_recursive(int final_score, int last_play, const vector<int>& plays) {
  if (final_score < 0) {
    return 0;
  }

  if (final_score == 0) {
    return 1;
  }

  int valid_plays = 0;
  for (unsigned int i = last_play; i < plays.size(); ++i) {
    valid_plays += solve_recursive(final_score - plays[i], i, plays);
  }

  return valid_plays;
}

int score_combinations_recursive(int final_score, const vector<int>& plays) {
  return solve_recursive(final_score, 0, plays);
}

int score_combinations_cache(int final_score, const vector<int>& plays) {
  vector<vector<int>> cache(plays.size(), vector<int>(final_score + 1, 0));
  for (unsigned int i = 0; i < plays.size(); ++i) {
    cache[i][0] = 1;
    for (int j = 1; j <= final_score; ++j) {
      int without = (i > 0) ? cache[i - 1][j] : 0;
      int with = (j - plays[i] >= 0) ? cache[i][j - plays[i]] : 0;
      cache[i][j] = with + without;
    }
  }
  return cache[plays.size() - 1][final_score];
}
// @exclude

int main(int argc, char* argv[]) {
  assert(score_combinations_recursive(12, {2, 3, 7}) == 4);
  assert(score_combinations_cache(12, {2, 3, 7}) == 4);
  return 0;
}
