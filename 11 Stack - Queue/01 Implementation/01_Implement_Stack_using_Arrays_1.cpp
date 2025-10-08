class ArrayStack {
private:
  int st[1000];
  int top_index;

public:
  ArrayStack() { top_index = -1; }

  void push(int x) {
    if (top_index >= 999) {
      cout << "Stack Overflow!" << '\n';
      return;
    }
    st[++top_index] = x;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Stack Empty!" << '\n';
      return -1;
    }
    return st[top_index--];
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack Empty!" << '\n';
      return -1;
    }
    return st[top_index];
  }

  bool isEmpty() { return top_index == -1; }
};
