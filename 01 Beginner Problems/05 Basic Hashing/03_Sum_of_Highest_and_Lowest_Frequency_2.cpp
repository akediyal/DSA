class Solution {
public:
  int sumHighestAndLowestFrequency(vector<int> &nums) {
    int min_freq = INT_MAX, max_freq = 0;

    int n = nums.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;
    }

    for (auto i : freq) {
      int freq = i.second;
      max_freq = max(max_freq, freq);
      min_freq = min(min_freq, freq);
    }

    return max_freq + min_freq;
  }
};
