class Solution {
public:
  int maxScore(vector<int> &cardScore, int k) {
    int n = cardScore.size();
    int lsum = 0, rsum = 0;
    int max_sum = 0;

    for (int i = 0; i < k; i++) {
      lsum += cardScore[i];
    }

    max_sum = lsum;
    int right_index = n - 1;

    for (int i = k - 1; i >= 0; i--) {
      lsum -= cardScore[i];
      rsum += cardScore[right_index];
      right_index--;
      max_sum = max(max_sum, lsum + rsum);
    }

    return max_sum;
  }
};
