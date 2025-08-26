class Solution {
public:
  long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> how_many(n - 1, 0);

    for (int gas_stations = 1; gas_stations <= k; gas_stations++) {
      long double max_section = -1;
      int max_idx = -1;

      for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double section_length = diff / (how_many[i] + 1);

        if (section_length > max_section) {
          max_section = section_length;
          max_idx = i;
        }
      }

      how_many[max_idx]++;
    }

    long double max_ans = -1;

    for (int i = 0; i < n - 1; i++) {
      long double diff = arr[i + 1] - arr[i];
      long double section_length = diff / (how_many[i] + 1);

      max_ans = max(max_ans, section_length);
    }

    return max_ans;
  }
};
