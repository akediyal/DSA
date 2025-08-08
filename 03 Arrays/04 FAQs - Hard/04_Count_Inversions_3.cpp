class Solution {
public:
  long long int cnt = 0;

  void mSort(vector<int> &nums, int low, int high) {
    if (low >= high) {
      return;
    }

    int mid = (low + high) / 2;

    mSort(nums, low, mid);
    mSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
  }

  void merge(vector<int> &nums, int low, int mid, int high) {
    int left = low, right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right]) {
        temp.push_back(nums[left]);
        left++;
      } else {
        temp.push_back(nums[right]);
        cnt += (mid - left + 1);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(nums[left]);
      left++;
    }

    while (right <= high) {
      temp.push_back(nums[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      nums[i] = temp[i - low];
    }
  }

  long long int numberOfInversions(vector<int> nums) {
    long long int n = nums.size();
    mSort(nums, 0, n - 1);

    return cnt;
  }
};
