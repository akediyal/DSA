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
  ListNode *sortList(ListNode *head) {
    ListNode *temp = head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while (temp != nullptr) {
      if (temp->val == 0) {
        cnt0++;
      } else if (temp->val == 1) {
        cnt1++;
      } else {
        cnt2++;
      }
      temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
      if (cnt0) {
        temp->val = 0;
        cnt0--;
      } else if (cnt1) {
        temp->val = 1;
        cnt1--;
      } else {
        temp->val = 2;
        cnt2--;
      }
      temp = temp->next;
    }

    return head;
  }
};
