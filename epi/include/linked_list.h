#ifndef EPI_LINKED_LIST_H_
#define EPI_LINKED_LIST_H_

#include <memory>

using std::shared_ptr;
using std::make_shared;

// @include
template <typename T>
struct ListNode {
  T data;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> search_list(shared_ptr<ListNode<int>> l, int key) {
  while (l && l->data != key) {
    l = l->next;
  }
  return l;
}

bool insert_after(const shared_ptr<ListNode<int>>& node,
                  const shared_ptr<ListNode<int>>& new_node) {
  if (!node || !new_node) {
    return false;
  }
  new_node->next = node->next;
  node->next = new_node;
  return true;
}

bool delete_after(const shared_ptr<ListNode<int>>& node) {
  if (!node || !node->next) {
    return false;
  }
  node->next = node->next->next;
  return true;
}

// @exclude

#endif  // EPI_LINKED_LIST_H_
