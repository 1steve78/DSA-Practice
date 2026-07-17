class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // exact[d] = pairs whose gcd is exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            exact[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        vector<long long> pref;
        vector<int> value;

        long long sum = 0;

        for (int d = 1; d <= mx; d++) {

            if (exact[d] == 0)
                continue;

            sum += exact[d];

            pref.push_back(sum);
            value.push_back(d);
        }

        vector<int> ans;

        for (long long q : queries) {

            int idx = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();

            ans.push_back(value[idx]);
        }

        return ans;
    }
};