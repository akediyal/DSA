class QueueStack {
private:
  queue<int> q;

public:
  QueueStack() {}

  void push(int x) {
    int n = q.size();
    q.push(x);

    for (int i = 0; i < n; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int popped_el = q.front();
    q.pop();
    return popped_el;
  }

  int top() { return q.front(); }

  bool isEmpty() { return q.empty(); }
};
