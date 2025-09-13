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
  ListNode *deleteNodeWithValueX(ListNode *&head, int X) {
    if (head == nullptr) {
      return head;
    }

    if (head->val == X) {
      ListNode *temp = head;
      head = head->next;
      delete temp;

      return head;
    }

    ListNode *temp = head;
    ListNode *prev = nullptr;

    while (temp != nullptr) {
      if (temp->val == X) {
        prev->next = prev->next->next;
        delete temp;
        break;
      }

      prev = temp;
      temp = temp->next;
    }

    return head;
  }
};
