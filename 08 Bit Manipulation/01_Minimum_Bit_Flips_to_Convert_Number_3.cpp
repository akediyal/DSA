class Solution {
private:
  int countSetBits(int n) {
    int cnt = 0;

    while (n != 0) {
      n &= n - 1;
      cnt++;
    }

    return cnt;
  }

public:
  int minBitsFlip(int start, int goal) {
    int n = start ^ goal;
    int ans = countSetBits(n);

    return ans;
  }
};
