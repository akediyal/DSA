class Solution {
private:
  bool static compare(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

public:
  int MaximumNonOverlappingIntervals(vector<vector<int>> &Intervals) {
    sort(Intervals.begin(), Intervals.end(), compare);

    int n = Intervals.size();
    int cnt = 1;
    int free_time = Intervals[0][1];

    for (int i = 1; i < n; i++) {
      if (Intervals[i][0] >= free_time) {
        free_time = Intervals[i][1];
        cnt++;
      }
    }

    return n - cnt;
  }
};
