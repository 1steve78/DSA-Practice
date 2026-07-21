class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n, 0);

        prev[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);

            // First element
            curr[0] = prev[0] + triangle[i][0];

            // Middle elements
            for (int j = 1; j < i; j++) {
                curr[j] = triangle[i][j] +
                          min(prev[j - 1], prev[j]);
            }

            // Last element
            curr[i] = prev[i - 1] + triangle[i][i];

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};