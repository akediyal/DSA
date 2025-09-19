/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
private:
  ListNode *deleteHead(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;

      return head;
    }

    ListNode *back = head;

    head = head->next;

    head->prev = nullptr;
    back->next = nullptr;
    delete back;

    return head;
  }

  ListNode *deleteTail(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;

      return head;
    }

    ListNode *temp = head;

    while (temp->next != nullptr) {
      temp = temp->next;
    }

    ListNode *back = temp->prev;

    temp->prev = nullptr;
    back->next = nullptr;

    delete temp;

    return head;
  }

public:
  ListNode *deleteKthElement(ListNode *head, int k) {
    if (head == nullptr) {
      return head;
    }

    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;

      if (cnt == k) {
        break;
      }

      temp = temp->next;
    }

    ListNode *back = temp->prev;
    ListNode *front = temp->next;

    if (back == nullptr && front == nullptr) {
      delete temp;

      return nullptr;
    }

    if (back == nullptr) {
      return deleteHead(head);
    }

    if (front == nullptr) {
      return deleteTail(head);
    }

    back->next = front;
    front->prev = back;

    delete temp;

    return head;
  }
};
