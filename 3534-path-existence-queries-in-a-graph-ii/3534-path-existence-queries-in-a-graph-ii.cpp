class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n), comp(n);

        // position of every original node in sorted order
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        // connected components
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first - a[i - 1].first > maxDiff)
                id++;
            comp[i] = id;
        }

        // R[i] = farthest index reachable in one edge to the right
        vector<int> R(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && a[j + 1].first - a[i].first <= maxDiff)
                j++;
            R[i] = j;
        }

        // L[i] = farthest index reachable in one edge to the left
        vector<int> L(n);
        j = 0;
        for (int i = 0; i < n; i++) {
            while (a[i].first - a[j].first > maxDiff)
                j++;
            L[i] = j;
        }

        const int LOG = 17; // 2^17 > 1e5

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<vector<int>> down(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = R[i];
            down[0][i] = L[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
                down[k][i] = down[k - 1][ down[k - 1][i] ];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int res = 0;

            if (u < v) {
                int cur = u;
                for (int k = LOG - 1; k >= 0; k--) {
                    if (up[k][cur] < v) {
                        cur = up[k][cur];
                        res += (1 << k);
                    }
                }
                ans.push_back(res + 1);
            } else {
                int cur = u;
                for (int k = LOG - 1; k >= 0; k--) {
                    if (down[k][cur] > v) {
                        cur = down[k][cur];
                        res += (1 << k);
                    }
                }
                ans.push_back(res + 1);
            }
        }

        return ans;
    }
};