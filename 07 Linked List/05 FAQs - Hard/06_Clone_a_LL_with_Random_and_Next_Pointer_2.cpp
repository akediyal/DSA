/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};
*/

class Solution {
private:
  void insertCopyInBetween(ListNode *head) {
    ListNode *temp = head;

    while (temp != nullptr) {
      ListNode *copy = new ListNode(temp->val);
      copy->next = temp->next;
      temp->next = copy;
      temp = temp->next->next;
    }
  }

  void connectRandomPointers(ListNode *head) {
    ListNode *temp = head;

    while (temp != nullptr) {
      ListNode *copy = temp->next;

      if (temp->random != nullptr) {
        copy->random = temp->random->next;
      } else {
        copy->random = nullptr;
      }

      temp = temp->next->next;
    }
  }

  ListNode *getDeepCopyList(ListNode *head) {
    ListNode *temp = head;
    ListNode *dummy = new ListNode(-1);
    ListNode *res = dummy;

    while (temp != nullptr) {
      res->next = temp->next;
      temp->next = temp->next->next;
      res = res->next;
      temp = temp->next;
    }

    return dummy->next;
  }

public:
  ListNode *copyRandomList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    insertCopyInBetween(head);
    connectRandomPointers(head);

    return getDeepCopyList(head);
  }
};
