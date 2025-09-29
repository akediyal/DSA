/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
private:
  ListNode *merge(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        temp->child = list1;
        temp = list1;
        list1 = list1->child;
      } else {
        temp->child = list2;
        temp = list2;
        list2 = list2->child;
      }

      temp->next = nullptr;
    }

    if (list1 != nullptr) {
      temp->child = list1;
    } else {
      temp->child = list2;
    }

    return dummy->child;
  }

public:
  ListNode *flattenLinkedList(ListNode *&head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *merged_head = flattenLinkedList(head->next);

    head = merge(head, merged_head);

    return head;
  }
};
