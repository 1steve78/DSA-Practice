class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

      
        vector<long long> right(n - 1);

        for (int i = 0; i < n - 1; i++) {
            long long dRight = (long long)nums[i + 1] - nums[i];

            bool rightIsClosest;

            if (i == 0) {
                rightIsClosest = true;
            } else {
                long long dLeft = (long long)nums[i] - nums[i - 1];

                rightIsClosest = dRight < dLeft;
            }

            right[i] = rightIsClosest ? 1 : dRight;
        }

        
        vector<long long> left(n - 1);

        for (int i = 1; i < n; i++) {
            long long dLeft = (long long)nums[i] - nums[i - 1];

            bool leftIsClosest;

            if (i == n - 1) {
                leftIsClosest = true;
            } else {
                long long dRight = (long long)nums[i + 1] - nums[i];

                leftIsClosest = dLeft <= dRight;
            }

            left[i - 1] = leftIsClosest ? 1 : dLeft;
        }

        
        vector<long long> prefRight(n, 0);

        for (int i = 0; i < n - 1; i++) {
            prefRight[i + 1] = prefRight[i] + right[i];
        }

        
        vector<long long> prefLeft(n, 0);

        for (int i = 1; i < n; i++) {
            prefLeft[i] = prefLeft[i - 1] + left[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r) {
                ans.push_back(prefRight[r] - prefRight[l]);
            } else {
                ans.push_back(prefLeft[l] - prefLeft[r]);
            }
        }

        return ans;
    }
};