class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx  = -1, maxIdx = -1;
        int n = nums.size();
        int mini = INT_MAX , maxi = INT_MIN;

        for(int i = 0 ; i < n ; i++ ){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i;
            }

            if(mini > nums[i]){
                mini = nums[i];
                minIdx = i;
            }
        }   

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        int bothLeft = r+1;
        int bothRight = n-l;
        int fromBothSides  = (l+1)+(n-r);
        return min({bothLeft, bothRight, fromBothSides});
    }
};