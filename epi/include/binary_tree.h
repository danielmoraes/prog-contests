#ifndef EPI_BINARY_TREE_H_
#define EPI_BINARY_TREE_H_

#include <memory>

using std::unique_ptr;

// @include
template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};
// @exclude

#endif  // EPI_BINARY_TREE_H_
