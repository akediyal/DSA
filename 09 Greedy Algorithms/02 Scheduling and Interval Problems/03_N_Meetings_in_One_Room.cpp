class Solution {
private:
  bool static compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  }

public:
  int maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++) {
      meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), compare);

    int free_time = meetings[0].second;
    int cnt = 1;

    for (int i = 0; i < n; i++) {
      if (meetings[i].first > free_time) {
        free_time = meetings[i].second;
        cnt++;
      }
    }

    return cnt;
  }
};
