class Solution {
public:
  int celebrity(vector<vector<int>> &M) {
    int n = M.size();
    vector<int> know_me(n, 0);
    vector<int> i_know(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (M[i][j] == 1) {
          know_me[j]++;
          i_know[i]++;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (know_me[i] == n - 1 && i_know[i] == 0) {
        return i;
      }
    }

    return -1;
  }
};
