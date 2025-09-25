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
    ListNode *front = nullptr;

    while (temp != nullptr) {
      front = temp->next;
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
      int sum = temp->val + carry;
      carry = sum / 10;
      temp->val = sum % 10;

      if (carry == 0) {
        break;
      }

      if (temp->next == nullptr && carry != 0) {
        temp->next = new ListNode(carry);
        break;
      }

      temp = temp->next;
    }

    head = reverseList(head);

    return head;
  }
};
