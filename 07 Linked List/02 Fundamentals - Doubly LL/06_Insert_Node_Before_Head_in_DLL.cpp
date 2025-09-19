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
  ListNode *insertBeforeHead(ListNode *head, int X) {
    if (head == nullptr) {
      return new ListNode(X);
    }

    ListNode *new_node = new ListNode(X, head, nullptr);
    head->prev = new_node;

    return new_node;
  }
};
