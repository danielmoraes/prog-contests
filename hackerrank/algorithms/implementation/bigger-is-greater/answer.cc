#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t_i = 0; t_i < t; t_i++) {
        string s;
        cin >> s;
        bool found = next_permutation(s.begin(), s.end());
        if (found) {
            cout << s << endl;
        } else {
            cout << "no answer" << endl;
        }
    }
    return 0;
}
