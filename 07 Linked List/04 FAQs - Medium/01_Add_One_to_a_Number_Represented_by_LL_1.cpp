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
private:
  ListNode *reverseList(ListNode *head) {
    ListNode *temp = head;
    ListNode *prev = nullptr;

    while (temp != nullptr) {
      ListNode *front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }

    return prev;
  }

public:
  ListNode *addOne(ListNode *head) {
    head = reverseList(head);
    ListNode *temp = head;
    int carry = 1;

    while (temp != nullptr) {
      temp->val = temp->val + carry;

      if (temp->val < 10) {
        carry = 0;
        break;
      } else {
        temp->val = 0;
        carry = 1;
      }

      temp = temp->next;
    }

    if (carry == 1) {
      ListNode *new_node = new ListNode(carry);
      head = reverseList(head);
      new_node->next = head;

      return new_node;
    }

    head = reverseList(head);

    return head;
  }
};
