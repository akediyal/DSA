class Solution {
private:
  bool helperFunc(int idx, int i, int j, vector<vector<char>> &board,
                  string word) {
    int rows = board.size();
    int cols = board[0].size();

    if (idx == word.size()) {
      return true;
    }

    if (i < 0 || j < 0 || i >= rows || j >= cols) {
      return false;
    }

    if (board[i][j] == '#' || board[i][j] != word[idx]) {
      return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool ans = false;

    ans = helperFunc(idx + 1, i - 1, j, board, word) ||
          helperFunc(idx + 1, i + 1, j, board, word) ||
          helperFunc(idx + 1, i, j - 1, board, word) ||
          helperFunc(idx + 1, i, j + 1, board, word);

    board[i][j] = temp;

    return ans;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == word[0]) {
          if (helperFunc(0, i, j, board, word)) {
            return true;
          }
        }
      }
    }

    return false;
  }
};
