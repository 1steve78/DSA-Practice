class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> count;
        for (int value : power) {
            count[value]++;
        }

        vector<int> values;
        values.reserve(count.size());
        for (const auto& entry : count) {
            values.push_back(entry.first);
        }
        sort(values.begin(), values.end());

        int n = static_cast<int>(values.size());
        vector<long long> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            long long take = static_cast<long long>(values[i]) * count[values[i]];

            int j = i - 1;
            while (j >= 0 && values[i] - values[j] <= 2) {
                j--;
            }
            take += dp[j + 1];

            dp[i + 1] = max(dp[i], take);
        }

        return dp[n];
    }
};