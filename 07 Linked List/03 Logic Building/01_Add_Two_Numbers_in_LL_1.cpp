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
    ListNode *dummy_head = new ListNode(-1);
    ListNode *current_node = dummy_head;

    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr) {
      int sum = carry;

      if (temp1) {
        sum += temp1->val;
      }

      if (temp2) {
        sum += temp2->val;
      }

      ListNode *new_node = new ListNode(sum % 10);
      carry = sum / 10;

      current_node->next = new_node;
      current_node = current_node->next;

      if (temp1) {
        temp1 = temp1->next;
      }

      if (temp2) {
        temp2 = temp2->next;
      }
    }

    if (carry) {
      ListNode *new_node = new ListNode(carry);
      current_node->next = new_node;
    }

    return dummy_head->next;
  }
};
