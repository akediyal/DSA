class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();

    map<int, int> freq;

    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;
    }

    for (auto it : freq) {
      if (it.second > (n / 2)) {
        return it.first;
      }
    }

    return -1;
  }
};
