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
  ListNode *deleteMiddle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      delete head;
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    fast = fast->next->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *middle = slow->next;
    slow->next = middle->next;
    delete middle;

    return head;
  }
};
