class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, int cap, vector<int>& prices) {
        if (cap == 0) return 0;
        if (i == prices.size()) return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if (buy) {
            profit = max(
                solve(i + 1, 0, cap, prices) - prices[i],
                solve(i + 1, 1, cap, prices)
            );
        } else {
            profit = max(
                solve(i + 1, 1, cap - 1, prices) + prices[i],
                solve(i + 1, 0, cap, prices)
            );
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 2, prices);
    }
};