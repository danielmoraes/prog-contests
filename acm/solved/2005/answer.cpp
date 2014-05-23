#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(void) {
    int matrix[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> matrix[i][j];

    int p1 = matrix[0][1] + matrix[1][2] + matrix[2][3] + matrix[3][4];
    int p2 = matrix[0][2] + matrix[2][1] + matrix[1][3] + matrix[3][4];
    int p3 = matrix[0][2] + matrix[2][3] + matrix[3][1] + matrix[1][4];
    int p4 = matrix[0][3] + matrix[3][2] + matrix[2][1] + matrix[1][4];

    int m = min(min(min(p1, p2), p3), p4);

    if (p1 == m) {
        cout << p1 << endl;
        cout << "1 2 3 4 5" << endl;
    } else if (p2 == m) {
        cout << p2 << endl;
        cout << "1 3 2 4 5" << endl;
    } else if (p3 == m) {
        cout << p3 << endl;
        cout << "1 3 4 2 5" << endl;
    } else if (p4 == m) {
        cout << p4 << endl;
        cout << "1 4 3 2 5" << endl;
    }
}
