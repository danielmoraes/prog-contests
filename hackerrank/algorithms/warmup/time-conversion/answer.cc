#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int pos = time.find(":");
    int h = stoi(time.substr(0, pos));
    string suffix = time.substr(time.size() - 2, -1);
    if (suffix == "PM" && h != 12) h += 12;
    if (suffix == "AM" && h == 12) h = 0;
    printf("%02d%s\n", h, time.substr(pos, time.size() - pos - 2).c_str());
    return 0;
}
