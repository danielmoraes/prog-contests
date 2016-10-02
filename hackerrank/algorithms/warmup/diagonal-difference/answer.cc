#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    int diag1_sum = 0, diag2_sum = 0;
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
          if (a_i == a_j) diag1_sum += a[a_i][a_j];
          if (a_j == (n - 1 - a_i)) diag2_sum += a[a_i][a_j];
       }
    }
    cout << abs(diag1_sum - diag2_sum);
    return 0;
}
