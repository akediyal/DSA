class ArrayStack {
private:
  int *stack_array;
  int capacity;
  int top_index;

public:
  ArrayStack(int size = 1000) {
    capacity = size;
    stack_array = new int[capacity];
    top_index = -1;
  }

  ~ArrayStack() { delete[] stack_array; }

  void push(int x) {
    if (top_index >= capacity - 1) {
      cout << "Stack Overflow!" << endl;
      return;
    }
    stack_array[++top_index] = x;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Stack Empty!" << endl;
      return -1;
    }
    return stack_array[top_index--];
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack Empty!" << endl;
      return -1;
    }
    return stack_array[top_index];
  }

  bool isEmpty() { return top_index == -1; }
};
