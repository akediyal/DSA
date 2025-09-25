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
  int helperFunc(ListNode *temp) {
    if (temp == nullptr) {
      return 1;
    }

    int carry = helperFunc(temp->next);
    temp->val = temp->val + carry;

    if (temp->val < 10) {
      return 0;
    }

    temp->val = 0;

    return 1;
  }

public:
  ListNode *addOne(ListNode *head) {
    int carry = helperFunc(head);

    if (carry == 1) {
      ListNode *new_node = new ListNode(carry);
      new_node->next = head;
      head = new_node;
    }

    return head;
  }
};
