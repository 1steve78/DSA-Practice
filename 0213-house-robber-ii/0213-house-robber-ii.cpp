class Solution {
public:
    int helper(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int skip = helper(i + 1, end, nums, dp);
        int take = nums[i] + helper(i + 2, end, nums, dp);

        return dp[i] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int excludeLast = helper(0, n - 2, nums, dp1);
        int excludeFirst = helper(1, n - 1, nums, dp2);

        return max(excludeLast, excludeFirst);
    }
};