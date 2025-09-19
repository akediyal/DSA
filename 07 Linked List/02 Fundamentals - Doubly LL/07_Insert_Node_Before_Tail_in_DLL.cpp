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
  ListNode *insertBeforeTail(ListNode *head, int X) {
    if (head == nullptr) {
      return new ListNode(X);
    }

    if (head->next == nullptr) {
      ListNode *new_node = new ListNode(X, head, nullptr);
      head->prev = new_node;

      return new_node;
    }

    ListNode *tail = head;

    while (tail->next != nullptr) {
      tail = tail->next;
    }

    ListNode *back = tail->prev;

    ListNode *new_node = new ListNode(X, tail, back);
    back->next = new_node;
    tail->prev = new_node;

    return head;
  }
};
