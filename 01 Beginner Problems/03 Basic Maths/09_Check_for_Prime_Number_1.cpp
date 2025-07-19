class Solution {
public:
  bool isPrime(int n) {
    // your code goes here
    vector<int> divisors;

    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        divisors.push_back(i);
      }
    }

    return divisors.size() == 2;
  }
};
