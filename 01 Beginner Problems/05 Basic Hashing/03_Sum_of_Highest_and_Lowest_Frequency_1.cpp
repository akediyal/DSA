class Solution {
public:
  int sumHighestAndLowestFrequency(vector<int> &nums) {
    int max_freq = 0, min_freq = INT_MAX;

    int n = nums.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

      if (visited[i]) {
        continue;
      }

      int freq = 0;
      for (int j = i; j < n; j++) {
        if (nums[i] == nums[j]) {
          freq++;
          visited[j] = true;
        }
      }

      max_freq = max(max_freq, freq);
      min_freq = min(min_freq, freq);
    }

    return max_freq + min_freq;
  }
};
