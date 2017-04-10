/*
 *
 * EPI
 * Merge Sorted Files (11.1)
 *
 */

#include <functional>
#include <queue>
#include <utils.h>
#include <vector>

using std::greater;
using std::priority_queue;
using std::vector;

// @include
struct Element {
  bool operator>(const Element& e) const { return element > e.element; }
  int element, element_idx, array_idx;
};

vector<int> merge_sorted_arrays(const vector<vector<int>>& sorted_arrays) {
  priority_queue<Element, vector<Element>, greater<Element>> min_heap;

  // add first element of each array to the min heap
  for (int i = 0; i < sorted_arrays.size(); ++i) {
    if (sorted_arrays[i].size() == 0) {
      continue;
    }
    min_heap.push(Element{sorted_arrays[i][0], 0, i});
  }

  vector<int> result;
  while (!min_heap.empty()) {
    auto min = min_heap.top();
    min_heap.pop();

    result.push_back(min.element);

    min.element_idx++;
    if (min.element_idx == sorted_arrays[min.array_idx].size()) {
      continue;
    }

    min.element = sorted_arrays[min.array_idx][min.element_idx];
    min_heap.push(Element{min.element, min.element_idx, min.array_idx});
  }

  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> a = {0, 10, 20, 30, 40, 50};
  vector<int> c = {2, 12, 22, 32, 42, 52};
  vector<int> b = {5, 15, 25, 35, 45, 55};

  vector<vector<int>> sorted_arrays = {a, b, c};

  print_vector(merge_sorted_arrays(sorted_arrays));

  return 0;
}
