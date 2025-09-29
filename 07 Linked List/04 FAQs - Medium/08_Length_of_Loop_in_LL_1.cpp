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
  int findLengthOfLoop(ListNode *head) {
    unordered_map<ListNode *, int> mp;

    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr) {
      if (mp.find(temp) != mp.end()) {
        return cnt - mp[temp];
      }

      mp[temp] = cnt;
      cnt++;
      temp = temp->next;
    }

    return 0;
  }
};
