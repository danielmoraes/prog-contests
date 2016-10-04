#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, t_i;
    int current_page = 1;
    int specials = 0;
    cin >> n >> k;
    // for each chapter
    for (int i = 0; i < n; i++) {
        cin >> t_i;
        // for each page of the chapter
        for (int j = 0; j < ceil(t_i / (double) k); j++) {
            if (current_page >= 1 + j * k && current_page <= min(t_i, k + j * k)) {
                specials++;
            }
            current_page++;
        }
    }
    cout << specials;
    return 0;
}
