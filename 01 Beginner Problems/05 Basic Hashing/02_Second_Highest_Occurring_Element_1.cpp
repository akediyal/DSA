class Solution {
public:
  int secondMostFrequentElement(vector<int> &nums) {
    int max_freq = 0, sec_max_freq = 0;
    int max_element = -1, sec_max_element = -1;

    int n = nums.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

      if (visited[i])
        continue;

      int freq = 0;

      for (int j = 0; j < n; j++) {
        if (nums[i] == nums[j]) {
          freq++;
          visited[j] = true;
        }
      }

      if (freq > max_freq) {
        sec_max_freq = max_freq;
        max_freq = freq;
        sec_max_element = max_element;
        max_element = nums[i];
      } else if (freq == max_freq) {
        max_element = min(max_element, nums[i]);
      } else if (freq > sec_max_freq) {
        sec_max_freq = freq;
        sec_max_element = nums[i];
      } else if (freq == sec_max_freq) {
        sec_max_element = min(sec_max_element, nums[i]);
      }
    }

    return sec_max_element;
  }
};
