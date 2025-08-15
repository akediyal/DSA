class Solution {
private:
  int sumOfDivisions(vector<int> &nums, int n, int d) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += (nums[i] + d - 1) / d;
    }

    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int limit) {
    int n = nums.size();

    int max_el = *max_element(nums.begin(), nums.end());

    for (int d = 1; d <= max_el; d++) {
      int sum = sumOfDivisions(nums, n, d);

      if (sum <= limit) {
        return d;
      }
    }

    return -1;
  }
};
