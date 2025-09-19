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

    return head;
  }
};
