/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
  ListNode *arrayToLinkedList(vector<int> &nums) {
    int n = nums.size();

    if (n == 0) {
      return nullptr;
    }

    ListNode *head = new ListNode(nums[0]);
    ListNode *back = head;

    for (int i = 1; i < n; i++) {
      ListNode *temp = new ListNode(nums[i], nullptr, back);
      back->next = temp;
      back = temp;
    }

    return head;
  }
};
