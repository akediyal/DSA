class Solution {
public:
  int mostFrequentElement(vector<int> &nums) {
    int max_freq = 0;
    int n = nums.size();
    int max_element = 0;
    int visited[100000 + 1];

    for (int i = 0; i < n; i++) {
      int freq = 0;
      if (visited[nums[i]] == 0) {
        visited[nums[i]] == 1;
      }

      for (int j = i; j < n; j++) {
        if (nums[i] == nums[j]) {
          freq++;
        }
      }

      if (freq > max_freq) {
        max_freq = freq;
        max_element = nums[i];
      } else if (freq == max_freq && max_element > nums[i]) {
        max_element = nums[i];
      }
    }

    return max_element;
  }
};
