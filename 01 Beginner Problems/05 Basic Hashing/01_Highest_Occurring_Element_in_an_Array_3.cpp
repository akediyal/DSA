class Solution {
public:
  int mostFrequentElement(vector<int> &nums) {
    int max_freq = 0, max_element = 0;
    int n = nums.size();

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;
    }

    for (auto i : freq) {
      int element = i.first;
      int freq = i.second;

      if (freq > max_freq) {
        max_freq = freq;
        max_element = element;
      } else if (freq == max_freq && max_element > element) {
        max_element = element;
      }
    }

    return max_element;
  }
};
