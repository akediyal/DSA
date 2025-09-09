class Solution {
private:
  void helperFunc(int i, int j, string path, vector<vector<int>> &grid,
                  vector<string> &ans) {
    int n = grid.size();

    if (i == n - 1 && j == n - 1) {
      ans.push_back(path);
      return;
    }

    if (grid[i][j] == 0) {
      return;
    }

    grid[i][j] = 0;

    if (i - 1 >= 0) {
      helperFunc(i - 1, j, path + 'U', grid, ans);
    }

    if (i + 1 < n) {
      helperFunc(i + 1, j, path + 'D', grid, ans);
    }

    if (j - 1 >= 0) {
      helperFunc(i, j - 1, path + 'L', grid, ans);
    }

    if (j + 1 < n) {
      helperFunc(i, j + 1, path + 'R', grid, ans);
    }

    grid[i][j] = 1;
  }

public:
  vector<string> findPath(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<string> ans;

    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) {
      return ans;
    }

    helperFunc(0, 0, "", grid, ans);

    return ans;
  }
};
