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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    int carry = 0;

    while ((l1 != nullptr || l2 != nullptr) || carry) {
      int sum = 0;

      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      sum += carry;
      carry = sum / 10;

      ListNode *new_node = new ListNode(sum % 10);
      temp->next = new_node;

      temp = temp->next;
    }

    return dummy->next;
  }
};
