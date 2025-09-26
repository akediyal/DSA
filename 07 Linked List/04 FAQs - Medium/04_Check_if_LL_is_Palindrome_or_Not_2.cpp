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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *new_head = reverseList(slow->next);
    ListNode *first = head;
    ListNode *second = new_head;

    while (second != nullptr) {
      if (first->val != second->val) {
        reverseList(new_head);
        return false;
      }

      first = first->next;
      second = second->next;
    }

    reverseList(new_head);

    return true;
  }
};
