class Solution {
private:
  int countStudents(vector<int> &nums, int pages) {
    int n = nums.size();

    int students = 1, pages_student = 0;

    for (int i = 0; i < n; i++) {
      if (pages_student + nums[i] <= pages) {
        pages_student += nums[i];
      } else {
        students++;
        pages_student = nums[i];
      }
    }

    return students;
  }

public:
  int findPages(vector<int> &nums, int m) {
    int n = nums.size();

    if (m > n) {
      return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    for (int pages = low; pages <= high; pages++) {
      if (countStudents(nums, pages) <= m) {
        return pages;
      }
    }

    return low;
  }
};
