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
    int pos = 0, neg = 0, zero = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        if (arr[arr_i] > 0) pos++;
        else if (arr[arr_i] < 0) neg++;
        else zero++;
    }
    cout << pos / double(n) << endl << neg / double(n) << endl << zero / double(n);
    return 0;
}
