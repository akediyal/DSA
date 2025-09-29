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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    for (int i = 0; i < k; i++) {
      ListNode *temp = head;

      while (temp->next->next != nullptr) {
        temp = temp->next;
      }

      ListNode *end_node = temp->next;
      temp->next = nullptr;
      end_node->next = head;
      head = end_node;
    }

    return head;
  }
};
