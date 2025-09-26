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
    unordered_set<ListNode *> visited;
    ListNode *temp = headA;

    while (temp != nullptr) {
      visited.insert(temp);
      temp = temp->next;
    }

    temp = headB;

    while (temp != nullptr) {
      if (visited.find(temp) != visited.end()) {
        return temp;
      }

      temp = temp->next;
    }

    return nullptr;
  }
};
