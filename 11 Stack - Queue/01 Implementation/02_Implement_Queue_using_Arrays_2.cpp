class ArrayQueue {
private:
  int *queue_array;
  int capacity;
  int start, end;
  int cur_size;

public:
  ArrayQueue(int size = 1000) {
    capacity = size;
    queue_array = new int[capacity];
    start = -1, end = -1;
    cur_size = 0;
  }

  void push(int x) {
    if (cur_size == capacity) {
      cout << "Queue Full!" << endl;
      exit(1);
    }

    if (isEmpty()) {
      start = 0, end = 0;
    } else {
      end = (end + 1) % capacity;
    }

    queue_array[end] = x;
    cur_size++;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Queue Empty!" << endl;
      exit(1);
    }

    int popped_el = queue_array[start];

    if (cur_size == 1) {
      start = -1, end = -1;
    } else {
      start = (start + 1) % capacity;
    }

    cur_size--;

    return popped_el;
  }

  int peek() {
    if (isEmpty()) {
      cout << "Queue Empty!" << endl;
      exit(1);
    }
    return queue_array[start];
  }

  bool isEmpty() { return cur_size == 0; }
};
