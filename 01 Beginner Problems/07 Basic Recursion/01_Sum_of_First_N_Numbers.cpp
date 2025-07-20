class Solution {
public:
  int NnumbersSum(int N) {
    // your code goes here
    if (N == 0) {
      return 0;
    }
    return N + NnumbersSum(N - 1);
  }
};
