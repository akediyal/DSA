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
  ListNode *removeDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *temp = head;

    while (temp != nullptr && temp->next != nullptr) {
      ListNode *next_node = temp->next;

      while (next_node != nullptr && next_node->val == temp->val) {
        ListNode *duplicate = next_node;
        next_node = next_node->next;
        delete duplicate;
      }

      temp->next = next_node;

      if (next_node != nullptr) {
        next_node->prev = temp;
      }

      temp = temp->next;
    }

    return head;
  }
};
