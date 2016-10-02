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
    int n, k, c;
    cin >> n >> k;
    int energy = 100;
    energy -= n / k;
    for (int c_i = 0;c_i < n;c_i++) {
        cin >> c;
        if (c_i % k == 0 && c == 1) {
            energy -= 2;
        }
    }
    cout << energy;
    return 0;
}
