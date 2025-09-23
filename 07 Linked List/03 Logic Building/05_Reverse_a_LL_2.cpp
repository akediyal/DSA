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
};
