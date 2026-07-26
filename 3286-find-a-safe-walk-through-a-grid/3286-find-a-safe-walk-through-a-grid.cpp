class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int,int>>> pq;

        vector<vector<int>> mxHealth(n, vector<int>(m, INT_MIN));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        pq.push({startHealth, {0, 0}});
        mxHealth[0][0] = startHealth;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int h = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // Ignore outdated states
            if (h < mxHealth[x][y]) continue;

            if (x == n - 1 && y == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newHealth = h - grid[nx][ny];

                    if (newHealth > 0 && newHealth > mxHealth[nx][ny]) {
                        mxHealth[nx][ny] = newHealth;
                        pq.push({newHealth, {nx, ny}});
                    }
                }
            }
        }

        return false;
    }
};