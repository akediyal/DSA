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
  ListNode *insertBeforeKthPosition(ListNode *head, int X, int K) {
    if (head == nullptr) {
      return new ListNode(X);
    }

    if (K == 1) {
      ListNode *new_node = new ListNode(X, head, nullptr);
      head->prev = new_node;

      return new_node;
    }

    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;

      if (cnt == K) {
        break;
      }

      temp = temp->next;
    }

    ListNode *back = temp->prev;

    ListNode *new_node = new ListNode(X, temp, back);
    back->next = new_node;
    temp->prev = new_node;

    return head;
  }
};
