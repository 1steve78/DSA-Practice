class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long currentSum = 0;

        for (int x : nums) {
            if (currentSum + x > maxSum) {
                parts++;
                currentSum = x;
            } else {
                currentSum += x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};