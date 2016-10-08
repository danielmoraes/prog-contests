#include <vector>
#include <iostream>

using namespace std;

void print_vec(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << v[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int t_i = 0; t_i < t; t_i++) {
    int n, k;
    cin >> n >> k;

    if (k == 0) {

      vector<int> p(n);
      for (int p_i = 0; p_i < n; p_i++) {
        p[p_i] = p_i + 1;
      }
      print_vec(p);

    } else if (n % (k * 2) == 0) {

      vector<int> p(n, 0);
      int groups = n / (k * 2);
      for (int g_i = 0; g_i < groups; g_i++) {
        for (int p_j = 0; p_j < k; p_j++) {
          int pos = g_i * (2 * k) + p_j;
          p[pos] = pos + k + 1;
          p[pos + k] = pos + 1;
        }
      }
      print_vec(p);

    } else {

      cout << -1 << endl;

    }
  }
  return 0;
}
