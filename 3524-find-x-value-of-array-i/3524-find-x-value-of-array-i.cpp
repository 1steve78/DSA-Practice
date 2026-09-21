class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        
        
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);

            int rem = num % k;
            next[rem]++;

   
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRem = (r * rem) % k;
                next[newRem] += dp[r];
            }

        
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};