#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k, 0);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
        b[a[a_i] % k]++;
    }
    int count = 0;
    for (int i = 0; i < (k / 2) + 1; i++) {
        int m = (k - i) % k;
        if (i == m) {
            count += min(1, b[i]);
        } else {
            count += max(b[i], b[m]);
        }
    }
    cout << count << endl;
    return 0;
}
