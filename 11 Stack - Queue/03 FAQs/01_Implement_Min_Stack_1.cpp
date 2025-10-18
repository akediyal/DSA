class MinStack {
private:
  stack<pair<int, int>> st;

public:
  MinStack() {}

  void push(int value) {
    if (st.empty()) {
      st.push({value, value});
    } else {
      int mn = min(value, getMin());
      st.push({value, mn});
    }
  }

  void pop() { st.pop(); }

  int top() { return st.top().first; }

  int getMin() { return st.top().second; }
};
