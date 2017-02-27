/*
 *
 * EPI
 * The Dutch National Flag Problem (6.1)
 *
 */

#include <iostream>
#include <algorithm>
#include <utils.h>
#include <math.h>

using namespace std;

int partition_dutch_flag(int arr[], int size, int pivot) {
  int l = -1, e = -1, h = -1;

  swap(arr[pivot], arr[size - 1]);
  pivot = size - 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] < arr[pivot]) {
      e += 1; h += 1;
      swap(arr[i], arr[e]);
      l += 1;
      swap(arr[e], arr[l]);
    } else if (arr[i] == arr[pivot]) {
      e += 1; h += 1;
      swap(arr[i], arr[e]);
    } else {
      h += 1;
      swap(arr[i], arr[h]);
    }
  }

  return ceil((e - l) / 2.0) + l;
}

int main() {
  int a[] = {5, 8, 7, 6, 5, 4, 3, 2, 1, 5};

  int pivot = 0;
  cout << string(pivot * 2, ' ') << "*" << endl;
  print_array(a, 10);

  pivot = partition_dutch_flag(a, 10, 0);
  cout << string(pivot * 2, ' ') << "*" << endl;
  print_array(a, 10);

  return 0;
}
