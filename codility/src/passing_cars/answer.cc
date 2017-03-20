/*
 * Codility - Count the number of passing cars on the road.
 *
 * Lesson: 5 (PrefixSums)
 * Problem code: PassingCars
 */

#include <vector>
#include <iostream>

using namespace std;

// @include
const int LIMIT = 1000000000;

int passing_cars(vector<int> &A) {
  int ones_so_far = 0, passing_cars = 0;
  for (int i = A.size() - 1; i >= 0; --i) {
    if (A[i] == 1) {
      ones_so_far++;
    } else {
      passing_cars += ones_so_far;
      if (passing_cars > LIMIT) {
        return -1;
      }
    }
  }
  return passing_cars;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> cars = {0, 1, 0, 1, 1};
  cout << passing_cars(cars) << endl;
  return 0;
}
