class Solution {
public:
  double median(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    int n = n1 + n2;

    int idx2 = n / 2;
    int idx1 = idx2 - 1;

    int cnt = 0;

    int idx1_el = INT_MAX;
    int idx2_el = INT_MAX;

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
      if (arr1[i] < arr2[j]) {
        if (cnt == idx1) {
          idx1_el = arr1[i];
        }

        if (cnt == idx2) {
          idx2_el = arr1[i];
        }

        cnt++, i++;
      }

      else {
        if (cnt == idx1) {
          idx1_el = arr2[j];
        }

        if (cnt == idx2) {
          idx2_el = arr2[j];
        }

        cnt++, j++;
      }
    }

    while (i < n1) {
      if (cnt == idx1) {
        idx1_el = arr1[i];
      }

      if (cnt == idx2) {
        idx2_el = arr1[i];
      }

      cnt++, i++;
    }

    while (j < n2) {
      if (cnt == idx1) {
        idx1_el = arr2[j];
      }

      if (cnt == idx2) {
        idx2_el = arr2[j];
      }

      cnt++, j++;
    }

    if (n % 2 == 1) {
      return (double)idx2_el;
    }

    double median = (double)(idx1_el + idx2_el) / 2.0;

    return median;
  }
};
