#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int factorial(int x, int result = 1) {
  if (x == 1)
      return result;
  else
      return factorial(x - 1, x * result);
}

int main(void) {
    int n, m[100], reps[100];
    int distincts = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m[i];
        reps[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        bool repeated = false;
        for (int j = 0; j < i; j ++)
            if (m[i] == m[j]) {
                repeated = true;
                break;
            }
        if (!repeated) {
            distincts++;
            for (int j = 0; j < n; j++) {
                if (i != j && m[i] == m[j])
                    reps[i]++;
            }
        }
    }

    if (n >= 6) {
        if (distincts > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        int den = 1;
        for (int i = 0; i < n; i++)
            den *= factorial(reps[i]);
        if (factorial(n) / den >= 6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
