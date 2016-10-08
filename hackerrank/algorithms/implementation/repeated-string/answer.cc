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
    string s;
    cin >> s;
    long n;
    cin >> n;
    int len = s.length();
    long count = 0;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            count++;
            if (i < n - (n / len) * len) {
                tmp++;
            }
        }
    }
    cout << count * (n / s.length()) + tmp << endl;
    return 0;
}
