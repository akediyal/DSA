/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
  ListNode *deleteTail(ListNode *&head) {
    if (head == nullptr) {
      return head;
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;

      return head;
    }

    ListNode *temp = head;

    while (temp->next->next != nullptr) {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
  }
};
