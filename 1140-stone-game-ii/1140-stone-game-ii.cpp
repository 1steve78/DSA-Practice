class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][101];

    int solve(int i, int M) {
        // Can take all remaining piles
        if (2 * M >= n - i) {
            return suffix[i];
        }

        // Already calculated
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            int opponent = solve(i + X, max(M, X));

            // Total stones remaining - opponent's final score
            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};