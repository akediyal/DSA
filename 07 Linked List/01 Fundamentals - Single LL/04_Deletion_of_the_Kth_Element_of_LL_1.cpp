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
  ListNode *deleteKthNode(ListNode *&head, int k) {
    if (head == nullptr) {
      return head;
    }

    if (k == 1) {
      ListNode *temp = head;
      head = head->next;
      delete temp;

      return head;
    }

    ListNode *temp = head;
    ListNode *prev = nullptr;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;

      if (cnt == k) {
        prev->next = prev->next->next;
        delete temp;
        break;
      }

      prev = temp;
      temp = temp->next;
    }

    return head;
  }
};
