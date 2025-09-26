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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != temp2) {
      temp1 = temp1->next;
      temp2 = temp2->next;

      if (temp1 == temp2) {
        return temp1;
      }

      if (temp1 == nullptr) {
        temp1 = headB;
      }

      if (temp2 == nullptr) {
        temp2 = headA;
      }
    }

    return temp1;
  }
};
