#ifndef EPI_STACK_H_
#define EPI_STACK_H_

#include <stack>
#include <stdexcept>

using std::stack;
using std::length_error;

// @include
class Stack {
  public:
    bool empty() const {
      return stack_.empty();
    }

    int max() const {
      if (empty()) throw length_error("empty stack");
      return max_stack_.top().element;
    }

    void push(int element) {
      if (empty() || element > max()) {
        max_stack_.push({element, 1});
      } else if (element == max()) {
        max_stack_.top().count++;
      }
      stack_.push(element);
    }

    int pop() {
      if (empty()) throw length_error("empty stack");
      int element = stack_.top();
      if (element == max()) {
        int& max_count = max_stack_.top().count;
        max_count--;
        if (max_count == 0) {
          max_stack_.pop();
        }
      }
      stack_.pop();
      return element;
    }

  private:
    struct MaxElement {
      int element, count;
    };

    stack<MaxElement> max_stack_;
    stack<int> stack_;
};
// @exclude

#endif  // EPI_STACK_H_
