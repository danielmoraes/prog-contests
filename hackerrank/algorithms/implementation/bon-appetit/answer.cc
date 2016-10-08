#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k;
    int actual = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (i != k) actual += c;
    }
    int charged;
    cin >> charged;
    int diff = charged - (actual / 2);
    if (diff <= 0) {
        cout << "Bon Appetit" << endl;
    } else {
        cout << diff << endl;
    }
    return 0;
}
