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
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    vector<int> arr;
    ListNode *temp = head;

    while (temp != nullptr && temp->next != nullptr) {
      arr.push_back(temp->val);
      temp = temp->next->next;
    }

    if (temp) {
      arr.push_back(temp->val);
    }

    temp = head->next;

    while (temp != nullptr && temp->next != nullptr) {
      arr.push_back(temp->val);
      temp = temp->next->next;
    }

    if (temp) {
      arr.push_back(temp->val);
    }

    temp = head;
    int i = 0;

    while (temp != nullptr) {
      temp->val = arr[i];
      i++;
      temp = temp->next;
    }

    return head;
  }
};
