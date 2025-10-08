struct ListNode {
  int val;
  ListNode *next;

  ListNode(int data1, ListNode *next1) {
    val = data1;
    next = next1;
  }

  ListNode(int data1) {
    val = data1;
    next = nullptr;
  }
};

class LinkedListQueue {
private:
  ListNode *start;
  ListNode *end;
  int size;

public:
  LinkedListQueue() {
    start = nullptr;
    end = nullptr;
    size = 0;
  }

  void push(int x) {
    ListNode *element = new ListNode(x);

    if (isEmpty()) {
      start = element;
      end = element;
    } else {
      end->next = element;
      end = element;
    }

    size++;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Queue Empty!" << '\n';
      return -1;
    }

    int value = start->val;
    ListNode *temp = start;
    start = start->next;
    delete temp;
    size--;

    return value;
  }

  int peek() {
    if (isEmpty()) {
      cout << "Queue Empty!" << '\n';
      return -1;
    }

    return start->val;
  }

  bool isEmpty() { return size == 0; }
};
