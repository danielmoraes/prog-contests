#include <iostream>
using namespace std;
int main(void) {
    int t;
    cin >> t;
    int sum_o = 0, sum_d = 0;
    while ((int) t != 0) {
        for (int i = 0; i < t; i++) {
            int o, d;
            cin >> o >> d;
            sum_o += o;
            sum_d += d;
        }
        if (sum_o == sum_d) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        sum_o = 0;
        sum_d = 0;
        cin >> t;
    }
}
