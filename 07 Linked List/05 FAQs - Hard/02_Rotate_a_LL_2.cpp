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
  ListNode *findNthNode(ListNode *temp, int k) {
    int cnt = 1;

    while (temp != nullptr) {
      if (cnt == k)
        return temp;
      cnt++;
      temp = temp->next;
    }

    return temp;
  }

public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
      return head;
    }

    ListNode *temp = head;
    int length = 1;

    while (temp->next != nullptr) {
      length++;
      temp = temp->next;
    }

    temp->next = head;
    k = k % length;
    int end = length - k;

    ListNode *new_last_node = findNthNode(head, end);

    head = new_last_node->next;
    new_last_node->next = nullptr;

    return head;
  }
};
