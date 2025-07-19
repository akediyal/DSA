class Solution {
public:
  int secondMostFrequentElement(vector<int> &nums) {
    int max_freq = 0, sec_max_freq = 0;
    int max_element = -1, second_max_element = -1;

    int n = nums.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;
    }

    for (auto i : freq) {
      int element = i.first;
      int freq = i.second;

      if (freq > max_freq) {
        sec_max_freq = max_freq;
        max_freq = freq;
        second_max_element = max_element;
        max_element = element;
      } else if (freq == max_freq) {
        max_element = min(max_element, element);
      } else if (freq > sec_max_freq) {
        sec_max_freq = freq;
        second_max_element = element;
      } else if (freq == sec_max_freq) {
        second_max_element = min(second_max_element, element);
      }
    }

    return second_max_element;
  }
};
