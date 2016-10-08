#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n, 0);
    for(int i = 0; i < m; i++) { 
        int c_i;
        cin >> c_i;
        c[c_i] = 1;
    }
    int left = -1;
    int max_left_distance = -1;
    for(int i = 0; i < n; i++) {
        if (c[i] == 1) {
            int left_distance = i - left - 1;
            if (left >= 0) {
                left_distance = ceil(left_distance / 2.0);
            }
            if (left_distance > max_left_distance) {
                max_left_distance = left_distance;
            }
            left = i;
        }
    }
    cout << max(max_left_distance, n - left - 1) << endl;
    return 0;
}
