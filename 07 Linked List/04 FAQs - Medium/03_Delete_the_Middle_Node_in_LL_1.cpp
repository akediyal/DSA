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

    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;
      temp = temp->next;
    }

    int res = cnt / 2;
    temp = head;
    ListNode *middle = nullptr;

    while (temp != nullptr) {
      res--;

      if (res == 0) {
        middle = temp->next;
        temp->next = middle->next;
        delete middle;
        break;
      }

      temp = temp->next;
    }

    return head;
  }
};
