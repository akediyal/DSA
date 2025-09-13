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
  ListNode *insertAtKthPosition(ListNode *&head, int X, int K) {
    if (head == nullptr) {
      if (K == 1) {
        return new ListNode(X);
      } else {
        return head;
      }
    }

    if (K == 1) {
      return new ListNode(X, head);
    }

    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      cnt++;

      if (cnt == K - 1) {
        ListNode *newnode = new ListNode(X, temp->next);
        temp->next = newnode;
        break;
      }

      temp = temp->next;
    }

    return head;
  }
};
