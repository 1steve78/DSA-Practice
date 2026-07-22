class Solution {
public:
    bool subsetSum(int n, int k, vector<int>& nums) {
        vector<bool> prev(k + 1, false), curr(k + 1, false);

        prev[0] = true;

        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            curr.assign(k + 1, false);
            curr[0] = true;

            for (int j = 1; j <= k; j++) {
                bool notTake = prev[j];
                bool take = false;

                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take || notTake;
            }

            prev = curr;
        }

        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        return subsetSum(nums.size(), sum / 2, nums);
    }
};