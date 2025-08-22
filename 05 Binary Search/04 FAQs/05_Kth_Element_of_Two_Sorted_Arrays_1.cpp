class Solution {
public:
  int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    int i = 0, j = 0;

    vector<int> arr3;

    while (i < n1 && j < n2) {
      if (a[i] < b[j]) {
        arr3.push_back(a[i++]);
      } else {
        arr3.push_back(b[j++]);
      }
    }

    while (i < n1) {
      arr3.push_back(a[i++]);
    }

    while (j < n2) {
      arr3.push_back(b[j++]);
    }

    return arr3[k - 1];
  }
};
