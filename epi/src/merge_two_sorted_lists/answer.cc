/*
 *
 * EPI
 * Merge Two Sorted Lists (8.1)
 *
 */

#include <iostream>
#include <linked_list.h>
#include <memory>
#include <utils.h>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

// @include
shared_ptr<ListNode<int>> merge_sorted_lists(shared_ptr<ListNode<int>> L1,
                                             shared_ptr<ListNode<int>> L2) {
  shared_ptr<ListNode<int>> sentinel(new ListNode<int>);
  shared_ptr<ListNode<int>> tail = sentinel;

  while (L1 && L2) {
    shared_ptr<ListNode<int>> el;
    if (L1->data <= L2->data) {
      el = L1;
      L1 = L1->next;
    } else {
      el = L2;
      L2 = L2->next;
    }
    insert_after(tail, el);
    tail = el;
  }
  tail->next = L1 ? L1 : L2;
  return sentinel->next;
}
// @exclude

int main(int argc, char* argv[]) {
  shared_ptr<ListNode<int>> L_even = make_shared<ListNode<int>>(ListNode<int>{
      0, make_shared<ListNode<int>>(ListNode<int>{
             2, make_shared<ListNode<int>>(ListNode<int>{4, nullptr})})});

  shared_ptr<ListNode<int>> L_odd = make_shared<ListNode<int>>(ListNode<int>{
      1, make_shared<ListNode<int>>(ListNode<int>{
             3, make_shared<ListNode<int>>(ListNode<int>{5, nullptr})})});

  print_list(merge_sorted_lists(L_even, L_odd));
  return 0;
}
