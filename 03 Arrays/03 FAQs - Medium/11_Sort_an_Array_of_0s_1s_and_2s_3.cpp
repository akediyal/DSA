class Solution {
public:
  void sortZeroOneTwo(vector<int> &nums) {
    int n = nums.size();

    int count_zero = 0;
    int count_one = 0;
    int count_two = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        count_zero++;
      } else if (nums[i] == 1) {
        count_one++;
      } else {
        count_two++;
      }
    }

    int i = 0;

    while (count_zero--) {
      nums[i] = 0;
      i++;
    }

    while (count_one--) {
      nums[i] = 1;
      i++;
    }

    while (count_two--) {
      nums[i] = 2;
      i++;
    }
  }
};
