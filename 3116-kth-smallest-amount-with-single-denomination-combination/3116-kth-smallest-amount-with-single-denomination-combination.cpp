class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    ll count(ll x, vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            ll L = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, (ll)coins[i]);

                    if (L > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            ll contribution = x / L;

            if (bits % 2 == 1)
                ans += contribution;
            else
                ans -= contribution;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll left = 1;
        ll right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            ll mid = left + (right - left) / 2;

            if (count(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};