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
  ListNode *middleOfLinkedList(ListNode *head) {
    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;
      temp = temp->next;
    }

    int mid_node = (cnt / 2) + 1;
    temp = head;

    while (temp != nullptr) {
      mid_node--;

      if (mid_node == 0) {
        break;
      }

      temp = temp->next;
    }

    return temp;
  }
};
