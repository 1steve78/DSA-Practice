class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;

        int m = s.size();

        vector<long long> prefNum(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);
        vector<int> cnt(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % mod;

        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = prefNum[i];
            prefSum[i + 1] = prefSum[i];
            cnt[i + 1] = cnt[i];

            int d = s[i] - '0';

            if (d != 0) {
                cnt[i + 1]++;
                prefSum[i + 1] += d;
                prefNum[i + 1] = (prefNum[i + 1] * 10 + d) % mod;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];
            int len = cnt[r + 1] - cnt[l];

            long long x =
                (prefNum[r + 1]
                - 1LL * prefNum[l] * pow10[len] % mod
                + mod) % mod;

            ans.push_back((x * (sum % mod)) % mod);
        }

        return ans;
    }
};