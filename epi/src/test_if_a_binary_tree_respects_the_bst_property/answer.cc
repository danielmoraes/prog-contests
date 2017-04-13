/*
 *
 * EPI
 * Test If a Binary Tree Respects the BST Property (15.1)
 *
 */

#include <binary_tree.h>
#include <cassert>
#include <limits>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::numeric_limits;

// @include
bool is_node_within_range(unique_ptr<BinaryTreeNode<int>>& tree,
                          int min, int max) {
  if (tree == nullptr) {
    return true;
  }

  if (tree->data < min || tree->data > max) {
    return false;
  }

  return is_node_within_range(tree->left, min, tree->data) &&
         is_node_within_range(tree->right, tree->data, max);
}

bool is_bst(unique_ptr<BinaryTreeNode<int>>& tree) {
  return is_node_within_range(
      tree, numeric_limits<int>::min(), numeric_limits<int>::max());
}
// @exclude

int main(int argc, char* argv[]) {
  //                   19
  //        7                    43
  //    3       11          23        47
  // 2     5        17          37        53
  //             13          29    41
  //                           31

  // level 0
  unique_ptr<BinaryTreeNode<int>> tree;
  tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{19});

  // level 1
  tree->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{7});
  tree->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{43});

  // level 2
  tree->left->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
  tree->left->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{11});
  tree->right->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{23});
  tree->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{47});

  // level 3
  tree->left->left->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
  tree->left->left->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
  tree->left->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{17});
  tree->right->left->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{37});
  tree->right->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{53});

  // level 4
  tree->left->right->right->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{13});
  tree->right->left->right->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{29});
  tree->right->left->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{41});

  // level 5
  tree->right->left->right->left->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{31});

  assert(is_bst(tree) == true);

  //                   19
  //        7                    43
  //    3       11          23        47
  // 2     5        17          37        53
  //             13          29    41
  //                       20  31

  // level 5
  tree->right->left->right->left->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{20});

  assert(is_bst(tree) == false);

  return 0;
}
