class Solution {
public:
  long long solve(vector<int> &bt) {
    int n = bt.size();

    sort(bt.begin(), bt.end());

    long long wait_time = 0;
    long long total_time = 0;

    for (int i = 0; i < n; i++) {
      wait_time += total_time;
      total_time += bt[i];
    }

    long long ans = wait_time / n;

    return (int)ans;
  }
};
