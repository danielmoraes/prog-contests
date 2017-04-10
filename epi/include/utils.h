#ifndef EPI_UTILS_H_
#define EPI_UTILS_H_

#include <memory>
#include <vector>
#include <iostream>
#include <linked_list.h>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

// @include

/*
 * I/O
 */

void print_array(int arr[], unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    if (i > 0) cout << " ";
    cout << arr[i];
  }
  cout << endl;
}

template<typename T>
void print_vector(const vector<T>& v) {
  for (unsigned int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

template<typename T>
void print_matrix(const vector<vector<T>>& v) {
  for (unsigned int i = 0; i < v.size(); i++) {
    for (unsigned int j = 0; j < v[i].size(); j++) {
      if (j > 0) cout << "\t";
      cout << v[i][j];
    }
    cout << endl;
  }
}

template<typename T>
void print_list(shared_ptr<ListNode<T>> L) {
  while (L) {
    cout << L->data << " ";
    L = L->next;
  }
  cout << endl;
}

// @exclude

#endif  // EPI_UTILS_H_
