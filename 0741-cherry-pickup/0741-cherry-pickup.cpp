class Solution {
public:
    int n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;   // since r1+c1 = r2+c2

        // Out of bounds
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return INT_MIN;

        // Thorn
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        // Reached destination
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;

        // Same cell -> count once
        if (r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        int best = max({
            solve(r1 + 1, c1, r2 + 1), // down, down
            solve(r1 + 1, c1, r2),     // down, right
            solve(r1, c1 + 1, r2 + 1), // right, down
            solve(r1, c1 + 1, r2)      // right, right
        });

        if (best == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();

        dp.assign(n,
                  vector<vector<int>>(n,
                  vector<int>(n, -1)));

        return max(0, solve(0, 0, 0));
    }
};