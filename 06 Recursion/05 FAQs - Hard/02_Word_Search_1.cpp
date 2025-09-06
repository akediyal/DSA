class Solution {
private:
  bool helperFunc(int idx, int i, int j, vector<vector<char>> &board,
                  string word) {
    int rows = board.size();
    int cols = board[0].size();

    if (board[i][j] == '#' || board[i][j] != word[idx]) {
      return false;
    }

    if (idx == word.size() - 1) {
      return true;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool ans = false;

    if (i - 1 >= 0) {
      ans |= helperFunc(idx + 1, i - 1, j, board, word);
    }

    if (i + 1 < rows) {
      ans |= helperFunc(idx + 1, i + 1, j, board, word);
    }

    if (j - 1 >= 0) {
      ans |= helperFunc(idx + 1, i, j - 1, board, word);
    }

    if (j + 1 < cols) {
      ans |= helperFunc(idx + 1, i, j + 1, board, word);
    }

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
