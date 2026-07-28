class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &word1, string &word2) {
        // If word1 is exhausted, insert remaining characters of word2
        if (i == word1.size())
            return word2.size() - j;

        // If word2 is exhausted, delete remaining characters of word1
        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match, no operation needed
        if (word1[i] == word2[j])
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);

        // Try Insert, Delete, Replace
        int insertOp = 1 + solve(i, j + 1, word1, word2);
        int deleteOp = 1 + solve(i + 1, j, word1, word2);
        int replaceOp = 1 + solve(i + 1, j + 1, word1, word2);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(0, 0, word1, word2);
    }
};