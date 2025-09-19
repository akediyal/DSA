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
      head = front;
      front->prev = nullptr;
      delete temp;

      return head;
    }

    if (front == nullptr) {
      back->next = nullptr;
      delete temp;

      return head;
    }

    back->next = front;
    front->prev = back;

    delete temp;

    return head;
  }
};
