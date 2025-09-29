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
  ListNode *findStartingPoint(ListNode *head) {
    unordered_map<ListNode *, int> mp;

    ListNode *temp = head;

    while (temp != nullptr) {
      if (mp.find(temp) != mp.end()) {
        return temp;
      }

      mp[temp] = 1;
      temp = temp->next;
    }

    return nullptr;
  }
};
