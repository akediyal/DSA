class Solution {
public:
  int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    int n = n1 + n2;

    int cnt = 0;

    int i = 0, j = 0;

    int kth_el = INT_MAX;

    while (i < n1 && j < n2) {
      if (a[i] < b[j]) {
        if (cnt == k - 1) {
          kth_el = a[i];
          return kth_el;
        }

        cnt++, i++;
      }

      else {
        if (cnt == k - 1) {
          kth_el = b[j];
          return kth_el;
        }

        cnt++, j++;
      }
    }

    while (i < n1) {
      if (cnt == k - 1) {
        kth_el = a[i];
        return kth_el;
      }

      cnt++, i++;
    }

    while (j < n2) {
      if (cnt == k - 1) {
        kth_el = b[j];
        return kth_el;
      }

      cnt++, j++;
    }

    return 0;
  }
};
