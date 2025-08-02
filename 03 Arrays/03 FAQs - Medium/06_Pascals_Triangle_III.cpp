class Solution {
public:
  vector<vector<int>> pascalTriangleIII(int n) {
    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++) {
      vector<int> temp;

      for (int j = 1; j <= i; j++) {
        long long num = nCr(i - 1, j - 1);
        temp.push_back(num);
      }

      ans.push_back(temp);
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
