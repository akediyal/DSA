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

class LinkedListStack {
private:
  ListNode *head;
  int size;

public:
  LinkedListStack() {
    head = nullptr;
    size = 0;
  }

  void push(int x) {
    ListNode *element = new ListNode(x);
    element->next = head;
    head = element;
    size++;
  }

  int pop() {
    if (head == nullptr) {
      cout << "Stack Empty!" << '\n';
      return -1;
    }

    int value = head->val;
    ListNode *temp = head;
    head = head->next;
    delete temp;
    size--;

    return value;
  }

  int top() {
    if (head == nullptr) {
      cout << "Stack Empty!" << '\n';
      return -1;
    }

    return head->val;
  }

  bool isEmpty() { return size == 0; }
};
