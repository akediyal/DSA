class StackQueue {
private:
  stack<int> st1, st2;

public:
  StackQueue() {}

  void push(int x) { st1.push(x); }

  int pop() {
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }

    if (st2.empty()) {
      cout << "Queue Empty!" << endl;
      return -1;
    }

    int popped_el = st2.top();
    st2.pop();

    return popped_el;
  }

  int peek() {
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }

    if (st2.empty()) {
      cout << "Queue Empty!" << endl;
      return -1;
    }

    return st2.top();
  }

  bool isEmpty() { return st1.empty() && st2.empty(); }
};
