/*
 *
 * CodeJam 2017 - Qualification Round
 * Problem 3
 *
 */

#include <iostream>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

struct R { long long y, z; };

void add(long long k, long long v, queue<long long>& q,
         unordered_map<long long, long long>& m) {
  if (v != 0) {
    if (m.find(k) == m.end()) {
      q.push(k);
      m[k] = v;
    } else {
      m[k] += v;
    }
  }
}

R stalls(long long n, long long k) {
  long long y = 0, z = 0;

  queue<long long> q;
  unordered_map<long long, long long> m;

  add(n, 1, q, m);

  int i = 0;
  while (i < k) {
    auto cur = q.front();

    y = cur / 2;
    z = (cur % 2 == 0) ? y - 1 : y;

    add(y, m[cur], q, m);
    add(z, m[cur], q, m);

    i += m[cur];
    m[cur] = 0;
    q.pop();

    if (y == 0) {
      break;
    }
  }

  return {y, z};
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    long long n, k;
    cin >> n >> k;
    printf("Case #%d: ", i);
    auto r = stalls(n, k);
    cout << r.y << " " << r.z << endl;
  }

  return 0;
}
