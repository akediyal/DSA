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
  void insertBeforeGivenNode(ListNode *node, int X) {
    ListNode *back = node->prev;

    ListNode *new_node = new ListNode(X, node, back);
    back->next = new_node;
    node->prev = new_node;

    return;
  }
};
