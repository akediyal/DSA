class Solution {
public:
  long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> how_many(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
      pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gas_stations = 1; gas_stations <= k; gas_stations++) {
      auto tp = pq.top();
      pq.pop();

      int sec_idx = tp.second;
      how_many[sec_idx]++;

      long double initial_diff = arr[sec_idx + 1] - arr[sec_idx];

      long double new_sec_len =
          initial_diff / (long double)(how_many[sec_idx] + 1);

      pq.push({new_sec_len, sec_idx});
    }

    return pq.top().first;
  }
};
