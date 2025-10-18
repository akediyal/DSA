class Solution {
public:
  int celebrity(vector<vector<int>> &M) {
    int n = M.size();
    int top = 0, down = n - 1;

    while (top < down) {
      if (M[top][down] == 1) {
        top += 1;
      }

      else if (M[down][top] == 1) {
        down -= 1;
      }

      else {
        top++, down--;
      }
    }

    if (top > down) {
      return -1;
    }

    for (int i = 0; i < n; i++) {
      if (i == top) {
        continue;
      }

      if (M[i][top] == 1 && M[top][i] == 0) {
        continue;
      } else {
        return -1;
      }
    }

    return top;
  }
};
