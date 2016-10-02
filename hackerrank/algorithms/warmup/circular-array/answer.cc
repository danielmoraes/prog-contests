#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, q, m;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < q; i++) {
        cin >> m;
        cout << arr[((m - k) % n + n) % n] << endl;
    }
    return 0;
}
