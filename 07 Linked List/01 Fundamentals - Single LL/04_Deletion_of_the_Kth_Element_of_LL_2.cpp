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

    for (int i = 1; temp != nullptr && i < k - 1; i++) {
      temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
      return head;
    }

    ListNode *node_to_delete = temp->next;
    temp->next = temp->next->next;
    delete node_to_delete;

    return head;
  }
};
