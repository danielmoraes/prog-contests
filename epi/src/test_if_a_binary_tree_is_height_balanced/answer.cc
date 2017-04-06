/*
 *
 * EPI
 * Test if a Binary Tree is Height Balanced (10.1)
 *
 */

#include <binary_tree.h>
#include <iostream>
#include <math.h>
#include <memory>
#include <stdexcept>

using std::abs;
using std::cout;
using std::endl;
using std::logic_error;
using std::max;
using std::unique_ptr;
using std::make_unique;

// @include
struct BalancedStatusWithHeight {
  int height;
  bool is_balanced;
};

BalancedStatusWithHeight check(const unique_ptr<BinaryTreeNode<int>>& node) {
  if (node == nullptr) return {-1, true};

  auto left = check(node->left);
  if (!(left.is_balanced)) return {0, false};

  auto right = check(node->right);
  if (!(right.is_balanced)) return {0, false};

  int height = max(left.height, right.height) + 1;
  bool is_balanced = abs(left.height - right.height) <= 1;

  return {height, is_balanced};
}

bool is_balanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return check(tree).is_balanced;
}
// @exclude

int main(int argc, char* argv[]) {
  //   1
  // 2
  unique_ptr<BinaryTreeNode<int>> tree;
  tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
  tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});

  cout << is_balanced(tree) << endl;

  //   1
  // 2   3
  //       4
  //         5
  tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
  tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
  tree->right->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});

  cout << is_balanced(tree) << endl;

  return 0;
}
