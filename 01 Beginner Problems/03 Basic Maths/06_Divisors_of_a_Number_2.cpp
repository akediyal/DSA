class Solution {
public:
  vector<int> divisors(int n) {
    vector<int> divList;

    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divList.push_back(i);

        if (i != n / i) {
          divList.push_back(n / i);
        }
      }
    }

    sort(divList.begin(), divList.end());

    return divList;
  }
};
