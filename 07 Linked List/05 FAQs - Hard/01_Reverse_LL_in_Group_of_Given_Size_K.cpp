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
private:
  ListNode *reverseList(ListNode *head) {
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *front = nullptr;

    while (temp != nullptr) {
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }

    return prev;
  }

  ListNode *getKthNode(ListNode *temp, int k) {
    k -= 1;

    while (temp != nullptr && k > 0) {
      k--;
      temp = temp->next;
    }

    return temp;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *temp = head;
    ListNode *next_node = nullptr;
    ListNode *prev_node = nullptr;

    while (temp != nullptr) {
      ListNode *kth_node = getKthNode(temp, k);

      if (kth_node == nullptr) {
        if (prev_node) {
          prev_node->next = temp;
        }

        break;
      }

      next_node = kth_node->next;
      kth_node->next = nullptr;
      reverseList(temp);

      if (temp == head) {
        head = kth_node;
      } else {
        prev_node->next = kth_node;
      }

      prev_node = temp;
      temp = next_node;
    }

    return head;
  }
};
