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
  void deleteGivenNode(ListNode *node) {
    ListNode *back = node->prev;
    ListNode *front = node->next;

    if (front == nullptr) {
      back->next = nullptr;
      delete node;

      return;
    }

    back->next = front;
    front->prev = back;

    delete node;
  }
};
