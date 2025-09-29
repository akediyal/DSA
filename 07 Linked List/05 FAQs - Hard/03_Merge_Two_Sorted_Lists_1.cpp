// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
private:
  ListNode *convertToLL(vector<int> &arr) {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    for (int i = 0; i < arr.size(); i++) {
      temp->next = new ListNode(arr[i]);
      temp = temp->next;
    }

    return dummy->next;
  }

public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    vector<int> arr;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;

    while (temp1 != nullptr) {
      arr.push_back(temp1->val);
      temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
      arr.push_back(temp2->val);
      temp2 = temp2->next;
    }

    sort(arr.begin(), arr.end());

    ListNode *head = convertToLL(arr);

    return head;
  }
};
