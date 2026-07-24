class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Use a 1D DP array to save space
        vector<unsigned int> dp(amount + 1, 0);
        
        // Base case: 1 way to make amount 0 (use no coins)
        dp[0] = 1;

        // Iterate through each coin
        for (int coin : coins) {
            // Update the dp array for all amounts that can include this coin
            for (int amt = coin; amt <= amount; amt++) {
                dp[amt] += dp[amt - coin];
            }
        }

        return dp[amount];
    }
};