class MinStack {
private:
  stack<int> st;
  int mn;

public:
  MinStack() { mn = INT_MAX; }

  void push(int value) {
    if (st.empty()) {
      mn = value;
      st.push(mn);
    } else {
      if (value > mn) {
        st.push(value);
      } else {
        st.push(2 * value - mn);
        mn = value;
      }
    }
  }

  void pop() {
    if (st.empty()) {
      return;
    }

    int x = st.top();
    st.pop();

    if (x < mn) {
      mn = 2 * mn - x;
    }
  }

  int top() {
    if (st.empty()) {
      return -1;
    }

    int x = st.top();

    if (mn < x) {
      return x;
    }

    return mn;
  }

  int getMin() { return mn; }
};
