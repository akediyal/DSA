/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *temp = head;

    int len = 0;

    while (temp != nullptr) {
      len++;
      temp = temp->next;
    }

    if (len == n) {
      ListNode *new_head = head->next;
      delete head;

      return new_head;
    }

    int res = len - n;
    temp = head;

    while (temp != nullptr) {
      res--;

      if (res == 0) {
        break;
      }

      temp = temp->next;
    }

    ListNode *del_node = temp->next;
    temp->next = del_node->next;
    delete del_node;

    return head;
  }
};
