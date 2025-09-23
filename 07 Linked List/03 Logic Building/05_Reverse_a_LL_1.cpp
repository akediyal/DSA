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
  ListNode *reverseList(ListNode *head) {
    stack<int> st;

    ListNode *temp = head;

    while (temp != nullptr) {
      st.push(temp->val);
      temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
      temp->val = st.top();
      st.pop();
      temp = temp->next;
    }

    return head;
  }
};
