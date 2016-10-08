#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, el;
    cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++){
       cin >> el;
       sum += el;
    }
    cout << sum << endl;
    return 0;
}
