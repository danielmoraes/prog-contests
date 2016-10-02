#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    sort(arr.begin(), arr.end());
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == min) {
            continue;
        }
        min = arr[i];
        cout << n - i << endl;
    }
    return 0;
}
