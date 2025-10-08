class ArrayQueue {
private:
  int start, end;
  int cur_size;
  int queue_array[1000];

public:
  ArrayQueue() {
    start = -1, end = -1;
    cur_size = 0;
  }

  void push(int x) {
    if (cur_size == 1000) {
      cout << "Queue Full!" << '\n';
      return;
    }

    if (isEmpty()) {
      start = 0, end = 0;
    } else {
      end = (end + 1) % 1000;
    }

    queue_array[end] = x;
    cur_size++;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Queue Empty!" << '\n';
      return -1;
    }

    int popped_el = queue_array[start];

    if (cur_size == 1) {
      start = -1, end = -1;
    } else {
      start = (start + 1) % 1000;
    }

    cur_size--;

    return popped_el;
  }

  int peek() {
    if (isEmpty()) {
      cout << "Queue Empty!" << '\n';
      return -1;
    }
    return queue_array[start];
  }

  bool isEmpty() { return cur_size == 0; }
};
