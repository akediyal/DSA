class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sum = 0;

        for (int K = i; K <= j; K++) {
          sum += nums[K];
        }

        if (sum == k) {
          cnt++;
        }
      }
    }

    return cnt;
  }
};
