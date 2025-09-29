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
public:
  ListNode *copyRandomList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    unordered_map<ListNode *, ListNode *> mp;
    ListNode *temp = head;

    while (temp != nullptr) {
      ListNode *new_node = new ListNode(temp->val);
      mp[temp] = new_node;
      temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
      ListNode *copy_node = mp[temp];
      copy_node->next = mp[temp->next];
      copy_node->random = mp[temp->random];
      temp = temp->next;
    }

    return mp[head];
  }
};
