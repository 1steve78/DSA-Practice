class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
         int n = word1.size();
        int m = word2.size();

        // dp[i] = maximum number of characters from the suffix
        // of word2 that can be matched exactly in word1[i...].
        vector<int> dp(n + 1, 0);

        int j = m - 1;

        // Build DP from right to left.
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i]++;
                j--;
            }
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        // Greedily choose the smallest possible indices.
        for (int i = 0; i < n && j < m; i++) {

            // Case 1: Exact match.
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Case 2: Use our one allowed modification.
            else if (!changed && dp[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

         // Couldn't match all characters.
        if (j != m)
            return {};

        return ans;
    }
};