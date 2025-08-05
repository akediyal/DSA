class Solution {
public:
  long long int mSort(vector<int> &nums, int low, int high) {
    long long int cnt = 0;

    if (low >= high) {
      return cnt;
    }

    int mid = (low + high) / 2;

    cnt += mSort(nums, low, mid);
    cnt += mSort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);

    return cnt;
  }

  long long int merge(vector<int> &nums, int low, int mid, int high) {
    int left = low, right = mid + 1;

    vector<int> temp;

    long long int cnt = 0;

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

    return cnt;
  }

  long long int numberOfInversions(vector<int> nums) {
    long long int n = nums.size();
    long long int ans = mSort(nums, 0, n - 1);

    return ans;
  }
};
