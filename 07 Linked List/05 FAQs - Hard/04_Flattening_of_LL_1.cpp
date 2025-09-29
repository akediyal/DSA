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
  ListNode *convertToVerticalLL(vector<int> &arr) {
    if (arr.size() == 0) {
      return nullptr;
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    for (int i = 0; i < arr.size(); i++) {
      temp->child = new ListNode(arr[i]);
      temp = temp->child;
    }

    return dummy->child;
  }

public:
  ListNode *flattenLinkedList(ListNode *&head) {
    vector<int> arr;
    ListNode *temp = head;

    while (temp != nullptr) {
      ListNode *temp1 = temp;

      while (temp1 != nullptr) {
        arr.push_back(temp1->val);
        temp1 = temp1->child;
      }

      temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    return convertToVerticalLL(arr);
  }
};
