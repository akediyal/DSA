class Solution {
public:
  string longestCommonPrefix(vector<string> &str) {
    // your code goes here
    sort(str.begin(), str.end());
    string first = str[0], last = str[str.size() - 1];

    int index = 0;
    for (int i = 0; i < first.size(); i++) {
      if (first[i] != last[i]) {
        break;
      }
      index++;
    }
    return first.substr(0, index);
  }
};
