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
    long sum = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        sum += arr[arr_i];
    }
    cout << sum << endl;
    return 0;
}
