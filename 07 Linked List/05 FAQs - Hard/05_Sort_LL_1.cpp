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
  ListNode *sortList(ListNode *head) {
    vector<int> arr;

    ListNode *temp = head;

    while (temp != nullptr) {
      arr.push_back(temp->val);
      temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;

    for (int i = 0; i < arr.size(); i++) {
      temp->val = arr[i];
      temp = temp->next;
    }

    return head;
  }
};
