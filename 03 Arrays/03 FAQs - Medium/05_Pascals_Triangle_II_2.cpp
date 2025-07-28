class Solution {
public:
  vector<int> pascalTriangleII(int r) {
    vector<int> ans;

    int num = 1;
    ans.push_back(num);

    for (int i = 1; i < r; i++) {
      num = num * (r - i);
      num = num / (i);
      ans.push_back(num);
    }

    return ans;
  }
};
