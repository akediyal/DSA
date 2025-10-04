class Solution {
public:
  int findPlatform(vector<int> &Arrival, vector<int> &Departure) {
    int n = Arrival.size();

    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    int i = 0, j = 0;
    int ans = 0;
    int cnt = 0;

    while (i < n && j < n) {
      if (Arrival[i] <= Departure[j]) {
        cnt++;
        i++;
      } else {
        cnt--;
        j++;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
