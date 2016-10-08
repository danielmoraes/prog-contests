#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k, 0);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       b[a[a_i] % k]++;
    }
    int pairs = 0;
    for(int i = 0; i < (k / 2) + 1; i++) {
       int m = (k - i) % k;
       if (i == m) {
           pairs += (b[i] * (b[i] - 1))/2;
       } else {
           pairs += b[i] * b[m];
       }
    }
    cout << pairs << endl;
    return 0;
}
