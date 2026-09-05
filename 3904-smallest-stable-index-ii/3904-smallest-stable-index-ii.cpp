class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        int maxi = INT_MIN;
        int mini = INT_MAX;

        vector<int> maxArr(n), minArr(n);

        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            maxArr[i] = maxi;
        }

    
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            minArr[i] = mini;
        }


        for (int i = 0; i < n; i++) {
            if ((long long)maxArr[i] - minArr[i] <= k)
                return i;
        }

        return -1;
    }
};