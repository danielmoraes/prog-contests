/*
 *
 * CodeJam 2017 - Round 1B
 * Problem A
 *
 */

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

#define F first
#define S second
#define pb push_back

typedef pair <int, int> ii;
typedef pair <ii, ii> iii;

double solve () {
  int D, N;
  cin >> D >> N;

  double max_t = 0.000000;
  for (int i = 0; i < N; ++i) {
    int K_i, S_i;
    cin >> K_i >> S_i;
    double t_i = (D - K_i) / (double) S_i;
    if (t_i > max_t) {
      max_t = t_i;
    }
  }

  return D / max_t;
}

int main(int argc, char* argv[]) {
  string input = (argc == 2) ? argv[1] : "sample";
  freopen((input + ".in").c_str(), "r", stdin);
  freopen((input + ".out").c_str(), "w", stdout);

  int T; cin >> T;

  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: %.6f\n", i, solve());
  }

  return 0;
}
