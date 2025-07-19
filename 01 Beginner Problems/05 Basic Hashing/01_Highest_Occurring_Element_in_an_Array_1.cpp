class Solution {
public:
  int mostFrequentElement(vector<int> &nums) {
    int n = nums.size();
    int max_element = 0;
    int max_freq = 0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

      if (visited[i]) {
        continue;
      }

      int freq = 0;
      for (int j = i; j < n; j++) {

        if (nums[i] == nums[j]) {
          visited[j] = true;
          freq++;
        }

        if (freq > max_freq) {
          max_freq = freq;
          max_element = nums[i];
        } else if (freq == max_freq && max_element > nums[i]) {
          max_element = nums[i];
        }
      }
    }

    return max_element;
  }
};
