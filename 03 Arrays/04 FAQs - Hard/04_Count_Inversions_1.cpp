class Solution {
public:
  long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] > nums[j]) {
          cnt++;
        }
      }
    }

    return cnt;
  }
};
