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
  ListNode *getCollisionPoint(ListNode *temp1, ListNode *temp2, int n) {
    while (n--) {
      temp2 = temp2->next;
    }

    while (temp1 != temp2) {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }

    return temp1;
  }

public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    int n1 = 0, n2 = 0;

    while (temp1 != nullptr) {
      n1++;
      temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
      n2++;
      temp2 = temp2->next;
    }

    temp1 = headA;
    temp2 = headB;

    if (n1 < n2) {
      return getCollisionPoint(temp1, temp2, n2 - n1);
    }

    return getCollisionPoint(temp2, temp1, n1 - n2);
  }
};
