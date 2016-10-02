#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, m, s;
    cin >> t;
    for (int t_i = 0; t_i < t; t_i++) {
        cin >> n >> m >> s;
        cout << (((s - 1) + (m - 1)) % n) + 1 << endl;
    }
    return 0;
}
