class Solution {
public:
  vector<int> pascalTriangleII(int r) {
    vector<int> ans;

    for (int i = 0; i < r; i++) {
      long long num = nCr(r - 1, i);
      ans.push_back(num);
    }

    return ans;
  }

  long long nCr(int n, int r) {
    int k = min(r, n - r);

    if (k == 1) {
      return n;
    }

    long long ans = 1;

    for (int i = 0; i < k; i++) {
      ans = ans * (n - i);
      ans = ans / (i + 1);
    }

    return ans;
  }
};
