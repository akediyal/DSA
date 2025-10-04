class Solution {
private:
  bool static compare(vector<int> &a, vector<int> &b) { return a[2] > b[2]; }

public:
  vector<int> JobScheduling(vector<vector<int>> &Jobs) {
    sort(Jobs.begin(), Jobs.end(), compare);

    int n = Jobs.size();
    int max_deadline = -1;

    for (int i = 0; i < n; i++) {
      max_deadline = max(max_deadline, Jobs[i][1]);
    }

    vector<int> hash(max_deadline + 1, -1);
    int cnt = 0;
    int total_profit = 0;

    for (int i = 0; i < n; i++) {
      for (int j = Jobs[i][1] - 1; j >= 0; j--) {
        if (hash[j] == -1) {
          hash[j] = Jobs[i][0];
          cnt++;
          total_profit += Jobs[i][2];
          break;
        }
      }
    }

    return {cnt, total_profit};
  }
};
